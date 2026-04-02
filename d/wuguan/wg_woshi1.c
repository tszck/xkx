// wg_woshi1.c

inherit ROOM;

void create()
{
	set("short","休息室");
	set("long", @LONG
這裏是武館內的休息室，屋子有點點舊，但是打掃的非常乾淨，一
排牀鋪靠牆擺着，南面過去也是一間休息室，不斷的有人進來休息或醒
後離去，你悄悄的找個空鋪睡了下來。
LONG);
	set("exits", ([
		"south" : __DIR__"wg_woshi2",
		"west"  : __DIR__"wg_lang6",
	]));
	set("no_clean_up", 0);
	set("no_get_from",1);
	set("no_fight",1);
	set("no_steal",1);
	set("sleep_room", 1);
	set("no_get", 1);
	set("coor/x", 61);
	set("coor/y", -60);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
