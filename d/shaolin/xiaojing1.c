// Room: /d/shaolin/xiaojing1.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "山坡");
	set("long", @LONG
這裏是少室山之陽的一座山坡山坡上長滿了豔紅色的不知名的
野花采密的蜂蝶們簇成一團團忙碌着。不時有幾隻好奇的小密蜂飛
近來似乎對你這個不速之客感到極大的驚奇。
LONG );
	set("exits", ([
		"east" : __DIR__"shijie1",
		"northup" : __DIR__"xiaojing2",
	]));
	set("no_clean_up", 0);
	set("outdoors", "shaolin");
	set("coor/x", -20);
	set("coor/y", 700);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}