// /cmds/std/task.c

// Created by Constant Jan 4 2001
inherit F_CLEAN_UP;

#include <ansi.h>



int main(object me, string str)
{
	string output;

	output = HIC"\n≡" +
		 HIY"------------------------"+
		 HIC"飛雪連天任務榜" +
		 HIY"------------------------"+
		 HIC"≡\n"NOR;

	output += HIG"       「任務物品」" +
		"                " +
		"          「物品主人」\n"NOR;

	output += HIY"  --------------------------------------------------------------"NOR + "\n";

	if (!str || str != "-u") output += TASK_D->dyn_quest_list(0);
	else output += TASK_D->dyn_quest_list(1);

	output += HIC"≡"HIY"--------------------------------------------------------------"HIC"≡\n"NOR;
	output += HIW"      前面帶"HIR"√"HIW"的表示該任務已完成。"NOR;
	me->start_more(output);

	return 1;
}

int help(object me)
{
	write(@HELP
指令格式: task [-u]

    這個指令是用來得知目前的所有使命，帶-u參數則顯示所有未
完成之使命。

HELP
	);
	return 1;
}
