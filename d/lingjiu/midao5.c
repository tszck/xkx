// midao5.c

inherit ROOM;

void create()
{
	set("short", "密道");
	set("long", @LONG
你走着走着，突然發現你迷失了方向，你往回走的時候卻發現那已
不是你來的道路了，你不禁心中一陣發麻。突然你在昏黃的燈光下，隱
約發現兩邊的漢白玉牆壁上刻着一些奇形怪狀的符號(fuhao)。
LONG );
	set("exits", ([
		"south" : __FILE__,
		"north" : __DIR__"midao6",
		"east" : __DIR__"midao13",
		"west" : __DIR__"midao14",
	]));
	set("no_clean_up", 0);
	set("coor/x", -50900);
	set("coor/y", 30180);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}