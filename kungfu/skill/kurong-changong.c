// kurong-changong.c 枯榮禪功
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#include "force.h";
inherit FORCE;
string type() { return "martial"; }
string martialtype() { return "force"; }

int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 10; }
int power_point(object me) { return 1; }

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
	if ( me->query_skill("force", 1) < 10)
		return notify_fail("你的基本內功不到火候，難以領會枯榮禪功。\n");
	if ( me->query("gender") == "無性")
		return notify_fail("你無根無性，陰陽不調，難以領會高深的枯榮禪功。\n");

	return valid_public(me);
}

int practice_skill(object me)
{
	return notify_fail("枯榮禪功只能用學(learn)的來增加熟練度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"kurong-changong/" + func;
}


int help(object me)
{
	write(HIC"\n枯榮禪功："NOR"\n");
	write(@HELP

    有常無常，雙樹枯榮，南北西東，非假非空！
    佛門奇功，天龍寺枯榮長老精擅此技。相傳釋迦牟尼在桫欏雙
樹之間入滅，代表了非枯非榮、非假非空的最高境界，後世弟子便
以此為修行之法，靜參枯禪。是為枯榮禪功之來由。
    為天南大理段家的本門內功。

	學習要求：
		基本內功10級
		不能是太監
HELP
	);
	return 1;
}

