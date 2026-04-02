// luoying-shenjian.c 落英神劍
// Last Modified by sir 10.22.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

mapping *action = ({
([	"skill_name" : "落英繽紛",
	"action" : "$N使一招"HIW"「落英繽紛」"NOR"，身形向上飄起，手中$w虛虛實實幻出萬點劍花紛紛揚揚撒向$n$l",
	"lvl"    : 0
]),
([	"skill_name" : "人面桃花",
	"action" : "$N舞動$w，一式"MAG"「人面桃花」"NOR"，左手向$n面門一晃，右手$w抖出幾朵劍花挾着虎虎劍氣刺向$n的$l",
	"lvl"    : 10
]),
([	"skill_name" : "急風驟雨",
	"action" : "$N身形繞$n一轉，手中$w望空一指，一式"BLU"「急風驟雨」"NOR"幻出滿天劍影，向$n$l接連揮出數劍",
	"lvl"    : 20
]),
([	"skill_name" : "江城飛花",
	"action" : "$N身形飄然而起，在半空中身子一旋，悠然一式"RED"「江城飛花」"NOR"手中$w若有若無淡淡刺向$n的$l",
	"lvl"    : 30
]),
([	"skill_name" : "萬花齊落",
	"action" : "$N縱起丈餘，一式"HIW"「細雲巧翻胸」"NOR"頭下腳上，一招"HIR "「萬花齊落」"NOR"手中$w舞成一個光球罩向$n的$l",
	"lvl"    : 40
]),
([	"skill_name" : "漫天花雨",
	"action" : "$N一聲大喝使出"HIM"「漫天花雨」"NOR"，手中$w幻出漫天花瓣，迅若奔雷射向$n的$l",
	"lvl"    : 50
]),
([	"skill_name" : "落花無意",
	"action" : "$N輕嘆一聲，手中$w懷中一抱，一時"HIB"「落花無意」"NOR"，$w鏘然躍出倏的化作幾點帶露的桃花，飄然飛向$n的$l",
	"lvl"    : 60
]),
});

int valid_enable(string usage) { return usage=="sword" || usage=="parry"; }
int valid_learn(object me)
{
	object ob;

	if( (int)me->query_skill("bibo-shengong",1) < 30)
		return notify_fail("你的碧波神功火候還不夠。\n"); 
	if( (int)me->query("max_neili") < 100 )
		return notify_fail("你的內力不夠，不能練落英神劍。\n"); 
	if (!objectp(ob = me->query_temp("weapon"))
	|| (string)ob->query("skill_type") != "sword")
		return notify_fail("你必須先找一把劍才能學習劍法。\n");

	return 1;
}
int practice_skill(object me)
{
	object ob;

	if( (int)me->query("qi") < 35 || (int)me->query("neili") < 15 )
		return notify_fail("你的內力或氣不夠，沒辦法練習落英神劍。\n");
	if (!objectp(ob = me->query_temp("weapon"))
		|| (string)ob->query("skill_type") != "sword")
		return notify_fail("你必須先找一把劍才能習練劍法。\n");
	me->receive_damage("qi", 35);
	me->add("neili", -15);
	write("你按著所學練了一遍落英神劍。\n");
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
	int p_e1 = -5;
	int p_e2 = 15;
	int f_e1 = 100;
	int f_e2 = 150;
	int m_e1 = 50;
	int m_e2 = 150;
	int i, lvl, seq, ttl = sizeof(action);

	lvl = (int) me->query_skill("luoying-shenjian", 1);
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
		"damage_type" : random(2) ? "割傷" : "刺傷",
	]);
}
int learn_bonus() { return 25; }
int practice_bonus() { return 25; }
int success() { return 15; }
int power_point(object me) { return 1.0; }

int help(object me)
{
	write(HIC"\n落英神劍："NOR"\n");
	write(@HELP

    落英神劍爲東海桃花島主黃藥師所創。
    在桃花島竹林內“積翠亭”兩旁，懸着一副對聯：“桃花影裏
飛神劍，碧海潮生按玉簫”，隱然黃藥師生平兩大得意武功。其中
之一就是落英神劍。

	學習要求：
		碧波神功30級
		內力100
HELP
	);
	return 1;
}

