//Room: wdroad7.c
//Date: Feb.12 1998 By Java

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
這裏一條靜悄悄的黃土路，兩旁有些小土屋，疏疏落落的。路上行
人很少，都行色匆匆向前趕路。
LONG);
	set("outdoors", "sanbuguan");
	set("exits", ([
            "east"      : __DIR__"wdroad6",
            "southwest" : __DIR__"wdroad8",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3100);
	set("coor/y", 2000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
