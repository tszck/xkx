// emote.c (Mon 09-04-95)
inherit F_CLEAN_UP;

#include <ansi.h>

 
int main(object me, string str)
{
	if (!str)
	{
		write(CYN"你看起來表情豐富。\n"NOR);
		tell_room(environment(me),CYN+(string)me->name()+"看起來表情豐富。\n" +NOR, me);
		return 1;
	}
	write(CYN"你"+str+"\n"NOR);
	tell_room(environment(me), CYN+(wizardp(me)? "":"->")+(string)me->name()+str+"\n"+NOR, me);
	message("channel:snp", HIB"【監聽】"+me->query("name")+"表情："+str+"\n"NOR, users());
	return 1;
}
 
int help(object me)
{
	write(@HELP
指令格式: emote <動作詞>

    這個指令可以讓你表達一個系統沒有預設的動作詞，系統會將你
所輸入的文字加上你的姓名後顯示給所有在同一個地方的生物看。爲
了避免造成困擾，玩家所輸入的詞句前面會加上 -> 以供區別（巫師
則不在此限）。
    預設的指令可以直接鍵入。

    範例：emote 坐了下來。

你會看見：你坐了下來。
其他人會看到：->包子坐了下來。

    其中，包子就是你的名字.

相關指令: semote
HELP
	);
	return 1;
}
