// Room: /d/nanshaolin/songshu1
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "松樹林");
	set("long", @LONG
這是一片松樹林。高高的大松樹簇在一塊，密實的枝葉象一蓬蓬巨
傘般伸向天空，把陽光遮得絲毫也無。一條潔淨的青石小徑蜿蜒林中。
LONG );
	set("outdoors","nanshaolin");
	set("exits", ([
		"east"      : __DIR__"yaowang",
		"south"     : __DIR__"songshu2",
		"northwest" : __DIR__"hguangc3",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1820);
	set("coor/y", -6200);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}



