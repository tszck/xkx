// zhixin.c
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

int exert(object me)
{
	int skill;
	skill = (int)me->query_skill("linji-zhuang",1);

  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/zhixin") &&
  !me->query("can_perform/linji-zhuang/zhixin") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("你所使用的內功中沒有這種功能。");

	if (me->query_temp("ljzhixin"))
		return notify_fail("你已經在運之心莊了！\n");

	if (me->query("gender") != "女性")
		return notify_fail("你不是純陰之體，不能運之心莊！\n");

//	if (me->query("sex/number") )
//		return notify_fail("你不是處女之身，不能運幽冥莊！\n");

	if( me->is_fighting() )
		return notify_fail("戰鬥中無法運之心莊！\n");

	if( (int)me->query("neili") < 200)
		return notify_fail("你的真氣不夠。\n");

	if( (int)me->query_skill("linji-zhuang",1) < 60)
		return notify_fail("你的臨濟莊級別不夠。\n");

	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
		return notify_fail( "已經受傷過重，無法運功！\n");

	message_vision(
HIY "$N坐了下來運起之心莊，將手掌在腦門上磕了兩下，頓覺靈臺清明，....
站了起來，發現腦袋瓜靈光了不少。\n" NOR, me );
	me->add("neili", -200);
	me->add("eff_jing", -10);
	me->add("jing", -20);
	me->add_temp("apply/intelligence", (int)skill/40);
	me->set_temp("ljzhixin", 1);
	me->start_call_out((:call_other,__FILE__,"remove_effect",me,skill/40:),skill);
	return 1;
}

void remove_effect(object me, int count)
{
	me->add_temp("apply/intelligence",-count);
	me->delete_temp("ljzhixin");
	tell_object(me, 
HIB "忽然你頭腦裏感到一陣空白，原來你的之心莊收功了，你頓時
覺得自己還是個大笨木瓜！\n" NOR );
}

int help(object me)
{
	write(WHT"\n臨濟十二莊之之心莊："NOR"\n");
	write(@HELP

	使用功效：
		臨時提高悟性

	出手要求：
		臨濟十二莊60級
		內力200
		處女純陰之體
HELP
	);
	return 1;
}

