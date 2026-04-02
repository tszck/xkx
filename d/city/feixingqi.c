// /d/city/feixingqi.c

#include <ansi.h>
inherit  ROOM;
string look_ban();

void create ()
{
	set ("short", "飛行棋室");
	set ("long", @LONG
這裏是飛行棋室，室中正中是一副雕花紅木大棋盤，上書“翱翔蒼
穹”四字，橫豎擺着一些戰機。牆上釘了一塊小木版 (ban)，用紅字綠
線勾畫了遊戲玩法。
LONG);

	set("no_fight",  1);
	set("objects", ([ /* sizeof() == 4 */
		__DIR__"obj/flyer" : 1,
	]));
	set("item_desc", ([ 
		"ban": (: look_ban :),
	]));
	set("exits", ([ /* sizeof() == 1 */
		"southwest" : __DIR__"qiyiting",
	]));
	set("no_clean_up", 0);
	set("coor/x", 21);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
}
string look_ban()
{
        return
"			飛行棋

——[開始遊戲]—————
加入遊戲：join　　　　　
開始遊戲：start
重置遊戲：reset qi

——[遊戲命令]—————
　搖骰子：toss
查看情況：view
移動棋子：move a|b|c|d
催促玩家：next

——[遊戲規則]—————
    飛行棋，大家打小就都玩過，丟骰子就是，丟出六來才能起飛，別
的也不用多說了吧？\n";
}
