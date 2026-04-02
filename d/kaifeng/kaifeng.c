// /kaifeng/kaifeng.c
// Last modified by winder 2003.10.20

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "開封府");
	set("long", @LONG
開封府統管開封這片區域。現任的開封府尹包拯包大人鐵面無私、
明斷秋毫，深得民衆信任，被稱爲包青天。大門一邊一個高大的鼓架告
狀鳴冤的可以在此敲鼓。
LONG);
	set("objects", ([
		__DIR__"npc/zhaohu" : 1,
		__DIR__"npc/zhanglong" : 1,
	]));
	set("no_clean_up", 0);
	set("exits", ([
		"east" : __DIR__"jiedao1",
		"west" : __DIR__"datang",
	]));
	set("outdoors", "kaifeng");

	setup();
}

int valid_leave(object me, string dir)
{
	object ob;

	if (dir == "west")
	{
		if (objectp(ob = present("zhang long", this_object())) &&
			living(ob))
			return notify_fail(CYN "張龍一把攔住你，喝道：衙門重地，怎由閒雜人等隨便進出。\n" NOR);

		if (objectp(ob = present("zhao hu", this_object())) &&
			living(ob))
			return notify_fail(CYN "趙虎一把攔住你，喝道：衙門重地，怎由閒雜人等隨便進出。\n" NOR);
	}
	return ::valid_leave(me, dir);
}

