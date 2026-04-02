//HSQTING.C

inherit ROOM;

void create()
{
	set("short", "洪水旗大廳");
	set("long", @LONG
這裏是洪水旗的大廳，廳中四壁漆墨，連桌案臺椅俱為黑色，槍曳
黑纓，劍垂玄穗，佈置得冷漠森嚴。廳中央擺有茶几，洪水旗掌旗使唐
洋正襟而坐，面帶殺氣。
LONG );
	set("exits", ([
		"south" : __DIR__"hsqchanglang",
	]));
	set("objects", ([
		__DIR__"npc/tangyang": 1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", -52020);
	set("coor/y", 950);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}