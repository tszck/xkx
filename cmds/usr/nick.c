// nick.c
inherit F_CLEAN_UP;

#include <ansi.h>



int main(object me, string arg)
{
	if( !arg ) return notify_fail("你要替自己取什麼綽號？\n");
	if( arg == "none" )
	{
		me->delete("nickname");
		write("你的綽號取消了。\n");
		return 1;
	}
	if( !wizardp(me) && strwidth(arg) > 30 )
		return notify_fail("你的綽號太長了，想一個短一點的、響亮一點的。\n");

	arg = replace_string(arg, "$BLK$", BLK);
	arg = replace_string(arg, "$RED$", RED);
	arg = replace_string(arg, "$GRN$", GRN);
	arg = replace_string(arg, "$YEL$", YEL);
	arg = replace_string(arg, "$BLU$", BLU);
	arg = replace_string(arg, "$MAG$", MAG);
	arg = replace_string(arg, "$CYN$", CYN);
	arg = replace_string(arg, "$WHT$", WHT);
	arg = replace_string(arg, "$HIR$", HIR);
	arg = replace_string(arg, "$HIG$", HIG);
	arg = replace_string(arg, "$HIY$", HIY);
	arg = replace_string(arg, "$HIB$", HIB);
	arg = replace_string(arg, "$HIM$", HIM);
	arg = replace_string(arg, "$HIC$", HIC);
	arg = replace_string(arg, "$HIW$", HIW);
	arg = replace_string(arg, "$NOR$", NOR);

	me->set("nickname", arg + NOR);
	write("你取好了綽號。\n");
	return 1;
}
int help(object me)
{
	write(@HELP
指令格式 : nick <外號, 綽號> | none

    這個指令可以讓你爲自己取一個響亮的名號或頭銜，nick none
取消綽號。你如果希望在綽號中使用ansi的控制字元改變顏色，可以
用以下的控制字串：（其中系統自動會在字串尾端加一個 $NOR$）

        $ＢＬＫ$：[30m黑色[0m
        $ＲＥＤ$：[31m紅色[0m          $ＨＩＲ$：[1;31m亮紅色[0m
        $ＧＲＮ$：[32m綠色[0m          $ＨＩＧ$：[1;32m亮綠色[0m
        $ＹＥＬ$：[33m土黃色[0m        $ＨＩＹ$：[1;33m黃色[0m
        $ＢＬＵ$：[34m深藍色[0m        $ＨＩＢ$：[1;34m藍色[0m
        $ＭＡＧ$：[35m淺紫色[0m        $ＨＩＭ$：[1;35m粉紅色[0m
        $ＣＹＮ$：[36m藍綠色[0m        $ＨＩＣ$：[1;36m天青色[0m
        $ＷＨＴ$：[37m淺灰色[0m        $ＨＩＷ$：[1;37m白色[0m
        $ＮＯＲ$：[0m恢復正常顏色[0m

HELP
	);
	return 1;
}
