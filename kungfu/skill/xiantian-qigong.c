// xiantian-qigong.c 先天氣功
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#include "force.h";
inherit FORCE;
string type() { return "martial"; }
string martialtype() { return "force"; }

int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 10; }
int power_point() { return 1; }

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
	int lvl = (int)me->query_skill("xiantian-qigong", 1);
	int t = 1, j;
	if (lvl<=100) for (j = 1; j < lvl / 10; j++) t*=2;

	if ( me->query("gender") == "無性")
		return notify_fail("你無根無性，陰陽不調，難以修行玄門正宗的先天氣功。\n");

	if ( me->query("class") == "bonze" )
		return notify_fail(RANK_D->query_respect(me)+"欲修我道家玄門氣功，怎又去入了佛門？\n");

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
	return notify_fail("先天氣功只能用學(learn)的來增加熟練度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"xiantian-qigong/" + func;
}

int help(object me)
{
	write(HIC"\n先天氣功："NOR"\n");
	write(@HELP

    先天功是天下內功正宗，是全真教其它武功的基礎。先天功講
究根基紮實，所以入門較慢，但練到後面，自然加快。先天功修行
步驟共分九節，即丹田生精，煉神入頂，金液還丹，周天火候，龍
虎交媾，太陽煉形，三田既濟，煉神合道，棄殼昇仙，超凡入聖。

	學習要求：
		基本內功10級
		不能做太監或和尚
		相應的正氣
HELP
	);
	return 1;
}

