//lingshe_zhangfa.c 靈蛇杖法
// Last Modified by sir 10.22.2001

#include "ansi.h"
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N使出一招"HIB"「靈蛇出洞」"NOR"，手中$w大開大闔掃向$n的$l",
	"lvl"    : 0,
	"skill_name" : "靈蛇出洞"
]),
([	"action" : "$N手中$w陣陣風響，一招"BLU"「搖頭擺尾」"NOR"向$n的$l攻去",
	"lvl"    : 20,
	"skill_name" : "搖頭擺尾"
]),
([	"action" : "$N舉起$w，居高臨下使一招"MAG"「靈蛇下澗」"NOR"砸向$n的$l",
	"lvl"    : 30,
	"skill_name" : "靈蛇下澗"
]),
([	"action" : "$N一招"HIM"「靈蛇挺身」"NOR"，手中$w猛烈掃向$n的$l",
	"lvl"    : 40,
	"skill_name" : "靈蛇挺身"
]),
([	"action" : "$N使出一招"YEL"「蛇遊蟒走」"NOR"，$w左右迂迴向$n的$l掃去",
	"lvl"    : 50,
	"skill_name" : "蛇遊蟒走"
]),
([	"action" : "$N手中$w一揮，使出一招"MAG"「蛇纏左右」"NOR"，忽左忽右掃向$n的$l",
	"lvl"    : 60,
	"skill_name" : "蛇纏左右"
]),
([	"action" : "$N使出一招"RED"「巨蟒下山」"NOR"，高舉手中$w，劈頭砸向$n的$l",
	"lvl"    : 80,
	"skill_name" : "巨蟒下山"
]),
([	"action" : "$N使出一招"HIR"「靈蛇出洞」"NOR"，手中$w猛一探，直掃$n的$l",
	"lvl"    : 100,
	"skill_name" : "靈蛇出洞"
]),
});

int valid_enable(string usage) { return usage == "staff" || usage == "parry"; }
int valid_learn(object me)
{
	if ((int)me->query_skill("hamagong", 1) < 20)
		return notify_fail("你的蛤蟆功功力不夠。\n");
	if ((int)me->query("max_neili") < 70)
		return notify_fail("你的內力不夠。\n");
	return 1;
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "staff")
		return notify_fail("你使用的武器不對。\n");
	if( (int)me->query("qi") < 60 || (int)me->query("neili") < 50 )
		 return notify_fail("你先歇口氣再練吧。\n");
	me->receive_damage("qi", 55);
	me->add("neili", -30);
	return 1;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	object weapon;

	if (objectp(weapon = me->query_temp("weapon")) &&
       ((string)weapon->query("id") == "she zhang" ||
        (string)weapon->query("id") == "lingshe zhang")&&
		random(me->query_skill("hamagong",1)) > 10 ) 
	{
		victim->apply_condition("snake_poison", random(me->query_skill("hamagong",1)/10) + 1 + victim->query_condition("snake_poison"));
		tell_object(victim, HIG"你覺得被擊中的地方一陣麻木！\n" NOR );
		tell_object(victim, HIG"原來是被杖頭竄出的毒蛇咬了一口！\n"NOR);
	}
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
	int d_e1 = -50;
	int d_e2 = -20;
	int p_e1 = 5;
	int p_e2 = 40;
	int f_e1 = 300;
	int f_e2 = 400;
	int m_e1 = 210;
	int m_e2 = 300;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("lingshe-zhangfa", 1);
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
int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 5; }
int power_point(object me) { return 1.0; }

string perform_action_file(string action)
{
	return __DIR__"lingshe-zhangfa/" + action;
}
int help(object me)
{
	write(HIC"\n靈蛇杖法："NOR"\n");
	write(@HELP

    靈蛇杖法是西毒歐陽鋒的歹毒武功。杖法兇狠，兼且杖頭毒蛇
乘隙傷人，甚是陰毒。

	學習要求：
		蛤蟆功20級
		內力修為70
HELP
	);
	return 1;
}

