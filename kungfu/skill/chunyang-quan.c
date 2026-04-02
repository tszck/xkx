// chunyang-quan.c 純陽拳
// Last Modified by sega on Mar. 10 2000

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action":
"只見$N身形一矮，大喝聲中以拳化勾一個"HIW"「玄鶴捕食」"NOR"對準$n的$l戳了過去",
	"lvl" : 0,
	"skill_name" : "玄鶴捕食"
]),
([	"action":
"$N左手一分，身形扭轉右拳運氣，蜿蜒前伸，一招"HIY"「金蛇尋龜」"NOR"便往$n的$l
招呼過去",
	"lvl" : 20,
	"skill_name" : "金蛇尋龜"
]),
([	"action":
"$N右拳在$n面門一晃，和身向前一撲左拳使了個"HIB"「野馬上槽」"NOR"往$n的$l狠命一掄",
	"lvl" : 40,
	"skill_name" : "野馬上槽"
]),
([	"action":
"$N步履一沉，左拳拉開，右拳帶風，一招"HIR"「黑虎掏心」"NOR"勢不可擋地擊向$n$l",
	"lvl" : 60,
	"skill_name" : "黑虎掏心"
]),
([	"action":
"只見$N拉開架式，一招"HIM"「二龍戲珠」"NOR"雙拳齊出擊向$n$l，虎虎有風",
	"lvl" : 80,
	"skill_name" : "二龍戲珠"
]),
([	"action":
"$N虛晃一拳，回身欲走，只霎那間身子一側，反腳踢起，正是"RED"「麒麟反掛」"NOR"！",
	"lvl" : 100,
	"skill_name" : "麒麟反掛"
]),
([	"action":
"$N拉開後弓步，左拳一晃，右拳隨出，左右拳掌交替變幻迭出，一招"GRN"「青龍
奪食」"NOR"往$n的$l攻去",
	"lvl" : 120,
	"skill_name" : "青龍奪食"
]),
([	"action":
"只見$N運足氣力，一個縱身，右拳從左拳後側身穿出，身隨拳至，力勢千鈞！
這一招的名字叫作"HIR"「赤龍穿雲」"NOR"",
	"lvl" : 140,
	"skill_name" : "赤龍穿雲"
]),
});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }
int valid_combine(string combo) { return combo=="haotian-zhang"; }

int valid_learn(object me)
{
	if(me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("練純陽拳必須空手。\n");
	if ((int)me->query_skill("xiantian-qigong", 1) < 20)
		return notify_fail("你的先天氣功火候不夠，無法學純陽拳。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的內力太弱，無法練純陽拳。\n");
	return 1;
}

int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("你的必須空手才能練習。\n");
	if ((int)me->query("qi") < 40)
		return notify_fail("你的體力太低了。\n");
	if ((int)me->query("neili") < 40)
		return notify_fail("你的內力不夠練純陽拳。\n");
	me->receive_damage("qi", 35);
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
	int d_e1 = 20;
	int d_e2 = 40;
	int p_e1 = -40;
	int p_e2 = -20;
	int f_e1 = 200;
	int f_e2 = 400;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("chunyang-quan", 1);
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
		"damage_type" : random(2) ? "內傷" : "瘀傷",
	]);
}
int learn_bonus() { return 10; }
int practice_bonus() { return 10; }
int success() { return 10; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"chunyang-quan/" + action;
}
int help(object me)
{
	write(HIC"\n純陽拳："NOR"\n");
	write(@HELP

    純陽拳為王重陽所創的全真派拳法。
    可與昊天掌互備。

	學習要求：
		先天氣元功20級
		內力100
HELP
	);
	return 1;
}

