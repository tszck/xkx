//Room: /d/dali/shanlu6.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","山路");
	set("long",@LONG
一條山路，兩邊是茂密的樹林，西面是延綿不絕的大山，南面是一
望無際的西雙版納大森林，傳說有邪教教衆在其中活動。道路兩旁間或
可見一些夷族的村鎮。山路轉向東蜿蜒着。
LONG);
	set("outdoors", "dalis");
	set("exits",([ /* sizeof() == 1 */
	    "south"      : __DIR__"shanlu5",
	    "east"       : __DIR__"gudao",
	]));
	set("no_clean_up", 0);
	set("coor/x", -65000);
	set("coor/y", -76000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}