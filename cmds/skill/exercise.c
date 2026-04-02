// exercise.c
inherit F_CLEAN_UP;

#include <skill.h>



int exercising(object me);
//int halt_exercise(object me, object who, string why);
int halt_exercise(object me);

int main(object me, string arg)
{
	int exercise_cost;
	object where;

	seteuid(getuid());
	where = environment(me);
	
	if (where->query("pigging"))
		return notify_fail("你還是專心拱豬吧！\n");
		
	if (where->is_chat_room() && where->query("no_fight"))
	  return notify_fail("這裏禁止打坐。\n");

	if (me->is_busy() || me->query_temp("pending/exercising"))
		return notify_fail("你現在正忙着呢。\n");

	if( me->is_fighting() )
		return notify_fail("戰鬥中不能練內功，會走火入魔。\n");

	if( !stringp(me->query_skill_mapped("force")) )
		return notify_fail("你必須先用 enable 選擇你要用的內功心法。\n");

	if( !arg || !sscanf(arg, "%d", exercise_cost))
		return notify_fail("你要花多少氣練功？\n");
	if (exercise_cost < 10)
		return notify_fail("你的內功還沒有達到那個境界！\n");

	if( (int)me->query("qi") < exercise_cost )
		return notify_fail("你現在的氣太少了，無法產生內息運行全身經脈。\n");

	if( (int)me->query("jing") * 100 / (int)me->query("max_jing") < 70 )
		return notify_fail("你現在精不夠，無法控制內息的流動！\n");

	write("你坐下來運氣用功，一股內息開始在體內流動。\n");

	me->set_temp("pending/exercise", 1);
	me->set_temp("exercise_cost", exercise_cost);
	message_vision("$N盤膝坐下，開始修煉內力。\n", me);
	me->start_busy((: exercising :), (:halt_exercise:));

	return 1;
}

int exercising(object me)
{
	int exercise_cost = (int)me->query_temp("exercise_cost");
	int neili_gain = 1 + (int)me->query_skill("force") / 10;
	int max_neili_gain = (int) random(me->query("max_neili") /500);

	int taixuan;
	object where=environment(me);
	if (exercise_cost < 1)
		return 0;
	me->add("neili", neili_gain);
	me->set_temp("exercise_cost", exercise_cost -= neili_gain);
// 靈鷲玄冰室
	if(where->query("xuanbing"))
		me->add("qi", (int)neili_gain/3);
// 太玄功
	if ((int)me->query_skill("taixuan-gong",1))
	{
		taixuan = (int)me->query_skill("taixuan-gong",1);
		if(taixuan > 10)
			me->add("qi", (int)neili_gain * taixuan / 400);
	}
// 神照經
	if ((int)me->query_skill("shenzhao-jing",1))
	{
		taixuan = (int)me->query_skill("shenzhao-jing",1);
		if(taixuan > 10)
			me->add("qi", (int)neili_gain * taixuan / 400);
	}

	if(living(me) && !me->query_temp("noliving") )
		me->add("qi", -neili_gain);
	
	if (exercise_cost > 0)
		return 1;

	me->set_temp("pending/exercise", 0);
	message_vision("$N運功完畢，深深吸了口氣，站了起來。\n", me);
	if ((int)me->query("neili") < (int)me->query("max_neili") * 2)
		return 0;
	else {
		if ((int)me->query("max_neili") > (int)me->query_skill("force") * 10) {
			write("你的內力修為似乎已經達到了瓶頸。\n");
			me->set("neili", (int)me->query("max_neili"));
			return 0;
		}
		else {
			if (max_neili_gain>2) max_neili_gain=2;
			me->add("max_neili", 1+max_neili_gain);
			me->set("neili", (int)me->query("max_neili"));
			write("你的內力增加了！！\n");
			return 0;
		}
	}
}

int halt_exercise(object me)
{
	if ((int)me->query("neili") > (int)me->query("max_neili") * 2)
		me->set("neili", (int)me->query("max_neili") * 2);
	me->set_temp("pending/exercise", 0);
	return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : exercise | dazuo <耗費「氣」的量>

    運氣練功，控制體內的氣在各經脈間流動，藉以訓練人體肌肉骨
骼的耐力、爆發力，並且用內力的形式將能量儲備下來。
    耗費氣的量必須不小於１０。

HELP
        );
        return 1;
}
