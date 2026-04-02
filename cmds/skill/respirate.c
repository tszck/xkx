// respirate.c
inherit F_CLEAN_UP;

#include <skill.h>



private int respirate_cost;
int respirating(object me);
int halt_respirate(object me);

int main(object me, string arg)
{
	object where = environment(me);

	seteuid(getuid());
	
	if (((int)me->query("age") < 30) && !wizardp(me))
		return notify_fail("你現在還年輕，以後再練吧！\n");

	if (where->query("pigging"))
		return notify_fail("你還是專心拱豬吧！\n");
		
	if (where->is_chat_room())
	  return notify_fail("這裏禁止吐納。\n");

	if (me->is_busy()) 
		return notify_fail("你現在正忙着呢！\n");

	if( me->is_fighting() )
		return notify_fail("戰鬥中吐納，好象只有神仙才能做到。\n");

	if( !arg || !sscanf(arg, "%d", respirate_cost))
		return notify_fail("你要花多少精修行？\n");

	if (respirate_cost <= 0)
		return notify_fail("你不是神仙！\n");

	if( (int)me->query("jing") < respirate_cost )
		return notify_fail("你現在精不足，無法修行精力！\n");

	if( (int)me->query("qi") * 100 / (int)me->query("max_qi") < 70 )
		return notify_fail("你現在身體狀況太差了，無法集中精神！\n");

	write("你閉上眼睛開始打坐。\n");
	me->set_temp("pending/respirate", 1);
	me->set_temp("respirate_cost", respirate_cost);
	message_vision("$N盤膝坐下，開始吐納煉精。\n", me);
	me->start_busy((: respirating :), (: halt_respirate :));
	return 1;
}

int respirating(object me)
{
//	int respirate_cost = (int)me->query_temp("respirate_cost");
	int jingli_gain = 1 + (int)me->query_skill("taoism") / 5;
//	object where=environment(me);

	if (respirate_cost < jingli_gain)
		jingli_gain = respirate_cost;

	me->add("jingli", jingli_gain);
	respirate_cost -= jingli_gain;
	me->add("jing", -jingli_gain);

	if (respirate_cost > 0)
		return 1;

	me->set_temp("pending/respirate", 0);
	respirate_cost = 0;
	message_vision("$N吐納完畢，睜開雙眼，站了起來。\n", me);
	if((int)me->query("jingli") < (int)me->query("max_jingli") * 2)
		return 0;
	else {
		if ((int)me->query("max_jingli") > 
                    ((int)me->query_skill("taoism",1) * 10))
		{
			write("你的精力修爲似乎已經達到了瓶頸。\n");
			me->set("jingli", (int)me->query("max_jingli"));
			return 0;
		}
		else
		{
			me->add("max_jingli", 1);
			me->set("jingli", (int)me->query("max_jingli"));
			write("你的精力增加了！！\n");
			return 0;
		}
	}
}

int halt_respirate(object me)
{
	respirate_cost = 0;
	if ((int)me->query("jingli") > (int)me->query("max_jingli") * 2)
		me->set("jingli", (int)me->query("max_jingli") * 2);
	message_vision("$N猛吸幾口大氣，站了起來。\n", me);
	me->set_temp("pending/respirate", 0);
	return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : respirate | tuna [<耗費「精」的量>]
 
    打坐修行，利用「煉精化氣，煉氣化神，煉神還虛」的方法將你
的精轉變成精力。

See also: exercise
HELP
        );
        return 1;
}