// save.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object link_ob;

	seteuid(getuid());

	if( !wizardp(me) && time()-me->query("last/lastsave") < 30)
		return notify_fail("你剛存過盤，不會丟數據，不必連續存盤。\n");

	if( !objectp(link_ob = me->query_temp("link_ob")) )
		return notify_fail("你不是經由正常連線進入，不能儲存。\n");

	if( environment(me)->query("valid_startroom") || wizardp(me) )
	{
		me->set("startroom", base_name(environment(me)));
		write("當你下次連線進來時，會從這裏開始。\n");
	}
	me->set("last/lastsave", time());
	if( (int)link_ob->save() && (int)me->save() )
	{
		write("檔案儲存完畢。\n");
		return 1;
	} else {
		write("儲存失敗。\n");
		return 0;
	}
}

int help(object me)
{
	write(@HELP
指令格式：save

    把你辛苦奮鬥的結果存起來。
HELP
	);
	return 1;
}
