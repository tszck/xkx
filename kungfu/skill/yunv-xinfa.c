// yunv-xinfa.c 玉女心法
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#include "force.h";
inherit FORCE;
string type() { return "martial"; }
string martialtype() { return "force"; }

int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 10; }
int power_point() { return 1; }

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{

	if ( me->query("gender") == "無性")
		return notify_fail("你無根無性，陰陽難調，不能修習玉女心法。\n");

	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("你的基本內功火候還不夠。\n");

	return valid_public(me);
}

int practice_skill(object me)
{
	return notify_fail("玉女心法只能用學(learn)來增加熟練度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"yunv-xinfa/" + func;
}

int help(object me)
{
	write(HIC"\n玉女心法："NOR"\n");
	write(@HELP

    古墓內功講究一個“靜”字，唯有平心靜氣、擺脫世俗之擾才
能修習上乘武功。玉女心經修煉難度很大，學習者要不急不躁，循
序漸進方有成功之望。可以尋覓本門祕籍《玉女心經》上下冊研讀。

	學習要求：
		基本內功10級
		不能做太監
HELP
	);
	return 1;
}

