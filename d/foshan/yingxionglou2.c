//Room: /d/foshan/yingxionglou2.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","英雄樓");
	set("long",@LONG
酒樓裏桌椅潔淨。座中客人衣飾豪奢，十九是富商大賈。這裏
可以俯瞰佛山鎮全景。
LONG);
	set("objects", ([
	    __DIR__"npc/pang": 1,
	    __DIR__"npc/shou": 1,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "down"  : __DIR__"yingxionglou",
	]));
	set("coor/x", -1300);
	set("coor/y", -6610);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
