// /guanwai/longmen.c

inherit ROOM;

void create()
{
	set("short", "龍門峯");
	set("long", @LONG
龍門峯在乘槎河西岸，因狀如門形，故名龍門。崇崖峻壁，形態奇
特，宛如臥龍吸水，傳説大禹治水曾到此峯，旁有蝌蚪形石柱。
LONG );
	set("exits", ([
		"northeast" : __DIR__"damen",
		"west"      : __DIR__"luming",
		"east"      : __DIR__"tianhuo",
		"southdown" : __DIR__"tianchi1",
	]));
	set("no_clean_up", 0);
	set("outdoors", "changbai");
	set("coor/x", 6190);
	set("coor/y", 5180);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}