// Room: /d/5lt/xiaoshulin.c

inherit ROOM;

void create()
{
	set("short", "小樹林");
	set("long", @LONG
這是路邊一片小松樹林，面積算不上大。林中有塊開闊地，習武的
村民們經常到這裏來切磋武藝。
LONG );
	set("exits", ([
		"north" : __DIR__"eroad2",
	]));
        set("objects", ([
	]));
	set("no_clean_up", 0);
	set("outdoors", "5lt");
	set("coor/x", -130);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}