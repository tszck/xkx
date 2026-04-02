// Filename : /cmds/std/stop.c
// Last Modified by Winder on Jul. 15 2001
inherit F_CLEAN_UP;

#include <ansi.h>


int main(object me, string arg)
{
	object ob;
//	int cost,i = 0;

	seteuid(getuid());

	if ( !arg )
		return notify_fail("你要讓什麼野獸停止咬人？\n");
	if( !objectp(ob = present(arg, environment(me)) ))
		return notify_fail("這裏沒有這個野獸吧？\n");
	if( ob->query_temp("owner") != me->query("id") )
		return notify_fail("你不是它的主人，它根本不理你！\n");
	if( ob->is_busy() )
		return notify_fail(ob->name() + "正在忙乎，沒空理你！\n");
	message_vision("只見$N衝着$n口中一聲呼哨，$n向後一竄，不咬了！\n\n",me,ob);
	ob->remove_all_enemy();
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : stop <動物>

    此指令可用於讓幫你咬人的動物停止攻擊。

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
