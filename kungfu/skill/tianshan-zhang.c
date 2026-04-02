// tianshan-zhang.c 天山杖法
// Last Modified by sir 10.22.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action": "$N使出一招"HIW"「冰河開凍」"NOR"，手中$w大開大闔掃向$n的$l",
	"lvl" : 1,
	"skill_name" : "冰河開凍"
]),
([	"action": "$N手中$w陣陣風響，一招"HIC"「山風凜冽」"NOR"向$n的$l攻去",
	"lvl" : 13,
	"skill_name" :"山風凜冽"
]),
([	"action": "$N舉起$w，居高臨下使一招"HIW"「天山雪崩」"NOR"砸向$n的$l",
	"lvl" : 30,
	"skill_name" : "天山雪崩"
]),
([	"action": "$N一招"HIR"「殘陽照雪」"NOR"，縱身飄開數尺，手中$w砸向$n的$l",
	"lvl" : 45,
	"skill_name" : "殘陽照雪"
]),
([	"action": "$N使一招"HIB"「回光幻電」"NOR"，手中$w幻一條疾光點向$n的$l",
	"lvl" : 60,
	"skill_name" : "回光幻電"
]),
([	"action": "$N使出的"HIC"「風霜碎影」"NOR"，$w連揮杖影霍霍劈向$n的$l",
	"lvl" : 75,
	"skill_name" : "風霜碎影"
]),
([	"action": "$N的$w憑空一指，一招"BLU"「斷石狼煙」"NOR"點向$n的$l",
	"lvl" : 90,
	"skill_name" : "斷石狼煙"
]),
([	"action": "$N縱身一躍，手中$w一招"MAG"「長空雷隱」"NOR"對準$n的$l掃去",
	"lvl" : 105,
	"skill_name" : "長空雷隱"
]),
([	"action": "$N手中$w中宮直進，一式"CYN"「冰谷初虹」"NOR"對準$n的$l點去",
	"lvl" : 120,
	"skill_name" : "冰谷初虹"
]),
([	"action": "$N一招"GRN"「峯迴路轉」"NOR"，$w左右迂迴向$n的$l點去",
	"lvl" : 145,
	"skill_name" : "峯迴路轉"
]),
});

int valid_enable(string usage) { return usage == "staff" || usage == "parry"; }
int valid_learn(object me)
{
	if (me->query_skill("huagong-dafa",1) < 20)
		return notify_fail("你的化功大法功力不夠。\n");
	if ((int)me->query("max_neili") < 80)
		return notify_fail("你的內力不夠。\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "staff")
		return notify_fail("你使用的武器不對。\n");
	if( (int)me->query("qi") < 50 || (int)me->query("neili") < 30 )
		return notify_fail("你的內力或氣不夠練天山杖法。\n");
	me->receive_damage("qi", 40);
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
string perform_action_file(string action)
{
	return __DIR__"tianshan-zhang/" + action;
}
mapping query_action(object me, object weapon)
{
/* d_e=dodge_effect p_e=parry_effect f_e=force_effect m_e=damage_effect */
	int d_e1 = -40;
	int d_e2 = -10;
	int p_e1 = 15;
	int p_e2 = 50;
	int f_e1 = 250;
	int f_e2 = 300;
	int m_e1 = 180;
	int m_e2 = 280;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("tianshan-zhang", 1);
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
		"damage_type" : "挫傷",
	]);
}
int learn_bonus() { return 10; }
int practice_bonus() { return 10; }
int success() { return 10; }
int power_point(object me) { return 1.0; }

int help(object me)
{
	write(HIC"\n天山杖法\n");
	write(@HELP

    天山杖法是星宿派器械功夫。

	學習要求：
		化功大法20級
		內力80
HELP
	);
	return 1;
}

