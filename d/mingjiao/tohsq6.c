//TOHSQ6.C

inherit ROOM;

void create()
{
	set("short", "山林路");
	set("long", @LONG
一掛巨大的瀑布白龍出霄般橫越山間，水氣已濃得彷彿可以滴下水
珠兒來。山巒間升起薄薄的青霧，凝聚不散。嘩嘩的水聲震耳欲聾。
LONG );
	set("exits", ([
		"north" : __DIR__"tohsq7",
		"south" : __DIR__"tohsq5",
	]));
	set("no_clean_up", 0);
	set("outdoors", "mingjiao");
	set("coor/x", -52020);
	set("coor/y", 910);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}