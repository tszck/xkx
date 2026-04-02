inherit ROOM;

void create()
{
	set("short", "客店");
	set("long", @LONG
這是一家價錢低廉的客棧，生意非常興隆。據説全國各地都有這樣
的分店，而且所有的客棧都歸一個人所有。不過他從來不露面，誰也不
知道他究竟是怎樣一個人。
LONG );
	set("no_fight", 1);
	set("valid_startroom", 1);
	set("objects", ([
		"/d/city/npc/xiaoer" : 1,
	]));
	set("exits", ([
		"west" : __DIR__"nandaj1",
		"east" : __DIR__"majiu",
	]));
	set("coor/x", -190);
	set("coor/y", 4030);
	set("coor/z", 0);
	setup();
	"/clone/board/kedian2_b"->foo();
	replace_program(ROOM);
}
