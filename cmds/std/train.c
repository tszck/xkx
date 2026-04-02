// Filename : /cmds/std/train.c
// Last Modified by winder on Aug. 5 2001
inherit F_CLEAN_UP;

#include <ansi.h>


int main(object me, string arg)
{
	object ob/*,where*/;
//	mapping fam;
	int sp, dp;
	int /*i,*/ cost, train_level;

	seteuid(getuid());

//	if( me->is_fighting() )
//		return notify_fail("一邊打架一邊馴獸？你真是活膩了！\n");
	if ( me->query_skill("training",1) < 10 )
		return notify_fail("你的馭獸術還不純熟，無法訓練野獸！\n");
	if ( !arg )
		return notify_fail("你要訓練什麼野獸？\n");
	if( !objectp(ob = present(arg, environment(me)) ))
		return notify_fail("這裏沒有這隻野獸吧？\n");
	if (userp(ob)) 
		return notify_fail("人家也是玩家，你搞什麼搞啊？\n");
	if (ob->query("owner")) 
		return notify_fail("這是寵物，你沒事幹操什麼心啊？\n");
	if (ob->query("race") == "人類") 
		return notify_fail("這不是野獸，你暈頭了吧？\n");
	if (ob->query("no_train") ) 
		return notify_fail("這東西野性難馴，還是算了吧。\n");
//	if( ob->is_fighting() )
//		return notify_fail(ob->name() + "正在打架，沒空理你！\n");
	if( ob->query_temp("owner") &&
		( ob->query_temp("owner") == me->query("id") ))
		return notify_fail(ob->name() + "就是你馴服過的，你還折騰個啥勁兒呢！\n");
	if( ob->query_temp("owner") &&
		( ob->query_temp("owner") != me->query("id") ))
		return notify_fail(ob->name() + "早被人家馴服了，你還折騰個啥勁兒呢！\n");
	if ( ob == me )
		return notify_fail("你沒這麼笨吧，把自己不當人？\n");
	if (!living(ob)) 
		return notify_fail("這隻野獸暈倒了，你怎能馴得它動呢？\n");

	cost = me->query("max_jing")/(me->query_skill("training",1)/10) - 10;

	if ( me->query("jing") <= cost )
		return notify_fail("現在你太累了，無法馴服野獸。\n");

	message_vision("只見$N衝着"+ob->name()+"手腳亂擺，口中似對它輕輕細語。\n\n",me);

	sp = me->query_skill("training",1) + me->query("int");
	dp = ob->query("combat_exp")/100;
	
	if ( random(sp) < random(dp)/2 )
	{
		ob->kill_ob(me);
		return notify_fail("你馭獸術不精，那東西野性不泯，衝着你就竄了過來！\n");
	}

	me->receive_damage("jing", cost );
	message_vision("頓時"+ob->name()+"衝着$N搖了搖尾巴，很溫馴的樣子。\n\n",me);

	train_level = me->query_skill("training", 1);
	if ( (int)me->query("combat_exp") > (train_level*train_level*train_level)/10)
	{
		me->improve_skill("training", random(me->query("int")));
	}

	ob->set("attitude", "peace");
	ob->remove_all_enemy();
	ob->set_temp("owner",me->query("id"));
	ob->set_temp("ownername",me->query("name"));
	if( (strsrch(ob->query("name"), "馬") >= 0) ||
		( strsrch(ob->query("name"), "驢") >= 0) ||
		( strsrch(ob->query("name"), "騾") >= 0) ||
		( strsrch(ob->query("name"), "駝") >= 0) ||
		( strsrch(ob->query("name"), "牛") >= 0) ||
		( strsrch(ob->query("name"), "象") >= 0) ||
		( strsrch(ob->query("name"), "獅") >= 0) ||
		( strsrch(ob->query("name"), "虎") >= 0) ||
		( strsrch(ob->query("name"), "豹") >= 0) ||
		( strsrch(ob->query("name"), "鹿") >= 0) ||
		( strsrch(ob->query("name"), "鯊") >= 0) ||
		( strsrch(ob->query("name"), "雕") >= 0))
		ob->set("ridable",1);
	me->remove_all_enemy();
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : train <動物>

    此指令可用於馴化某動物。

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
