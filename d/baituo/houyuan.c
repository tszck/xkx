// Room: /d/baituo/houyuan.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short","後院");
	set("long", @LONG
這是僻靜的後院，住着『歐陽克』的老奶媽『張媽』。由於年歲已
高，她已經不幹活了，在這裏靜養。
LONG	);
	set("exits",([
		"southeast" : __DIR__"zhuyuan",
	]));
	set("outdoors", "baituo");
	set("objects",([
		__DIR__"npc/zhangma" : 1,
	]));
	set("coor/x", -50020);
	set("coor/y", 20080);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}

