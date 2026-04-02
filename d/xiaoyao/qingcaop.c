// qingcaop.c
// Modified by Winder June.25 2000

inherit ROOM;

void create()
{
        set("short", "青草坪");
        set("long", @LONG
這裏是樹林中的一片比較大的空地，名曰：青草坪。因爲處於密林
之中所以這裏平時很少有人來，但是不知道爲什麼，這裏卻經常有人跡
出現。你看，又一個來了。
LONG );
	set("exits", ([
		"north" : __DIR__"xiaodao3",
		"south" : __DIR__"xiaodao5",
		"east" : __DIR__"xiaodao4",
		"west" : __DIR__"xiaodao1",
	]));
	set("outdoors", "xiaoyao");
	set("objects", ([
		CLASS_D("xiaoyao")+"/suxinghe": 1,
//		__DIR__"npc/xue": 1,
	]));
	set("valid_startroom", 1);
//	set("no_clean_up", 0);
	set("coor/x", 80);
	set("coor/y", -500);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
	"/clone/board/xiaoyao_b"->foo();
}