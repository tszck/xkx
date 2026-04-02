// Room: /yangzhou/caohecexiang.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","小草河側巷");
	set("long",@LONG
傍依官河的草河小街上的一處普普通通的巷子，也是這裏的居民區
的一部分。向東穿過草河小街就是官河了，西南通向繁華熱鬧的通泗街，
從那裏向西就是通泗門－揚州的西門。這裏雖小，卻熱熱鬧鬧，兩側有
許多店鋪，另有許多小販沿街擺攤，吆喝着自己的生意。
LONG );
	set("outdoors", "yangzhouw");
	set("exits", ([
		"east"      : __DIR__"yudian",
		"southeast" : __DIR__"huadian",
		"southwest" : __DIR__"garments",
		"north"     : __DIR__"caizhu",
		"northeast" : __DIR__"tongsijie",
	]));
	set("objects", ([
		__DIR__"npc/tangfan" : 1,
	]));
	set("no_clean_up", 0);
	set("coor/x", -30);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}