// Room: /d/taohua/chufang1.c
// Last Modified by winder on Nov. 17 2000

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "廚房");
	set("long", @LONG
這是給桃花島弟子們做飯用的廚房，供應弟子們每日的飯食。屋中
充斥着青菜和調料的味道。幾個廚師正在忙碌着。偶爾會有些喫不完的
主食和做菜時剩下的豬肉留在這裏。
LONG
	);

	set("exits", ([
		"south" : __DIR__"fanting1",
	]));
	
	set("objects",([
		__DIR__"obj/meat" : 2,
		__DIR__"obj/baozi" : 1,
		__DIR__"obj/rice" : 1,
	]));
	
	set("coor/x", 8970);
	set("coor/y", -3000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}