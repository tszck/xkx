// lamaism.c 密宗心法
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
	if ((me->query_skill("buddhism",1) > 1) ||
		(me->query_skill("mahayana",1) > 1))
		return notify_fail("哈哈！"+RANK_D->query_respect(me)+ "既入禪門，怎麼卻來學密宗心法？\n");
	if( (int)me->query_skill("taoism",1) > 1 )
		return notify_fail("你學了牛鼻子的心法，無法修煉密宗心法。\n");
	if ((me->query_skill("ziyunyin",1) > 1) ||
		(me->query_skill("zhengqijue",1) > 1))
		return notify_fail("哈哈！"+RANK_D->query_respect(me)+ "已經學了僞君子的心法，怎麼卻來學密宗心法？\n");
	if ((me->query_skill("poison",1) > 1))
		return notify_fail("哈哈！"+RANK_D->query_respect(me)+ "已經學了邪魔外道的毒技，怎麼卻來學密宗心法？\n");
	if (me->query_skill("lamaism", 1) >= 150)
		return notify_fail("限於資質，你對密宗心法的理解也就到此爲止了。\n");
	return 1;
}

int practice_skill(object me)
{
	return notify_fail("密宗心法只能靠學(learn)來提高。\n");
}

int help(object me)
{
	write(HIC"\n密宗心法："NOR"\n");
	write(@HELP

    密宗心法是雪域密宗心法，用以超渡生靈。

	學習要求：
		不可學禪宗、道家和華山的心法以及星宿毒技
HELP
	);
	return 1;
}

