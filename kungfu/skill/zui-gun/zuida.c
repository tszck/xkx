// zuida.c 少林醉棍 [八仙醉打]
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

inherit F_SSERVER;
#define PNAME "「八仙醉打」"
void remove_effect(object me, int amount, int amount1);

int perform(object me, object target)
{
	object weapon;	
  	string msg;
	int count, count1, cnt, skill;
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
/*
	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"只能對戰鬥中的對手使用。\n");
*/
	if (!objectp(weapon = me->query_temp("weapon")) || 
	(string)weapon->query("skill_type") != "club")
		return notify_fail("你使用的武器不對。\n");

	if( (int)me->query_temp("jingang") ) 
		return notify_fail("你已經在運大金剛神通了。\n");

	if( (int)me->query_temp("zuida") ) 
		return notify_fail("你已經在運功中了。\n");

	if( (int)me->query_temp("powerup"))
		return notify_fail(HIG "你已經運起內功加力了，沒有更多的內力使用八仙醉打。\n"NOR);

	if( (int)me->query_str() < 25 )
		return notify_fail("你的臂力不夠，目前不能使用此絕技！\n");
		
	fskill = "hunyuan-yiqi";
	bskill = "club";
	if (SCBORN_D->valid_perform(me,sskill,pfname))
		fskill = me->query_skill_mapped("force");
	if( me->query_temp("murong/xingyi") )
	{
		sskill = "douzhuan-xingyi";
		fskill = "shenyuan-gong";
		bskill = "parry";
	}

	if( (int)me->query_skill(fskill, 1) < 60 )
		return notify_fail("你的"+to_chinese(fskill)+"修為不夠，無法使用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 90 )
		return notify_fail("你的"+to_chinese(sskill)+"還不夠嫺熟，無法使用"+PNAME+"。\n");

	if( (int)me->query_skill(sskill, 1) < 90 )
		return notify_fail("你的"+to_chinese(sskill)+"修為不夠，不能使用"+PNAME+"。\n");

	if( (int)me->query("neili") < 500 )
		return notify_fail("你的真氣不足！\n");

	cnt =(int)( (int)me->query_condition("drunk") / 3 );
	if( cnt < 2 )
		return notify_fail("你的醉意不足激發醉打！\n");

	msg = HIY"$N使出少林醉棍的絕技「八仙醉打」，臂力陡然增加, 身法陡然加快！\n" NOR;
	
   	message_combatd(msg, me, target);
	skill = me->query_skill("club", 1);
	count = me->query("str") * random(cnt + 1);
	count1 = me->query("dex") * random(cnt + 1);
	if (count > 100);
	   else (count = 100);
	if (count < 50);
	   else (count =50);
	if (count1 > 60);
	   else (count1 = 60);
	if (count1 < 50);
	    else (count1 =50);
	me->add_temp("apply/strength", count);
	me->add_temp("apply/dexerity", count1);
	me->set_temp("zuida", 1);

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, count, count1 :), skill /3 );

	me->add("neili", -150);
   	return 1;
}

void remove_effect(object me, int amount, int amount1)
{
	if ( (int)me->query_temp("zuida") ) 
	{
		me->add_temp("apply/strength",-amount);
		me->add_temp("apply/dexerity",-amount1);
		me->delete_temp("zuida");
		tell_object(me, HIY "你的八仙醉打運功完畢，將內力收回丹田。\n" NOR);
		me->start_busy(4);
	}
}
string name() {return replace_string(replace_string(PNAME,"「",""),"」","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"之"+name()+WHT"："NOR"\n");
	write(@HELP

	使用功效：
		增強自己的攻擊力和防護力

	出手要求：
		混元一氣功60級
		少林醉棍90級
		基本棍法90級
		內力500
		後天膂力25
		喝醉
HELP
	);
	return 1;
}

