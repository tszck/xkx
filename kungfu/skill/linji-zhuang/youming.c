// youming.c
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>

int exert(object me)
{
	object obj;
	int skill;
	
	seteuid(getuid());
	skill = (int)me->query_skill("linji-zhuang",1);
  if ( userp(me) && !wizardp(me) && 
  !me->query("perform/youming") &&
  !me->query("can_perform/linji-zhuang/youming") && 
  !me->query_temp("murong/xingyi"))
   return notify_fail("你所使用的內功中沒有這種功能。");

	if (!wizardp(me))
	{
	if (me->query("gender") != "女性")
		return notify_fail("你不是純陰之體，不能運幽冥莊！\n");

	if (me->query("sex/number") )
		return notify_fail("你不是處女之身，不能運幽冥莊！\n");

	if( me->is_busy() )
		return notify_fail("你現在太累！\n");

	if( me->is_fighting() )
		return notify_fail("戰鬥中無法運幽冥莊！\n");

	if( !me->query("dietime"))
		return notify_fail("你未歷幽冥，恐怕難運此莊。\n");

	if( me->query("dietime") < time() - 300)
		return notify_fail("你離開幽冥已久，已無幽冥靈氣。\n");

	if( (int)me->query("neili") < 1000)
		return notify_fail("你的真氣不夠。\n");

	if( me->query("jing") < 100 || me->query("qi") < 200)
		return notify_fail("你的精氣不夠。\n");

	if( (int)me->query_skill("linji-zhuang",1) < 180)
		return notify_fail("你的臨濟莊級別不夠。\n");
	}
	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
		return notify_fail( "已經受傷過重，無法運功！\n");

	message_vision(
HIG"$N坐了下來運起"HIB"幽冥莊"HIG"，雙掌抱球，兩股"MAG"紫氣"HIG"從掌心中漸漸透出，在兩\n掌之間交匯激盪，發出"HIY"風雷之聲"HIG"。於是"MAG"紫氣"HIG"中慢慢投射出"HIW"白光"HIG"，又緩緩\n地"HIR"耀目"HIG"起來，終於一聲清脆的爆響，$N的雙掌猛地合在了一起！$N翻開\n手掌，呵護着一粒晶瑩剔透的"HIW"丹丸。\n" NOR, me );
	message_vision("\n$N身子一歪坐在地上，實在太累了，爬不起來。\n",me);
	me->add("neili", -1000);
	me->receive_wound("jing", 100);
	me->receive_wound("qi", 100);
	obj = new("/clone/medicine/nostrum/guiyuandan");
	obj->set("owner",me);
	obj->move(me);
	me->start_busy(2);
	return 1;
}

int help(object me)
{
	write(WHT"\n臨濟十二莊之幽冥莊："NOR"\n");
	write(@HELP

	使用功效：
		練制歸元丹

	出手要求：
		臨濟十二莊180級
		內力1000
		精氣100
		氣血200
		處女純陰之體
HELP
	);
	return 1;
}

