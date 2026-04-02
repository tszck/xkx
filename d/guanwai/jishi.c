// /guanwai/jishi.c

inherit ROOM;

void create()
{
	set("short", "集市");
	set("long", @LONG
這裏是城中一片開闊的廣場，乃是來往客商交易毛皮，藥材以及其
它雜物的集市。由於附近方圓百里僅有這麼一個集市，因此這裏的人最
多，貨物也最全。不同的服飾，不同的語言都可以在這裏看到，聽到。
雜亂的人羣中傳出各種吆喝，叫賣的聲音。
LONG );
	set("exits", ([
		"north" : __DIR__"beicheng",
		"south" : __DIR__"nancheng",
		"east"  : __DIR__"dongcheng",
		"west"  : __DIR__"majiu",
	]));
	set("objects", ([
		__DIR__"npc/pihuoshang" : 3,
	]));
//	set("no_clean_up", 0);
	set("outdoors", "guanwai");
	set("coor/x", 6040);
	set("coor/y", 5210);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}