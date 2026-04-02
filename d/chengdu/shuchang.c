// Room: /d/chengdu/shuchang.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "書場");
	set("long", @LONG
這裏是全城有名的書場，每天來這裏聽書的絡繹不絕，場場暴滿，
要知道今天說啥，先看看這裏牆上的海報。內容主要是些梁山泊、三國
演義等。也有不少武俠書可以看，有興趣也可以一讀。
LONG	);
	set("exits", ([
		"east" : __DIR__"nanjie2",
		"west" : __DIR__"shuoshuyuan",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8060);
	set("coor/y", -3020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

