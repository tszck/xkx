// mahayana.c 大乘涅磐功
//Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit SKILL;

string type() { return "knowledge"; }
int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 30; }
int power_point(object me) { return 1; }

int valid_learn(object me)
{
	mapping myfam;
	myfam = (mapping)me->query("family");
/*
	if (!myfam || (myfam["family_name"] != "峨嵋派"))
		return notify_fail("你不是峨嵋弟子，不能修煉大乘涅磐功。\n");
	if (me->query_skill("linji-zhuang",1) < me->query_skill("mahayana",1))
		return notify_fail("你的本門內功修爲太少，修煉大乘涅磐功也沒用。\n");
*/
	if ((int)me->query("shen") < 0 )
		return notify_fail("你的邪氣太重，無法修煉大乘涅磐功。\n");
//	if (me->query_skill("persuading",1) <= me->query_skill("mahayana",1))
//		return notify_fail("你的善行太少，修煉大乘涅磐功也沒用。\n");
	if( (int)me->query_skill("taoism",1) > 1 )
		return notify_fail("你學了牛鼻子的心法，無法修煉大乘涅磐功。\n");
	if ((me->query_skill("lamaism",1) > 1))
		return notify_fail("你心存密宗，無法修煉大乘涅磐功。\n");
	if (me->query_skill("mahayana", 1) >= 200)
		return notify_fail("限於資質，你對大乘涅磐功的理解也就到此爲止了。\n");

	return 1;
}

int practice_skill(object me)
{
	return notify_fail("大乘涅磐功只能靠學習來提高。\n");
}
int help(object me)
{
	write(HIC"\n大乘涅磐功："NOR"\n");
	write(@HELP

    峨嵋派素不喜與人爭鬥，弟子門人常常閉門修煉以增長人體潛
能，其有效程度乃取決於佛法修爲（即大乘涅磐功的等級）。打坐
靜修可在峨嵋禪房使用命令jingzuo。請help jingzuo。

	學習要求：
		相應的臨濟十二莊
		不能學禪宗心法外的其他宗教心法
HELP
	);
	return 1;
}

