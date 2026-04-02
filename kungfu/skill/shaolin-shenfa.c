// shaolin-shenfa.c 少林身法
// Last Modified by sir on 10.18.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "dodge"; }

string *dodge_msg = ({
"$n一式"HIW"「一葦渡江」"NOR"，前後腳腳尖腳跟相靠，身體如行雲流水般滑出丈餘。\n",
"$n一式"BLU"「雨燕掠波」"NOR"，雙臂前伸，全身貼地平飛，頓時閃過了$N的凌厲攻勢。\n",
"$n一式"HIC"「移步換形」"NOR"，足不動，手不抬，一轉眼間便繞到了$N的身後。\n",
"$n一式"HIG"「分身化影」"NOR"，一轉身間，四面八方飄動着無數個$n的身影，令$N手無足措。\n",
"$n一式"HIY"「孤騖落日」"NOR"，全身筆直，拔地而起，在半空中一轉，已落到幾丈遠的地方。\n",
"$n一式"HIB"「鴻雁雙飛」"NOR"，兩臂鵬舉如翼，在剌剌風聲中，從$N頭頂橫躍而過。\n",
"$n一式"HIY"「蒼龍出水」"NOR"，雙腳點地，全身化為一道白影，急速繞着$N打了幾轉。\n",
"$n一式"GRN"「稚鳳歸巢」"NOR"，身體如陀螺般急轉，氣流形成一個個漩渦，令$N陷身其間，動彈不得。\n",
});

int valid_enable(string usage) { return (usage=="dodge") || (usage=="move"); }
int valid_learn(object me)
{      	
	if( (int)me->query_skill("hunyuan-yiqi", 1) < 10 )
	return notify_fail("你的混元一氣功不夠精熟，無法領會少林身法。\n");
	return 1;
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 30 || (int)me->query("neili") < 6 )
		return notify_fail("你的體力太差了，無法能練習少林身法。\n");
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
int river_point() {return 2;} // 過河比普通容易 越高越好
string river_go_msg() {	return HIW"$N撿起一段蘆葦拋入水中，緊跟着飛身躍上蘆葦，長袖飄飄，渡過了水面。\n"NOR;}
string river_come_msg() {	return HIW"只見$N踩着一段蘆葦從對岸過來，姿態瀟灑地落在岸邊。\n"NOR;}

int help(object me)
{
	write(HIC"\n少林身法："NOR"\n");
	write(@HELP

    少林身法為少林本門輕功身法。少林輕功名冠天下。

	學習要求：
		混元一氣功10級
HELP
	);
	return 1;
}


