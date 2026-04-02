//Room: /d/foshan/road11.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","林間道");
	set("long",@LONG
這裏是一條林間小道，在樹叢中蜿蜒。嶺南山林茂密，多產毒
蟲，各位行路要十分小心。
LONG);
	set("objects", ([
	   __DIR__"obj/shikuai": 1,
	]));
	set("outdoors", "foshan");
	set("exits",([ /* sizeof() == 1 */
	    "northeast" : __DIR__"road13",
	    "southwest" : __DIR__"road10",
	]));
	set("coor/x", 1500);
	set("coor/y", -6550);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
