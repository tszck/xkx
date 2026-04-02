// Room: /d/baituo/fendi.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short", "墳地");
	set("long", @LONG
這裏是荒涼陰森的荒墳地。一個墳包連着一個墳包。有的墳包上還
插着一支竹竿，扯着一條布帶，有的墳包根本什麼都沒有。幾隻老鴉站
在墳地裏的枯枝上，不時地啼叫兩聲。
LONG	);
	set("outdoors", "baituo");
	set("exits", ([
		"southwest" : __DIR__"xiaolu1",
		"north"     : __DIR__"mumen",
	]));
	set("objects" , ([
		__DIR__"npc/guafu" : 1,
	]) );
	set("coor/x", -49960);
	set("coor/y", 20000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
