// Room: /d/lingxiao/roomgeng.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
#include <ansi.h> 
void create()
{
	set("short","居室");
	set("long",@LONG 
這是一間安靜的居室，是凌霄城第六代弟子耿萬鐘的房間。桌上放
着一卷《冰雪心法》，牆上掛着一柄劍。束束陽光從窗格中射入，照在
牆上，映得一副《萬裏江山圖》分外雄偉。
LONG);
	set("exits",([ /* sizeof() == 1 */
		"south"  : __DIR__"zoulang1", 
	]));
	set("objects", ([  
		__DIR__"npc/geng" : 1,
	]));
	set("coor/x", -31010);
	set("coor/y", -8860);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}

