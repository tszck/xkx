// Room: youxiting.c
// Last Modified by winder on Aug. 18 2002

inherit ROOM;

void create()
{
	set("short", "遊嬉廳");
	set("long", @LONG
遊嬉廳一貫熱鬧非凡，人來人往的嘈雜，幫閒的吆喝，雞飛狗跳的
聲音，賭徒滿臉油汗的臭氣，充斥了整個空間。如果你沒興趣，那是真
不想在這裏呆的。
LONG );
	set("no_fight", "1");
	set("no_beg", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");
	set("no_clean_up", 0);
	set("exits", ([
		"west"  : __DIR__"doujiroom",
		"east"  : __DIR__"saiguiroom",
		"north" : __DIR__"zoulang2",
		"south" : __DIR__"yaqianroom",
	]));

	set("coor/x", 20);
	set("coor/y", 9);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
