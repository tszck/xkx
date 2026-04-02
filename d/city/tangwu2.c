// Room: /d/city/tangwu2.c
// Last Modified by winder on Jul. 20 2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","堂屋");
	set("long",@LONG
北牆貼着一張孔子畫像，下面點着一柱清香。東邊倚牆放着一書架，
稀稀拉拉放着幾本書。中間放着幾張木桌和凳子，卻沒有一個學童在屋
裏，只有一個老儒生在邊上坐着拿本書在獨自讀着，邊上擺着一把戒尺
(chi)。
LONG
	);
	set("exits",([ /* sizeof() ==  */
		"south" : __DIR__"zizheng",
	]));
	set("objects", ([ /* sizeof() == */
		__DIR__"npc/wuguxian" : 1,
	]));
	set("item_desc" , ([ /* sizeof() == */
		"chi" : "戒尺上落滿了灰塵，象是許久未用了。\n",
	]));
	set("coor/x", -30);
	set("coor/y", 40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
