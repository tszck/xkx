// dian.c 凌虛點穴
// Last Modified by winder on Jun. 4 2000

#include <ansi.h>
inherit F_SSERVER;
#define PNAME "凌虛點穴"

int perform(object me, object target)
{
	string msg;
	int damage;
	int flag;
	string fskill,sskill,bskill,pfname;

	sskill = explode(__FILE__,"/")[<2];
	pfname = explode(__FILE__,"/")[<1][0..<3];
  if (userp(me) && !wizardp(me) &&
   !me->query("perform/"+pfname) &&
   !me->query("can_perform/"+sskill+"/"+pfname) &&
   !me->query_temp("murong/xingyi") &&
   !SCBORN_D->valid_perform(me,sskill,pfname) )
   return notify_fail("你所使用的外功中沒有這種功能。\n");

	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
//	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail("你要對誰使用"PNAME"！\n");
  if( environment(me)->query("no_fight") )
		return notify_fail("在這裏不能攻擊他人。\n");

  notify_fail("你不能攻擊這個人。\n");
	if (!userp(target) && !target->accept_hit(me)) return 0;
	
	//兵器空手均可
 
	if((int)me->query_str() < 25)
		return notify_fail("你臂力不夠，不能使用"PNAME"！\n");
	fskill = "shenyuan-gong";
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
		return notify_fail("你的"+to_chinese(fskill)+"功力不夠，不能使用"+PNAME+"。\n");
	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(sskill)+"修爲不夠，不能"+PNAME+"。\n");
	if( (int)me->query_skill(bskill, 1) < 100 )
		return notify_fail("你的"+to_chinese(bskill)+"修爲不夠，還不能使用"+PNAME+"。\n");

	if((int)me->query("neili") < 300)
		return notify_fail("你內力現在不夠，不能使用"PNAME"！\n");
	if( target->is_busy() )
		return notify_fail(target->name() +"目前正自顧不暇，放膽攻擊吧！\n");
	msg = HIY"$N"HIY"伸出食指，凌虛向$n"HIY"點了過去。指風尖銳如刀，帶出細長的嘯聲。\n";

	if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/4)
	{
		if (target->query_temp("hmg_dzjm"))
		{
			msg += HIY "$P指風正中$p的胸口，$p微微一笑，行動竟絲毫不受阻礙，$P一驚之下，呆在當場。\n"NOR;
			me->start_busy(4);
			me->add("neili", -100);
		} else {
			msg +=  HIG "結果$p胸口一麻，便即摔倒在地下。\n" NOR;
			target->start_busy( random((int)me->query_skill(bskill, 1) / 30)  + 2);
			me->add("neili", -100);
		}
	}
	else
	{
		msg += HIM "$p雙掌擋護胸前，恰恰封住$P的凌空指力。\n" NOR;
 		me->start_busy(4);
  }
  if ((int)me->query("str")>33 && 
    (int)me->query_skill("canhe-finger", 1) > 400 &&
    (int)me->query_skill("finger", 1) > 350 &&
     me->query("family/master_id") == "murong fu")
	{
		me->start_busy(2);
		target->start_busy(random(8));
		damage = (int)me->query_skill("canhe-finger", 1);
		damage = damage + random(damage);
		target->receive_damage("qi", damage,me);
		target->receive_wound("qi", damage,me);
	        me->add("neili", -200);
	        msg += HIC "一股陰寒的指風從$p"HIC"掌間滲入。\n" NOR; 
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
		後天膂力25
		神元功100級
		基本指法100級
		參合指100級
		內力300
HELP
	);
	return 1;
}

