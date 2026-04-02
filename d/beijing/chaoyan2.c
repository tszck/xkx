inherit ROOM;

void create()
{
	set("short", "朝陽路");
	set("long", @LONG
這是一條青石路，一路走來見不到幾個行人。東南邊是東門。朝陽
門在西北邊。
LONG );
	set("outdoors", "beijing");
	set("exits", ([
		"northwest" : __DIR__"chaoyang",
		"southeast" : __DIR__"dongmen",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}


