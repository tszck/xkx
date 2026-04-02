// /guanwai/songhuajiang.c

inherit ROOM;

void create()
{
	set("short", "松花江面");
	set("long", @LONG
這裏是松花江的江面，冰面早已解凍，清澈的江水濤濤北去，兩岸
是如煙如霧松支，柳條。船伕悠閒地在船尾把着舵。
LONG );
	set("no_clean_up", 0);
	set("outdoors", "guanwai");
	set("coor/x", 6090);
	set("coor/y", 5230);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}