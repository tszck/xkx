// /d/city/majiangroom1.c

#include <ansi.h>
inherit ROOM;

void create ()
{
	set("short", "麻將西場");
	set("long", @LONG
這是一間麻將室，吵吵囔囔聚了一大堆人。房間中央是一張雕邊釉
面方桌(table) ，每邊都有一張紅木錦墊雕背椅，坐(sit) 上去玩起麻
將來挺舒坦的。椅子邊上都有一個小茶几，擺着喫的喝用的，大概幾個
通宵不挪窩是沒啥問題了。這裏雖然和外間陳設一樣，可是有三個絕代
佳人陪你同樂，實是難得。
    牆上貼了一張小帖子(tie)。
LONG);
	set("item_desc",  ([
		"tie" :
HIY"  指  令        例          子              説    明"HIC"
┌----------------------------------------------------┐
│ sit       ----------                          入局 │
│ look      l mj或.看自己牌,l 1p或.1看玩家1的牌      │
│           l all或..看全部,l end看流局l dump。 看牌 │
│ mo        如果剛摸完就按會打掉剛摸的牌        摸牌 │
│ da        da <代碼>。                         打牌 │
│ chi       chi <代碼1> <代碼2>。               喫牌 │
│ peng      ----------                          碰牌 │
│ gang      gang 或 gang <代碼>(暗槓用)。       槓牌 │
│ hu                                            胡牌 │
│ setmj     請看桌面                        設定參數 │
│ start     ----------                      牌局開始 │
│ restart   restart 或 restart mj。         重新開始 │
│ continue  催NPC或玩家出牌，特殊情況時特別有用。    │
│ top                                         查戰績 │
└----------------------------------------------------┘
"NOR,
		"table" : "
                       基  本  設  定
            setmj 可用的有自動胡、槓 、碰、聽、顯式方法。
--------------------------------------------------------------------
例子1: setmj peng 1w    設定會自動碰1w 當別人打出一萬時會自動碰一萬。
       setmj gang 1w    設定會自動槓1w 當別人打出一萬時會自動槓一萬。
       setmj ting 1w    設定會自動聽1w 當別人打出一萬時會自動胡一萬。
例子2: setmj show 代碼  設定為只顯示代碼。
       setmj show color 設定為彩色顯示。
例子3: setmj ting none  取消會自動胡牌設定。
       setmj gang none  取消會自動槓牌設定。
       setmj peng none  取消會自動碰牌設定。
例子4: setmj auto ting  設定自動聽牌。
--------------------------------------------------------------------
"
	]));
	set("exits", ([
		"east" : __DIR__"majiangting",
	]));

	set("objects", ([
		__DIR__"npc/east"  :  1,
		__DIR__"npc/west"  :  1,
		__DIR__"npc/south"  :  1,
		__DIR__"npc/majiang"  :  1,
	]));

	set("no_fight",  1);
	set("no_beg",  1);
	set("no_steal", 1);
	set("no_clean_up",  1);
	set("coor/x", 22);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
}
