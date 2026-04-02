// chanchu_bufa.c 蟾蜍步法
// Last Modified by sir on 10.18.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "dodge"; }

string *dodge_msg = ({
	"只見$n一招"HIY"「蟾飛九天」"NOR"，身體向上筆直地縱起丈餘，躲過了$N這一招。\n",
	"但是$n一個使出"HIY"「蛙鳴震天」"NOR"，身形飄忽，輕輕一縱，早已避開。\n",
	 "$n一招"HIY"「蛙入稻田」"NOR"，身行隨意轉，倏地往一旁挪開了三尺，避過了這一招。\n",
	"可是$n一個"HIY"「蟾蜍撲蟲」"NOR"，側身一讓，$N這一招撲了個空。\n",
	"卻見$n"HIY"「蟾翻白肚」"NOR"，足不點地，往旁竄開數尺，躲了開去。\n",
	"$n身形一招"HIY"「金蟾歸月」"NOR"，身形微晃，有驚無險地避開了$N這一招。\n"
});

int valid_enable(string usage) { return (usage=="dodge") || (usage=="move"); }
int valid_learn(object me) 
{      	
	if( (int)me->query_skill("hamagong", 1) < 10 )
		return notify_fail("你的蛤蟆功不夠精熟，無法領會蟾蜍步法。\n");
	return 1;
}

int practice_skill(object me)
{
	if( (int)me->query("qi") < 10 || (int)me->query("neili") < 2 )
		return notify_fail("你的體力太差了，不能練蟾蜍步法。\n");
	me->receive_damage("qi", 10);
	me->add("neili", -2);
	return 1;
}
string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}
int learn_bonus() { return 25; }
int practice_bonus() { return 25; }
int success() { return 20; }
int power_point() { return 1.1; }

int help(object me)
{
	write(HIC"\n蟾蜍步法："NOR"\n");
	write(@HELP

    白駝山本門輕功。

	學習要求：
	   蛤蟆功10級
HELP
	);
	return 1;
}

