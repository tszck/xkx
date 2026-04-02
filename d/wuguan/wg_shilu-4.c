// wg_shilu-4.c

inherit ROOM;

void create()
{
	set("short", "石板路");
	set("long", @LONG
你走在一條石板路上，東面過去就是後院了，西面是北練功場，
北面傳來陣陣飯菜的香氣，那裏是武館的飯廳。南面過去是武館大廳。
LONG);
	set("exits", ([
		"west"  : __DIR__"wg_lang3",
		"east"  : __DIR__"wg_shilu-3",
		"south" : __DIR__"wg_shilu-2",
		"north" : __DIR__"wg_fanting",
	]));
	set("objects", ([
		__DIR__"npc/wg_emxiaost" : 1,
		__DIR__"npc/wg_tiezhangdizi" : 1,
	]));
	set("outdoors", "wuguan");
	set("coor/x", 41);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

