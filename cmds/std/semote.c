// semote.c
// 增加參數功能，使semote命令可以查找開頭部分字母匹配的emote
// Modified by Spacenet@FXLT
inherit F_CLEAN_UP;

#include "/doc/help.h"



int head_index(string str, string index);

int main(object me, string arg)
{
	string *e, str;
	int i;

	e = sort_array(EMOTE_D->query_all_emote(), 1);
	e = filter_array(e, (: head_index :), arg);

	if (sizeof(e)) {
		str = "                        俠客行一百表情動作總彙 \n\n";
		str += "—————————————————————————————————————\n";
		for(i=0; i<sizeof(e); i++)
//			printf("%-15s%s", e[i], (i%5==4)?"\n": "");
			str += sprintf("%-15s%s", e[i], (i%5==4)?"\n": "");
		me->start_more(str);
		write("\n");
		return 1;
	} else return notify_fail("沒有符合指定要求的表情動作。\n");
}

int head_index(string str, string substr)
{
	int i;
	
	for (i = 0; i < sizeof(substr); i ++)
		if (str[i] != substr[i])
			return 0;
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : semote [詞首]

    這個指令可以列出目前所能使用的ｅｍｏｔｅ。如果帶上參數，將列出以
該參數爲詞首的所有ｅｍｏｔｅ，例如：ｓｅｍｏｔｅ ｓｕ，可以列出ｓｕ
開頭的ｅｍｏｔｅ。不跟參數的話將列出全部的ｅｍｏｔｅ。

HELP
	);
	return 1;
}
