// Room: /d/lingxiao/weideju.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
#include <ansi.h> 
void create()
{
	set("short","威德居");
	set("long",@LONG
這是白自在的寢室，傢俱屋飾，極盡豪華，謂金碧輝煌，桂殿蘭宮。
但現在白自在已不知去向，只剩他的一個妾室，還在這裏抽抽噎噎地哭。
LONG);
	set("exits",([ /* sizeof() == 1 */
		"west"  : __DIR__"book",   
	]));
	set("objects", ([  
		__DIR__"npc/yaoniang" : 1,
	]));
	set("coor/x", -30990);
	set("coor/y", -8830);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}

