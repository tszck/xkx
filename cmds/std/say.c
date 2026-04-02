// say.c
inherit F_CLEAN_UP;

#include <ansi.h>



int main(object me, string arg)
{
	if (!arg) {
		write("你自言自語不知道在說些什麼。\n");
		message("sound", me->name() + "自言自語不知道在說些什麼。\n",
			environment(me), me);
		return 1;
	}
	if( (int)me->query("qi") < (int)me->query("max_qi") / 5 ) {
		arg = replace_string(arg, " ", " ... ") + " ...";
	}

	tell_object(me, CYN "你說道：" + arg + "\n" NOR);
	message("sound", CYN + me->name() + "說道：" + arg + "\n" NOR, environment(me), me);
	if( userp(me))
		message("channel:snp", HIB"【監聽】" + me->name() + "說道：" + arg + "\n"NOR, users());

	// The mudlib interface of say
	all_inventory(environment(me))->relay_say(me, arg);

	return 1;
}

int help (object me)
{
	write(@HELP
指令格式: say <訊息>
 
    說話，所有跟你在同一個房間的人都會聽到你說的話。
 
注: 本指令可用 ' 取代.
 
HELP
	);
	return 1;
}
