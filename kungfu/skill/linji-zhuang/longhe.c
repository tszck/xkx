// longhe.c
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

int exert(object me)
{
	int skill;
	skill = (int)me->query_skill("linji-zhuang",1);

  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/longhe") &&
  !me->query("can_perform/linji-zhuang/longhe") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("你所使用的內功中沒有這種功能。");

	if (me->query_temp("ljlonghe"))
		return notify_fail("你已經在運龍鶴莊了！\n");

	if (me->query("gender") != "女性" || me->query("sex/number"))
		return notify_fail("你不是處女純陰之體，不能運龍鶴莊！\n");

	if( me->is_fighting() )
		return notify_fail("戰鬥中無法運龍鶴莊！\n");

	if( (int)me->query("neili") < 300)
		return notify_fail("你的真氣不夠。\n");

	if( (int)me->query_skill("linji-zhuang",1) < 90)
		return notify_fail("你的臨濟莊級別不夠。\n");

	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
		return notify_fail( "已經受傷過重，無法運功！\n");

	message_vision(
HIR "$N坐了下來運起龍鶴莊，把全身上下拍打了一遍，覺得全身充滿力量，....
就想發泄出去，和誰過過招一樣。\n" NOR, me);
	me->add("neili", -300);
	me->add("eff_jing", -15);
	me->add("jing", -20);
	me->set_temp("ljlonghe", 1);
	me->add_temp("apply/constitution", (int)skill/30);
	me->start_call_out((:call_other,__FILE__,"remove_effect",me,skill/30:),skill);
	return 1;
}

void remove_effect(object me, int count)
{
	me->add_temp("apply/constitution",-count);
	me->delete_temp("ljlonghe");
	tell_object(me, 
HIB "忽然你覺得全身懶洋洋的，連個小指頭也不想動了，原來你的
龍鶴莊收功了！\n" NOR );
}

int help(object me)
{
	write(WHT"\n臨濟十二莊之龍鶴莊："NOR"\n");
	write(@HELP

	使用功效：
		臨時提高根骨

	出手要求：
		臨濟十二莊90級
		內力300
		處女純陰之體
HELP
	);
	return 1;
}

