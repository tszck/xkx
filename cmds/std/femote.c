// femote.c
inherit F_CLEAN_UP;

#include "/doc/help.h"
#include <ansi.h>


int help(object me);

int main(object me, string arg)
{
	mapping emote;
	string *e, *loop;
	string result="", msg;

	int i,count=0;

	loop = ({ "others_target", "others_self", "others" });
	if( !arg ) return help(me);
	if( sscanf(arg, "-s %s", arg) )
	{
		emote = EMOTE_D->query_emote(arg);
		result+=emote["myself"]+emote["others"]+emote["myself_self"]+emote["others_self"]+emote["myself_target"]+emote["target"]+emote["others_target"];
		result = replace_string(result, "$n", "(對方)");
		result = replace_string(result, "$N", me->name(1));
		result = replace_string(result, "$P", "你");
		result = replace_string(result, "$p", "(他/她)");
		result = replace_string(result, "$S", RANK_D->query_self(me));
		result=replace_string(result, "$s",RANK_D->query_self_rude(me));
		result = replace_string(result, "$R", "(對方的尊稱)");
		result = replace_string(result, "$r", "(對方的辱稱)");
		result = replace_string(result, "$C", "(自己的呢稱)");
		result = replace_string(result, "$c", "(對方的呢稱)");
		me->start_more(result);
		return 1;
	}

	e = sort_array( EMOTE_D->query_all_emote(), 1);
	for(i=0; i<sizeof(e); i++)
	{
		emote = EMOTE_D->query_emote(e[i]);
		for( int j=0; j<sizeof(loop); j++ )
		{
			msg = emote[ loop[j] ];
			if( msg && strsrch(msg, arg) >=0 )
			{
				result += sprintf("emote 名: %s\n動作: %s\n", e[
i], msg);
				count ++;
			}
		}
	}

	if( result == "" )
		return notify_fail(MUD_NAME" 中無符合查詢條件的 emote.\n");
	else result = "\n查詢結果"
	"\n------------------------------------------------------------\n" + result;
	result = replace_string(result, "$n", "(對方)");
	result = replace_string(result, "$N", me->name(1));
	result = replace_string(result, "$P", "你");
	result = replace_string(result, "$p", "(他/她)");
	result = replace_string(result, "$S", RANK_D->query_self(me));
	result = replace_string(result, "$s", RANK_D->query_self_rude(me));
	result = replace_string(result, "$R", "(對方的尊稱)");
	result = replace_string(result, "$r", "(對方的辱稱)");
	result = replace_string(result, "$C", "(自己的呢稱)");
	result = replace_string(result, "$c", "(對方的呢稱)");

	result += "------------------------------------------------------------\n";
	result += sprintf("在%s中，包含“%s”的 emote 共有 %d 個。\n", MUD_NAME, arg, count );
	me->start_more(result);
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : femote [-s] 關鍵字

    這個命令用來查找符合你需要的內容的emote。
    如果帶參數 -s ，將顯示關鍵字代表的emote的全部內容。
    例如 femote -s hi

    如果不帶參數，列出目前所有含指定關鍵字的 emote。
    例如：femote 英雄   列出所有含有英雄這個字的動作詞。

相關命令 emote, 'help channels'
HELP
	);
	return 1;
}
 
