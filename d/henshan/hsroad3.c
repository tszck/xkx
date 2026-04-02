// Room: /d/henshan/hsroad3.c 黃土路
// Modified by Java on Feb.14.1998

inherit ROOM;

void create()
{
	set("short", "黃土路");
	set("long", @LONG
你走在一條塵土飛揚的黃土路上，兩旁是陰森森的樹林。西面不遠
就是衡陽縣城了。
LONG );
	set("outdoors", "hengyang");

	set("exits", ([
		"northeast": __DIR__"hsroad2",
		"west"     : __DIR__"hengyang",
	]));

	set("no_clean_up", 0);
	set("coor/x", -200);
	set("coor/y", -1200);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}