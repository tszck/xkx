// Room: /d/chengdu/zhubaopu.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "週記珠寶鋪");
	set("long", @LONG
這是一家專營金銀、珠寶類的首飾店，老闆和藹可親，熱情周到。
如果你想找件禮物送給你的心上人，那就不要再猶豫了，趕緊到錢莊取
錢吧。
LONG	);

	set("exits", ([
		"west" : __DIR__"beijie",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8040);
	set("coor/y", -2970);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

