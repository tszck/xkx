// count.c 陰陽八卦
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit SKILL;

string type() { return "knowledge"; }
int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 10; }
int power_point(object me) { return 1; }

void skill_improved(object me) {}

int valid_learn(object me)
{
	object ob;

	mapping myfam;
	myfam = (mapping)me->query("family");
	if(!myfam || myfam["family_name"] != "桃花島"|| myfam["master_id"] != "huang yaoshi")
		return notify_fail("只有黃藥師的弟子才能學陰陽八卦。\n");
	if( (int)me->query_skill("literate",1) < 50 )
		return notify_fail("你的讀書寫字太低，沒有辦法學陰陽八卦。\n");

	return 1;
}

int practice_skill(object me)
{
	return notify_fail("陰陽八卦只能用學(learn)的來增加熟練度。\n");
}
int help(object me)
{
	write(HIC"\n陰陽八卦："NOR"\n");
	write(@HELP

    桃花島弟子可以憑此技能查知玩家目前所在的位置。可以通過
閲讀《河圖》、《洛書》提高。
    請help location。

	學習要求：
		讀書寫字50級
		身為黃藥師嫡傳弟子
HELP
	);
	return 1;
}

