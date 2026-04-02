inherit ROOM;

void create()
{
	set("short", "朝陽路");
	set("long", @LONG
這是一條東西走向的大道。西邊人聲鼎沸，十分熱鬧。東邊就是朝
陽門。
LONG );
	set("outdoors", "beijing");
	set("exits", ([
		"west" : __DIR__"wangfu2",
		"east" : __DIR__"chaoyang",
	]));
	set("no_clean_up", 0);
	set("coor/x", -170);
	set("coor/y", 4060);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
