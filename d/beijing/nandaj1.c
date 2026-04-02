// Room: /beijing/nandajie1.c

inherit ROOM;

void create()
{
	set("short", "南大街");
	set("long", @LONG
這裏是南大街。北邊是天安門廣場，南邊是南大街廣場。西邊是一
家店鋪，牆上寫着一個大大的“當”字，仔細傾聽，可以聽到壓低的討
價還價的聲音。東邊是一家小客店。
LONG );
        set("outdoors", "beijing");
	set("exits", ([
		"west" : __DIR__"dangpu",
		"south" : __DIR__"nandaj2",
		"east" : __DIR__"kedian",
		"north" : __DIR__"tian_anm",
	]));
        set("objects", ([
		"/d/shaolin/npc/tiao-fu" : 1,
		__DIR__"npc/xiaofan" : 1,
        ]));
	set("coor/x", -200);
	set("coor/y", 4030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
