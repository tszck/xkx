//Room: /d/dali/shanlu5.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","山路");
	set("long",@LONG
一條山路，兩邊是茂密的樹林，西面是延綿不絕的大山，道路兩
旁間或可見一些夷族的村鎮。山路向南蜿蜒着。
LONG);
	set("outdoors", "dalis");
	set("exits",([ /* sizeof() == 1 */
	    "southeast"  : __DIR__"shanlu4",
	    "north"      : __DIR__"shanlu6",
	]));
	set("objects", ([
	   __DIR__"npc/wuliangdizi": 1,
	]));
	set("coor/x", -65000);
	set("coor/y", -78000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}