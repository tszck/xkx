// /d/city/dahuashaizi.c

#include <ansi.h>
inherit  ROOM;
string look_ban();

void create ()
{
	set ("short", "大話骰子屋");
	set ("long", @LONG
這裏是大話骰子屋，屋子中間擺着一個大案臺，案檯面上，用草字
刻着“吹牛不要本錢”字樣。案臺上有兩個竹筒，覆筒下面各有五個骰
子，酒酣耳熱之後，儘可“大話”一番。牆上釘了一塊小木版 (ban)，
密密麻麻大致寫了基本玩法。
LONG);

	set("no_fight",  1);
	set("objects", ([ /* sizeof() == 4 */
		__DIR__"obj/dahuashaizi" : 1,
	]));
	set("item_desc", ([ 
		"ban": (: look_ban :),
	]));
	set("exits", ([ /* sizeof() == 1 */
		"southwest" : __DIR__"shaiziting",
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
"			大話骰子

——[開始遊戲]—————
加入遊戲：join	開始遊戲：start	重置遊戲：reset se
——[遊戲命令]—————
搖骰子：toss	查看骰子：view [玩家ID]
準備結束：finish/deal
拆穿大話：dahua [玩家ID]
猜測骰子：guess 骰子數量 骰子點數
　　　　　或者 g 骰子數量 骰子點數
催促玩家：next
——[其它命令]—————
計數器：showc	猜測日誌：history
——[旁觀命令]—————
觀戰命令：visit [-d] 玩家ID
                邀請其它玩家觀看你的遊戲。
                加參數 -d 表示刪除該玩家的觀看資格。
——[遊戲規則]—————
    這個遊戲，凡是上過酒吧、歌廳的，都應該玩過。不多說啦，
很考驗智慧的。\n";
}
