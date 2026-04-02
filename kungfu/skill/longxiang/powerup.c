// powerup.c 龍相功加力
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
	int skill;
	int i,lx,num;

  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/powerup") &&
  !me->query("can_perform/longxiang/powerup") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("你所使用的內功中沒有這種功能。");

	if( target != me )
		return notify_fail("你只能提升自己的戰鬥力。\n");
	if( (int)me->query("neili")<200)
		return notify_fail("你的內力不夠。\n");
	if( (int)me->query_temp("powerup"))
		return notify_fail("你已經在運功中了。\n");

	skill = me->query_skill("force");
/*
    “龍象般若功”共分十三層，第一層功夫十分淺易，縱是下愚
之人，只要得到傳授，一二年中即能練成。第二層比第一層加深一
倍，需時三四年。第三層又比第二層加深一倍，需時七八年。如此
成倍遞增，越是往後，越難進展。待到第五層以後，欲再練深一層，
往往便須三十年以上苦功。
一層 2 
二層 4
三   8
四   16
五   32
六   32
七   32
八   32

*/
	lx = me->query_skill("longxiang",1);
	for(num=0,i=0;i<13;i++)
	{
		if (lx < 0) break;
		switch(i)
		{
			case 0: lx -= 2;num++;break;
		  case 1: lx -= 4;num ++;break;
		  case 2: lx -= 8;num ++;break;
		  case 3: lx -= 16;num ++;break;
		  default : lx -= 32;num ++;break;
		}
	}

//	message_combatd(HIR"$N大喝一聲，全身骨骼節節暴響，一股迅猛的罡氣向四周擴散開來！\n"NOR, me);
	message_combatd(HIR"$N口中默唸大明六字真言，手結摩利支天憤怒印，運起"+chinese_number(num)+"龍"+chinese_number(num)+"象之力！\n"NOR, me);

	me->add_temp("apply/attack", skill/3);
	me->add_temp("apply/dodge", skill/3);
	me->set_temp("powerup", 1);
	me->add("neili", -100);

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/3 :), skill);

	if( me->is_fighting() ) me->start_busy(3);

	return 1;
}

void remove_effect(object me, int amount)
{
	if ( (int)me->query_temp("powerup") )
	{
		me->add_temp("apply/attack", - amount);
		me->add_temp("apply/dodge", - amount);
		me->delete_temp("powerup");
		tell_object(me, "你的龍象般若功運行完畢，將內力收回丹田。\n");
	}
}
int help(object me)
{
	write(WHT"\n龍象般若功之加力："NOR"\n");
	write(@HELP

	使用功效：
		提升自己的攻擊防禦能力

	出手要求：
	        內力200
HELP
	);
	return 1;
}

