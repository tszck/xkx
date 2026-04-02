// huashan-neigong.c 華山內功
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit FORCE;
#include "force.h"

string type() { return "martial"; }
string martialtype() { return "force"; }
int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 10; }
int power_point(object me) { return 1; }

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
// need more limit here
{
	if ((int)me->query_skill("zixia-shengong", 1) < 10)
		return notify_fail("你的紫霞神功火候還不夠。\n");
	return valid_public(me,"zixia-shengong");
}

int practice_skill(object me)
{
	return notify_fail("華山氣功只能用學(learn)的來增加熟練度。\n");
}

string exert_function_file(string func)
{
	return SKILL_D(__DIR__"huashan-neigong/") + func;
}

int help(object me)
{
	write(HIC"\n華山內功："NOR"\n");
	write(@HELP

    華山內功為華山劍宗本門內功心法。

	學習要求：
		紫霞神功10級
HELP
	);
	return 1;
}

