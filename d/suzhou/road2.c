// Room: /d/suzhou/road2.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "青石大道");
	set("long", @LONG
你走在一條青石大道上，人來人往非常繁忙，不時地有人騎着馬匆
匆而過。大道兩旁有一些小貨攤，似乎是一處集市。往東面就是號稱天
堂的蘇州城了。
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"west"  : __DIR__"road3",
		"east"  : __DIR__"ximen",
	]));
	set("coor/x", 810);
	set("coor/y", -1010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
