// Room: /d/lingxiao/zoulang1.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
#include <ansi.h> 
void create()
{
	set("short","走廊");
	set("long",@LONG 
這是一條安靜的走廊。上下都是凌霄弟子的居所，北邊是耿萬鐘的
居室，聽説他目前正在廣收門徒。南邊是汪萬翼的房間。西邊是一個安
靜的小間，可以在那睡覺休息。
LONG);
	set("outdoors", "lingxiao");
	set("exits",([ /* sizeof() == 1 */
		"west"  : __DIR__"sleep",
		"east"  : __DIR__"zhongting",
		"north" : __DIR__"roomgeng",
		"south" : __DIR__"roomwang", 
	]));
	set("no_clean_up", 0);
	set("coor/x", -31010);
	set("coor/y", -8870);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}

