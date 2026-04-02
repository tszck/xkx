// Room: /d/lingxiao/jianyuzhu.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;

void create()
{
	set("short", "牢房");
	set("long", @LONG
這裏漆黑一片，你細細摸索。不久便摸到石門的縫隙，以肩頭推去，
石門竟絕不搖晃，不知有多重實。一個臉色蒼白的年輕人，垂頭喪氣地
坐在地上。
LONG );
	set("exits", ([
		"west" : __DIR__"laolang",
	]));
	set("objects", ([ 
		__DIR__"npc/zhu" : 1,
	])); 
	set("coor/x", -30980);
	set("coor/y", -8900);
	set("coor/z", 130);
	setup(); 
	replace_program(ROOM);
}

