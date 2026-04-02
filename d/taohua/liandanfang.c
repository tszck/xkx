// Room: /d/taohua/liandanfang.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "煉丹房");
	set("long", @LONG
這是桃花島主黃藥師的祕密練丹房。裏面藏着他苦心熬製的丹藥和
桃花島的總圖，島上所有五行生剋、陰陽八卦的變化，全記在內。
LONG
	);
	set("exits", ([
	      "out" : __DIR__"jingshe.c",
	]) );
	set("objects", ([
		"/clone/medicine/nostrum/jiuhuawan": 1,
		__DIR__"obj/tupu": 1,
	]));
	set("no_clean_up",0);
	set("coor/x", 9010);
	set("coor/y", -2990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

