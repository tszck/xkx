// halt.c
// By Xiang@XKX (12/17/95)

int main(object me, string arg)
{
	if (me->is_fighting()) {
		me->remove_all_enemy();
                message_vision("$N身行向後一躍，跳出戰圈不打了。\n", me); 
	}
	else if (!me->is_busy()) 
		return notify_fail("你現在不忙。\n");
	else if ((int)me->query_temp("pending/exercise") != 0) {
	        message_vision("$N把正在運行的真氣強行壓回丹田，站了起來。\n", me);
		me->interrupt_me();
	}
	else if ((int)me->query_temp("pending/respirate") != 0)
		me->interrupt_me();
	me->interrupt_me();
//	me->start_busy(1);

	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : halt
 
    這個指令可以讓你用於停止手頭正在做的事情，例如：攻擊敵
人（當對方要殺你時無效，只是單方面取消你對別人的殺指令），
打坐或吐納等。
 
HELP
    );
    return 1;
}
 
