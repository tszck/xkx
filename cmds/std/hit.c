// fight.c

inherit F_CLEAN_UP;

#include <ansi.h>


int main(object me, string arg)
{
	object obj/*, old_target*/;
	if( environment(me)->query("no_fight") )
		return notify_fail("這裏禁止戰鬥。\n");
	if(me->is_busy())
		return notify_fail("你上一個動作還沒有完成！\n");
	if(!arg || !objectp(obj = present(arg, environment(me))))
		return notify_fail("你想攻擊誰？\n");
	if(me->query("id") != obj->query_temp("bt_ownname") && me->query_temp("bt/working"))
		return notify_fail("你身爲捕快，執行公務，可不能殺良冒功！\n");
//  if ( userp(me) && obj->query("owner") && me->query("id") != obj->query("owner"))
//    return notify_fail("不是你要抓的人，湊什麼熱鬧！\n");
//  if( obj->query("jianxi") && !obj->query_temp("asked") )
//    return notify_fail("不是你要抓的人，湊什麼熱鬧！\n");
	if( !obj->is_character() || obj->is_corpse() )
		return notify_fail("看清楚一點，那並不是生物。\n");

//	if( obj->is_fighting(me) )
//		return notify_fail("加油！加油！加油！\n");

	if( me->is_fighting(obj) )
		return notify_fail("加油！加油！加油！\n");

	if( me->query_temp("hitting") )
		return notify_fail("加油！加油！加油！\n");

	if( !living(obj) || obj->query_temp("noliving") )
		return notify_fail(obj->name() + "已經暈菜了你還打，過分了點吧？\n"); 

	if(obj==me) return notify_fail("打自己？別這麼想不開。\n");

	if((int)obj->query("age") <= 15 && userp(obj))
		return notify_fail("爲了世界更美好，放過小孩子吧。\n");

	notify_fail("此人來頭不小，還是少惹爲妙。\n");
	if (!userp(obj) && !obj->accept_hit(me)) return 0;

	if( userp(obj) ) {
		message_vision("\n$N對着$n大喝一聲：看招！\n\n", me, obj);
		me->set_temp("hitting");
		remove_call_out("do_hit");
		call_out("do_hit", 1, me, obj);
		return 1;
	}

	if( obj->query("can_speak") ) {
		message_vision("\n$N對着$n大喝一聲：看招！\n\n", me, obj);

		me->fight_ob(obj);
		obj->fight_ob(me);
	} else {
		message_vision("\n$N大喝一聲，開始對$n發動攻擊！\n\n", me, obj);
		me->fight_ob(obj);
		obj->kill_ob(me);
	}

	return 1;
}

void do_hit(object me, object obj)
{
	if(objectp(present(obj, environment(me)))) {
		COMBAT_D->do_attack(me, obj, me->query_temp("weapon") );
		COMBAT_D->do_attack(obj, me, obj->query_temp("weapon") );
	}
	me->delete_temp("hitting");
	return;
}

int help(object me)
{
  write(@HELP
指令格式 : hit <人物>
 
    這個指令讓你直接向一個人物「進招」。這種形式的戰鬥是即時的，只要
玩家一敲這個命令，戰鬥就會開始，直到某一方受傷50% 以上爲止。這個指令
對那些不喜歡fight的NPC很有用，因爲很多時候你的比武要求會被拒絕。
 
    其他相關指令: fight, kill

HELP
    );
    return 1;
}
 