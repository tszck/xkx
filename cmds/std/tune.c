// tune.c
// Modified by zeratul,2000.1.14

inherit F_CLEAN_UP;

mapping channel_name = ([
	"sys"  :        1,
	"snp"  :        1,
	"debug":        1,
	"wiz"  :        1,
	"gwiz" : 	1,
	"qst"  :  1,
	"rumor":        0,
	"chat" :        0,
	"xkx"  :        0,
	"sing" :        0,
	"party":        0,
	"snow" :        0,
	"es"   :	0,	
]);

int main(object me, string arg)
{
	string *tuned_ch, chinese_name;
	int i;

	tuned_ch = me->query("channels");
	if( !arg )
	{
		if( !pointerp(tuned_ch) || !sizeof(tuned_ch) )
			write("你現在並沒有收聽任何頻道。\n");
		else
			write("你現在收聽的頻道：" + implode(tuned_ch, ", ") + "。\n");
		return 1;
	}

	switch (arg)
	{
		  case "sys" 	: chinese_name = "系統"; break;
		  case "snp" 	: chinese_name = "監聽"; break;
		  case "debug"	: chinese_name = "調試"; break;
		  case "wiz"	: chinese_name = "巫師"; break;
		  case "gwiz"	: chinese_name = "網際巫師"; break;
		  case "qst"  : chinese_name = "任務"; break;
		  case "rumor"	: chinese_name = "謠言"; break;
		  case "chat"	: chinese_name = "閒聊"; break;
		  case "xkx"	: chinese_name = "俠客行"; break;
		  case "sing"	: chinese_name = "歌唱"; break;
		  case "party"	: chinese_name = "門派"; break;
		  case "es"	: chinese_name = "網際閒聊"; break;
		  case "snow": chinese_name = "風聞"; break;
	}	
	if( pointerp(tuned_ch) && member_array(arg, tuned_ch)!=-1 )
	{
		tuned_ch -= ({ arg });
		me->set("channels", tuned_ch);
		write("關閉" + chinese_name + "頻道。\n");
		return 1;
	}
	else
		if ( !undefinedp(channel_name[arg]))
		{
			if (!wizardp(me) && channel_name[arg])
				return notify_fail("你沒有使用這個頻道的權力。\n");
			tuned_ch += ({ arg });
			me->set("channels",tuned_ch);
			write("打開" + chinese_name + "頻道。\n");
			return 1;
		}

	if ( arg == "on" )
	{
		tuned_ch = ({ });
		for ( i = 0; i < sizeof(channel_name); i++ )
			if ( (!wizardp(me) && !values(channel_name)[i]) ||
				wizardp(me) )
				tuned_ch += ({ keys(channel_name)[i] });
		me->set("channels", tuned_ch);
		write("已打開所有頻道。\n");
		return 1;
	}
	if ( arg == "off" )
	{
		tuned_ch = ({ });
		me->set("channels", tuned_ch);
		write("已關閉所有頻道。\n");
		return 1;
	}

	return notify_fail("有這個頻道嗎？\n");
}

int help(object me)
{
	write(@HELP
指令格式：tune [<頻道名稱> | on | off]

    這個指令讓你選擇是否要收聽某一頻道的訊息，如果沒有指定頻
道名稱，就會列出你目前收聽中的頻道，如果指定了頻道，原來收聽
中的就會關掉，反之打開。
    用 tune on|off 可以打開或關閉所有頻道。

如果你對一個沒有收聽中的頻道講話，會自動將它打開。
要對一個頻道講話，只要用：

<頻道名稱> <訊息> ....

例子：
     chat hello everyone!

你可以用 help channels 查詢目前有哪些頻道可以收聽。

see also : shout
HELP
	);
	return 1;
}

