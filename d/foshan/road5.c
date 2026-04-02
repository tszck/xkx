//Room: /d/foshan/road5.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","林間道");
	set("long",@LONG
這裏是一條林間小道，在樹叢中蜿蜒。這裏是廣西了。嶺南山
林茂密，多產毒蟲，各位行路要十分小心。
LONG);
	set("outdoors", "foshan");
	set("exits",([ /* sizeof() == 1 */
	    "east"      : __DIR__"road6",
	    "northwest" : __DIR__"road4",
	]));
        set("objects", ([
                "/clone/medicine/vegetable/chuanshanjia" : random(2),
        ]));
	set("coor/x", -20000);
	set("coor/y", -6600);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
