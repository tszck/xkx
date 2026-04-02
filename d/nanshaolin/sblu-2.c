// Room: /d/nanshaolin/sblu-2
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "石板路");
	set("long", @LONG
一條青石鋪成的小路向西，北，東三個方向蜿蜒而去。石路上絕無
半點塵土，看來經常有人來打掃。路的兩旁中滿的翠綠的青竹，在微風
中左右搖曳，沙沙做響。東面似乎有輕微的水流聲傳到你的耳中。
LONG );
	set("exits", ([
		"west"  : __DIR__"xiaolu5",
		"east"  : __DIR__"xiaolu1",
		"south" : __DIR__"lxting",
		"north" : __DIR__"sblu-3",
	]));
	set("outdoors", "nanshaolin");
	set("no_clean_up", 0);
	set("coor/x", 1820);
	set("coor/y", -6150);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}



