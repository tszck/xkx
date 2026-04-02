// Filename : /cmds/std/come.c
// Last Modified by winder on Aug. 5 2001
inherit F_CLEAN_UP;

#include <ansi.h>


int main(object me, string arg)
{
	object ob;
	int cost;

	seteuid(getuid());

	if( me->is_fighting() )
		return notify_fail("一邊打架一邊馴獸？你真是活膩了！\n");
	if( me->query_temp("comedby"))
		return notify_fail("已經有野獸跟着你了！\n");
	if( !arg )
		return notify_fail("你要讓什麼野獸跟隨你？\n");
	if( !objectp(ob = present(arg, environment(me)) ))
		return notify_fail("這裏沒有這隻野獸吧？\n");
	if( userp(ob) )
		return notify_fail("人家也是玩家，你搞什麼搞啊？\n");
	if( me->query_skill("training",1) < 10 &&
		ob->query("owner") != me->query("id"))
		return notify_fail("你的馭獸術還不純熟，無法讓野獸跟隨你！\n");
	if( ob->query("race") == "人類") 
		return notify_fail("這不是野獸，你暈頭了吧？\n");
	if( ob->is_fighting() )
		return notify_fail(ob->name() + "正在打架，沒空理你！\n");
	if( ob->is_busy() )
		return notify_fail(ob->name() + "正在忙乎，沒空理你！\n");
	if( !ob->query_temp("owner") )
		return notify_fail(ob->name() + "是隻無主野獸，你得先馴服(train)它啊！\n");
	if( ob->query_temp("owner") &&
		( ob->query_temp("owner") != me->query("id") ))
	{
		ob->kill_ob(me);
		return notify_fail(ob->name() + "早被人家馴服了，你不是找死啊！\n");
	}
	if ( ob == me )
		return notify_fail("你沒問題吧，自己跟自己？\n");
	if (!living(ob)) 
		return notify_fail("這隻野獸暈倒了，你怎能讓它跟你呢？\n");

	cost = me->query("max_jing")/((me->query_skill("training",1)+10)/10)-10;

	if ( me->query("jing") <= cost )
		return notify_fail("現在你太累了，無法讓野獸跟隨。\n");

	message_vision("只見$N衝着"+ob->name()+"手中擺了個手式，它一竄就跟上了。\n\n",me);

	me->receive_damage("jing", cost );
	me->set_temp("comedby", ob->query("id"));
	ob->set_leader(me);
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : come <動物>

    此指令可用於讓某動物跟隨你。

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
        imbibe <飲料>:                  給動物飲水。

HELP
	);
	return 1;
}

