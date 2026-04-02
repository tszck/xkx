// wg_houyuan.c

inherit ROOM;
void create()
{
	set("short", "後院");
	set("long", @LONG
這裏是後院，都是些幹活做事的地方，南面過去都是柴房，北面是
一個水房。人們忙忙碌碌的進出，幹着自己的活。
LONG);
	set("exits", ([
		"south" : __DIR__"wg_chaifang",
		"north" : __DIR__"wg_shuifang",
		"east" : __DIR__"wg_houyuan2",
		"west" : __DIR__"wg_shilu-3",
	]));
	set("objects", ([		
		__DIR__"npc/wg_hengshannvni" : 1,
		__DIR__"npc/wg_wududizi" : 1,
	]));
	set("outdoors", "wuguan");
	set("coor/x", 61);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

