// Room: tidujie.c
// Date: Feb.14 1998 by Java

inherit ROOM;
void create()
{
	set("short", "提督街");
	set("long", @LONG
提督街就是因為通往提督府而得名。這一帶來往行人很少，做生意
的就更是絕跡了。提督大人好象有甚麼想不開的，派了好多兵在這裏守
衞，連江湖人物都不敢輕率踏入。
LONG );
	set("outdoors", "chengdu");
	set("exits", ([
		"west"  : __DIR__"nanjie2",
		"north" : __DIR__"tidugate",
	]));
	set("objects", ([
		__DIR__"npc/bing" : 3,
	]));
	set("coor/x", -8040);
	set("coor/y", -3020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
