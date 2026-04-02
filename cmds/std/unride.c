// Filename : /cmds/std/unride.c
// Last Modified by winder on Aug. 5 2001
inherit F_CLEAN_UP;

#include <ansi.h>


void create() { seteuid(getuid()); }

int main(object me)
{
	object obj, *inv;
	int i = 0;

	inv = all_inventory(me);
	while( i < sizeof(inv) && i >= 0 )
	{
		if( inv[i]->query_temp("is_rided_by") == me )
		{
			obj = inv[i];
			i = -10;
		}
		i++;
	}
	if( i >= 0 ) return notify_fail("下什麼下！你根本就沒坐騎！\n");
	message_vision("$N從$n上飛身跳下。\n", me, obj);
//跳下動物減少膂力和身法。
	if( !living(obj) || obj->query_temp("noliving"))
		return notify_fail("這個東西自己都暈倒了，你也沒法下了。\n");
/*
	if(obj->query("dex"))
		me->delete_temp("apply/dexerity");
	if(obj->query("str"))
		me->delete_temp("apply/strength");
*/
	obj->move( environment(me) );
	obj->delele("is_rided_by");
	me->delete_temp("is_riding");
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : unride
 
    這個指令可以讓你從騎着的已馴養的動物上跳下來。
 
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

