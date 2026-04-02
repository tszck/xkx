// bibo-shengong.c 碧波神功
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

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me)
{
	int lvl = (int)me->query_skill("bibo-shengong", 1);

	if ( me->query_skill("force", 1) < 10)
		return notify_fail("你的基本內功還不到火候。\n");
	if ( me->query("gender") == "無性" && lvl > 49)
		return notify_fail("你無根無性，陰陽不調，難以領會高深的碧波神功。\n");

	return valid_public(me);
}

int practice_skill(object me)
{
	return notify_fail("碧波神功只能用學的，或是從運用(exert)中增加熟練度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"bibo-shengong/" + func;
}
int help(object me)
{
	write(HIC"\n碧波神功："NOR"\n");
	write(@HELP

    這是東海桃花島黃藥師所創的一門內功心法。傳説當初黃藥師行
船海上，忽見碧海潮生，碧波洶湧，聲勢驚人，在與風浪搏鬥之餘，
豁然頓悟，創出一門陽剛陰柔相結合的內功，此謂碧波神功。

	學習要求：
		基本內功10級
		太監無法領悟50級以上的碧波神功
HELP
	);
	return 1;
}

