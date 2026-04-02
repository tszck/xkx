//Room: /d/foshan/yingxionglou.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","英雄樓");
	set("long",@LONG
酒樓裏桌椅潔淨。座中客人衣飾豪奢，十九是富商大賈。佛山
地處交通要地，來這喫飯的人還真不少。
LONG);
	set("objects", ([
	    __DIR__"npc/fengqi": 1,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "north"  : __DIR__"street4",
	    "south"  : __DIR__"majiu",
	    "up"     : __DIR__"yingxionglou2",
	]));
	set("coor/x", -1300);
	set("coor/y", -6610);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
