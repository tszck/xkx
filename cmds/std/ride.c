// Filename : /cmds/std/ride.c
// Last Modified by winder on Aug. 5 2001
inherit F_CLEAN_UP;

#include <ansi.h>


int do_ride(object me, object ob);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object obj, env;

	if( !arg ) return notify_fail("你要騎什麼東西？\n");
	if( me->query_temp("is_riding") )
		return notify_fail("你已經有座騎了！\n");
	if( me->is_busy() )
		return notify_fail("你上一個動作還沒有完成！\n");
	if( me->is_fighting() )	return notify_fail("你還在戰鬥中！沒空騎上去。\n");

	// Check if a container is specified.
	env = environment(me);

	if( !objectp(obj = present(arg, env)) || !living(obj) )
		return notify_fail("這裏沒有這樣東西可騎。\n");
	if( !obj->query("ridable") &&
		obj->query_temp("owner") != me->query("id") )
		return notify_fail("這個東西你也要騎？當心你的屁股！\n");
	if( !living(obj) || obj->query_temp("noliving"))
		return notify_fail("這個東西自己都暈倒了，你怎麼騎？\n");
	return do_ride(me, obj);
	write("騎上去了。\n");
}
	
int do_ride(object me, object obj)
{
	object /*old_env,*/ *guard;

	if( !obj ) return 0;

	if( guard = obj->query_temp("guarded") )
	{
		guard = filter_array(guard, (: objectp($1) && present($1, environment($2)) && living($1) && ($1!=$2) :), me);
		if( sizeof(guard) )
			return notify_fail( guard[0]->name() + "正守在" + obj->name() + "一旁，防止任何人騎走。\n");
	}

	if( obj->move(me) )
	{
		message_vision("$N走近$n，飛身騎了上去，身手很是矯捷。\n", me, obj );
		obj->set_temp("is_rided_by", me);
		me->set_temp("is_riding", obj);
//騎動物增加膂力和身法。
/*
		if(obj->query("dex"))
			me->set_temp("apply/dexerity", obj->query("dex")/3);
		if(obj->query("str"))
			me->set_temp("apply/strength", obj->query("str")/3);
*/
	}
	else
	{
		message_vision("$N身上帶的東西太重了，無法騎到$n身上去。\n", me, obj );
	}
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : ride <生物名>
 
    這個指令可以讓你騎上代步的已馴養的動物。

    對於已經馴服的動物，可以進行下述指令：

基本指令：
        come <動物名>:                  讓動物跟隨主人行動。
        stay:                           停止動物的跟隨狀態。
        attack <某物>:                  讓動物攻擊敵人。
        stop <動物名>:                  讓動物停止對人的攻擊。
        release:                        結束主奴狀態，將動物放離。

特殊指令：（只對某些動物適用）
        ride <動物名>:                  騎，如騎馬，虎，雕，鯊等。
        unride <動物名>:                下，離開坐騎。
        feed <飼料> to <動物名>:        替動物餵食。
        imbibe <動物名>:                給動物飲水。

HELP
	);
	return 1;
}
