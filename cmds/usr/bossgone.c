// TIE@FY3
inherit F_CLEAN_UP;

#include <ansi.h>

int main(object me, string arg)
{
//	string msg;
	me->delete_temp("block_msg/all");
	write(CLR);
	me->delete_temp("boss_screen");
	write("俠客行告訴你：運氣如何？被抓住了嗎？哈哈！\n");
//	message("channel:chat",GRN"【警鈴】"+me->name(1)+"得意洋洋地打開屏幕，看着老闆在門外消失：拜拜了您哪。\n"NOR,users());
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式: bossgone

    這個指令讓你(玩家)在老闆走後恢復正常俠客行遊戲。

有關指令：boss
HELP
	);
	return 1;
}