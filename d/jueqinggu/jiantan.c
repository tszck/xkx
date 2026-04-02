// Room: /d/jueqinggu/jiantan.c
// Last Modified by winder on Feb. 17 2001

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "劍潭");
	set("long", @LONG
只見這裏壁上、桌上、架上、櫃中、幾間，盡皆列滿兵刃，式樣繁
多，其中十之八九都是古劍，或長逾七尺，或短僅數寸，有的是鐵鏽斑
駁，有的卻仍寒光逼人。
LONG
	);
	set("exits", ([
		"north" : __DIR__"sanqingxuan",
	]));
	set("no_clean_up", 0);
 	set("coor/x", -540);
	set("coor/y", -370);
	set("coor/z", 20);
	setup();
	replace_program(ROOM); 
}

