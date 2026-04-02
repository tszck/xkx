// iron-sword.c 玄鐵劍法
// Last Modified by winder on Feb. 28 2001
 
#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

string *msg = ({
BLU "$N當胸平平刺出一劍，實在是毫無任何變化，而卻有轟轟之聲，$n"BLU"只覺\n一股大力由$w"BLU"直逼周身",
BLU "$N凌空躍起，身隨劍起，藉助下行之勢向下猛劈一劍，將$n"BLU"周身籠於劍氣之下",
BLU "$N輕嘆一聲，隨手橫劈一劍，緩緩指向$n"BLU"，看似無絲毫變化，卻盡得劍\n法精髓，當真平淡中蘊涵所有變化，無招勝有招",
BLU "$N迅疾挑出一劍，但見劍勢如虹，快似閃電，無可當鋒！此劍之快，匪夷所\n思，$n"BLU"無法分辨出劍路去來",
BLU "$N仰首長嘯，令風雲變幻，狂風遽起，旋及一劍平指，劍氣瀰漫於$n"BLU"周\n身各處，$n"BLU"只覺身處驚濤駭浪之中，驚怖中更覺$N劍力有如海潮一般，一波\n一浪陣陣湧來，綿延不絕，愈發愈強",
BLU "$N祭起$w"BLU"，左手捏成劍訣置於胸前，咄喝一聲，正是劍法至尊的“御劍\n式”，空中滿是劍影，宛若千道銀鏈，只在$n"BLU"身邊遊動",
BLU "$N$w"BLU"連出十餘劍，一時迅疾如流星劃空，一時凝重遲緩，招招無跡可尋，\n平淡至極又匪思至極，順刺，逆擊，橫削，倒劈，無不是劍法的入門，當真返樸\n歸真，卻已不再存任何破綻",
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }
int valid_learn(object me)
{
	object weapon;
	if ((int)me->query("max_neili") < 1500)
		return notify_fail("你的內力太弱，無法練玄鐵劍法。\n");
	if ((int)me->query_skill("yunv-xinfa", 1) < 150)
		return notify_fail("你的玉女心法不熟練，無法練玄鐵劍法。\n");
	if (!(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "sword" )
		return notify_fail("你必須先找一把劍才能練劍法。\n");
	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("id") != "iron sword")
		return notify_fail("沒有玄鐵劍在手，你無法體會玄鐵劍法以拙馭巧的劍意。\n");
	return 1;
}
int practice_skill(object me)
{
	int cost;
	cost = 40;
	if ((int)me->query("qi") < 140)
		return notify_fail("你的體力太低了。\n");
	if ((int)me->query("neili") < 50)
		return notify_fail("你的內力不夠練玄鐵劍法。\n");
	if ((int)me->query_skill("anran-zhang", 1)>150)
	        cost=80;
	if ((int)me->query_skill("anran-zhang", 1)>250)
	        cost=160;   
	me->receive_damage("qi", cost);
	me->add("neili", -50);
	return 1;
}
mapping query_action(object me, object weapon)
{
	return ([
		"action":msg[random(sizeof(msg))]+NOR,
		"damage":240+random(100),
		"damage_type":random(2)?"刺傷":"割傷",
		"dodge":-25+random(20),
		"parry":-55+random(20),
		"force":150+random(80)
	]);
}
int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 5; }
int power_point(object me)
{
	object weapon;
  if (!objectp(weapon = me->query_temp("weapon")) ||
                (string)weapon->query("id") != "iron sword")  
		return 0.8;
  else return 1.2;
}

string perform_action_file(string action)
{
	return __DIR__"iron-sword/" + action;
}
int help(object me)
{
	write(HIC"\n玄鐵劍法："NOR"\n");
	write(@HELP

    楊過自和小龍女在絕情谷斷腸崖前分手，不久便由神鵰帶着在
海潮之中練功，數年之後，藉助海潮之力，練成此劍法。

	學習要求：
		玉女心法150級
		內力1500
		必須手執玄鐵劍
HELP
	);
	return 1;
}

