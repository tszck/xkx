// Room: /d/baituo/caomeide.c
// Last Modified by winder on May. 15 2001

inherit ROOM;
void create()
{
	set("short","草莓地");
	set("long", @LONG
這裏是一塊草莓地，鮮紅的草莓散落在綠草中，讓人感到美妙愜
意。
LONG	);
	set("exits", ([
		"northeast" : __DIR__"shulin1",
	]));
	set("objects" , ([
		__DIR__"obj/caomei" : random(7),
	]));
	set("outdoors","baituo");
	set("coor/x", -50050);
	set("coor/y", 20010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
