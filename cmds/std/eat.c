// Last Modified by Winder on May. 15 2001
// eat.c
inherit F_CLEAN_UP;

#include <ansi.h>


int main(object me, string arg)
{
	object obj;

	if(!living(me) || me->query_temp("noliving") ) return 1;
	if(me->query("jing")<0 || me->query("qi")<0 )
		return notify_fail("你太累了，實在沒力氣喫什麼了。\n");
	if(me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢。\n");
	if(!arg) return notify_fail("你要喫什麼東西？\n");
	if(!objectp(obj = present(arg, me)) )
	{
		if(objectp(obj = present(arg, environment(me))) &&
			!obj->is_character())
			tell_room(environment(me), me->name() + "盯着地上的"+obj->name() + "，嚥了一口唾沫。\n",({ me }));
		return notify_fail("你身上沒有這樣東西。\n");
	}
	if(!obj->query("food_supply") )
		return notify_fail("看清楚點，這東西能喫嗎？\n");
	if(!obj->query("food_remaining") )
		return notify_fail( obj->name() + "已經沒什麼好喫的了。\n");
	if( me->query("food") >= me->max_food_capacity() )
		return notify_fail("你已經喫太飽了，再也塞不下任何東西了。\n");
		
	me->add("food", obj->query("food_supply"));
	if( obj->query("eat_func") ) return 1;
	if( !obj ) return 1;
	
	obj->set("value", 0);
	obj->add("food_remaining", -1);
	if((int)obj->query("food_busy"))
		me->start_busy(obj->query("food_busy"));
		
	if( !obj->query("food_remaining") )
	{
		obj->delete_temp("apply/long");
		if((string)obj->query("finish_msg"))
			message_vision(obj->query("finish_msg"), me, obj);
		else message_vision("$N將剩下的$n喫得乾乾淨淨。\n", me, obj);
		if( !obj->finish_eat() ) destruct(obj);
	} 
	else
	{
		if((string)obj->query("eat_msg"))
			message_vision(obj->query("eat_msg"), me, obj);
		else message_vision("$N拿起$n咬了幾口。\n", me, obj);
	}
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : eat | chi <物品名稱>
 
    這個指令就是喫，補充消耗的食物。但要注意有些食物可能是帶毒的。
 
HELP
	);
	return 1;
}
 
