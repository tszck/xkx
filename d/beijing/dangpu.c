// Room: /beijing/dangpu.c

inherit ROOM;

void create()
{
	set("short", "當鋪");
	set("long", @LONG
這是一家以買賣公平著稱的當鋪，一個五尺高的櫃檯擋在你的面前，
櫃檯上擺着一個牌子 (paizi)，櫃檯後坐着賈老闆，一雙精明的眼睛上
上下下打量着你。
LONG );
	set("no_fight", 1);
	set("no_beg",1);
	set("item_desc", ([
		"paizi" : "\n公平交易\n",
	]));
	set("objects", ([
		CLASS_D("yunlong")+"/jia" : 1,
	]));
	set("exits", ([
		"east" : __DIR__"nandaj1",
	]));
	set("coor/x", -210);
	set("coor/y", 4030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
