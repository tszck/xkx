// beimin-shengong.c 北冥神功
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#include "force.h";
inherit FORCE;
string type() { return "martial"; }
string martialtype() { return "force"; }

int valid_enable(string usage) { return usage=="force"; }
int learn_bonus() { return 0; }
int practice_bonus() { return 0; }
int success() { return 10; }
int power_point(object me) { return 1; }

int valid_learn(object me)
{
	int i, lvl = (int)me->query_skill("beiming-shengong", 1);

	if(me->query("family/family_name")!="逍遙派")
		return notify_fail("只有逍遙弟子才能學北冥神功。\n");
	if ( me->query_skill("force",1) < 10)
		return notify_fail("你的基本內功火候還不夠，難以領會北冥神功。\n");
	if ( me->query("gender") == "無性" && lvl > 49)
		return notify_fail("你無根無性，陰陽不調，難以領會高深的北冥神功。\n");
	return valid_public(me,"bahuang-gong");
}

int practice_skill(object me)
{
	return notify_fail("北冥神功只能用學的，或是從運用(exert)中增加熟練度。\n");
}
/* 被擊中對方的副作用，目前主要用在內功上 factor= 加力 damage_bonus=臂力 */
mixed be_hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int ap, dp;
	int jiali;
	string msg;
	
	
	  if ((int) me->query_skill("beiming-shengong", 1) < 70 ||
            ! living(me) 
     	  || victim->query_skill_mapped("force") == "taixuan-gong"
				)
       return;
       if (!me->query("perform/shield") 
       && !SCBORN_D->valid_learn(me,"beiming-shengong"))
       return ;
   jiali=factor;
   if ( jiali <1 || victim->query("id")=="songyang" /*給布袋打木人開個後門*/ )
      return;

	ap=me->query_skill("force");
	dp=victim->query_skill("force");
	switch (random(4))
                {
                case 0:
                        msg=HIM "$N" HIM "只覺得內力源源而瀉，不由得大喫一驚。\n" NOR;
                        break;
                case 1:
                        msg=HIM "$N" HIM "只覺得發出的內力猶如石沉大海，不知所蹤。\n" NOR;
                        break;
                case 2:
                        msg=HIM "$N" HIM "只覺得發出的內力猶無影無蹤，渾然不知着落。\n" NOR;
                        break;
                default:
                        msg=HIM "$N" HIM "不住催動內力，但是隻覺得$n竟似毫不費力。\n" NOR;
                        break;
                }

	if (dp/2+random(dp)<ap )
	{

//		message("vision",msg,environment(me));
    if (victim->query("neili")>0)
		   {
		   	victim->add("neili",-(jiali+ap/6));
    		if (me->query("neili") < me->query("max_neili") * 2)
          	me->add("neili", ap/6+jiali);
      	return msg;
        }
	}
	return 0;
}

string exert_function_file(string func)
{
	return __DIR__"beiming-shengong/" + func;
}
int help(object me)
{
	write(HIC"\n北冥神功："NOR"\n");
	write(@HELP

    北冥神功為逍遙派無上內功。
    莊子‘逍遙遊’有云：‘窮髮之北有冥海者，天池也。有魚焉，
其廣數千裏，未有知其修也。’又云：‘且夫水之積也不厚，則其
負大舟也無力。覆杯水於坳堂之上，則芥為之舟；置杯焉則膠，水
淺而舟大也。’是故逍遙派武功，以積蓄內力為第一要義。內力既
厚，天下武功無不為我所用，猶之北冥，大舟小舟無不載，大魚小
魚無不容。是故內力為本，招數為末。北冥神功系引世人之內力而
為我有。北冥大水，非由自生。語雲：百川匯海，大海之水以容百
川而得。汪洋巨浸，端在積聚。
    世人練功，皆自雲門而至少商，我逍遙派則反其道而行之，自
少商而至雲門，拇指與人相接，彼之內力即入我身，貯於雲門等諸
穴。然敵之內力若勝於我，則海水倒灌而入江河，兇險莫甚。逍遙
派旁支，未窺要道，惟能消敵內力，不能引而為我用，猶日取千金
而復棄之於地，暴殄珍物，殊可哂也。

	學習要求：
		基本內功10級
		太監無法學到50級以上的北冥神功
HELP
	);
	return 1;
}

