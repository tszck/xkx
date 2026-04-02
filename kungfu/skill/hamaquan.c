// hamaquan.c
// Last Modified by winder on May. 15 2001
#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N一式"HIB"「蛙鳴三起」"NOR"，以掌化爪，分襲$n的上中下三路要害",
	"lvl" : 0,
	"skill_name" : "蛙鳴三起"
]),
([	"action" : "$N左手虛晃，右手由前至後，反扣$n的肩井大穴",
	"lvl" : 8,
	"skill_name" : "反手點穴"
]),
([	"action" : "$N使一式"HIY"「前瞻後跳」"NOR"，人似蛤蟆狀，半蹲而立，忽得撲向$n",
	"lvl" : 30,
	"skill_name" : "前瞻後跳"
]),
([	"action" : "$N使一式"HIW"「分身無影」"NOR"，四面八方出現無數掌影，一拳擊向$n的胸口",
	"lvl" : 70,
	"skill_name" : "分身無影"
]),
([	"action" : "$N兩手成爪像，全身咕嚕作響，一式"HIR"「無敵蛤蟆」"NOR"，擊向$n的$l",
	"lvl" : 98,
	"skill_name" : "無敵蛤蟆"
])
});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("練蛤蟆拳必須空手。\n");
	if ((int)me->query_skill("hamagong", 1) < 20)
		return notify_fail("你的蛤蟆功火候不夠，無法學蛤蟆拳。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的內力太弱，無法練蛤蟆拳手。\n");
	return 1;
}
int practice_skill(object me)
{
	if ((int)me->query("qi") < 40)
		return notify_fail("你的體力太低了。\n");
	if ((int)me->query("neili") < 40)
		return notify_fail("你的內力不夠練蛤蟆拳。\n");
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
	int d_e1 = 25;
	int d_e2 = 45;
	int p_e1 = -35;
	int p_e2 = -15;
	int f_e1 = 150;
	int f_e2 = 300;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("hamaquan", 1);
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
int learn_bonus() { return 15; }
int practice_bonus() { return 15; }
int success() { return 15; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"hamaquan/" + action;
}

int help(object me)
{
	write(HIC"\n蛤蟆拳："NOR"\n");
	write(@HELP

    歐陽鋒創立的白駝山派本門拳法。

	學習要求：
		蛤蟆功20級
		內力修為100
HELP
	);
	return 1;
}

