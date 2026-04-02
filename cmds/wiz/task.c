
inherit F_CLEAN_UP;

#include <ansi.h>


int main(object me, string str)
{
	string output;

	output = HIC"≡" + HIG"------------------------" + HIG" 飛雪連天任務榜 " + HIG"------------------------" + HIC"≡\n"NOR;
    	output += TASK_D->dyn_quest_list();
	output += HIC"≡" + HIG"------------------------------------------------------------" + HIC"≡\n"NOR;
	output += "前面帶√的表示該任務已完成。";
	me->start_more(output);

	return 1;
}

int help(object me)
{
	write(@HELP
指令格式: task

這個指令是用來得知目前的所有使命.

HELP
	);
	return 1;
}
