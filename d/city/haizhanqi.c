// /d/city/haizhanqi.c

#include <ansi.h>
inherit  ROOM;
string look_ban();

void create ()
{
	set ("short", "海戰棋室");
	set ("long", @LONG
這裏是很現代氣息的海戰棋室，室中正中是一副大棋盤，上書“擊
水滄海”四字，橫豎擺着一些戰船。牆上釘了一塊小木版 (ban)，密密
麻麻大致寫了徵戰要訣。
LONG);

	set("no_fight",  1);
	set("objects", ([ /* sizeof() == 4 */
		__DIR__"obj/seawar" : 1,
	]));
	set("item_desc", ([ 
		"ban": (: look_ban :),
	]));
	set("exits", ([ /* sizeof() == 1 */
		"southeast" : __DIR__"qiyiting",
	]));
	set("no_clean_up", 0);
	set("coor/x", 19);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
}
string look_ban()
{
        return
"			海戰棋

——[開始遊戲]—————
加入遊戲：join		開始遊戲：start	重置遊戲：reset board
——[船隻佈置]—————
放置船隻：place X座標 Y座標		隨機放置：rplace
取消放置：unplace X座標 Y座標		放置結束：finish
——[火力佈置]—————
放置火力：fire X座標 Y座標		放置結束：finish
取消放置：unfire X座標 Y座標
——[觀戰命令]—————
觀戰命令：visit [-d] 玩家ID		邀請其它玩家觀看遊戲
				加參數-d刪除該玩家的觀看資格
——[遊戲規則]—————
    該遊戲是兩人遊戲。遊戲開始時候，每人有十艘船。
    在準備階段，各人把自己的船放置於自己的棋盤上。當各人都準備
好以後，進入戰鬥階段。
    在戰鬥階段，各人決定攻擊的位置。每一艘船有一次攻擊機會。在
完成攻擊設置以後，進入戰鬥狀態。系統根據雙方的攻擊設置進行攻擊，
當攻擊位置上有敵方船，則可以把對方該船擊毀。被擊毀的船喪失攻擊
能力。
    在所有攻擊結束以後，重新進入攻擊設置。如此循環，直到一方的
船全部被擊毀。\n";
}
