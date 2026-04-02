// Last Modified by Winder on May. 15 2001
// drink.c
inherit F_CLEAN_UP;

#include <ansi.h>


int main(object me, string arg)
{
	object obj;
	
	if( !living(me) || me->query_temp("noliving") ) return 1;
	if( me->query("jing")<0 || me->query("qi")<0 )
		return notify_fail("你太累了，實在沒力氣喝東西了。\n");
	if( me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢。\n");
	if( (int)me->query("water") >= me->max_water_capacity() )
		return notify_fail("你已經喝太多了，再也灌不下一滴水了。\n");
	if(!arg)
	{
		obj = environment(me);
		if(!obj->query("resource/water"))
			return notify_fail("這地方可沒水。\n");
	
		if((string)obj->query("drink_msg"))
			message_vision(obj->query("drink_msg"), me);
		else message_vision("$N捧起一些清水，慢慢喝了下去。\n", me);
		me->add("water", 20);
		if( obj->query("liquid/drink_func") ) return 1;
		return 1;
	}
	
	else if(!objectp(obj = present(arg, me)) )
		return notify_fail("你身上沒有這樣東西。\n");
	if(!obj->query("liquid") )
		return notify_fail("看清楚點，這東西裝有喝的嗎？\n");
	if(!obj->query("liquid/remaining") )
		return notify_fail( obj->name() + (obj->query("liquid/name") ? "已經被喝得一滴也不剩了。\n":"是空的。\n"));
	me->add("water", 10+((int)obj->query("liquid/drunk_apply")?obj->query("liquid/drunk_apply"):20));
	obj->add("liquid/remaining", -1);

	if((int)obj->query("liquid/busy"))
		me->start_busy(obj->query("liquid/busy"));

	if((string)obj->query("drink_msg"))
		message_vision(obj->query("drink_msg"), me, obj);
	else message_vision("$N拿起$n咕嚕嚕地喝了幾口" + obj->query("liquid/name")+ "。\n", me, obj);
	if( obj->query("liquid/poisontime") > 1 )
	{
		me->apply_condition(obj->query("liquid/poison"), obj->query("liquid/poisontime") );
		write("你突然覺得喝的東西有點不對勁。可已經來不及了。\n");
	}
	if( !obj->query("liquid/remaining") )
	{
		if((string)obj->query("finish_msg"))
			write(obj->query("finish_msg"));
		else write("你已經將" + obj->name() + "裏的" + obj->query("liquid/name")+ "喝得一滴也不剩了。\n");
	}

	if( obj->query("liquid/drink_func") ) return 1;
	if (!obj) return 1;

	switch(obj->query("liquid/type"))
	{
		case "alcohol":
			me->apply_condition("drunk",(int)me->query_condition("drunk")+ (int)obj->query("liquid/drunk_apply"));
			break;
	}
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : drink | he [物品名稱]
 
    這個指令就是喝，補充消耗的水分。但要注意有些飲料可能是帶毒的。
    如果你身上帶着器皿且裏面還有水，可以drink <器皿>
    如果你所在的地方有水源的話，可以直接用drink來喝水。
	
HELP
	);
	return 1;
}
 
