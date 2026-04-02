// huagong-dafa.c 化功大法
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#include "force.h";
inherit FORCE;
string type() { return "martial"; }
string martialtype() { return "force"; }

int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 10; }
int power_point(object me) { return 1; }

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
	int i = (int)me->query_skill("huagong-dafa", 1);
	int t = 1, j;
	for (j = 1; j < i / 10; j++) t*= 2;

	if(me->query("family/family_name")!="星宿派")
		return notify_fail("只有星宿弟子才能學化功大法。\n");
	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("你的基本內功火候不足，不能學化功大法。\n");
	if (i > 10 && (int)me->query("shen") > t * 100)
		return notify_fail("學化功大法，要心狠手辣，奸惡歹毒，你可做得不夠呀！\n");
	if ( me->query_skill("buddhism",1) )
		return notify_fail("你練了禿驢們的心法，還學化功大法做什麼！\n");

	return valid_public(me);
}

int practice_skill(object me)
{
	return notify_fail("化功大法只能用學(learn)的來增加熟練度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"huagong-dafa/" + func;
}
/* 被擊中對方的副作用，目前主要用在內功上 factor= 加力 damage_bonus=臂力 */
mixed be_hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int ap, dp;
	int jiali;
	string msg;
  if ((int) me->query_skill("huagong-dafa", 1) < 70 ||
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
                        msg=HIB "$N" HIB "只覺得內力源源而瀉，不由得大喫一驚。\n" NOR;
                        break;
                case 1:
                        msg=HIB "$N" HIB "只覺得發出的內力猶如石沉大海，不知所蹤。\n" NOR;
                        break;
                case 2:
                        msg=HIB "$N" HIB "只覺得發出的內力猶無影無蹤，渾然不知着落。\n" NOR;
                        break;
                default:
                        msg=HIB "$N" HIB "不住催動內力，但是隻覺得$n竟似毫不費力。\n" NOR;
                        break;
                }

//if (dp/2+random(dp)<ap)  // 北冥同等級1/2幾率
	if (dp*2/3+random(dp)<ap)	//同等級1/3幾率
//化功大法源自北冥 重用毒，內功上面比北冥弱
	{

//		message("vision",msg,environment(me));
    if (victim->query("neili")>0)
		   {
		   	victim->add("neili",-(ap/6+jiali));
    		if (me->query("neili") < me->query("max_neili") * 2)
        	{
         //   	me->add("neili", ap/6+jiali);//化功不算吸內力？
        	}
        	return msg;
        }
	}
	return 0;
}
int help(object me)
{
	write(HIC"\n化功大法："NOR"\n");
	write(@HELP

    星宿祖師丁春秋原爲逍遙派無崖子之徒，無崖子精通北冥神功，
但未授與丁春秋。後丁春秋叛師出門，憑着過人的智慧，吸收北冥
神功的精髓，自創出一套化功大法，與北冥神功各擅勝場，難分軒
輊。

	學習要求：
		基本內功10級
		不能學禪宗心法
		相應的戾氣
HELP
	);
	return 1;
}

