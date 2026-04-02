// Filename: /cmds/std/attack.c
// Last Modified by winder on Aug. 5 2001
inherit F_CLEAN_UP;

#include <ansi.h>


int main(object me, string arg)
{
	object ob, *inv;
	int cost, i = 0;

	seteuid(getuid());

	if(environment(me)->query("no_fight"))
		return notify_fail("這裏不許打鬥！\n");
	if(environment(me)->query("no_ansuan"))
		return notify_fail("這裏不許打鬥！\n");
	if(me->is_busy())
		return notify_fail("你上一個動作還沒有完成！\n");
	cost = me->query("max_jing")/((me->query_skill("training",1)/10)+1)-10;
	if ( me->query("jing") <= cost )
		return notify_fail("現在你太累了，無法讓野獸幫你咬人。\n");
	if ( !arg )
		return notify_fail("你要讓什麼野獸幫你咬誰？\n");
	if( !objectp(ob = present(arg, environment(me)) ))
		return notify_fail("這裏沒有這個東西吧？\n");
	notify_fail("此人來頭不小，還是少惹為妙。\n");
	if (!userp(ob) && !ob->accept_hit(me)) return 0;

	inv = all_inventory(environment(me));
	while( i < sizeof(inv) && i >= 0 )
	{
		if( inv[i]->query_temp("owner") == me->query("id") )
		{
			if( inv[i]->is_fighting() )
				return notify_fail("已經有野獸在幫你咬人了！\n");
			if( inv[i]->is_busy() )
				return notify_fail(inv[i]->name()+ "正在忙乎，沒空理你！\n");
			if( (ob->query("age")< 16 ) && userp(ob))
				return notify_fail(ob->query("name")+"還是個小孩子，算了吧...！！\n");
			if( ob->query_temp("noliving")&&userp(ob))
                                return notify_fail(ob->query("name")+"都那樣了你還不親自動手! \n");
                        if (ob->query("owner") && ob->query("yinshi"))      
                                return notify_fail(inv[i]->name()+ "正在忙乎，沒空理你！\n");
                        if( me->query_skill("training",1) < 30 &&
				inv[i]->query("owner") != me->query("id") )
				return notify_fail("你的馭獸術還不純熟，無法讓野獸幫你咬人！\n");
			message_vision("只見$N衝着"+inv[i]->name()+"口中一聲呼哨，它一竄就向$n撲了上去。\n\n",me,ob);
			me->receive_damage("jing", cost);
			inv[i]->fight_ob(ob);
			return 1;
		}
		i++;
	}
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : attack <某物>

    此指令可用於讓某動物幫你攻擊，咬別人。

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

