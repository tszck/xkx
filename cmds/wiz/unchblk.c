// unchblk.c

inherit F_CLEAN_UP;

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
	string who, ch_name;
	
	if (!arg)
		return notify_fail("<Syntax>: unchblk <player id> <channel name>\n");
	if (sscanf(arg, "%s %s", who, ch_name) != 2)
	{
		ch_name = "";
		if (sscanf(arg, "%s", who) != 1)
		{
			return notify_fail("<Syntax>: unchblk <player id> <channel name>\n");
		}
	}
// 打開所有玩家的頻道 	
    	ob = LOGIN_D->find_body(who);
	if (ch_name == "" && !ob && (member_array(who, blocks_name) == -1))
		return notify_fail("你無法打開此頻道或此人不在線！\n");
//	if (!ob) return notify_fail("此人不在線！\n");
	if (who == "all")
	{
		for (i = 0;i < sizeof(blocks_name);i ++)
			CHANNEL_D->set_block(blocks_name[i],0);
		CHANNEL_D->do_channel(me,"sys","所有頻道	ｏｋａｙ！\n");
		return 1;
	}	
    	for (i = 1;i < sizeof(blocks_name);i ++)
	{
		if (who	== blocks_name[i])
		{
			CHANNEL_D->set_block(who, 0);
			CHANNEL_D->do_channel(me, "sys", ch_str[who] + "頻道ｏｋａｙ！\n");
			return 1;
		}
	}			
	if (ch_name == ""||ch_name == " "||ch_name == "all")
	{	
		if ((int)ob->query("chblk_on") ||
			(int)ob->query("chblk_rumor") ||
			(int)ob->query("chblk_chat") ||
			(int)ob->query("chblk_xkx") ||
			(int)ob->query("chblk_sing") ||
			(int)ob->query("chblk_family") ||
			(int)ob->query("chblk_party"))
                {
			ob->delete("chblk_on");
			for (i = 1;i < sizeof(blocks_name);i ++)
				ob->delete("chblk_" + blocks_name[i]);
			tell_object(me,(string)ob->query("name") + "的所有頻道被打開了。\n");
		}
		else tell_object(me, (string)ob->query("name") + "的所有頻道本來就是開着的。\n");	
	}
	else
		if (member_array(ch_name, blocks_name, 1) != -1)
		{
			if ((int)ob->query("chblk_" + ch_name))
			{
				ob->delete("chblk_on");
				ob->delete("chblk_" + ch_name);
				tell_object(me, (string)ob->query("name") + "的" + ch_str[ch_name] + "頻道被打開了。\n");
			}
			else tell_object(me, (string)ob->query("name") + "的" + ch_str[ch_name] + "頻道本來就是開着的。\n");	
		}
		else 
		{
			return notify_fail("<Syntax>: unchblk <player id> <channel name>\n");
		}
	return 1;
}

int help(object me)
{
write(@HELP
    指令格式 : unchblk <某人> <頻道名>

    此命令將打開某人的頻道。如果沒有頻道名就打開所有合法頻道。
    <某人>　也可以是頻道名。這將打開所有玩家的某個頻道。
    <頻道名> 可以是rumor， chat， xkx， sing， party，family或者all

HELP
    );
    return 1;
}

