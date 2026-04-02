// Room: /d/chengdu/dangpu.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "當鋪");
	set("long", @LONG
這是一家以買賣公平著稱的當鋪，一個五尺高的櫃檯擋在你的面前，
櫃檯上擺着一個牌子 (paizi)，櫃檯後坐着當鋪老闆燕六，一雙精明的
眼睛上上下下打量着你。
LONG	);
	set("no_fight", 1);
	set("no_beg",1);
	set("item_desc", ([
		"paizi" : "公平交易\n",
	]));
	set("exits", ([
		"north" : __DIR__"xijie",
	]));
	set("objects" , ([
		__DIR__"npc/yanliu" : 1,
	]));
	set("coor/x", -8080);
	set("coor/y", -3010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

