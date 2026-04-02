// vote command..
// Modified by Marz, 04/18/96
inherit F_CLEAN_UP;

#include <net/dns.h>
#include <ansi.h>



// int valid_voters(object me);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object victim;
	string act_name, victim_name;
	string file;
	object file_ob;

	if (((int)me->query("age")<16) && !wizardp(me))
	{
		return notify_fail("民主不是兒戲！小孩子一邊玩去！\n");
	}
	if ((int)me->query("xkx_jail"))
	{
		return notify_fail("你還是老老實實做完牢再說吧！\n");
	}
	if ((int)me->query("vote/deprived"))
	{
		return notify_fail("你想起當初玩弄民主、被剝奪投票權的事，追悔莫及。\n");
	}
	if (!arg || sscanf(arg, "%s %s", act_name, victim_name) != 2)
	{
		return notify_fail("這神聖的一票，要想清楚了才能投。\n");
	}
	victim = find_player(victim_name);
	if (!victim) victim = LOGIN_D->find_body(victim_name);
	if (!victim || !me->visible(victim) || victim->query("no_look_wiz"))
		return notify_fail("你要投誰的票？\n");
	if (wizardp(victim) && !victim->query("no_look_wiz")) return notify_fail("你要投巫師的票？\n");
		
	if( !stringp(file = (string)"/cmds/std/vote/"+act_name)
		|| file_size(file + ".c") <= 0 )
			return notify_fail("你要投票幹什麼？\n");
	
	if ( !(file_ob = find_object(file)) ) file_ob = load_object(file);
	
	if ((int)file_ob->vote(me, victim) <= 0)
	{
		if ((int)me->query("vote/abuse")> 50)
		{
			write( HIG "你因爲胡亂投票，投票權被剝奪了！\n" NOR);

//			me->set("xkx_jail", 1);
			me->set("vote/deprived", 1);
			me->apply_condition("vote_suspension", 120);
			me->delete("vote/abuse");
// 			me->move("/d/city/jail");
		}	
		return 0;
	};
	
	return 1;
}


string *valid_voters(object me,object victim)
{
	object *list;
//	int d = 0;
	int j;
	string *adds=({});
	string ip;

	list = users();
	j = sizeof(list);
	while( j-- )
	{
		// Skip those users in login limbo.
		if( !environment(list[j]) ) continue;
		if( !me->visible(list[j]) ) continue;
		if (((int)list[j]->query("age")<16) && !wizardp(list[j])) continue;
		if ((int)list[j]->query("vote/deprived")) continue;
		ip = query_ip_name(list[j]);
		if (member_array(ip,adds)==-1)
		 adds += ({ip});
	}
	return adds;
}


int help(object me)
{
	write(@HELP
指令格式 : vote <動議> <某人> 

    此命令提議對某人採取行動，由大家投票決定。可是如果五分鐘內沒有
人附議，投票會自動取消。當前可以有如下<動議>：

chblk:   關閉某人交談頻道，需三票以上的簡單多數同意。
unchblk: 打開某人交談頻道，需三票以上的三分之一票數同意。
jail:    將某人送進監獄，需三票以上的簡單多數同意。
unjail:  將某人放出監獄，需三票以上的簡單多數同意。

HELP
	);
	return 1;
}

/**
future motion (not implemented yet):
eject: 驅逐某人，需三票以上的簡單多數同意。
robot: 懷疑某人是機器人，如果有五人附議，則由系統審訓被懷疑者。
jail: 將某人送進監獄，需三票以上的簡單多數同意。
**/