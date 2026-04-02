// Room: /d/suzhou/hutong3.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "衚衕");
	set("long", @LONG
這是一條黑暗、骯髒的小巷，空氣中彷彿飄揚着一股罪惡的氣息，
幾個流氓在遊蕩，向東南就能回到大街，你還是趕快走吧。
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"west"      : __DIR__"hutong2",
		"southeast" : __DIR__"dongdajie2",
	]));
	set("objects", ([
		"/d/city/npc/liumang" : 2,
	]));
	set("coor/x", 880);
	set("coor/y", -990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
