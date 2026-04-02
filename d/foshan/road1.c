//Room: /d/foshan/road1.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","林間道");
	set("long",@LONG
這裏是一條林間小道，在樹叢中蜿蜒。這裏向東是廣西。向西
北走就是大理國的地界了。
LONG);
	set("objects", ([
	   __DIR__"obj/shikuai": 1,
	]));
	set("outdoors", "foshan");
	set("exits",([ /* sizeof() == 1 */
	    "southwest" : "/d/dali/road5",
	    "east"      : __DIR__"road2",
	]));
	set("coor/x", -36000);
	set("coor/y", -45000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
