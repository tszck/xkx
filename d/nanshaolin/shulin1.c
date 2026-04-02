// Room: /d/nanshaolin/shulin1.c
// Last Modified by winder on May. 29 2001
// 這裏也是去青雲坪的地方。可是南少林可以不要。

inherit ROOM;

void create()
{
	set("short", "松樹林");
	set("long", @LONG
這是一片松樹林。幾十丈高的大松樹簇在一塊，密實的枝葉象一蓬
蓬巨傘般伸向天空，把陽光遮得絲毫也無。尺把厚的松針積在地上，一
腳踩下去，半天拔不出來。
LONG );
	set("exits", ([
		"east"  : __FILE__,
		"west"  : __FILE__,
		"south" : __FILE__,
		"north" : __FILE__,
/*
		"east"  : __DIR__"shulin"+(random(10)+2),
		"west"  : __DIR__"shulin2",
		"south" : __DIR__"shanlu8",
		"north" : __DIR__"shulin"+(random(10)+2),
*/
	]));
	set("outdoors", "nanshaolin");
	set("no_clean_up", 0);
	set("coor/x", 1840);
	set("coor/y", -6010);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}

