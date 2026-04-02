// Room: /d/guiyun/houting.c
// Last Modified by winder on Jul. 9 2001

inherit ROOM;

void create()
{
	set("short","後廳");
	set("long",@LONG
這是歸雲莊的後廳。也是莊主處理家中私事的地方。東邊是一間書
房，入口處放着一扇大屏風；西面則是主人的臥房。
LONG
);
	set("exits",([
		"east"  : __DIR__"shufang",
		"west"  : __DIR__"wofang",
		"north" : __DIR__"zoulang3",
	]) );
	set("objects",([
		__DIR__"npc/yahuan" : 1,
	]));  
	setup();
	replace_program(ROOM);
}
