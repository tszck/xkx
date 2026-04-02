// Room: /d/taohua/kefang.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short","客房");
	set("long",@LONG
這裏是桃花島招待客人住宿的房間。室內陳設精雅，兩牀相對，枕
衾雅潔。窗外透進早春四月的顏色。推窗遠處隔着如海的桃花林，就是
桃花島的兩忘峯了。
LONG
);
	set("exits",([
		"west" : __DIR__"jicui",
	]) );
	set("no_clean_up", 0);
	set("sleep_room", 1);
	set("coor/x", 9020);
	set("coor/y", -3030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}