// qishang-quan.c 七傷拳
// Last Modified by sega on Mar. 10 2000

#include <ansi.h>
inherit "/inherit/skill/cuff.c";
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N氣凝如山，一式「金戈鐵馬」，雙拳蓄勢而發，擊向$n的$l",
	"lvl" : 0,
	"skill_name" : "金戈鐵馬"
]),
([	"action" : "$N身形凝重，勁發腰背，一式「木已成舟」，緩緩向$n推出",
	"lvl" : 10,
	"skill_name" : "木已成舟"
]),
([	"action" : "$N步伐輕靈，兩臂伸舒如鞭，一式「水中撈月」，令$n無可躲閃",
	"lvl" : 20,
	"skill_name" : "水中撈月"
]),
([	"action" : "$N身形躍起，一式「火海刀山」，雙拳當空擊下，勢不可擋",
	"lvl" : 30,
	"skill_name" : "火海刀山"
]),
([	"action" : "$N身形一矮，一式「土載萬物」，兩拳自下而上，攻向$n",
	"lvl" : 40,
	"skill_name" : "土載萬物"
]),
([	"action" : "$N身形一轉，一式「陰風慘慘」，攻向$n的身前身後",
	"lvl" : 48,
	"skill_name" : "陰風慘慘"
]),
([	"action" : "$N移形換位，步到拳到，一式「陽光普照」，四面八方都是拳影",
	"lvl" : 54,
	"skill_name" : "陽光普照"
]),
([	"action" : "$N長嘯一聲，向前踏出一步，雙拳中宮直進，一式「七者皆傷」，驟然擊向$n的前胸",
	"lvl" : 60,
	"skill_name" : "七者皆傷"
])
});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }
int valid_learn(object me)
{
	mapping myfam;
	myfam = (mapping)me->query("family");
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("練七傷拳必須空手。\n");
	if ((int)me->query_skill("jiuyang-shengong", 1) < 10)
		return notify_fail("你的九陽神功火候不夠，無法學七傷拳。\n");
	if ((int)me->query("max_neili") < 200)
		return notify_fail("你的內力太弱，無法練七傷拳。\n");
	if ((int)me->query_skill("qishang-quan", 1) > 199)
		return 1;
	if(!myfam || myfam["family_name"] != "明教" ||
		myfam["master_id"] != "xie xun")
		return notify_fail("七傷拳只能向金毛獅王學習。\n");
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("你的必須空手才能練習。\n");
	if ((int)me->query("qi") < 30)
		return notify_fail("你的體力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的內力不夠練七傷拳。\n");
/*
	if ((int)me->query_skill("qishang-quan",1) % 20 == 0 &&
		(int)me->query_skill("qishang-quan",1) < 200)
		return notify_fail("你的七傷拳到了關鍵火候，怎麼練都無法領悟。\n");
*/
	me->receive_damage("qi", 30);
	me->add("neili", -20);
	return 1;
}
string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action); i > 0; i--)
		if(level >= action[i-1]["lvl"])
			return action[i-1]["skill_name"];
}
mapping query_action(object me, object weapon)
{
/* d_e=dodge_effect p_e=parry_effect f_e=force_effect m_e=damage_effect */
	int d_e1 = 5;
	int d_e2 = 30;
	int p_e1 = -50;
	int p_e2 = -5;
	int f_e1 = 250;
	int f_e2 = 450;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("qishang-quan", 1);
	for(i = ttl; i > 0; i--)
		if(lvl > action[i-1]["lvl"])
		{
			seq = i; /* 獲得招數序號上限 */
			break;
		}
	seq = random(seq);       /* 選擇出手招數序號 */
	return ([
		"action"      : action[seq]["action"],
		"dodge"       : d_e1 + (d_e2 - d_e1) * seq / ttl,
		"parry"       : p_e1 + (p_e2 - p_e1) * seq / ttl,
		"force"       : f_e1 + (f_e2 - f_e1) * seq / ttl,
		"damage_type" : "瘀傷",
	]);
}
int learn_bonus() { return 10; }
int practice_bonus() { return 10; }
int success() { return 10; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"qishang-quan/" + action;
}
int help(object me)
{
	write(HIC"\n七傷拳："NOR"\n");
	write(@HELP

    七傷拳，拳出必傷。是崆峒派的不傳之祕，但後來謝遜爲報家
仇，從崆峒派手中盜出《七傷拳譜》，從而練成。名爲七傷，實則
爲每出一拳可以有七種不同內勁，使人不知如何與之相抗。

                    ┌--------------------┐
                    │    七傷拳總訣      │
                    │  五行之氣調陰陽，  │
                    │  損心傷肺摧肝腸，  │
                    │  藏離精失意恍惚，  │
                    │三焦齊逆兮魂魄飛    │
                    └--------------------┘

	學習要求：
		只能向謝遜學習
		九陽神功20級
		內力200
HELP
	);
	return 1;
}
