// chblk.c
inherit F_CLEAN_UP;

#include <globals.h>


string *blocks_name = ({
	"all",
	"rumor",
	"chat",
	"xkx",
	"sing",
	"party",
	"family",
});
mapping ch_str = ([
	"all"	:	"所有",
	"rumor"	:	"謠言",
	"chat"	:	"聊天",
	"xkx"	:	"俠客行",
	"sing"	:	"歌唱",
	"party"	:	"幫會",
	"family":	"門派",
]);

int main(object me, string arg)
{
	object ob;
	int i;
	string who, ch_name, str;
	
	if (!arg)
	{
		tell_object(me,"目前所有公共頻道的情況如下：\n");
		for (i = 1;i < sizeof(blocks_name);i ++)
		{
			str = "  ";
			str += ch_str[blocks_name[i]];
			str += "頻道：  ";
			if (CHANNEL_D->query_block("all")) str += "關閉";
			else str += CHANNEL_D->query_block(blocks_name[i])?"關閉":"打開";
			str += "\n";
			tell_object(me,str);
		}	
		return 1;
	}

	if (sscanf(arg, "%s %s", who, ch_name) != 2)
	{
		ch_name = "";
		if (sscanf(arg, "%s", who) != 1)
		{
			return notify_fail("<Syntax>: unchblk <player id> <channel name>\n");
		}
	}
	//關閉所有玩家的頻道
	ob = LOGIN_D->find_body(who);
	if (ch_name == "")
	{
		if ( !ob && (member_array(who, blocks_name) == -1))
			return notify_fail("你無法關閉此頻道或此人不在線！\n");
		else if ( !LOGIN_D->find_body(who)) {
			CHANNEL_D->set_block(who, 1);
			CHANNEL_D->do_channel(me, "sys", ch_str[who] + "頻道關閉了。\n");
			return 1;
		}		
	}
	if (!ob) return notify_fail("此人不在線！\n");
	if (wizardp(ob)) return notify_fail("不能關閉巫師的頻道。\n");

	//如果不帶頻道名，則返回該玩家所有頻道情況
	if (ch_name == "" || ch_name == " ") 
	{	
		for (i = 1;i <sizeof(blocks_name);i ++) 
			if ( ob->query("chblk_on") ||
				ob->query("chblk_" + blocks_name[i]) )
				tell_object(me, (string)ob->query("name") + "的" + ch_str[blocks_name[i]] + "頻道是關閉的。\n");
		if (!(ob->query("chblk_on") ||
			ob->query("chblk_rumor") ||
			ob->query("chblk_chat") ||
			ob->query("chblk_xkx") ||
			ob->query("chblk_sing") ||
			ob->query("chblk_family") ||
			ob->query("chblk_party"))) 
		{
			tell_object(me,(string)ob->query("name")+"沒有被關閉的頻道。\n");
		} 
	}
	else
		if ( member_array(ch_name, blocks_name) != -1)
		{
			if (ch_name == "all")
			{
				if ( ob->query("chblk_on"))
					tell_object(me, (string)ob->query("name") + "的所有頻道已經是關閉的。\n");
				else
				{
					ob->set("chblk_on",1);
					tell_object(me, (string)ob->query("name") + "的所有頻道被關閉了。\n");
				}	
			}
			else
				if ( ob->query("chblk_" + ch_name) )
				{
					 tell_object(me, (string)ob->query("name")+"的" + ch_str[ch_name] + "頻道已經是關閉的。\n");
				}
				else
				{
					ob->set("chblk_" + ch_name, 1);
					tell_object(me, (string)ob->query("name")+"的" + ch_str[ch_name] + "頻道被關閉了。\n");
				}
		}
		else 
		{
			return notify_fail("<Syntax>: chblk <player id> <channel name>\n");
		}
		
	return 1;
}

int help(object me)
{
write(@HELP
    指令格式 : chblk <某人> <頻道名>

    此命令將關閉某人的某個頻道。

    如果不加任何參數，將顯示目前所有頻道的情況。
    <頻道名>：可以是rumor、chat、xkx、sing、party、family或all。
    如果不提供頻道名，則顯示某人當前的頻道狀態。 

並且：
chblk rumor  將關閉所有玩家的謠言頻道。
chblk chat   將關閉所有玩家的聊天頻道。
chblk xkx    將關閉所有玩家的俠客行頻道。
chblk sing   將關閉所有玩家歌唱頻道。
chblk party  將關閉所有玩家的幫會頻道。
chblk family 將關閉所有玩家的門派頻道。
chblk all    將關閉所有玩家的所有頻道。

HELP
    );
    return 1;
}

