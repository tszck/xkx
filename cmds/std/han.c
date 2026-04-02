// han.c
inherit F_CLEAN_UP;

#include <ansi.h>



int main(object me, string arg)
{
	if( !wizardp(me) )
		return notify_fail("目前暫不開放玩家 shout。\n");
	if (!arg) return notify_fail("你想要大叫什麼？\n");
	shout( HIW + me->name() + HIW + "縱聲長嘯：" + arg + "\n"NOR);
	write(HIW"你縱聲長嘯：" + arg + "\n"NOR);
	return 1;
}
int help(object me)
{
	write(@HELP
指令格式 : shout | han <訊息>
 
    這個指令讓你將 <訊息> 傳送出去，所有正在遊戲中的人都
會聽見你的話。
 
see also : tune
HELP
	);
	return 1;
}
 
