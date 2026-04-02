// /guanwai/milin2.c

inherit ROOM;

void create()
{
	set("short", "密林");
	set("long", @LONG
這是一片茂密的松林，雜亂的生長在傾斜的山坡上。每棵松樹都有
三四抱粗細，高達十幾丈。樹冠枝多葉密，將天空完全遮住，因此林內
顯得有些昏暗。樹木之間長着很多灌木雜草，使行走很艱難，據説人蔘
就生長在這些雜草之中。
LONG );
	set("exits", ([
		"westdown" : __DIR__"milin1",
		"southup"  : __DIR__"milin3",
	]));
	set("objects", ([
		__DIR__"npc/dongbeihu": 1,
	]));
	set("outdoors", "changbai");
	set("coor/x", 6160);
	set("coor/y", 5210);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}