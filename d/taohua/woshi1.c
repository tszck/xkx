// Room: /d/taohua/woshi1.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "蓉香榭");
	set("long", @LONG
你走進了一間臥房。一股若有若無的甜香撲鼻而來。琴劍書畫，掛
在牆上。錦籠紗罩，金彩珠光。小几上汝窯美人瓶內的桃花正自盛開。
右首一張牀，牀頭放着五彩鸞紋被。
LONG );
	set("exits", ([
		"west" : __DIR__"neishi1",
	]));
	set("objects", ([
		CLASS_D("taohua")+"/rong" : 1,
		__DIR__"npc/binu" : 2,
	]) );
	set("coor/x", 9010);
	set("coor/y", -2980);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}