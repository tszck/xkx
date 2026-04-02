// Room: /d/5lt/caomeidi.c

inherit ROOM;
void create()
{
	set("short","草莓地");
	set("long", @LONG
這裏是一塊草莓地，鮮紅的草莓散落在綠草中，讓人感到美妙愜
意。
LONG	);
	set("exits", ([
		"southeast" : __DIR__"fanshudi",
	]));
	set("objects" , ([
		__DIR__"obj/caomei" : random(10),
	]));
	set("outdoors","5lt");
	set("coor/x", -130);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
