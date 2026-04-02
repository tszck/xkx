// Room: /city/chanzhimenqian.c

inherit ROOM;

void create()
{
	set("short", "禪智寺門前");
	set("long", @LONG
這裏是禪智寺門前的一塊空地，兩邊是寺廟裏種的芍藥圃，現在正
值芍藥開放之時，遠遠就能看到火紅的一片，東邊新搭起一座賞芍藥的
花棚。向北可以看到寺廟高高的殿門，東南邊是草河南街。
LONG );
	set("outdoors", "yangzhouw");
	set("no_clean_up", 0);
	set("exits", ([
		"southeast"  : __DIR__"caohenanjie",
		"north"      : __DIR__"chanzhisi",
		"east"       : __DIR__"huapeng",
		"west"       : __DIR__"shaoyaopu",
	]));
	set("coor/x", -20);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}