// /cmds/std/locate.c

// Created by Constant Jan 4 2001

inherit F_CLEAN_UP;

int main(object me, string str)
{
	string output = "";
	
	if (!str) return notify_fail("指令格式: locate <物品>\n");
	if(me->query("jing") < 10)
		return notify_fail("抱歉，你沒有精氣探知此物方位。\n");
	me->receive_damage("jing", 10+random(10));
	output = TASK_D->locate_obj(me, str);
	if (output=="") return notify_fail("抱歉，無法探知此物方位。\n");
	write(output);
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式: locate <物品>

    用來得知任務物品的大致位置。

HELP
	);
	return 1;
}
