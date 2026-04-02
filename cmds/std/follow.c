// follow.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;

	if( !arg ) return notify_fail("指令格式：follow <某人>|none。\n");

	if( arg=="none")
		if( me->query_leader() )
		{
			me->set_leader(0);
			write("你決定不再跟隨任何人了。\n");
			return 1;
		} else {
			write("你現在並沒有跟隨任何人。\n");
			return 1;
		}
	if( me->is_ghost())
	{
                write("你是鬼魂，不能跟隨行走。\n");
		return 1;
	}
	if( !objectp(ob = present(arg, environment(me))) )
		return notify_fail("這裏沒有 " + arg + "。\n");
	if( !ob->is_character() )
		return notify_fail("什麼？跟隨...." + ob->name() + "。\n");
	if( ob->query_leader() == me )
	{
		write("人家已經在跟隨你了耶！\n");
		return 1;
	}
/* 不允許旋環follow，避免宕機*/
	if( ob==me )
	{
		write("跟隨自己？虧你想得出來！\n");
		return 1;
	}
	if( ob->query_leader() && !(wizardp(me) && me->query("env/invisibility")))
	{
		write("人家已經在跟隨別人跑呢，你恐怕跟不上耶！\n");
		return 1;
	}

	me->set_leader(ob);
  if (!me->query("env/invisibility"))
	message_vision("$N決定開始跟隨$n一起行動。\n", me, ob);

	return 1;
}

int help (object me)
{
	write(@HELP
指令格式 : follow [<生物>|none]
 
    這個指令讓你能跟隨某人或生物。不能跟隨已經在跟隨別人的生物。
    如果輸入 follow none 則停止跟隨。
    （你可能會問：如果玩家的ｉｄ也是ｎｏｎｅ，該怎麼做才能跟隨他
（她）？仔細想想啦，很容易做的。：)

 
HELP );
	return 1;
}
