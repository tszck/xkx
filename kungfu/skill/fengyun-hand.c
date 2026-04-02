// Last Modified by winder on May. 29 2001
// fengyun-hand.c 風雲手 和羅漢拳互備

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N一式"CYN"「風滿長空」"NOR"，雙手以掌化爪，五指如鉤，挾着風聲直逼$n的膻中要穴",
	"limb" : "膻中穴",
	"lvl" : 0,
	"skill_name" : "風滿長空"
]),
([	"action" : "$N一式"RED"「烈火騰雲」"NOR"，右手上下揮動化成迷霧，接着左手一探，反扣$n的肩井大穴",
	"lvl" : 8,
	"limb" : "肩井穴",
	"skill_name" : "烈火騰雲"
]),
([	"action" : "$N使一式"GRN"「草深霧澤」"NOR"，掌指齊出，幻出無數幻影，風聲中右手按向$n的胸前要害",
	"lvl" : 16,
	"skill_name" : "草深霧澤"
]),
([	"action" : "$N左手成掌，右手握拳，一式"BLU"「天目昭輝」"NOR"，拉出的拳影掌影有如雲霧變幻一般，罩向$n",
	"lvl" : 24,
	"skill_name" : "天目昭輝"
]),
([	"action" : "$N使一式"YEL"「雷震四方」"NOR"，雙手揮動，四面八方出現無數掌影，跟着一爪突出，抓向$n$l",
	"lvl" : 40,
	"skill_name" : "雷震四方"
]),
([	"action" : "$N兩手環扣，雙臂如流雲般晃動，一式"CYN"「水到渠成」"NOR"，節節進逼，將$n拉入招中",
	"lvl" : 48,
	"skill_name" : "水到渠成"
]),
([	"action" : "$N一式"GRN"「山高林密」"NOR"，一掌拍出飛天沙石，然後十指齊伸，遮天蔽日般地籠罩$n的全身要穴",
	"lvl" : 54,
	"skill_name" : "山高林密"
]),
([	"action" : "$N嶽立霆峙，一式"YEL"「地老天荒」"NOR"，在一陣暴雷風雲聲中，雙手同時拍中$n的七道死穴",
	"lvl" : 100,
	"skill_name" : "地老天荒"
])
});

int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }
int valid_combine(string combo){ return combo=="luohan-cuff"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("練風雲手必須空手。\n");
	if ((int)me->query_skill("zhanzhuang-gong", 1) < 10)
		return notify_fail("你的站樁功火候不夠，無法學風雲手。\n");
	if ((int)me->query("max_neili") < 10)
		return notify_fail("你的內力太弱，無法練風雲手。\n");
	if (me->query_skill("shaolin-cuff", 1) < 10 )
		return notify_fail("你還未掌握少林南拳，無法學習風雲手。\n");

	return 1;
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 40)
		return notify_fail("你的體力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的內力不夠練風雲手。\n");
	me->receive_damage("qi", 20);
	me->add("neili", -10);
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
	int d_e1 = -30;
	int d_e2 = 0;
	int p_e1 = 30;
	int p_e2 = 60;
	int f_e1 = 60;
	int f_e2 = 160;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("fengyun-hand", 1);
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
int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 20; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	 return __DIR__"fengyun-hand/" + action;
}

int help(object me)
{
	write(HIC"\n風雲手："NOR"\n");
	write(@HELP

    風雲手是南少林入門手法。和羅漢拳互備。

	學習要求：
		站樁功10級
		少林南拳10級
		內力修爲10
HELP
	);
	return 1;
}

