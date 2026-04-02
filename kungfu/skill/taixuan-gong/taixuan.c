// kungfu/skill/taixuan-gong/taixuan
#include <ansi.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int exert(object me, object target)
{
   int skill;
   if ( userp(me) && !wizardp(me) && 
//  !me->query("perform/taixuan") &&
  !me->query("can_perform/taixuan-gong/taixuan") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("你所使用的內功中沒有這種功能。");

   if( target != me ) 
      return notify_fail("你只能對自己用["+HIW+"白首太玄"+NOR+"]\n"NOR,);
	 if ((int)me->query_skill("taixuan-gong", 1) < 100)
		  return notify_fail("你的太玄神功太差了。\n");
   if( (int)me->query("neili") < 100 ) 
  	  return notify_fail("你的內力不夠。\n");
   if( (int)me->query_temp("powerup") ) return
       notify_fail("你已經在運功中了。\n");

        skill = me->query_skill("taixuan-gong",1);

        me->add("neili", -100);
        me->receive_damage("qi",0);

        message_combatd(
HIW"$N突然一聲長吟，極快的念出了一首詩來，旁人細聽之下不由大驚!!!!!\n原來這居然竟是傳説中的天下奇功【白首太玄經】！\n" NOR, me);
        me->add_temp("apply/attack", skill/3);
        tell_object(me,HIR"你的攻擊力提高了!\n"NOR);
        me->add_temp("apply/dodge", skill/3);
        tell_object(me,HIR"你的防禦力提高了!\n"NOR);
        me->set_temp("powerup", 1);
        me->add_temp("apply/strength",skill/40);
        tell_object(me,HIG"你的力量提高了!\n"NOR);
        me->add_temp("apply/dexerity",skill/40);
        tell_object(me,HIG"你的速度提高了!\n"NOR);
        me->add_temp("apply/constitution",skill/40);
        tell_object(me,HIG"你的根骨提高了!\n"NOR);
        me->add_temp("apply/intelligence",skill/40);
        tell_object(me,HIG"你的悟性提高了!\n"NOR);
        me->start_call_out((:call_other,__FILE__,"remove_effect",me,skill:),skill);
        if( me->is_fighting() ) me->start_busy(3);
        return 1;
}

void remove_effect(object me, int skill)
{
        me->add_temp("apply/attack", - skill/3);
        me->add_temp("apply/dodge", - skill/3);
        me->delete_temp("powerup");
        me->add_temp("apply/strength",- skill/40);
        me->add_temp("apply/intelligence",- skill/40);
        me->add_temp("apply/constitution",- skill/40);
        me->add_temp("apply/dexerity" , - skill/40);
        tell_object(me, "你的"+HIW+"【白首太玄】"+NOR+"運行完畢，將內力收回丹田。\n");
}
int help(object me)
{
		write(WHT"\n太玄功之【白首太玄經】"NOR"\n");
	write(@HELP

	使用功效：
		增加攻擊力、防禦力
		暫時提升後天臂力、悟性、根骨、身法

	出手要求：
		從俠客島石壁參悟
		太玄功100級
		內力100
HELP
	);
	return 1;
}
