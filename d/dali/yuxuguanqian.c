//Room: /d/dali/yuxuguanqian.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","玉虛觀前");
	set("long",@LONG
東面一座廟觀，門前匾上寫着“玉虛觀”三個大字，西邊一個
碧水盪漾的小湖，四周綠柳成蔭，實乃修心養性的好地方。
LONG);
	set("objects", ([
	   __DIR__"npc/xiaodaogu": 2,
	]));
	set("outdoors", "dalic");
	set("exits",([ /* sizeof() == 1 */
	    "north"  : __DIR__"yuxuguan",
	    "south"  : __DIR__"hudiequan",
	]));
	set("coor/x", -39000);
	set("coor/y", -68990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}