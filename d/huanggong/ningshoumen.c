// Room: /d/huanggong/ningshougong.c

inherit ROOM;

void create()
{
	set("short", "寧壽門");
	set("long", @LONG
這裏是寧壽宮的大門. 往北進去就是太上皇休憩的寧壽宮了.
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		 "north"      : __DIR__"huangjidian",
		 "south"      : __DIR__"huangjimen",
	]));
	set("no_clean_up", 0);

	set("coor/x", -180);
	set("coor/y", 5190);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}