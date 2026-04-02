// Room: /d/baituo/cave.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short","巖洞");
	set("long", @LONG
這裏是大巖洞，它是在『白駝山』特殊的地質條件下經過漫長的年代
形成的。南邊是青竹林。再往北走就進洞了。
LONG	);
	set("exits",([
		"north"     : __DIR__"cave1",
		"southdown" : __DIR__"zhulin",
	]));
	set("objects",([
		__DIR__"npc/mangshe" : 1,
	]));
	set("outdoors","baituo");
	set("coor/x", -50040);
	set("coor/y", 20070);
	set("coor/z", 40);
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir =="north" )
	{
		if (objectp(present("mang she", environment(me))))
			return notify_fail("蟒蛇擋住你的去路！\n");
	}
	return ::valid_leave(me, dir);
}


