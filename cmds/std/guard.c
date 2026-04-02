// guard.c
// Modified by Spacenet@FLXT 11.30.1999
inherit F_CLEAN_UP;

#include <ansi.h>


mapping default_dirs = ([
	"north":        "北",
	"south":        "南",
	"east":	        "東",
	"west":	        "西",
	"northup":      "北邊",
	"southup":      "南邊",
	"eastup":       "東邊",
	"westup":       "西邊",
	"northdown":    "北邊",
	"southdown":    "南邊",
	"eastdown":	"東邊",
	"westdown":	"西邊",
	"northeast":    "東北",
	"northwest":    "西北",
	"southeast":    "東南",
	"southwest":    "西南",
	"up":           "上",
	"down":	        "下",
	"out":	        "外",
	"in" :          "裏",
	"enter" :       "裏面",
]);

int main(object me, string arg)
{
	string dir;
	object ob, *guards, env;
	mixed old_obj, old_dir; 

	if( me->is_busy() )
		return notify_fail("你現在沒有辦法分心去做這類事！\n");
	if( me->query("jing") < 200 || me->query("qi") < 200 )
		return notify_fail("你現在沒有足夠的精、氣去做這類事！\n");
	old_dir = me->query_temp("guardto");  
	old_obj = me->query_temp("guardfor");  
	env = environment(me);
	if(env->query("no_guard") || env->query("no_fight"))
		return notify_fail("你無法在這裏守護什麼！\n");

	if( !arg || arg=="" )
	{
		if( !old_obj && !old_dir)
			return notify_fail("指令格式：guard <生物> | <物品> | <方向>\n");
		if( objectp(old_obj) )
			if(living(old_obj) && !old_obj->query_temp("noliving"))
				write("你正在守護着"+old_obj->name()+"。\n");
			else
				write("你正守在"+old_obj->name()+"一旁，防止別人拿走。\n");
		else write( "你正把守住往 "+default_dirs[old_dir]+" 的方向，不準任何人離開。\n");
		return 1;
	}

	ob = present(arg, env);
	if( ob )
	{
		if( ob==me )
			return notify_fail("守衛自己？不用說你也會，對吧。\n");
		me->delete_temp("guardto", ob);
		me->set_temp("guardfor", ob);
	}
	else
		if( env->query("exits/" + arg) )
		{
			if( env->query("no_fight") )
				return notify_fail("這裏不準戰鬥，也不準堵住別人去路！\n");
		}
		else
			if( arg == "cancel" )
			{
				if (!old_obj)
					return notify_fail("你本來就沒有守護什麼東西啊。\n");
				write("什麼也不用守護了，真是好輕鬆。\n");
				me->delete_temp("guardfor");
				guards = old_obj->query_temp("guarded");
				guards -= ({ me });
				old_obj->set_temp("guarded", guards);
				return 1;
			}
			else
				return notify_fail("你要守護誰，什麼，或是把守哪個方向？\n");

	if( objectp(old_obj) )
	{
		guards = old_obj->query_temp("guarded");
		guards -= ({ me });
		old_obj->set_temp("guarded", guards);
		if( living(old_obj) && !old_obj->query_temp("noliving") )
		{
			if (old_obj != ob)  
				message_vision("$N不再保護$n了。\n",me,old_obj);
		}
	}
	else
	{
		env->delete("guarded/"+old_dir);
		me->delete_temp("guardto");
		if (old_dir && arg != old_dir)
			message_vision( "$N不再把守"+default_dirs[old_dir]+"這個方向了。\n",me);
		me->enable_path();
	}

	if( objectp(ob) )
	{
		ob->add_temp("guarded", ({ me }) );
		if( living(ob) && !ob->query_temp("noliving") )
		{
			if (ob == old_obj)  
				message_vision("$N正在保護$n。\n", me, ob);
			else message_vision("$N開始保護$n。\n", me, ob);
		}
		else
		{
			if (ob == old_obj)  
				message_vision("$N站到地上的$n一旁守着，以免別人取走。\n", me, ob);
			else message_vision("$N正在守着地上的$n。\n", me, ob);
		}
	}
	else
	{
		if( env->query("guarded/"+arg))
		{
			dir = env->query("guarded/"+arg);
			if( ob = present(dir, env) )
				return notify_fail(HIR+ob->query("name")+"已經擋住了往"+default_dirs[arg]+"去的出路！\n"NOR);
		}
		me->start_busy(1);
		me->set_temp("guardto", arg);
		me->delete_temp("guardfor");
		env->set("guarded/" + arg, me->query("id") );
		if (arg == old_dir)  
			message_vision( "$N正在把守着往" + default_dirs[arg] + "的方向不讓任何人通行。\n", me);
		else
		{
			message_vision( "$N開始把守住往" + default_dirs[arg] + "的方向不讓任何人通行。\n", me);
		}
	}

	return 1;
}

// guarding需耗精氣，因太累將自動結束guard。
// 程序設置在/kungfu/condition/autosaved.c。
int help(object me)
{
	write(@TEXT
指令格式：guard [<某人>|<地上某物>|<某個出口>|cancel]

這個指令有三種作用方式，分別如後：

guard <某人>      保護<某人>，當他／她受到攻擊時，保護者會自動加入戰鬥，並且
                  受攻擊的順位會排在被保護者前面，由於只有攻擊順位前四個目標
                  纔會受到攻擊，因此理論上如果有四個人  guard 你，你就不會受
                  到任何攻擊。

guard <地上某物>  守住放在地上的某件東西，防止別人來拿，只要你還在這個房間，
                  而且沒有忙着其他事，別人就無法拿走這件東西。若你離開後再回
                  來，只要東西還在，那仍將在你守護之下。

guard cancel      取消上述的 guard 對象。

guard <某個出口>  守住某個出口防止所有人從這個出口離開，可以用來阻攔善於逃跑
                  的敵人或攔路打劫做壞事。只要你一移動，guard 的狀態就會解除。

guard             不接任何參數會顯示你目前 guard 的對象。
TEXT
	);
	return 1;
}

