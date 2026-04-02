// tell.c
inherit F_CLEAN_UP;

#include <mudlib.h>
#include <ansi.h>
#include <net/dns.h>
#include <net/daemons.h>
#include <net/macros.h>
#define NEW_PERIOD 32400


int help(object me);

void create() {seteuid(getuid());}

int main(object me, string arg)
{
	string target, msg, mud;
	object obj;
	string name, refuse_name;
	mapping mud_list;
	string *clist=({});
	
	if( !arg || sscanf(arg, "%s %s", target, msg)!=2 ) return help(me);
/*
	if(me->query("channel/tell_block"))
		return notify_fail("你的頻道被關了！\n");
	if((int)me->query("mud_age") < NEW_PERIOD)
		return notify_fail("你只可以使用（say）。\n");
*/
//added by lion,首先判斷請求發送的MUD不能是自己,而且已經連接.

	if( sscanf(target, "%s@%s", target, mud)==2 ) 
	if(mud!=INTERMUD_NAME)
	{
		if( !find_object(DNS_MASTER) )
		return notify_fail("網路精靈並沒有被載入，不能向外發信息。\n");
		mud_list = (mapping)DNS_MASTER->query_muds();
		if(!mud_list)
			return notify_fail( MUD_NAME + "目前還沒有跟網路上其他 Mud 取得聯繫。\n");		
		mud = htonn(mud);
		if(!mapp( mud_list[mud] )) 
			return notify_fail(MUD_NAME + "並沒有和"+mud+"取得聯繫，請用mudlist命令查看。\n");
    if (mud != mud_nname())      
//判斷完畢,開始向mud發請求.		
		{
			GTELL->send_gtell(mud, target, me, msg);
		  write("網路訊息已送出，可能要稍候才能得到回應。\n");
		 return 1;
    }
	}

	obj = find_player(target);
	if(!obj || !me->visible(obj))
		return notify_fail("沒有這個人....。\n");
	name = (string) me->query("id");
	refuse_name = (string) obj->query("env/no_tell");
	if (stringp(obj->query("env/can_tell")))
	clist = explode(obj->query("env/can_tell"),",");
	if( !wizardp(me) && (refuse_name == "all" || refuse_name == name)
	 && (!arrayp(clist) || member_array(name,clist)==-1))
		return notify_fail(obj->query("name")+"不想聽你嘰嘰歪歪。\n");
	write(HIG "你告訴" + obj->name(1) + "：" + msg + "\n" NOR);
	tell_object(obj, sprintf( HIG "%s告訴你：%s\n" NOR,
		me->name(1)+"("+me->query("id")+")", msg));
	if (stringp(obj->query("env/auto_reply")) && query_idle(obj) > 60)
	tell_object(me,HIW"(自動回覆)"NOR+obj->name()+"回答你："+obj->query("env/auto_reply")+"\n");
	message("channel:snp", HIB"【監聽】"+me->query("name")+"告訴"+obj->query("name")+"："+msg+"\n"NOR, users());

	obj->set_temp("reply", me->query("id"));
	return 1;
}

//changed by lion@xjtufy3
string remote_tell(string cname, string from, string mud, string to, string msg)
{
	object ob;

	if( ob = find_player(to) )
	{
		if(wizardp(ob) && ob->query("env/invisibility"))
			return "現在找不到這個人。"; //respond no such user.
		if( ob->query("env/no_tell") ) return
			ob->query("name")+"現在不想聽你嘰嘰歪歪。";
		if(!living(ob) || ob->query_temp("noliving") ||
			ob->query_temp("netdead")) 
			return ob->query("name")+"現在聽不見你説的話。\n";
		if( cname )
			tell_object(ob, sprintf(HIG "%s(%s@%s)告訴你：%s\n" NOR, cname, capitalize(from), mud, msg ));
		else
			tell_object(ob, sprintf(HIG "%s@%s 告訴你：%s\n" NOR, capitalize(from), mud, msg ));
		ob->set_temp("reply", lower_case(from) + "@" + mud);
		return ob->query("name")+"收到了你的消息。";
// if succeed, return target's name.
	} else return "現在找不到這個人。";
}

int help(object me)
{
	write(@HELP
指令格式：tell <某人> <訊息>

    你可以用這個指令和其他地方的使用者説話。

其他相關指令：reply
HELP
	);
	return 1;
}

