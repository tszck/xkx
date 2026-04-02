// buddhism.c 禪宗心法
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }
int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 30; }
int power_point(object me) { return 1; }

int valid_learn(object me)
{
	if( (int)me->query("guilty") > 0 )
		return notify_fail("你屢犯僧家數戒，塵俗之心太重，無法修煉禪宗心法。\n");
	if ( me->query_skill("taoism",1) > 1)
		return notify_fail("你已學了道學心法，怎麼能修煉禪宗心法？\n");
	if ((me->query_skill("ziyunyin",1) > 1) ||
		(me->query_skill("zhengqijue",1) > 1))
		return notify_fail("你已學了華山心法，不能修煉禪宗心法。\n");
	if (me->query("class") != "bonze")
		return notify_fail("你凡心重，不出家，怎麼能修煉禪宗心法。\n");
	if (me->query_skill("buddhism", 1) >= 150)
		return notify_fail("限於資質，你對禪宗心法的理解也就到此爲止了。\n");
	return 1;
}
int practice_skill(object me)
{
	return notify_fail("禪宗心法只能靠學(learn)來提高。\n");
}

int help(object me)
{
	write(HIC"\n禪宗心法："NOR"\n");
	write(@HELP

    少林弟子的必修課。少林派創派祖師達摩乃是天竺禪宗大師，
又是東土禪宗第一祖，少林弟子自應以修習禪宗，精研佛法爲任。
配合混元一氣功可以長精，精增加的程度取決於混元一氣功和禪宗
心法等級的高低。

	學習要求：
		犯戒或非出家人無法領悟
                與道家心法和紫氳吟不能兼學
HELP
	);
	return 1;
}

