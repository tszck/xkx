// Room: /d/5lt/fbzhongxin.c
inherit ROOM;

#include <ansi.h>

string look_board();

void create()
{
	set("short", "新聞發佈中心");
	set("long", @LONG
這裏是新聞發佈中心，所有無釐頭電視臺的新聞和記者招待會都是
這裏第一時間發佈出去的。這裏金光閃閃的，比起CCTV強多了，對面的
牆上有一個很大的電子通告牌(board)，裏頭滾動播放着最新的新聞。
LONG);
	set("outdoors", "5lt");
	set("exits", ([
		"west"     : __DIR__"dating",
	]));
	set("item_desc",([
		"board"		:	(: look_board :),
	]));
	set("no_fight", 1);
	set("no_clean_up", 0);
	set("coor/x", -175);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
}

string look_board()
{
	return
	"********	"HIY"電子公告牌:"NOR"			********\n"
	"********	五月天來廈,祕會緋聞女友。	********\n"
	"********	謠言：據説某人戀愛了。		********\n";
}
