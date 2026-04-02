// tanzhi.c 彈指神通
// Last Modified by sir 10.22.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N右指劃了個半圈，一式"CYN"「劃天裂地」"NOR"自上而下划向$n的全身",
	"lvl" : 0,
	"skill_name" : "劃天裂地"
]),
([	"action" : "$N左掌護胸，一招"BLU"「我心悠悠」"NOR"，右指欲舉無力指向$n的額頭",
	"lvl" : 10,
	"skill_name" : "我心悠悠"
]),
([	"action" : "$N雙手齊出，一式"YEL"「千夫所指」"NOR"，疾指向$n的$l",
	"lvl" : 20,
	"skill_name" : "千夫所指"
]),
([	"action" : "$N仰天一嘆，一招"RED"「彈指人生」"NOR"，雙手幻出重重指影，點向$n的$l",
	"lvl" : 30,
	"skill_name" : "彈指人生"
]),
([	"action" : "$N一式"GRN"「笑指天南」"NOR"，左掌蓄式，右指彈出一縷指風點向$n的$l",
	"lvl" : 40,
	"skill_name" : "笑指天南"
]),
([	"action" : "$N用出"HIY"「擎天一指」"NOR"，蓄集全身力氣，一指點向$n的$l",
	"lvl" : 50,
	"skill_name" : "擎天一指"
]),

});

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }
int valid_combine(string combo) { return combo=="lanhua-shou"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("練彈指神通必須空手。\n");
	if ((int)me->query_skill("bibo-shengong", 1) < 20)
		return notify_fail("你的碧波神功火候不夠，無法學彈指神通。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的內力太弱，無法練彈指神通。\n");
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("你的必須空手才能練習。\n");
	if ((int)me->query("qi") < 40)
		return notify_fail("你的體力不夠，休息一下再練吧。\n");
	if ((int)me->query("neili") < 30)
		return notify_fail("你的內力不夠練彈指神通。\n");
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
	int d_e1 = 30;
	int d_e2 = 50;
	int p_e1 = -30;
	int p_e2 = -10;
	int f_e1 = 300;
	int f_e2 = 400;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("tanzhi-shentong", 1);
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
		"damage_type" : random(2) ? "刺傷" : "瘀傷",
	]);
}
int learn_bonus() { return 10; }
int practice_bonus() { return 10; }
int success() { return 15; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"tanzhi-shentong/" + action;
}
int help(object me)
{
	write(HIC"\n彈指神通："NOR"\n");
	write(@HELP

    東海桃花島主黃藥師的成名絕技。
    可與蘭花拂穴手互備。

	學習要求：
		碧波神功20級
		內力100
HELP
	);
	return 1;
}

