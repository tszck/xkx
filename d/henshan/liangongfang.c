// Room: /d/henshan/liangongfang.c
// Date: Sep.1 2001 by ahda

inherit ROOM;

void create()
{
	set("short", "練功房");
	set("long", @LONG
這裏是劉府中用來練功的地方。有幾個人正在專心致致地練武，有
幾個手持兵器，在互相拆招。身法靈動，猶如穿花蝴蝶一般，你不禁看
花了眼，別的人則坐在地上的蒲團上苦練內力。
LONG );
//      set("outdoors", "henshan");

	set("exits", ([
		"west" : __DIR__"liufudayuan",
	]));
	set("objects", ([
		"/d/shaolin/npc/mu-ren" : 5,
	]));
	set("coor/x", -390);
	set("coor/y", -1180);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

