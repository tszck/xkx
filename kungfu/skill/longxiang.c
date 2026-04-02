// longxiang.c 龍象般若功
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
{
	int i = (int)me->query_skill("longxiang", 1);
     //   int t = 1, j;
     //	for (j = 1; j < i / 10; j++) t*= 2;

	if (((string)me->query("class") != "lama") && i > 29)
		return notify_fail("你不是僧人，學不了高深的龍象般若功。\n");

	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("你的基本內功火候不足，不能學龍象般若功。\n");

	if ( me->query("gender") == "無性" && i > 49)
		return notify_fail("你無根無性，陰陽不調，難以領會高深的龍象般若功。\n");

	if (i > 10 && (int)me->query("shen") >  - i * 1000)
		return notify_fail("要學龍象般若功，你的表現還不夠吧！ \n");
  return valid_public(me,"xiaowuxiang");
}

int practice_skill(object me)
{
	return notify_fail("龍象般若功只能用學(learn)的來增加熟練度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"longxiang/" + func;
}
int help(object me)
{
	write(HIC"\n龍象般若功："NOR"\n");
	write(@HELP

    “龍象般若功”，那是密宗中至高無上的護法神功。爲雪山派
本門內功。【龍象般若經】言道，功成十層以上，每出一招，均具
十龍十象的大力，故名“龍象般若功”。

    “龍象般若功”共分十三層，第一層功夫十分淺易，縱是下愚
之人，只要得到傳授，一二年中即能練成。第二層比第一層加深一
倍，需時三四年。第三層又比第二層加深一倍，需時七八年。如此
成倍遞增，越是往後，越難進展。待到第五層以後，欲再練深一層，
往往便須三十年以上苦功。密宗一門，高僧奇士歷代輩出，但這一
十三層“龍象般若功”卻從未有一人練到十層以上。這功夫循序漸
進，本來絕無不能練成之理，若有人得享千歲高齡，最終必臻第十
三層境界，只是人壽有限，密宗中的高僧修士欲在天年終了之前練
到第七層、第八層，便非得躁進不可，這一來，往往陷入了欲速不
達的大危境。北宋年間，藏邊曾有一位高僧練到了第九層，繼續勇
猛精進，待練到第十層時，心魔驟起，無法自制，終於狂舞七日七
夜，自終絕脈而死。

	學習要求：
		基本內功10級
		相應的戾氣
		非出家喇嘛不能學到30級以上的龍象般若功
		太監不能學到50級以上的龍象般若功
HELP
	);
	return 1;
}

