// ROOM lianbangshi.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;
void create()
{
	set("short", "鑄棒院");
	set("long", @LONG
這裏是玄兵古洞的打造的地方。處在成都丐幫分舵的小院裏。一個
粗壯的漢子守着一個烈焰騰騰的大鐵爐，拿着一個大鐵錘不停地敲打着
什麼。
LONG );
	set("exits", ([
		"south" : "/d/chengdu/ruin1",
	]));
	set("objects", ([
		__DIR__"npc/shibang" :1,
	]));
	set("coor/x", -8070);
	set("coor/y", -3030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
