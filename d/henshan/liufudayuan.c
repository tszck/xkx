// liufudayuan.c
// Date: Nov.1997 by Venus
// Last Modified by ahda on Sep.1 2001

#include <room.h>
inherit ROOM;
int do_knock(string arg);

void create()
{
	set("short", "劉府大院");
	set("long", @LONG
劉府大院裏現在擠着很多江湖豪客，原來今天是劉正風金盆洗手的
好日子。劉老爺子在衡陽人緣很好，來捧場的自然不少，大院裏已擺了
很多張桌子，杯筷往來，很是熱鬧。
LONG);
	set("outdoors", "hengyang");
	set("exits", ([
	    "north"  : __DIR__"liufudating",
	    "out"    : __DIR__"liufugate",
	    "east"   : __DIR__"liangongfang",
	    "west"   : __DIR__"kefang",
	]));
	set("objects", ([
		"/d/taishan/npc/dao-ke" : 1,
		"/d/taishan/npc/jian-ke" : 1,
		"/d/huashan/npc/haoke" : 1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", -400);
	set("coor/y", -1180);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
