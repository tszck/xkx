// Last Modified by winder on May. 29 2001
// ghost.c
inherit F_CLEAN_UP;

#include <ansi.h>



int main(object me, string arg)
{
	if (!arg || arg!="-p")
	{
		me->set_ghost(1);
		write("你成功地變成了一隻鬼！\n");
	}
	else {
		me->set_ghost(0);
		write("你又投胎做人了！\n");
	}
	return 1;
}
		
int help(object me)
{
write(@HELP
指令格式 : ghost [-p]
 
這個指令讓你在人鬼之間切換。
HELP	);
	return 1;
}
