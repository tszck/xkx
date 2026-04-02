// Room: /city/bingyin.c
// YZC 1995/12/04 

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "兵營");
	set("long", @LONG
這裏是兵營，密密麻麻到處都是官兵，有的在武將的指揮下列隊操
練，有的獨自在練功，有的坐着、躺着正在休息。南牆下坐着主帥，不
動聲色地尋視着四周。看到你進來，他們全都向你包圍了過來，形勢看
來不太妙。南邊有一個門(door)。
LONG );
	set("item_desc", ([
		"door" : "這是一扇極厚的鐵門。\n",
	]));
	set("exits", ([
		"south" : __DIR__"bingqiku",
		"north" : __DIR__"bingyindamen",
	]));
	set("objects", ([
		__DIR__"npc/shi" : 1,
		__DIR__"npc/wujiang" : 2,
		__DIR__"npc/bing" : 2,
	]));
//	set("no_clean_up", 0);
	create_door("south", "鐵門", "north", DOOR_CLOSED);
	set("coor/x", 20);
	set("coor/y", -61);
	set("coor/z", 0);
	setup();
}
int valid_leave(object me, string dir)
{
	if (!wizardp(me) && objectp(present("guan bing", environment(me))) && 
		dir == "south")
		return notify_fail("官兵攔住了你的去路。\n");
	return ::valid_leave(me, dir);
}