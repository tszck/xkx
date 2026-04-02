// Room: /yangzhou/shuyuan.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","庭院");
	set("long",@LONG
北向升階而上為書院講堂，堂名「至止」，是增城湛公所題。園內
遍種樹木，或桃或李，或松或竹，間以花卉，而湖石假山，則順其自然，
砌於院內。遊目尋芳，無需遠步。
LONG );
	set("outdoors", "yangzhouw");

	set("exits", ([
		"south"   : __DIR__"qionghuajie",
		"northup" : __DIR__"shuyuan1",
	]));
	set("objects", ([
		"/d/taishan/npc/shu-sheng" : 1,
	]));
	set("coor/x", 20);
	set("coor/y", 31);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}