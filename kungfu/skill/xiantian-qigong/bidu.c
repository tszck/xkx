// bidu.c
// Last Modified by Winder on Oct. 20 2000
#include <ansi.h>

int exert(object me, object target)
{
	int con1, con2, con3, con4, con5, con6;
  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/bidu") &&
  !me->query("can_perform/xiantian-qigong/bidu") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("你所使用的內功中沒有這種功能。");

	con1 = me->query_condition("snake_poison");
	con2 = me->query_condition("scorpion_poison");
	con3 = me->query_condition("xx_poison");
//	con4 = me->query_condition("ss_poison");
	con5 = me->query_condition("zhua_poison");
	con6 = me->query_condition("ice_poison");

	if(con1< 1 && con2< 1 && con3< 1 &&con4 < 1 && con5< 1 && con6< 1)
		return notify_fail("你坐下運功逼毒。不過好象沒法逼出什麼來。\n");
	if( me->is_fighting() )
		return notify_fail("戰鬥中運功逼毒？嫌死不快是嗎？\n");

	if( (int)me->query("neili") < 500 )
		return notify_fail("你的真氣不夠。\n");

	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
		return notify_fail("你已經受傷過重，只怕一運真氣便有生命危險！\n");

	if ((int)me->query_skill("xiantian-qigong", 1) < 80)
		return notify_fail("你的先天氣功修為還不夠。\n");

	message("vision", 
	HIY+me->name()+"盤膝坐下，緩引真氣，運功逼毒。只見一團"HIW"白霧"HIY"漸漸籠住"+me->name()+"的面目。\n良久，一滴"HIM"紫血"HIY"從"+me->name()+"的右手小指尖緩緩滴了下來。\n" NOR,
		environment(me));

	me->add("neili", -300);
	me->add("qi", 10 + (int)me->query_skill("force")/5 );
	if(me->query("qi") > me->query("eff_qi"))
		me->set("qi", me->query("eff_qi"));
	me->start_busy(4);
	if (con1) me->clear_condition("snake_poison");
	if (con2) me->clear_condition("scorpion_poison");
	if (con3) me->clear_condition("xx_poison");
//	con4 = me->query_condition("ss_poison");
	if (con5) me->clear_condition("zhua_poison");
	if (con6) me->clear_condition("ice_poison");
	return 1;
}
int help(object me)
{
	write(WHT"\n先天氣功之逼毒"NOR"\n");
	write(@HELP

	使用功效：
		運功逼出體內毒素，對下列毒有效：
		蛇毒、蠍子毒、星宿掌毒、凝血神抓

	出手要求：
		先天氣功80級
		內力500
HELP
	);
	return 1;
}

