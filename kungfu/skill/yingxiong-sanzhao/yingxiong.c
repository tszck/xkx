// yingxiong.c
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit F_SSERVER;
#define PNAME "蓋世英雄"
int perform(object me, object target)
{
	int level;
	string msg;
	int flag;
	string fskill,sskill,bskill,pfname,pskill;

	sskill = explode(__FILE__,"/")[<2];
	pfname = explode(__FILE__,"/")[<1][0..<3];
  if (userp(me) && !wizardp(me) &&
   !me->query("perform/"+pfname) &&
   !me->query("can_perform/"+sskill+"/"+pfname) &&
   !me->query_temp("murong/xingyi") &&
   !SCBORN_D->valid_perform(me,sskill,pfname))
   return notify_fail("你所使用的外功中沒有這種功能。\n");

	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"只能對戰鬥中的對手使用。\n");
		
		//兵器空手均可
		
	if( me->query("gender") != "男性" && !wizardp(me))
		return notify_fail("象你這副娘娘腔，也許練“絕世風姿”恐怕更合適點吧。\n");

	fskill = "dulong-dafa";
	bskill = "finger";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 50 )
		return notify_fail("你的"+to_chinese(fskill)+"不夠嫺熟，不會使用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 60 )
		return notify_fail("你的"+to_chinese(sskill)+"不夠嫺熟，不會使用"+PNAME+"。\n");

	if( (int)me->query("neili") < 300 )
		return notify_fail("你的內力不足，恐怕沒法逞英雄了。\n");

	if( me->query_temp("shenlong/yingxiong") )
		return notify_fail("你已經在大擺英雄的譜了，還不夠啊？\n");

	level = me->query_cor()/3;
	me->add("neili", -200);
	me->start_busy(1);
	if( target->query_cor() < random(me->query_cor() * 2) )
	{
		message_combatd(HIY"$N"HIY"越鬥越是兇猛，激鬥中仰天大吼一聲：“蓋世英雄！！”，一股豪氣自$N心中升起，頓時更是兇悍起來。\n" NOR, me, target);
		me->set_temp("shenlong/yingxiong", 1);
		me->add_temp("apply/courage", level);
		target->start_busy(random(3)+1);
		me->start_call_out( (: call_other, __FILE__, "remove_effect", me, level:), 30);
	}
	else
	{
		message_combatd(HIG"激鬥中的$N衝着$n大喊：“蓋世。。。”，語意未了，就被$n迫得手忙腳亂。\n" NOR, me, target);
	}
	return 1;
}
void remove_effect(object me, int level)
{
	me->delete_temp("shenlong/yingxiong");
	me->add_temp("apply/courage", -level);
	message_combatd(HIY"$N突然感到心底一陣失落：“歷代英雄，都歸孤冢。”一念及此，頓時意興蕭然。\n" NOR, me);
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		耗費自己的內力
		大幅提高自己的膽識

	出手要求：
		毒龍大法50級
		英雄三招60級
		自身爲男性
		內力300
HELP
	);
	return 1;
}

