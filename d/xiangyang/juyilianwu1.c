// Room: /d/xiangyang/juyilianwu1.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "練功場");
	set("long", @LONG
這裏是聚義館中用來練功的地方。有幾個人正在專心致致
地練武，有幾個手持兵器，在互相拆招。身法靈動，猶如穿花
蝴蝶一般，你不禁看花了眼，別的人則坐在地上的蒲團上苦練
內力。
LONG );
        set("outdoors", "xiangyang");

	set("exits", ([
		"west" : __DIR__"juyiyuan",
	]));
	set("objects", ([
		"/d/shaolin/npc/mu-ren" : 3,
	]));
	set("coor/x", -529);
	set("coor/y", -501);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}