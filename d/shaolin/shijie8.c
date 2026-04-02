// Room: /d/shaolin/shijie8.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "石階");
	set("long", @LONG
這裏看來是半山腰了。不遠的前面有一座小石亭，幾位遊客
在這裏歇息。山路到這裏變得十分平坦，東邊的山壁上題滿了名
人即興題下的詩句。遠望山林間層巒迭嶂，滿目滴翠。
LONG );
	set("exits", ([
		"westdown" : __DIR__"shanmen",
		"northup" : __DIR__"shijie9",
	]));
	set("no_clean_up", 0);
	set("outdoors", "shaolin");
	set("coor/x", 0);
	set("coor/y", 750);
	set("coor/z", 70);
	setup();
	replace_program(ROOM);
}
