// fight.c
inherit F_CLEAN_UP;

#include <ansi.h>



int main(object me, string arg)
{
	object obj, old_target;

	if( me->is_busy())
		return notify_fail("你上一個動作還沒有完成！\n");
	if( environment(me)->query("no_ansuan") )
		return notify_fail("這裏禁止戰鬥。\n");
	if( environment(me)->query("no_fight") )
		return notify_fail("這裏禁止戰鬥。\n");
	if( !arg || !objectp(obj = present(arg, environment(me))))
		return notify_fail("你想攻擊誰？\n");
	if( !obj->is_character() )
		return notify_fail("看清楚一點，那並不是生物。\n");
	if( obj->is_fighting(me) )
		return notify_fail("加油！加油！加油！\n");
	if( !living(obj) || obj->query_temp("noliving") )
		return notify_fail(obj->name() + "已經無法戰鬥了。\n"); 
	if(obj==me) return notify_fail("你不能攻擊自己。\n");

	if( userp(obj) && (object)obj->query_temp("pending/fight")!=me )
	{
		message_vision("\n$N對着$n説道：" + RANK_D->query_self(me) + me->name() + "，領教" + RANK_D->query_respect(obj) + "的高招！\n", me, obj);
		if( objectp(old_target = me->query_temp("pending/fight")) )
			tell_object(old_target, YEL + me->name() + "取消了和你比試的念頭。\n" NOR);
		me->set_temp("pending/fight", obj);
		tell_object(obj, YEL"如果你願意和對方進行比試，請你也對" + me->name() + "("+(string)me->query("id")+")"+ "下一次 fight 指令。\n" NOR);
		write(YEL"由於對方是由玩家控制的人物，你必須等對方同意才能進行比試。\n" NOR);
		return 1;
	}
	if( obj->query("can_speak") )
	{
		message_vision("\n$N對着$n説道：" + RANK_D->query_self(me) + me->name() + "，領教" + RANK_D->query_respect(obj) + "的高招！\n", me, obj);
		notify_fail("看起來" + obj->name() + "並不想跟你較量。\n");
		if( !userp(obj) && !obj->accept_fight(me) ) return 0;

		me->fight_ob(obj);
		obj->fight_ob(me);
	} else {
		message_vision("\n$N大喝一聲，開始對$n發動攻擊！\n\n", me, obj);
		me->fight_ob(obj);
		obj->kill_ob(me);
	}

	return 1;
}
int help(object me)
{
	write(@HELP
指令格式 : fight <人物>

    這個指令讓你向一個人物“討教”或者是“切磋武藝”，這種形式的戰鬥
純粹是點到為止，直到有一方的氣降低到一半為止，因此只會消耗體力，不會
真的受傷，但是並不是所有的ＮＰＣ都喜歡打架，因此有許多狀況下你的比武
要求會被拒絕。如果對方不願意接受你的挑戰，你仍然可以強行用ｈｉｔ或者
ｋｉｌｌ等等指令開始戰鬥（甚至ｓｔｅａｌ指令，如果行竊失敗也會導致戰
鬥）。要注意的是動物，因為不通人言，所以它們會對任何攻擊施以死亡性報
復，而且許多動物是攻擊性的，會見人就殺。
 
其他相關指令: kill, hit

    如果對方不願意接受你的挑戰，你仍然可以直接用 kill 指令開始戰鬥。
HELP
	);
	return 1;
}
 
