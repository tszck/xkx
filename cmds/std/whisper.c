// whisper.c
inherit F_CLEAN_UP;


#include <ansi.h>


int main(object me, string arg)
{
	string dest, msg;
	object ob;

	if( !arg || sscanf(arg, "%s %s", dest, msg)!=2 )
		return notify_fail("你要對誰耳語些什麼？\n");

	ob = present(dest, environment(me));
	if( !ob || !ob->is_character() )
		return notify_fail("你要對誰耳語？\n");

	write( GRN "你在" + ob->name() + "的耳邊悄聲説道：" + msg + "\n" NOR);
	tell_room( environment(me), me->name() + "在" + ob->name()
		+ "耳邊小聲地説了些話。\n", ({ me, ob }) );
	if( !userp(ob) ) ob->relay_whisper(me, msg);
	else
		tell_object( ob, GRN + me->name() + "在你的耳邊悄聲説道：" + msg + "\n" NOR);
	message("channel:snp", HIB"【監聽】"+me->query("name")+"在"+ob->query("name")+"的耳邊悄聲説道："+msg+"\n"NOR, users());
	return 1;
}

int help(object me)
{
	write( @TEXT
指令格式：whisper <某人> <訊息>

    這個指令可以用來和同一房間中的人耳語，包括 NPC 在內。

TEXT
	);
	return 1;
}
