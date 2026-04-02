// taxue-wuhen.c 踏雪無痕 

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "dodge"; }

string *dodge_msg = ({
"$n一式"YEL"「雁落平沙」"NOR"，變招奇速，右足向前踢出，身子已然騰起，輕輕巧巧地落在一旁。\n",
"$n一式"HIW"「玉龍飛起」"NOR"，縱身高躍，半空中一折一轉，已飄身在數丈之外。\n",
"$n一式"HIY"「夏日消融」"NOR"，兩足足跟不動，足尖左磨，身子隨之右轉，卸開了$N這一招。\n",
"$n一式"HIB"「枯松倒掛」"NOR"，只見$n身子後仰，雙掌往地下一撐，身子借勢倒射而出，$N便已打$n不着。\n",
"$n一式"HIW"「晴雪飛灘」"NOR"，縱高伏低，東奔西閃，身形飄忽不定，$N手無足措，只得回招自守。\n",
"$n一式"HIW"「冰絲帶雨」"NOR"，突然反手一招，竟然是兩敗俱傷的打法，趁$N手忙腳亂安全脫身。\n",
"$n一式"HIM"「寒江釣雪」"NOR"，不招不架，只微微一側身，$N猶如暴風驟雨般的進攻便即落空。\n",
"$n一式"HIY"「魚龍潛躍」"NOR"，陡然間身形拔起，直衝雲霄，直如鷹隼，幾個盤旋，飄飄蕩蕩落在數丈之外。\n",
"$n一式"HIW"「踏雪無痕」"NOR"，身形急速旋轉，幾下就劃到數丈之外。\n",
});

int valid_enable(string usage) { return (usage=="dodge") || (usage=="move"); }
int valid_learn(object me) 
{      	
	if( (int)me->query_skill("xuantian-wuji", 1) < 10 )
	return notify_fail("你的玄天無極功不夠精熟，無法領會踏雪無痕。\n");
	return 1;
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 20|| (int)me->query("neili") < 4 )
		return notify_fail("你的體力太差了，不能練踏雪無痕。\n");
	me->receive_damage("qi", 20);
	me->add("neili", -4);	
	return 1;
}
string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int learn_bonus() { return 20; }
int practice_bonus() { return 20; }
int success() { return 20; }
int power_point(object me) { return 1.2; }

int help(object me)
{
	write(HIC"\n踏雪無痕："NOR"\n");
	write(@HELP

    踏雪無痕為崑崙派本門輕功。

	學習要求：
	  玄天無極功10級
HELP
	);
	return 1;
}

