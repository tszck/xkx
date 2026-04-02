//zhongping-qiang.c 中平槍法
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action": "$N雙手一別，盡力前伸，使出一招"HIW"「中平無敵」"NOR"，手中$w平平直出，刺向$n的$l",
	"lvl" : 0,
	"skill_name" : "中平無敵"
]),
([	"action": "$N手中$w盤旋迴轉，風響陣陣，屈身下蹲，反手一招"HIB"「夜叉探海」"NOR"自下向$n的$l刺去",
	"lvl" : 10,
	"skill_name" : "夜叉探海"
]),
([	"action": "$N舉起$w，抖出一朵槍花，一招"HIB"「靈蛇出洞」"NOR"向$n分心扎去",
	"lvl" : 20,
	"skill_name" : "靈蛇出洞"
]),
([	"action": "$N一招"HIM"「反身拿槍」"NOR"，手中$w劃個小圈消去$n的後招，而後$w微抬，指向$n的$l",
	"lvl" : 30,
	"skill_name" : "反身拿槍"
]),
});

int valid_enable(string usage) { return usage=="spear" || usage=="parry"; }
int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 70)
		return notify_fail("你的內力不夠。\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "spear")
		return notify_fail("你使用的武器不對。\n");
	if( (int)me->query("qi") < 50 || (int)me->query("neili") < 50 )
		return notify_fail("你的內力或氣不夠練中平槍法。\n");
	me->receive_damage("qi", 20);
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
	int d_e1 = -30;
	int d_e2 = -10;
	int p_e1 = 0;
	int p_e2 = 20;
	int f_e1 = 200;
	int f_e2 = 300;
	int m_e1 = 200;
	int m_e2 = 350;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("zhongping-qiang", 1);
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
		"damage"      : m_e1 + (m_e2 - m_e1) * seq / ttl,
		"damage_type" : "刺傷",
	]);
}
int learn_bonus() { return 15; }
int practice_bonus() { return 15; }
int success() { return 10; }
int power_point(object me) { return 1.0; }

int help(object me)
{
	write(HIC"\n中平槍法："NOR"\n");
	write(@HELP

    中平槍法是花鐵乾的成名武功。

	學習要求：
		內力70
HELP
	);
	return 1;
}

