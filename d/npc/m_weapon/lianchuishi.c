// ROOM lianchuishi.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;
void create()
{
	set("short", "打錘坪");
	set("long", @LONG
這裏是玄兵古洞的打造鋼錘的地方。處在荒蕪人煙的大雪山上。大
雪山長年積雪，這裏卻是一坪長草扶地的山谷。四周擺了很多銅鐵五金，
一個靦腆少年手執大錘，看着你走近身來。
LONG );
	set("exits", ([
		"eastdown" : "/d/xuedao/nroad5",
	]));
	set("objects", ([
		__DIR__"npc/shichui" :1,
	]));
	set("coor/x", -30050);
	set("coor/y", -8000);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}
