// Last Modified by Winder on May. 29 2001
// sanhua-strike.c 散花掌 和摩訶指互備。四季詩句截至前人。

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N合掌抱球而開，一式「"HIG"春深芳草盡"NOR"」，掌力變幻吞吐，宛若春風撫體，緩緩飄向$n",
	"lvl"   : 0,
	"skill_name" : "春深芳草盡"
]),
([	"action" : "$N五指綻開，一式「"GRN"夏閒獨蘭馨"NOR"」，左右雙掌穿插翻飛，活力四濺，勁風向$n疾飛而去",
	"lvl"   : 30,
	"skill_name" : "夏閒獨蘭馨"
]),
([	"action" : "$N一式「"HIY"秋酣菊霜清"NOR"」，左掌虛託，右掌乍伸乍合，如在風中搖擺，輕輕撫向$n$l",
	"lvl"   : 60,
	"skill_name" : "秋酣菊霜清"
]),
([	"action" : "$N雙掌雪白，一式「"HIW"冬臥聽梅吟"NOR"」，翻飛中掌尖幻成漫天梅花朵朵，雨點般向$n飄去",
	"lvl"   : 100,
	"skill_name" : "冬臥聽梅吟"
])
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }
int valid_combine(string combo){ return combo=="mohe-finger"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("練散花掌必須空手。\n");
	if ((int)me->query_skill("zhanzhuang-gong", 1) < 30)
		return notify_fail("你的站樁功火候不夠，無法學散花掌。\n");
	if ((int)me->query("max_neili") < 200)
		return notify_fail("你的內力太弱，無法練散花掌。\n");
	if (me->query_skill("weituo-strike", 1) < 30)
		return notify_fail("你的韋陀掌火候不夠，無法學散花掌。\n");
	return 1;
}
int practice_skill(object me)
{
	if ((int)me->query("qi") < 40)
		return notify_fail("你的體力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的內力不夠練散花掌。\n");
	me->receive_damage("qi", 30);
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
	int d_e1 = -25;
	int d_e2 = 0;
	int p_e1 = 20;
	int p_e2 = 45;
	int f_e1 = 140;
	int f_e2 = 240;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("sanhua-strike", 1);
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
int power_point() { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"sanhua-strike/" + action;
}

int help(object me)
{
	write(HIC"\n散花掌："NOR"\n");
	write(@HELP

    散花掌是南少林掌法。和摩訶指互備。

	學習要求：
		站樁功30級
		韋陀掌30級
		內力修為200
HELP
	);
	return 1;
}

