// Room: /d/chengdu/wangjianglou2.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "望江樓二樓");
	set("long",@LONG
你來到望江樓上，極目遠眺，整個成都的美景盡收眼低。只見府南
河象條玉帶似的環繞全城，太陽照在河面，發出緞子般的光澤。旁邊的
竹林鬱鬱蔥蔥，空氣竟也變得更加清新起來。樓的牆上刻着前代文人墨
客留下的詩句。
LONG	);
	set("outdoors", "chengdu");
	set("exits", ([
		"down" : __DIR__"wangjianglou1",
	]));
	set("objects", ([
		__DIR__"npc/youke" : 2,
	]));
	set("coor/x", -8030);
	set("coor/y", -3030);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);       
}


