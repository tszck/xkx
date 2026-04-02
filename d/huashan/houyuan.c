// houyuan.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;
void create()
{
	set("short","後院");
	set("long",@LONG
這裏是華山派的後院，裏面是華山弟子的居室和練功房。華山派總
所倚山而建，地勢險峻，往東便是懸崖。西面是另一個小花院，有假山
小池，景色怡人，頗有江南林園的特色。
LONG);
	set("exits",([
		"northeast"  : __DIR__"garden",
		"west"       : __DIR__"jiashan",
		"east"       : __DIR__"xuanya",
	]));
	set("objects",([
		__DIR__"npc/shu-qi": 1,
	]));
	set("outdoors", "huashan");
	set("coor/x", -880);
	set("coor/y", 210);
	set("coor/z", 120);
	setup();
	replace_program(ROOM);
}
 
