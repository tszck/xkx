// qiankun-danuoyi.c 乾坤大挪移
// Last Modified by sir on 10.18.2001

#include <ansi.h>
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "dodge"; }

string *parry_msg = ({
	HIY"$N一招擊在$n身上，卻被$n暗運乾坤大挪移，將內力盡數移入地下。\n"NOR,
	HIW"$n輕輕一帶，$N發現自己招數回擊過來，嚇得往後倒退幾步。\n"NOR,
	HIC"$n手臂迴轉，在$N手肘下輕輕一推，$N招數落空。\n"NOR,
	HIG"$n右手伸出，在$N手腕上輕輕一拉，$N收勢不住，直往前撲去。\n"NOR,
	MAG"$n身形不動，$N一招擊下，有如石沉大海，不覺呆住了。\n"NOR,
	HIM"$n左牽右引，$N如身處漩流，連續轉了好幾個圈。\n"NOR,
	GRN"$n雙手迴圈，$N只覺得前面好象有一堵牆，再也攻不進去。\n"NOR,
	HIY"$n輕輕一轉，$N一招擊在地上，只打得塵土飛揚。\n"NOR,
});

string *dodge_msg = ({
	"$N一招擊在$n身上，卻被$n暗運乾坤大挪移，將內力盡數移入地下。\n",
	"$n輕輕一帶，$N發現自己招數回擊過來，嚇得往後倒退幾步。\n",
	"$n手臂迴轉，在$N手肘下輕輕一推，$N招數落空。\n",
	"$n右手伸出，在$N手腕上輕輕一拉，$N收勢不住，直往前撲去。\n",
	"$n身形不動，$N一招擊下，有如石沉大海，不覺呆住了。\n",
	"$n左牽右引，$N如身處漩流，連續轉了好幾個圈。\n",
	"$n雙手迴圈，$N只覺得前面好象有一堵牆，再也攻不進去。\n",
	"$n輕輕一轉，$N一招擊在地上，只打得塵土飛揚。\n",
});

int valid_enable(string usage) 
{ 
	return (usage == "parry") || (usage == "dodge") || (usage=="move"); }

string query_parry_msg(string limb)
{
	return parry_msg[random(sizeof(parry_msg))];
}
string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}
int valid_learn(object me)
{
	int lvl = (int)me->query_skill("qiankun-danuoyi", 1);

	if ( me->query("gender") == "無性" && lvl > 99)
		return notify_fail("你先天不足，再學下去難免走火入魔。\n");
	if ((int)me->query_skill("force", 1) < 100)
		return notify_fail("就這麼點基本內功還想學乾坤大挪移？\n");
	if (lvl > 50)
		return notify_fail("乾坤大挪移只能通過讀<<乾坤大挪移心法>>提高。\n");
	if ((int)me->query("max_neili", 1) < 1500)
		return notify_fail("就這麼點內力還想學乾坤大挪移？\n");
	if ((int)me->query_skill("force", 1) < lvl)
		return notify_fail("你的基本內功火候還不夠，小心走火入魔！\n");
	if ((int)me->query_skill("jiuyang-shengong", 1) < lvl)
		return notify_fail("你的九陽神功火候還不夠，小心走火入魔！\n");
	if ((int)(me->query("max_neili")/15) < lvl)
		return notify_fail("你的內力火候還不夠，小心走火入魔！\n");
	return 1;
}
int practice_skill(object me)
{
	return notify_fail("乾坤大挪移只能通過讀<<乾坤大挪移心法>>提高。\n");
}
string perform_action_file(string action)
{
	return __DIR__"qiankun-danuoyi/" + action;
}

int learn_bonus() { return 0; }
int practice_bonus() { return 0; } 
int success() { return 5; }
int power_point(object me) { return 1.5; }

int help(object me)
{
	write(HIC"\n乾坤大挪移："NOR"\n");
	write(@HELP

    “乾坤大挪移”是明教歷代相傳一門最厲害的武功，是明教的
護教神功。為波斯大盜山中老人所創，專門講述運氣使力的法門。
中原會用的人甚少，自明教三十三代教主陽頂天死後，幾乎失傳，
但後來張無忌一番奇遇，以其深厚的內功一朝而成。乾坤大挪移只
作招架和輕功用，不具攻擊。其威力之所在是可以把別人的招數盡
數還於對方。
    乾坤大挪移神功的主旨，乃在顛倒一剛一柔、一陰一陽的乾坤
二氣，臉上現出青紅之色，便是體內血液沉降、真氣變換之象。練
至第六層時，全身都能忽紅忽青，但到第七層時，陰陽二氣轉換於
不知不覺之間，外形上便半點也瞧不出表徵了。其根本道理也並不
如何奧妙，只不過先求激發自身潛力，然後牽引挪移敵勁，但其中
變化神奇，卻是匪夷所思。

	學習要求：
		基本內功100級並不得低於乾坤大挪移的級別
		九陽神功不得低於乾坤大挪移的級別
		內力1500並不得低於乾坤大挪移的級別的15倍
		太監無法領悟100級以上的乾坤大挪移
HELP
	);
	return 1;
}

