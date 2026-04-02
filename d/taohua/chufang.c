// Room: /d/taohua/chufang.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "廚房");
	set("long", @LONG
這是桃花島的廚房。黃藥師不知使用了什麼方法抓了幾個御廚來，
正在忙碌着。屋中充斥着青菜和調料的味道。幾個廚師正在忙碌着。偶
爾會有些喫不完的主食和做菜時剩下的豬肉留在這裏。
LONG
	);
	set("no_clean_up", 0);

	set("objects",([
		__DIR__"obj/meat" : 1,
		__DIR__"obj/rice" : 1,
	]));
	set("exits", ([
		"east"  : __DIR__"neishi2",
		"south" : __DIR__"fanting",
	]));

	set("coor/x", 8990);
	set("coor/y", -2970);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}