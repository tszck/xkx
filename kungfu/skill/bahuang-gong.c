// bahuang-gong.c 八荒六合唯我獨尊功
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#include "force.h";
inherit FORCE;

string type() { return "martial"; }
string martialtype() { return "force"; }
int valid_enable(string usage) { return usage == "force"; }
int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 10; }
int power_point(object me) { return 1; }

int valid_learn(object me)
{
	if ((string)me->query("family/master_id")!="ju jian"
	&& (string)me->query("family/master_id")!="mei jian"
	&& (string)me->query("family/master_id")!="tong lao"
	&& (string)me->query("family/master_id")!="xu zhu")
	return notify_fail("只有靈鷲宮門下弟子才能學習八荒六合唯我獨尊功。\n");
	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("你的基本內功火候還不夠。\n");
	return valid_public(me,"beiming-shengong");
}
int practice_skill(object me)
{
	return notify_fail("八荒六合唯我獨尊功只能用學(learn)的來提高。\n");
}
string exert_function_file(string func)
{
	return __DIR__"bahuang-gong/" + func;
}
int help(object me)
{
	write(HIC"\n八荒六合唯我獨尊功："NOR"\n");
	write(@HELP

    八荒六合唯我獨尊功是靈鷲宮至高無上的內功，須以最上乘內
功爲根基。這功夫威力奇大，卻有一個大大的不利之處，每三十年，
便要返老還童一次。

	學習要求：
		靈鷲宮弟子
		基本內功10級
HELP
	);
	return 1;
}

