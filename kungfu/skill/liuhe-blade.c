// liuhe-blade.c 四象六合刀

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N一聲長嘯，手中$w一揚，一式天穹如蓋將$n罩在刀光之下",
	"lvl"    : 0,
	"skill_name" : "天穹如蓋",
]),
([	"action" : "$N一招"HIR"「乾坤倒轉」"NOR"，手中$w在空中虛劈數下，突然下劃割向$n的$l",
	"lvl"    : 20,
	"skill_name" : "乾坤倒轉",
]),
([	"action" : "$N腳下急旋，踏遍四方八面，手中$w化做一道寒芒，上下飛舞。好一招兩儀四象",
	"lvl"    : 40,
	"skill_name" : "兩儀四象",
]),
([	"action" : "$N神色肅殺，一聲虎吼，掌中刀光閃爍不定，一片刺骨的刀風將$n團團圍住，"HIC"「氣吞六合」"NOR"!",
	"lvl"    : 60,
	"skill_name" : "氣吞六合",
]),
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }
int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 50)
		return notify_fail("你的內力不夠。\n");
	if ((int)me->query_skill("huntian-qigong", 1) < 30)
		return notify_fail("你的混天氣功火候太淺。\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "blade")
		return notify_fail("你使用的武器不對。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的體力不夠練四象六合刀法。\n");
	me->receive_damage("qi", 25);
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
	int d_e1 = 55;
	int d_e2 = 35;
	int p_e1 = 5;
	int p_e2 = -15;
	int f_e1 = 100;
	int f_e2 = 150;
	int m_e1 = 50;
	int m_e2 = 160;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int)me->query_skill("liuhe-blade", 1);
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
		"damage_type" : "割傷",
	]);
}
int learn_bonus() { return 20; }
int practice_bonus() { return 25; }
int success() { return 15; }
int power_point(object me) { return 1; }

string perform_action_file(string action)
{
	return __DIR__"liuhe-blade/" + action;
}

int help(object me)
{
	write(HIC"\n四象六合刀："NOR"\n");
	write(@HELP

    四象六合刀為丐幫的刀法。

	學習要求：
		混天氣功30級
		內力50
HELP
	);
	return 1;
}

