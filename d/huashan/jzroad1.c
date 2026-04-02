// Room: /d/huashan/jzroad1.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;
void create()
{
	set("short", "松樹林");
	set("long", @LONG
這是一片松樹林。中間一條小路，兩邊都是黑森森的幾丈高的松樹。
樹上結着不少松果，間或有野兔遊悠遊而過。
LONG );
	set("exits", ([
		"southwest" : "/d/village/hsroad2",
		"east"      : __DIR__"jzroad2",
	]));
	set("objects", ([
		"/d/wudang/npc/yetu": 2,
	]));
	set("outdoors", "zhongtiao");
	set("coor/x", -950);
	set("coor/y", 210);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
