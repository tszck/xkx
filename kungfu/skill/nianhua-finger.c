// Last Modified by Winder on May. 29 2001
// nianhua-finger.c 拈花指 和鷹爪功互備 取自如來十大弟子名。

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N側身抬臂，右指鈎了個半圈，一式"HIB"「優婆離式」"NOR"輕輕一彈，擊向$n的$l",
	"lvl"    : 0,
	"skill_name" : "優婆離式"
]),
([	"action" : "$N左掌虛託胸前，一招"HIY"「須菩提式」"NOR"，右指穿腋而出，不緊不緩，點向$n的$l",
	"lvl"    : 10,
	"skill_name" : "須菩提式"
]),
([	"action" : "$N面帶微笑，俯身斜倚，左手駐起氣牆，右手一式"HIM"「阿難式」"NOR"，向$n$l輕點",
	"lvl"    : 20,
	"skill_name" : "阿難式"
]),
([	"action" : "$N雙目微睜，面露輕笑，一式"HIG"「迦葉式」"NOR"，幻化出千百個指影，拂向$n$l",
	"lvl"    : 30,
	"skill_name" : "迦葉式"
]),
([	"action" : "$N一式"MAG"「金蟬子式」"NOR"，左掌護住丹田，右手斜指蒼天蓄勢，接着才緩緩點向$n$l",
	"lvl"    : 40,
	"skill_name" : "金蟬子式"
]),
([	"action" : "$N微笑之中提雙掌平託胸前，十指叉開，一式"CYN"「僑陳如式」"NOR"，指向$n的周身大穴",
	"lvl"    : 60,
	"skill_name" : "僑陳如式"
]),
([	"action" : "$N雙掌翻飛，一式"RED"「阿金婆誓式」"NOR"，微笑中於指端迸出數道柔勁，點向$n",
	"lvl"    : 80,
	"skill_name" : "阿金婆誓式"
]),
([	"action" : "$N一招"HIC"「摩訶跋提式」"NOR"，並指如柳，化出一束束細柔的氣勁，凌虛向$n的$l點去",
	"lvl"    : 110,
	"skill_name" : "摩訶跋提式"
]),
([	"action" : "$N一招"HIM"「十力伽葉式」"NOR"，輕笑一聲，雙手食指交叉，指端挑出一縷罡氣，輕輕撫向$n$l",
	"lvl"    : 130,
	"skill_name" : "十力伽葉式"
]),
([	"action" : "$N左掌豎立胸前，一式"HIR"「摩男俱利式」"NOR"，微笑中右手食指扣住拇指，輕輕對着$n一彈",
	"lvl"    : 150,
	"skill_name" : "摩男俱利式"
])
});

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }
int valid_combine(string combo){ return combo=="eagleg-claw"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("練拈花指必須空手。\n");
	if ((int)me->query_skill("zhanzhuang-gong", 1) < 60)
		return notify_fail("你的站樁功火候不夠，無法學拈花指。\n");
	if ((int)me->query("max_neili") < 600)
		return notify_fail("你的內力太弱，無法練拈花指。\n");
	if ((me->query_skill("duoluoye-finger", 1) < 50) ||
		(me->query_skill("jingang-strike", 1) < 50))
		return notify_fail("你的大金剛神掌和多羅葉指火候不夠，無法學拈花指。\n");
	return 1;
}
int practice_skill(object me)
{
	if ((int)me->query("qi") < 55)
		return notify_fail("你的力氣太低了。\n");
	if ((int)me->query("neili") < 30)
		return notify_fail("你的內力不夠練拈花指。\n");
	me->receive_damage("qi", 35);
	me->add("neili", -15);
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
	int d_e1 = 35;
	int d_e2 = 60;
	int p_e1 = -20;
	int p_e2 = -5;
	int f_e1 = 200;
	int f_e2 = 300;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("nianhua-finger", 1);
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
int learn_bonus() { return 25; }
int practice_bonus() { return 25; }
int success() { return 15; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"nianhua-finger/" + action;
}

int help(object me)
{
	write(HIC"\n拈花指："NOR"\n");
	write(@HELP

    拈花指是南少林指法，和鷹爪功互備，取自如來十大弟子名。

	學習要求：
		站樁功60級
		大金剛神掌50級
		多羅葉指50級
		內力修為600
HELP
	);
	return 1;
}

