// Room: /d/chengdu/jiulou1.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "銀杏酒樓");
	set("long", @LONG
這裏就是城裏最豪華的銀杏酒樓，川菜的歷史悠久，以麻辣爲主，
因爲這裏一年四季都很潮溼，多喫點辣椒既開胃健脾，又強身益壽，寬
敞明亮而又富麗堂皇的大廳高朋滿座，小二哥滿頭大汗的招呼着所有嘉
賓，不時傳來陣陣歡歌笑語......
LONG );
	set("objects", ([
		__DIR__"npc/xiaoer2" : 1,
	]));
	set("exits", ([
		"west" : __DIR__"chunxilu1",
		"up"   : __DIR__"jiulou2",
	]));
	set("coor/x", -8030);
	set("coor/y", -3020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

