// poison.c 基本毒技
// Last Modified by winder on Mar. 10 2000
// Modified by Java Mar.1998

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
	mapping myfam;
	myfam = (mapping)me->query("family");	
	if (!myfam || (myfam["family_name"] != "星宿派"))
		return notify_fail("你不是星宿弟子，不能修煉毒技。\n");
	if((myfam["master_id"]!="ding chunqiu")&&
		(me->query_skill("poison",1) > 120))
		return notify_fail("你只能向丁春秋學習更高深的毒技。\n");	
	if((me->query_skill("taoism",1) > 1 ) ||
		(me->query_skill("buddhism",1) > 1) ||
		(me->query_skill("ziyunyin",1) > 1) ||
		(me->query_skill("zhengqijue",1) > 1))
		return notify_fail("哈哈！"+ RANK_D->query_respect(me)+"已經學了名門正派的心法，怎麼卻來學你們不恥的毒技？\n");
	if (me->query_skill("poison", 1) >= 150)
		return notify_fail("限於資質，你對基本毒技的理解也就到此為止了。\n");
	return 1;
}

void skill_improved(object me)
{
	if ((me->query_skill("poison",1) == 50) ||
		(me->query_skill("poison",1) == 60) ||
		(me->query_skill("poison",1) == 70) ||
		(me->query_skill("poison",1) == 80) ||
		(me->query_skill("poison",1) == 90) ||
		(me->query_skill("poison",1) >= 100))
	{
		tell_object(me, "你體內的毒質開始反噬自身了，得找人散毒了。\n");
		me->apply_condition("poison_sandu",1000);
	}
}

int practice_skill(object me)
{
	return notify_fail("基本毒技只能靠學習來提高。\n");
}
int help(object me)
{
	write(HIC"\n基本毒技："NOR"\n");
	write(@HELP

    星宿弟子下毒必具武功，下毒的效果和基本毒技的高低有很大
的關係。當體內毒素反噬自身時，得找人散毒。

	學習要求：
		名門正派的心法不能學
		非星宿派弟子不能學
HELP
	);
	return 1;
}

