// Room: /d/chengdu/nanjie1.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "南大街");
	set("long", @LONG
這條街上，雙人合抱的大樹在街邊十步一株，整整齊齊，青石鋪就
的街面打掃得乾乾淨淨。你沒事最好不要在這裏溜達，因爲這裏是成都
的王府大街。西邊一座牌樓，金碧輝煌，令人目爲之眩，這便是梁王府。
東邊則是一些民居。
LONG	);
	set("outdoors", "chengdu");
	set("exits", ([
		"west"  : __DIR__"wang",
		"east"  : __DIR__"minju",
		"south" : __DIR__"nanjie2",
		"north" : __DIR__"guangchang",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8050);
	set("coor/y", -3010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

