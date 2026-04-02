// Room: /d/nanshaolin/sblu-3.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "石板路");
	set("long", @LONG
一條青石鋪成的小路向西，北，東三個方向蜿蜒而去。石路上絕無
半點塵土，看來經常有人來打掃。路的兩旁中滿的翠綠的青竹，在微風
中左右搖曳，沙沙做響。北面是受戒的戒壇。
LONG );
	set("exits", ([
		"south"     : __DIR__"sblu-2",
		"northwest" : __DIR__"jietan1",
		"northeast" : __DIR__"jietan2",
	]));
	set("outdoors", "nanshaolin");
	set("no_clean_up", 0);
	set("coor/x", 1820);
	set("coor/y", -6140);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}

