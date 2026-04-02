// bobing2.c 東搏餅屋
// Last Modified by winder on Sep. 22 2002

#include <room.h>
#include <ansi.h>
//inherit ROOM;
inherit __DIR__"bobing.c";

void create()
{
	set("roomname","東間搏餅屋");
	set("no_fight","1");
	set("no_magic","1");
	set("no_steal","1");
	set("no_beg","1");
	set("short","東搏餅屋");
	set("long", @LONG
這是一間古樸典雅的的搏餅屋。房間的裝修充滿了盛明時候的風味，
滿屋子的琳琅玉石襯着柔和的光線，洋溢着溫馨的氣氛，真是個溫暖而
熱鬧的地方。房間的四周點着一溜松明子，中間一張楠木桌，大家都席
地而坐 (sit)，看着桌面上一個大海碗，碗裏面滴溜溜轉着六顆玉製的
骰子！南邊的牆上貼着一張發黃的陳紙(paper)。
LONG);
	set("item_desc", ([
		"paper" : "介紹和命令請 help bobing。\n",
	]));
	set("objects",([
		__DIR__"npc/dog":1,
	]));
	set("exits", ([
		"west" : __DIR__"bobingting",
	]));
	set("no_clean_up",1);
	set("coor/x", 19);
	set("coor/y", 9);
	set("coor/z", 0);
	setup();
}