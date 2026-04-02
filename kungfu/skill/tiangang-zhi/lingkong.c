// lingkong.c 天罡指穴法 「凌空指穴」
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

inherit F_SSERVER;
#define PNAME "「凌空指穴」"
int perform(object me, object target)
{
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
//	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail("你要對誰使用凌空指穴！\n");
         
	if( environment(me)->query("no_fight") )
		return notify_fail("在這裏不能攻擊他人。\n");
        
  notify_fail("你不能攻擊這個人。\n");
	if (!userp(target) && !target->accept_hit(me)) return 0;
	
	//兵器空手均可
	
	if((int)me->query_str() < 25)
		return notify_fail("你臂力不夠，不能使用這一絕技！\n");
		
	fskill = "linji-zhuang";
	bskill = "finger";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(fskill)+"的火候不夠使用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(sskill)+"火候不夠，不能使用"+PNAME+"。\n");

	if( (int)me->query_skill(bskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(bskill)+"火候不夠，不能使用"+PNAME+"。\n");

	if((int)me->query("neili") < 300)
		return notify_fail("你內力現在不夠，不能使用凌空指穴！\n");

	if( target->is_busy() )
		return notify_fail(target->name()+"目前正自顧不暇，放膽攻擊吧！\n");

	msg = 
HIY "$N使出天罡指穴法絕技「凌空指穴」，回過身來，背後竟似生了眼睛一般，左
手食中二指向$n接連戳去，一連七指，全是對向$n的頭臉與前胸重穴。$n不
及攻敵，拼力躲避$N指力，頓時動作大亂。\n";
	if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/4)
	{
		if (target->query_temp("hmg_dzjm"))
		{
			msg += HIY "$P一指點中$p的大穴，$p只覺微微一麻，迅即行動如常。\n"NOR;
            me->start_busy(4);             
			me->add("neili", -100);
		} else {
			msg +=  HIG "結果$p被$P指力點中幾處穴道! \n" NOR;
			target->start_busy( random((int)me->query_skill(bskill, 1) / 20));
			me->add("neili", -100);
		}
	}
	else
	{
		msg += HIM "$p情急智生，狠力一躍，退出老遠。\n" NOR;
		me->start_busy(3);
		if(!target->is_fighting(me) &&
			target->query("owner") &&
			me->query("id") == target->query("owner"))
	        target->fight_ob(me);
        }
	message_combatd(msg, me, target);

	return 1;
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		遲滯對方出手

	出手要求：
		臨濟十二莊100級
		基本指法100級
		天罡指穴法100級
		內力300
		後天膂力25
HELP
	);
	return 1;
}

