// taiji-shengong.c 太極神功
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
	int lvl = (int)me->query_skill("taiji-shengong", 1);
	int t = 1, j;
	if (lvl<=100)
		for (j = 1; j < lvl / 10; j++)
			t*=2;

	if ( me->query("gender") == "無性" && lvl > 49)
		return notify_fail("你無根無性，陰陽不調，難以領會高深的太極神功。\n");

	if ( me->query("class") == "bonze" )
		return notify_fail("太極神功講究陰陽調合，有違佛家六根清淨之意，"+RANK_D->query_respect(me)+"欲修此功，已是罪過。\n");

	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("你的基本內功火候還不夠。\n");

	if(lvl<=100)
	{
		if (lvl > 10 && (int)me->query("shen") < t * 100) 
			return notify_fail("你的俠義正氣太低了。\n");
	}
	else
	{
		if ((int)me->query("shen") < (51200 + (lvl - 100) * 1000)) 
			return notify_fail("你的俠義正氣太低了。\n");
	}

	return valid_public(me);
}

int practice_skill(object me)
{
	return notify_fail("太極神功只能用學(learn)的來增加熟練度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"taiji-shengong/" + func;
}

int help(object me)
{
	write(HIC"\n太極神功："NOR"\n");
	write(@HELP

    太極神功乃武當不傳之祕，講究「衝」、「虛」、「圓」、「
通」，是修習武當派各種高深武功的根基。武當弟子配合太極神功
和道學心法可以養精練氣，有延年益壽之功效。

	學習要求：
		和尚不能學
		太監無法領悟50級以上的太極神功
		基本內功10級
		相應的正氣
HELP
	);
	return 1;
}

