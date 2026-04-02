//Edited by fandog, 02/15/2000

inherit ROOM;

void create()
{
	set("short", "廚房");
	set("long", @LONG
這是知府衙門的膳房。一位廚娘正站在竈臺後面笑眯眯地看着你，
她手上拿着一柄鐵勺，用力地把鍋裏煮着的一大堆食物攪勻。正中一張
八仙桌，桌上疊了許多盤碗。
LONG
	);
	set("exits", ([
		"west" : __DIR__"keting",
	]));
	set("objects", ([ 
		__DIR__"npc/chuniang" : 1,
	]));
	set("no_clean_up", 0);

	set("coor/x", -1387);
	set("coor/y", -2031);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}