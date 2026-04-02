// Room: /d/nanshaolin/shifang.c
// Last Modified by winder on May. 29 2001

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", BLU"石坊"NOR);
	set("long", @LONG
一個巨大的牌坊橫架在兩片山壁之間，牌坊正上方刻着六個斗大的
字：『閩中第一古剎』。字跡有些剝落，看上去年代頗為久遠了。前方
是一片很大的廣場，站滿了前來進香的香客和一些江湖上的豪士。象徵
着少林寺的山門殿，就矗立在廣場的北側。
LONG);

	set("exits", ([
		"north" : __DIR__"guangchang",
		"south" : __DIR__"shanlu3",
	]));
	set("outdoors", "nanshaolin");
	set("no_clean_up", 0);
	set("coor/x", 1820);
	set("coor/y", -6320);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

