// Room: /city/mingren.c
// YZC 1995/12/04 

#include <room.h>

inherit ROOM;
string look_shu();

void create()
{
	set("short", "名人堂");
	set("long", @LONG
這裏就是俠客行一百的名人堂。在這裏供奉的有大俠，也有魔頭，
也有不是大俠不是魔頭的玩家。無論是哪一位，都曾冠絕一時，都有一
個長長而驚心動魄的故事，每一個故事都曾很深遠地影響了一代甚至兩
三代玩家。
    雖然他們都曾經轟轟烈烈掀起滿江湖的風雨，如今，他們再也不會
在江湖出現了。他們都已經退出江湖，但他們的俠影魔蹤很長時間以後
仍是一個傳說。
LONG );

	set("no_fight", "1");
	set("no_beg", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");
	set("no_clean_up", 0);

	set("exits", ([
		"down" : __DIR__"wumiao2",
	]));
	set("objects", ([
		__DIR__"player/abab": 1,
		__DIR__"player/automan": 1,
		__DIR__"player/cnba": 1,
		__DIR__"player/eagleg": 1,
		__DIR__"player/fall": 1,
		__DIR__"player/geng": 1,
		__DIR__"player/laughing": 1,
		__DIR__"player/luoyz": 1,
		__DIR__"player/news": 1,
		__DIR__"player/qinqin": 1,
		__DIR__"player/rewj":1,
		__DIR__"player/shh": 1,
		__DIR__"player/top": 1,
		__DIR__"player/wuqing": 1,
		__DIR__"player/wuxiangxinmo": 1,
		__DIR__"player/xem": 1,
		__DIR__"player/xxqqf": 1,
		__DIR__"player/saite": 1,
		__DIR__"player/noodle": 1,	
	]));
	set("coor/x", 0);
	set("coor/y", 0);
	set("coor/z", 20);
	setup();
	replace_program(ROOM); 
}
