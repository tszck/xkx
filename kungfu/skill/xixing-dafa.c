// xixing-dafa.c 吸星大法
// Last Modified by winder on Apr. 10 2000

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
	int i = (int)me->query_skill("xixing-dafa", 1);
	int t = 1, j;
	for (j = 1; j < i / 10; j++) t*= 2;
	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("你的基本內功火候不足，不能學吸星大法。\n");
	if (i > 10 && (int)me->query("shen") > t * 100)
		return notify_fail("學吸星大法，要心狠手辣，奸惡歹毒，你可做得不夠呀！\n");
	if (!me->query("family") || me->query("family/master_id")!="ren woxing")
		return notify_fail("吸星大法只能向任教主學習。\n");
	if (((int)me->query_skill("xixing-dafa", 1) < 20) &&
		((int)me->query_skill("xixing-dafa", 1) > 1) &&
		((int)me->query("max_neili") > 0))
		return notify_fail("你未放棄掉的內力，無法繼續學吸星大法！\n");

	if ( me->query_skill("buddhism",1) || me->query_skill("taoism",1) )
		return notify_fail("你練了禿驢牛鼻子們的心法，還學吸星大法做什麼！\n");

	if ( !me->query_skill("kuihua-xinfa",1))
		return notify_fail("你不先學葵花心法，怎能學吸星大法？！\n");

  return valid_public(me,"kuihua-xinfa");
}
int practice_skill(object me)
{
	return notify_fail("吸星大法只能用學(learn)的來增加熟練度。\n");
}

mixed be_hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int ap, dp;
	int jiali;
	string msg;
  if ((int) me->query_skill("xixing-dafa", 1) < 70 ||
            ! living(me) 
            || victim->query_skill_mapped("force") == "taixuan-gong"
				)
                return;
    jiali=factor;
   if (jiali < 1 )
     return;

	ap=me->query_skill("force");
	dp=victim->query_skill("force");
	switch (random(4))
                {
                case 0:
                        msg=BLU "$N" BLU "只覺得內力源源而瀉，不由得大喫一驚。\n" NOR;
                        break;
                case 1:
                        msg=BLU "$N" BLU "只覺得發出的內力猶如石沉大海，不知所蹤。\n" NOR;
                        break;
                case 2:
                        msg=BLU "$N" BLU "只覺得發出的內力猶無影無蹤，渾然不知着落。\n" NOR;
                        break;
                default:
                        msg=BLU "$N" BLU "不住催動內力，但是隻覺得$n竟似毫不費力。\n" NOR;
                        break;
                }

//if (dp/2+random(dp)<ap)  // 北冥同等級1/2幾率
                           // 化功 1/3
	if (dp*3/4+random(dp)<ap)	//同等級1/4幾率
	{

    if (victim->query("neili")>0)
		   {
		   	victim->add("neili",-(ap/6+jiali));
    		if (me->query("neili") < me->query("max_neili") * 2)
        	{
           	me->add("neili", ap/6+jiali);
        	}
        	return msg;
        }
	}
	return 0;
}

string exert_function_file(string func)
{
	return __DIR__"xixing-dafa/" + func;
}

int help(object me)
{
	write(HIC"\n吸星大法："NOR"\n");
	write(@HELP

    日月神教黑木崖的一種內功。

    吸星大法創自北宋年間的逍遙派，分為北冥神功和化功大法兩
路，後來從大理段氏和星宿派分別傳落，合而為一，稱為吸星大法。
主要是繼承了化功大法一路，修習者當令丹田常如空箱，恆似深谷，
空箱可貯物，深谷可容水。若有內息，散之於任脈諸穴。
    吸星大法只能拜任我行為師學習，非有相當機緣不能學到。

	學習要求：
		葵花心法
		基本內功10級
		儘量少的正氣
		不能學習佛門心法
		散功
HELP
	);
	return 1;
}

