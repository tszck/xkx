// Room: /d/5lt/xiaolu.c

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
這是一條去海濱浴場的小路，路兩旁都栽上了村裏新引進的亞熱帶
植物。一陣雨星伴着微帶海水氣息的風飄了過來，你不禁打了個噴嚏。
LONG);
	set("outdoors", "5lt");
	set("exits", ([
		"north"     : __DIR__"haitan",
		"southeast" : __DIR__"wroad4",
	]));

	set("no_clean_up", 0);
	set("coor/x", -195);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
