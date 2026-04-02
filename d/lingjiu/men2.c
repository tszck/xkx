//ROOM men1.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "書房大門");
	set("long",@LONG
這是書房門口，只看見大門兩旁貼着一副對聯 (duilian)，抬頭上
望。門楣上一塊大匾(bian)上寫着幾個大字。
LONG );
	set("exits", ([
		"east" : __DIR__"shufang",
		"west" : __DIR__"changl12",
	]));
	set("objects",([
		__DIR__"npc/zhujian" : 1,
	]));
	set("item_desc", ([
		"duilian" : "行到水窮處，坐看雲起時.\n",
		"bian" : HIC "任我逍遙\n" NOR,
	]));
	set("coor/x", -51000);
	set("coor/y", 30160);
	set("coor/z", 70);
	setup();
}

int valid_leave(object me, string dir)
{
	if ( (dir == "east") &&
		((string)me->query("family/family_name") != "逍遙派") &&
		((string)me->query("family/family_name") != "靈鷲宮") &&
		objectp(present("zhu jian", environment(me))) )
		return notify_fail("竹劍伸手攔住你，説道：“對不起，本門重地，請回！”\n");
	return ::valid_leave(me, dir);
}