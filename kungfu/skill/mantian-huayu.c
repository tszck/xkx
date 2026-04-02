// mantian-huayu.c 漫天花雨

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

string	*msg = ({
"$N身子左側，一式「月下踏徑」，右手$w從身體下方突然甩出，直射向$n的$l",
"$w破空飛出，一式「長虹經天」，緩緩一個弧線，由左自右，繞向$n的$l，",
"$N雙手連揚，一式「破雲見日」，兩把$w向$n撒出，籠罩$n的全身上下",
"$N向空中一撒，卻是$n一招「秋日落葉」，十多枚$w由空中緩緩落下",
"$N身形急速向前滑動，一式「雪地追蹤」，三枚$w向$n的脅下射去",
"$N一式「回首滄桑」，身體一轉，反手擲出數枚$w，飛向$n的背部",
"$N凌空一縱，一招「雨打浮萍」，居高臨下，手中$w疾射，直向$n的$l",
"$N一招「流星電閃」，手指彈出五枚$w，一點黑光射向$n的頭部",
});

int valid_enable(string usage) { return usage=="throwing" || usage=="parry"; }
mapping query_action(object me, object weapon)
{
	return ([
		"action":msg[random(sizeof(msg))],
		"damage":(random(2)+2)*(me->query_skill("mantian-huayu",1))/4,
		"damage_type":"刺傷",
		"dodge":random(20)+20,
		"force":random(50)+me->query_skill("mantian-huayu",1),
		"post_action": (: call_other, WEAPON_D, "throw_weapon" :)
	]);
}
int practice_skill(object me)
{
	object weapon;
	if (!objectp(weapon = me->query_temp("weapon")) ||
		(string)weapon->query("skill_type") != "throwing")
		return notify_fail("你使用的武器不對。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的體力不夠練漫天花雨。\n");
	me->receive_damage("qi", 30);
	return 1;
}
int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的內力不夠。\n");
	if ((int)me->query_skill("xuantian-wuji", 1) < 30)
		return notify_fail("你的玄天無極功火候太淺。\n");
	return 1;
}
int learn_bonus() { return 15; }
int practice_bonus() { return 10; }
int success() { return 10; }
int power_point(object me) { return 1; }

string perform_action_file(string action)
{
	return __DIR__"mantian-huayu/" + action;
}

int help(object me)
{
	write(HIC"\n漫天花雨："NOR"\n");
	write(@HELP

    漫天花雨是崑崙派的暗器絕技。

	學習要求：
		玄天無極功30級
		內力100
HELP
	);
	return 1;
}

