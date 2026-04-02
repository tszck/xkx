// wg_woshi2.c

inherit ROOM;

void create()
{
	set("short","休息室");
	set("long", @LONG
這裏是武館內的休息室，屋子有點點舊，但是打掃的非常乾淨，一
排牀鋪靠牆擺着，你悄悄的走過去，找個空鋪睡了下來。
LONG);
	set("exits", ([
		"north" : __DIR__"wg_woshi1",
	]));
	set("no_clean_up", 0);
	set("no_fight",1);
	set("no_get",1);
	set("no_steal",1);
	set("no_get_from",1);
	set("sleep_room", 1);
	set("coor/x", 61);
	set("coor/y", -70);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
