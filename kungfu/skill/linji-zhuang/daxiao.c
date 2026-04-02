// daxiao.c
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

int exert(object me)
{
	int skill;
	skill = (int)me->query_skill("linji-zhuang",1);

  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/daxiao") &&
  !me->query("can_perform/linji-zhuang/daxiao") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("你所使用的內功中沒有這種功能。");

	if (me->query_condition("linji_daxiao") || me->query("linji/jing")>0)
		return notify_fail("你已經在運大小莊了！\n");

	if (me->query("gender") != "女性" || me->query("sex/number") )
		return notify_fail("你不是處女純陰之體，不能運大小莊！\n");

	if( me->is_fighting() )
		return notify_fail("戰鬥中無法運大小莊！\n");

	if( (int)me->query("neili") < 500)
		return notify_fail("你的真氣不夠。\n");

	if( (int)me->query("jing") < skill + 100)
		return notify_fail("你的精不夠運大小莊。\n");

	if( (int)me->query_skill("linji-zhuang",1) < 150)
		return notify_fail("你的臨濟莊級別不夠。\n");

	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
		return notify_fail( "你已經受傷過重，無法運功！\n");

	if( (int)me->query("qi") < skill ||
		(int)me->query("max_qi") < skill ||
		(int)me->query("eff_qi") < skill)
		return notify_fail("你的身體狀況現在不適宜運轉此功法。\n");

	message_vision("$N坐了下來運起大小莊，呼吸吐納，真氣直透九重。臉上神色一會變"HIR"紅"NOR"，一\n會變"HIC"青"NOR"，一會又變成"HIY"黃"NOR"色，最後終於回覆原來的臉色。\n"NOR,me);
	me->apply_condition("linji_daxiao", (int)skill/20);
	me->add("neili",  -500);
	me->add("max_jing", 0 - skill);
	me->add("eff_jing", 0 - skill);
	me->add("jing", 0 - skill);
	me->add("max_qi", 2 * skill);
	me->add("eff_qi", 2 * skill);
	me->add("qi", 2 * skill);
	me->set("linji/jing", skill);
	me->save();
	return 1;
}

int help(object me)
{
	write(WHT"\n臨濟十二莊之大小莊："NOR"\n");
	write(@HELP

	使用功效：
		以氣化精

	出手要求：
		臨濟十二莊150級
		內力500
		處女純陰之體
HELP
	);
	return 1;
}

