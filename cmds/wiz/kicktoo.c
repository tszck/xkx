// kickto.c 踢某人至陰間
inherit F_CLEAN_UP;


#include <ansi.h>
#include <command.h>


int main(object me, string arg)
{
	object ob;
	string wiz_status/*, tmpstr*/;

	if( me!=this_player(1) ) return 0;
	if( !arg )
		return notify_fail("你要踢誰？\n");
	wiz_status=SECURITY_D->get_status(me) ;
//	if (wiz_status != "(admin)" )
//		return notify_fail("踢什麼踢？\n");
	ob = LOGIN_D->find_body(arg);
	if (!ob) return notify_fail("咦... 有這個人嗎？\n");
	if ( !living(ob) || !ob->is_character() || ob==me )
		return notify_fail("ob error!\n");
	message_vision(HIW"\n$N一腳踹在$n的屁股上，$n頓時橫着飛了出去。\n\n"NOR, me,ob);
	tell_object( me, "你把 " + ob->query("name") + " 踹到監獄去了。\n");
	seteuid(getuid(ob));
	me->save();
	seteuid(ROOT_UID);
	ob->move("/d/wizard/wizard_jail");
	ob->save();
	seteuid(getuid());
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : kickto <某人>
作    用 : 防止某些玩家搗亂。
HELP);
	return 1;
}
