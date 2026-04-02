// qingfu-shenfa.c 青蝠身法
// Last Modified by sir on 10.18.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "dodge"; }

string *dodge_msg = ({
	"只見$n一招"HIC"「福滿乾坤」"NOR"，身形陡然縱起，躲過了$N這一招。\n",
	"$n一式"HIC"「五蝠獻壽」"NOR"，身形晃動，向一旁飄出，避開了$N這一招。。\n",
	"$n使出"HIC"「洞天福地」"NOR"，一個空心筋斗向後翻出，避開了$N的凌厲攻勢。\n",
	"$n一招"HIC"「雲龍百蝠」"NOR"，身隨意轉，$N只覺眼前一花，$n已繞至$N的身後。\n",
});

int valid_enable(string usage) { return usage == "dodge" || usage == "move"; }
int valid_learn(object me)
{      	
	if( (int)me->query_skill("jiuyang-shengong", 1) < 10 )
	return notify_fail("你的九陽神功不夠精熟，無法領會青蝠身法。\n");
	return 1;
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 40|| (int)me->query("neili") < 8 )
		return notify_fail("你的體力太差了，不能練青蝠身法。\n");
	me->receive_damage("qi", 40);
	me->add("neili", -8);	
	return 1;
}
string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int learn_bonus() { return 10; }
int practice_bonus() { return 10; }
int success() { return 10; }
int power_point(object me) { return 1.4; }

int help(object me)
{
	write(HIC"\n青蝠身法："NOR"\n");
	write(@HELP

    明教的本門輕功身法。主要是從韋一笑的輕功身法而來。

	學習要求：
		無
HELP
	);
	return 1;
}

