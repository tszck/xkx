// xiaoyaoyou.c 逍遙遊
// Last Modified by sir on 18.10.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "dodge"; }

string *dodge_msg = ({
	"$n一個"RED"「蜻蜓點水」"NOR"，躲過了$N這一招。\n",
	"$n身形向後一縱，使出一招"HIW"「細胸巧翻雲」"NOR"，避過了$N的攻擊。\n",
	"$n使出"BLU"「虛懷若谷」"NOR"，恰好躲過了$N的攻勢。\n"
	"但是$n一招"HIY"「蜻蜓點水」"NOR"身形飄忽，輕輕一縱，早已避開。\n",
	"$n身隨意轉，一招"MAG"「細胸巧翻雲」"NOR"倏地往一旁挪開了三尺，避過了這一招。\n",
	"可是$n側身一讓，一招"HIY"「虛懷若谷」"NOR"$N這一招撲了個空。\n",
	"卻見$n足不點地，一招"GRN"「蜻蜓點水」"NOR"往旁竄開數尺，躲了開去。\n",
	"$n身形微晃，一招"HIB"「虛懷若谷」"NOR"有驚無險地避開了$N這一招。\n"
});

int valid_enable(string usage) { return (usage=="dodge") || (usage=="move"); }
int valid_learn(object me) 
{      	
	if ((int)me->query("can_learn/hong/xiaoyaoyou"))
 	return 1;
	if( (int)me->query_skill("huntian-qigong", 1) < 10 )
	return notify_fail("你的混天氣功不夠精熟，無法領會逍遙遊。\n");
	return 1;
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 30 || (int)me->query("neili") < 6 )
		return notify_fail("你的體力太差了，無法練習逍遙遊。\n");
	me->receive_damage("qi", 30);
	me->add("neili", -6);
	return 1;
}
string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int learn_bonus() { return 15; }
int practice_bonus() { return 15; }
int success() { return 15; }
int power_point(object me) { return 1.3; }

int help(object me)
{
	write(HIC"\n逍遙遊："NOR"\n");
	write(@HELP

    逍遙遊是丐幫本門輕功身法。

	學習要求：

	   混天氣功10級或有洪七公指點
HELP
	);
	return 1;
}

