// wake.c
inherit F_CLEAN_UP;

#include <ansi.h>


int main(object me, string arg)
{
	object target;

	if(!arg || !objectp(target = present(arg, environment(me))))
		return notify_fail("你想喚醒誰？\n");
	if(target == me)
		return notify_fail("你不能自己喚醒自己！\n");
	message_vision(HIY "$N拍了拍$n的頭，喊道：“別裝蒜了，起來！”\n$n睜開眼睛一臉不好意思地站了起來。\n" NOR, me, target );
	target->receive_curing("qi", 10 );
	target->remove_call_out("revive");
	target->revive();
	target->reincarnate();
 
	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : wake <生物>
 
喚醒活物
 
HELP
    );
    return 1;
}
