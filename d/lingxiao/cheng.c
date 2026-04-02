// Room: /d/lingxiao/cheng.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
#include <ansi.h> 
void create()
{
	set("short","居室");
	set("long",@LONG 
這是成自學的房間。成自學雖和其他三位師弟一樣，由白自在代師
授藝，但在四位師兄弟中，他和白自在關係最好。同時他為人方正，剛
嚴不曲，最得白自在信任，所以白自在在失蹤以前，把凌霄城的寒玉牌
交給他保管。這間屋子整潔典雅，只在桌上放着一卷未寫完的帛卷。
LONG);
	set("outdoors", "lingxiao");
	set("exits",([ /* sizeof() == 1 */
		"south"  : __DIR__"zoulang4", 
	]));
	set("objects", ([  
		__DIR__"npc/cheng" : 1,
	]));
	set("no_clean_up", 0);
	set("coor/x", -30990);
	set("coor/y", -8830);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}

