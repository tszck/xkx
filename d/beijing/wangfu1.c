// Room: /beijing/wangfu1.c

inherit ROOM;

void create()
{
	set("short", "王府井大街");
	set("long", @LONG
你走在一條繁忙的街道上，車水馬龍，人來人往。許多人都從南邊
走來，那裏是東長安街。西邊是一條寬闊的街道，不知為何卻十分冷清。
東邊是一家錢莊，可以聽到叮叮噹噹的金銀聲音。
LONG );
	set("outdoors", "beijing");
	set("exits", ([
		"east" : __DIR__"qianzhua",
		"south" : __DIR__"dongcha2",
		"west" : __DIR__"aobai1",
		"north" : __DIR__"wangfu2",
	]));
	set("objects", ([
		"/d/huashan/npc/youke" : 2,
	]));
	set("coor/x", -180);
	set("coor/y", 4050);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
