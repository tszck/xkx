// Room: /d/5lt/jiulou1.c

inherit ROOM;

void create()
{
	set("short", "悅華酒樓");
	set("long", @LONG
這裏就是村裏最豪華的悅華酒樓，寬敞明亮的大廳高朋滿座，小二
哥滿頭大汗地招呼着所有嘉賓，不時傳來陣陣歡歌笑語......
LONG );
	set("objects", ([
		__DIR__"npc/xiaoer" : 1,
	]));
	set("exits", ([
		"east" : __DIR__"sroad1",
		"up"   : __DIR__"jiulou2",
	]));
	set("coor/x", -160);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

