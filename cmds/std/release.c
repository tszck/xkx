// Filename : /cmds/std/release.c
// Last Modified by winder on Aug. 5 2001
inherit F_CLEAN_UP;

#include <ansi.h>


int main(object me)
{
	object *inv;
	int j = 0, i = 0;

	inv = all_inventory(environment(me));
	while( i < sizeof(inv) && i >= 0 )
	{
		if( inv[i]->query_temp("owner") == me->query("id") && //馴養
			inv[i]->query("owner") != me->query("id"))    //寵物
		{
			message_vision("$N很慈悲地把$n放離，任其迴歸自然了。\n", me, inv[i]);
			inv[i]->delete_temp("owner");
			inv[i]->delete_temp("ownername");
			j=1;
		}
		i++;
	}
	if (j == 0) message_vision("$N想放生，可是沒啥可放的。\n", me);
	
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : release

    此指令可用於讓某動物結束主奴狀態，將動物放離。寵物不能放生。

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

