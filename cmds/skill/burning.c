// burning.c
inherit F_CLEAN_UP;

#include <ansi.h>



int main(object me, string arg)
{
        int count;

        if (me->query_temp("burning_up"))
                return notify_fail("你現在正在怒火中，沒有必要再發作一次。\n");

        if (me->query("nuqi") < 1000)
                return notify_fail("你現在還不夠憤怒，無法讓自己怒火燃燒。\n");

        message_vision(HIR "$N" HIR "一聲大吼，兩目登時精光"
                       "四射，咄咄逼人，勢不可擋。\n" NOR, me);

        me->add("nuqi",- (500 + random(300)));
        count = me->query_skill("force") / 5;
        me->set_temp("burning_up", count);
        me->add_temp("apply/attack", count);
        me->apply_condition("burning", 1);

	return 1;
}

int help (object me)
{
        write(@HELP
指令格式: burning|fennu
 
這個指令讓你將現在將積蓄的憤怒發泄出來，這樣可以充分的提升你
的攻擊能力。在發泄時會不斷的消耗你的憤怒，直到心情平靜的時候
才自動恢復。

HELP
        );
        return 1;
}
