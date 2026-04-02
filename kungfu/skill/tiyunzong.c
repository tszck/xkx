// tiyunzong.c 梯雲縱
// Last Modified by sir on 10.18.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "dodge"; }

string *dodge_msg = ({
	"只見$n一招"HIW"「白鶴沖天」"NOR"，身體向上筆直地縱起丈餘，躲過了$N這一招。\n",
	"$n一個"BLU"「鷂子翻身」"NOR"，向後縱出數丈之遠，避開了$N的凌厲攻勢。\n",
	"$n使出"HIY"「大鵬展翅」"NOR"，向一旁飄然縱出，輕輕着地。\n",
	"但是$n一招"HIC"「白鶴沖天」"NOR"身形飄忽，輕輕一縱，早已避開。\n",
	"$n身隨意轉，一招"HIB"「鷂子翻身」"NOR"倏地往一旁挪開了三尺，避過了這一招。\n",
	"可是$n一招"YEL"「大鵬展翅」"NOR"側身一讓，$N這一招撲了個空。\n",
	"卻見$n足不點地一招"HIC"「白鶴沖天」"NOR"，往旁竄開數尺，躲了開去。\n",
	"$n身形微晃，一招"MAG"「鷂子翻身」"NOR"有驚無險地避開了$N這一招。\n",
});

int valid_enable(string usage) { return (usage=="dodge") || (usage=="move"); }
int valid_learn(object me) 
{      	
	if( (int)me->query_skill("taiji-shengong", 1) < 10 )
	return notify_fail("你的太極神功不夠精熟，無法領會梯雲縱。\n");
	return 1;
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 50 || (int)me->query("neili") < 10 )
		return notify_fail("你的體力太差了，無法練習梯雲縱。\n");
	me->receive_damage("qi", 50);
	me->add("neili", -10);
	return 1;
}
string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int learn_bonus() { return 25; }
int practice_bonus() { return 25; }
int success() { return 20; }
int power_point(object me) { return 1.1; }

int help(object me)
{
	write(HIC"\n梯雲縱："NOR"\n");
	write(@HELP

    梯雲縱爲武當最高輕功心法。

	學習要求：
	  太極神功10級
HELP
	);
	return 1;
}

