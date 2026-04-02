// Room: /d/lingxiao/qi.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
#include <ansi.h> 
void create()
{
	set("short","居室");
	set("long",@LONG 
這是齊自勉的房間。齊自勉性格風雅，為人飄逸。牆上掛着李白的
《將進酒》，是齊自勉親手所書，字跡豪放奔放，走的是張旭狂草的路
子，從這依稀也能看出主人武功的性情。照壁上一幅《雪月夜行圖》，
是他當年一夜奔波八百里，滅掉太行三十寨的榮事。桌上燃着一束檀香，
散發出恬靜的氣息。一張焦尾琴擺在桌上，主人正在自斟自飲，自得其
樂。
LONG);
	set("exits",([ /* sizeof() == 1 */
		"north"  : __DIR__"zoulang4", 
	]));
	set("objects", ([  
		__DIR__"npc/qi" : 1,
	]));
	set("coor/x", -30990);
	set("coor/y", -8850);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}

