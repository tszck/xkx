//Room: /d/dali/chufang.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","廚房");
	set("long",@LONG
這是鎮南王府的廚房，中央有個大桌子，周圍則放着幾個圓凳，
這裏是段家弟子用餐的地方。
LONG);
	set("objects", ([
	    __DIR__"obj/xueli"       : 4,
	    __DIR__"npc/obj/puercha" : 1,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "east"  : __DIR__"tingfang",
	]));
	set("coor/x", -38990);
	set("coor/y", -69990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}