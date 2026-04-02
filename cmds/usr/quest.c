// /cmds/usr/quest.c

#include <ansi.h>
#include <quest.h>

//inherit F_CLEAN_UP;

mapping quest;
string time_period(int timep );
string quest_msg( object who, string quest_id );

int main(object me, string arg)
{
	int nowtime = time();
	string quest_list = "";
	string msg;
	object who = this_player();

	if ( stringp(arg) )
	{
		who = find_player( arg );
		if ( !objectp(who) || !me->visible(who))
			return notify_fail( "你想查看誰的任務？\n" );
		if ( who->query("id") != me->query("id") && !wizardp(me) )
			return notify_fail( "只有巫師才能查看別人的任務！\n" );
	}

	msg = quest_msg( who, "wei" );
	quest_list += msg;
	if ( msg != "" && !quest["finished"] && !quest["lock"] )
	{
		quest_list += HIC;
		quest_list += quest["quest_type"]+"『"+quest["quest"]+"』。\n		";
		nowtime = quest["time"] - time();
		quest_list += time_period( nowtime );
		quest_list += "\n\n"NOR;
	}

	msg = quest_msg( who, "shan" );
	quest_list += msg;
	if ( msg != "" && !quest["finished"] && !quest["lock"] )
	{
		quest_list += HIC;
		quest_list += quest["quest_type"] + "『" + quest["quest"] + "』。\n		";
		nowtime = quest["time"] - time();
		quest_list += time_period( nowtime );
		quest_list += "\n\n"NOR;
	}

	msg = quest_msg( who, "helian" );
	quest_list += msg;
	if ( msg != "" && !quest["finished"] && !quest["lock"] )
	{
		quest_list += HIC;
		quest_list += quest["quest_type"] + "『" + quest["quest"] + "』。\n		";
		nowtime = quest["time"] - time();
		quest_list += time_period( nowtime );
		quest_list += "\n\n"NOR;
	}

	msg = quest_msg( who, "book" );
	quest_list += msg;
	if ( msg != "" && !quest["finished"] && !quest["lock"] )
	{
		quest_list += HIC;
		quest_list += "查找在『" + quest["dest"] + "』一帶的" + quest["book"] + "。\n		";
		nowtime = quest["time"] - time();
		quest_list += time_period( nowtime );
		quest_list += "\n\n"NOR;
	}

	msg = quest_msg( who, "betrayer" );
	quest_list += msg;
	if ( msg != "" && !quest["finished"] && !quest["lock"] )
	{
		quest_list += HIC;
		quest_list += "剷除在『" + quest["dest"] + "』一帶活動的『" + quest["name"] + "』。\n		";
		nowtime = quest["time"] - time();
		quest_list += time_period( nowtime );
		quest_list += "\n\n"NOR;
	}

	msg = quest_msg( who, "thief" );
	quest_list += msg;
	if ( msg != "" && !quest["finished"] && !quest["lock"] )
	{
		quest_list += HIC;
		nowtime = quest["time"] - time();
		quest_list += time_period( nowtime );
		quest_list += "\n\n"NOR;
	}

	msg = quest_msg( who, "kill" );
	quest_list += msg;
	if ( msg != "" && !quest["finished"] && !quest["lock"] )
	{
		quest_list += HIC;
		quest_list += "殺了在『" + quest["place"] + "』一帶出現的『" + quest["name"] + "』。\n		";
		nowtime = quest["time"] - time();
		quest_list += time_period( nowtime );
		quest_list += "\n\n"NOR;
	}

	if ( quest_list != "" )
	{
		write( "\n你目前的部分任務：\n\n" );
		write( HIC"≡"HIY"------------------------------------------------------------"HIC"≡\n\n"NOR );
 		write( quest_list );
 		write( HIC"≡"HIY"------------------------------------------------------------"HIC"≡\n\n"NOR );
 	}
 	else
 		write( HIW"\n你現在沒有任何任務！\n\n"NOR );

	return 1;
}

string time_period( int timep )
{
	int t, d, h, m, s;
	string time;
	t = timep;
	s = t % 60;	     t /= 60;
	m = t % 60;	     t /= 60;
	h = t % 24;	     t /= 24;
	d = t;

 	if ( timep <= 0 )
 		return WHT"你已經沒有足夠的時間來完成它了。"NOR;
	if(d) time = chinese_number(d) + "天";
	else time = "";

	if(h) time += chinese_number(h) + "小時";
	if(m) time += chinese_number(m) + "分";
	time += chinese_number(s) + "秒";
	return "你還有" + time + "去完成它。";
}

string quest_msg( object who, string quest_id )
{
	string msg = "";

	if ( quest = who->query( "quest/" + quest_id ) )
	{
		msg += HIY"〖" + quest_name[quest_id] + "〗	"NOR;
		if ( quest["lock"] )
			msg += "你得先完成若干個"HIY + quest_name[quest["lock"]] + NOR"任務才能繼續這個任務。\n\n";
		else
			if ( quest["finished"] )
				msg += "恭喜你，你已經完成了這項任務！\n\n";
	}
	return msg;
}

int help(object me)
{
	write(@HELP
指令格式 : quest
	   quest <對象名稱>		(巫師專用)

    這個指令可以顯示出自己或指定對象當前任務的相關信息。
HELP
	);
	return 1;
}
