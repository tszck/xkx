// tiandi.c
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

int exert(object me)
{
	int skill;
	skill = (int)me->query_skill("linji-zhuang",1);

  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/tiandi") &&
  !me->query("can_perform/linji-zhuang/tiandi") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("你所使用的內功中沒有這種功能。");

	if (me->query_temp("ljtiandi"))
		return notify_fail("你已經在運天地莊了！\n");

	if (me->query("gender") != "女性" || me->query("sex/number"))
		return notify_fail("你不是處女純陰之體，不能運天地莊！\n");

	if( me->is_fighting() )
		return notify_fail("戰鬥中無法運天地莊！\n");

	if( (int)me->query("neili") < 100)
		return notify_fail("你的真氣不夠。\n");

	if( (int)me->query_skill("linji-zhuang",1) < 30)
		return notify_fail("你的臨濟莊級別不夠。\n");

	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
		return notify_fail( "已經受傷過重，無法運功！\n");

	message_vision(
HIM "$N坐了下來運起天地莊，將手掌貼在臉上，緩緩地將真氣輕輕撲在臉上....
過了不久，$N的臉上亮出晶瑩的顏色，緩緩睜開的眼裏透出青春的氣息。\n" NOR,
	me );
	me->add("neili", -100);
	me->add("jing", -20);
	me->add("eff_jing", -10);
	me->set_temp("ljtiandi", 1);
	me->add_temp("apply/personality", (int)skill/20);
	me->start_call_out((:call_other,__FILE__,"remove_effect",me,skill/20:),skill);
	return 1;
}

void remove_effect(object me, int count)
{
	me->add_temp("apply/personality",-count);
	me->delete_temp("ljtiandi");
	tell_object(me, 
HIB "忽然你心裏頭感到一陣失落，原來你的天地莊收功了，你頓時
倍感紅顏老去之嘆！\n" NOR );
}

int help(object me)
{
	write(WHT"\n臨濟十二莊之天地莊："NOR"\n");
	write(@HELP

	使用功效：
		臨時提高容貌

	出手要求：
		臨濟十二莊30級
		內力100
		處女純陰之體
HELP
	);
	return 1;
}

