// Room: /d/henshan/chating.c 茶亭
// Modified by Java on Feb.14.1998

inherit ROOM;

void create()
{
	set("short", "茶亭");
	set("long", @LONG
這是一家路邊的小茶亭，趕山路的人常在此處歇歇腳。亭子裏
有幾張桌子和幾支條凳。周圍是一片樹林。
LONG );
	set("outdoors", "hengyang");

	set("exits", ([
		"west"  : __DIR__"hsroad6",
	]));
	set("objects", ([
		__DIR__"npc/yuanziyi" :1,
	]));

	set("no_clean_up", 0);
	set("coor/x", -1390);
	set("coor/y", -1500);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
