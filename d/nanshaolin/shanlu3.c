// Room: /d/nanshaolin/shanlu3.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "石階路");
	set("long", @LONG
這裏已經沒什麼樹林了。兩邊是隆起的山脊。南邊山谷通往山外，
遠遠看去，是一片馬尾松的海洋。北面山坳裏，連片的建築窩在山谷裏，
好大一片禪林。這裏路近少林，路面都鋪上了石板。
LONG);

	set("exits", ([
		"south" : __DIR__"shanlu2",
		"north" : __DIR__"shifang",
	]));
	set("no_clean_up", 0);
	set("outdoors", "nanshaolin");
	set("coor/x", 1820);
	set("coor/y", -6330);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}



