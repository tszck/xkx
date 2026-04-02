// /guanwai/bingmian.c

inherit ROOM;

void create()
{
	set("short", "冰面");
	set("long", @LONG
這裏是松花江的江面，現已凍成了幾尺厚的堅冰。行人或馬匹，車
輛均可橫逾江面而絕無危險。冰面上留有厚厚的積雪，與兩岸連成一片，
只有中間經常行走之出，露出一條青色的冰路。
LONG );
	set("exits", ([
		"east"  : __DIR__"damenkan",
		"west"  : __DIR__"chuanchang",
	]));
	set("no_clean_up", 0);
	set("outdoors", "guanwai");
	set("coor/x", 6090);
	set("coor/y", 5230);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}