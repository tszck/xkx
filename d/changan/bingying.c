// /d/changan/bingyin.c

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "兵營");
	set("long", @LONG
這裏是長安守軍駐紮地，一對官兵正在操練。你最好趕緊走開，不
然被隨便安個罪名關進大牢可不是好玩的。
LONG );
	set("exits", ([
		"west" : __DIR__"northroad2",
	]));
	set("objects", ([
		"/d/city/npc/wujiang" : random(2) + 1,
		"/d/city/npc/bing" : random(2) + 1,
	]));
	set("outdoors", "changan");
	set("coor/x", -5030);
	set("coor/y", 1010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
