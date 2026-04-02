// hannbing-mianzhang.c 寒冰綿掌
// Last Modified by sir 10.22.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"action" : "$N一式"HIB"「大江東去」"NOR"，雙掌大開大合，直向$n的$l擊去",
	"lvl" : 0,
	"skill_name" : "大江東去"
]),
([	"action" : "$N身形一變，一式"YEL"「黃河九曲」"NOR"，雙掌似曲似直，拍向$n的$l",
	"lvl" : 10,
	"skill_name" : "黃河九曲"
]),
([	"action" : "$N使一式"GRN"「湖光山色」"NOR"，左掌如微風拂面，右掌似細雨纏身，直取$n的$l",
	"lvl" : 20,
	"skill_name" : "湖光山色"
]),
([	"action" : "$N兩掌一分，一式"MAG"「曾經滄海」"NOR"，隱隱發出潮聲，向$n橫擊過去",
	"lvl" : 30,
	"skill_name" : "曾經滄海"
]),
([	"action" : "$N身形一轉，使出一式"HIM"「水光瀲灩」"NOR"，只見漫天掌影罩住了$n的全身",
	"lvl" : 40,
	"skill_name" : "水光瀲灩"
]),
([	"action" : "$N突然身形一緩，使出一式"HIG"「小雨初晴」"NOR"，左掌凝重，右掌輕盈，擊往$n的$l",
	"lvl" : 50,
	"skill_name" : "小雨初晴"
]),
([	"action" : "$N使一式"HIW"「風雪江山」"NOR"，雙掌挾狂風暴雪之勢，猛地劈向$n的$l",
	"lvl" : 60,
	"skill_name" : "風雪江山"
]),
([	"action" : "$N一招"HIW"「霜華滿地」"NOR"，雙掌帶着蕭瑟的秋氣，拍向$n的$l",
	"lvl" : 70,
	"skill_name" : "霜華滿地"
]),
([	"action" : "$N身法陡然一變，使出一式"HIW"「仙鄉冰舸」"NOR"，掌影千變萬幻，令$n無法躲閃",
	"lvl" : 80,
	"skill_name" : "仙鄉冰舸"
]),
([	"action" : "$N清嘯一聲，一式"HIW"「冰霜雪雨」"NOR"，雙掌揮舞，如同雪花隨風而轉，擊向$n的$l",
	"lvl" : 90,
	"skill_name" : "冰霜雪雨"
])
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry" ; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("練寒冰綿掌必須空手。\n");
	if (me->query_skill("jiuyang-shengong", 1) < 40)
		return notify_fail("你的九陽神功不到火候，無法學寒冰綿掌。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的內力太弱，無法練寒冰綿掌。\n");
	return 1;
}
int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("你的必須空手才能練習。\n");
	if ((int)me->query("qi") < 30)
		return notify_fail("你的體力太低了。\n");
	if ((int)me->query("neili") < 40)
		return notify_fail("你的內力不夠練寒冰綿掌。\n");
	me->receive_damage("qi", 25);
	me->add("neili", -10);
	return 1;
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	if( random(me->query_skill("hanbing-mianzhang",1)) > 10 )
		victim->apply_condition("ice_poison", random(me->query_skill("hanbing-mianzhang",1)/10) + 1 + victim->query_condition("ice_poison"));
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
	int d_e1 = -15;
	int d_e2 = 5;
	int p_e1 = 25;
	int p_e2 = 55;
	int f_e1 = 110;
	int f_e2 = 220;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("hanbing-mianzhang", 1);
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
	return __DIR__"hanbing-mianzhang/" + action;
}
int help(object me)
{
	write(HIC"\n寒冰綿掌："NOR"\n");
	write(@HELP

    寒冰綿掌是明教青翼蝠王韋一笑的獨門武功。中掌後就會寒毒
發作，歷時發作，其害無比。

	學習要求：
		九陽神功40級
		內力100
HELP
	);
	return 1;
}

