// taoism.c 道學心法
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
	int lvl;

	lvl = (int)me->query_skill("taoism", 1);

	if( (int)me->query("shen") < 0 )
		return notify_fail("你的戾氣太重，無法修煉道學心法。\n");
	if(me->query("gender") == "無性" && lvl > 39)
		return notify_fail("你剛聽一會兒，便覺心智迷糊，原來你沒有陽剛之
氣，無法領會裏面的陰陽變化之道。\n");
	if ((me->query_skill("buddhism",1) > 1) ||
		(me->query_skill("mahayana",1) > 1))
		return notify_fail( "哈哈！"+RANK_D->query_respect(me)+"既入佛門，怎麼卻來學道學心法？\n");
	if ((int)(me->query_skill("lamaism",1) > 1))
		return notify_fail( "哈哈！"+RANK_D->query_respect(me)+"已經學了密宗心法，怎麼卻來學道學心法？\n");
	if ((me->query_skill("ziyunyin",1) > 1) ||
		(me->query_skill("zhengqijue",1) > 1))
		return notify_fail( "哈哈！"+RANK_D->query_respect(me)+"已經學了華山派的心法，怎麼卻來學道學心法？\n");
	if ((int)(me->query_skill("poison",1) > 1))
		return notify_fail( "哈哈！"+RANK_D->query_respect(me)+"已經學了邪魔外道的毒技，怎麼卻來學道學心法？\n");
	if (me->query_skill("taoism", 1) >= 150)
		return notify_fail("限於資質，你對道學心法的理解也就到此爲止了。\n");

	return 1;
}

int practice_skill(object me)
{
	return notify_fail("道學心法只能靠學習來提高。\n");
}

int help(object me)
{
        write(HIC"\n道學心法："NOR"\n");
        write(@HELP

    太上道祖傳下的道德真言五千字中蘊涵的博大精深的心法。
    可尋找道德經閱讀。

        學習要求：
                與禪宗心法、密宗心法、紫氳吟、正氣訣和基本毒技不能兼學
HELP
        );
        return 1;
}

