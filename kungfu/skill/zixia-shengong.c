// zixia-shengong.c 紫霞神功
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit FORCE;
#include "force.h"
string type() { return "martial"; }
string martialtype() { return "force"; }

int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 10; }
int power_point() { return 1; }

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
	int i = (int)me->query_skill("zixia-shengong", 1);
	int t = 1, j;

	if(i <= 100) for (j = 1; j < i / 10; j++) t *= 2;

	if ( me->query("gender") == "無性" && i > 49)
		return notify_fail("你無根無性，陰陽不調，難以領會高深的紫霞神功。\n");

	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("你的基本內功火候還不夠，還不能學習紫霞神功。\n");

	if(i<=100)
	{
		if (i > 10 && (int)me->query("shen") < t * 100) 
			return notify_fail("你的俠義正氣太低了，無法領會更高深的紫霞神功。\n");
	}
	else
	{
		if ((int)me->query("shen") < (51200 + (i - 100) * 1000)) 
			return notify_fail("你的俠義正氣太低了，無法領會更高深的紫霞神功。\n");
	}


	return valid_public(me,"huashan-neigong");
}

int practice_skill(object me)
{
	return notify_fail("紫霞神功只能用學(learn)的來增加熟練度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"zixia-shengong/" + func;
}
int help(object me)
{
	write(HIM"\n紫霞神功："NOR"\n");
	write(@HELP

    華山氣宗內功，具自療及運功之用，並能增加精氣。精的增加
視乎於自身紫氤吟的修爲，氣的增加則決定於自身正氣訣的修爲。

	學習要求：
		基本內功10級
		相應的正氣
		太監無法學到50級以上的紫霞神功
HELP
	);
	return 1;
}

