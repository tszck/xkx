// /cmds/usr/finger.c

inherit F_CLEAN_UP;

void create()
{
	seteuid(getuid());
}

int main(object me, string arg)
{
	int i;
	if( !arg ) {
		if( (int)me->query("jing") < 50 )
			return notify_fail("你的精神無法集中。\n");
		if( !wizardp(me) )
			me->receive_damage("jing", 50);
		me->start_more( FINGER_D->finger_all() );
	} else {
		for (i = 0; i < sizeof(arg); i++)
        		if (arg[i]<'a' || arg[i]>'z')
                           return notify_fail("沒有這個人存在。\n"); 
		if( (int)me->query("jing") < 15 )
			return notify_fail("你的精神無法集中。\n");
		if( !wizardp(me) )
			me->receive_damage("jing", 15);
		write( FINGER_D->finger_user(arg) );
	}
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : finger [使用者姓名]
 
    這個指令，如果沒有指定使用者姓明，會顯示出所有正在線上玩家
的連線資料。反之，則可顯示有關某個玩家的連線，權限等資料。
 
see also : who
HELP
	);
	return 1;
}
 
