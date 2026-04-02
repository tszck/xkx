// xiaowuxiang.c 小無相功
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
	int i = (int)me->query_skill("xiaowuxiang", 1);

	if (((string)me->query("class") != "lama") && i > 29)
		return notify_fail("你不是僧人，學不了高深的小無相功。\n");

	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("你的基本內功火候不足，不能學小無相功。\n");

	if ( me->query("gender") == "無性" && i > 49)
		return notify_fail("你無根無性，陰陽不調，難以領會高深的小無相功。\n");

//       if (i > 10 && (int)me->query("shen") < t * 100)
  //      	return notify_fail("要學小無相功，你的表現還不夠吧！ \n");


	return valid_public(me,"longxiang");
}

int practice_skill(object me)
{
	return notify_fail("小無相功只能用學(learn)的來增加熟練度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"xiaowuxiang/" + func;
}
int help(object me)
{
	write(HIC"\n小無相功："NOR"\n");
	write(@HELP

    小無相功乃北宋年間逍遙派的內功之一，逍遙內功分為北冥神
功，八荒六合唯我獨尊功及小無相功三種，逍遙派掌門逍遙子精通
北冥神功，天山童姥專擅八荒六合唯我獨尊功，其師妹西夏太后李
秋水則得授小無相功作為防身絕技，後為吐蕃國師鳩摩智所得，成
為雪山派內功。小無相功精微奧妙，以之催動雪山絕技之火焰刀，
威力不在少林絕藝之下。

	學習要求：
		非出家為喇嘛學不到30級以上的小無相功
		太監學不到50級以上的小無相功
		基本內功10
		相應的正氣
HELP
	);
	return 1;
}

