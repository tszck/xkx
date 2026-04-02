// fengyun.c
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

int exert(object me)
{
	int skill;
	skill = (int)me->query_skill("linji-zhuang",1);

  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/fengyun") &&
  !me->query("can_perform/linji-zhuang/fengyun") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("你所使用的內功中沒有這種功能。");

	if (me->query_temp("ljfengyun"))
		return notify_fail("你已經在運風雲莊了！\n");

	if (me->query("gender") != "女性" || me->query("sex/number"))
		return notify_fail("你不是處女純陰之體，不能運風雲莊！\n");

	if( me->is_fighting() )
		return notify_fail("戰鬥中無法運風雲莊！\n");

	if( (int)me->query("neili") < 400)
		return notify_fail("你的真氣不夠。\n");

	if( (int)me->query_skill("linji-zhuang",1) < 120)
		return notify_fail("你的臨濟莊級別不夠。\n");

	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
		return notify_fail( "已經受傷過重，無法運功！\n");

	message_vision(
HIC "$N坐了下來運起風雲莊，緩緩將內力運到腳心湧泉穴，....
稍許，覺得一股暖流自足底湧洶湧而上，頓時覺得身輕如燕，躍躍欲飛。\n" NOR, me);
	me->add("neili", -400);
	me->add("jing", -20);
	me->set_temp("ljfengyun", 1);
	me->add_temp("apply/dexerity", (int)skill/40);
	me->start_call_out((:call_other,__FILE__,"remove_effect",me,skill/40:),skill);
	return 1;
}

void remove_effect(object me, int count)
{
	me->add_temp("apply/dexerity",-count);
	me->delete_temp("ljfengyun");
	tell_object(me, 
HIB"忽然你覺得一股濁氣自腰間猛向下沉去，頓時雙足如灌鉛般沉
重，原來你的風雲莊收功了！\n" NOR );
}

int help(object me)
{
	write(WHT"\n臨濟十二莊之風雲莊："NOR"\n");
	write(@HELP

	使用功效：
		臨時提高身法

	出手要求：
		臨濟十二莊120級
		內力400
		處女純陰之體
HELP
	);
	return 1;
}

