// Room: /d/jueqinggu/guanlanting.c
// Last Modified by winder on Feb. 17 2001

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "觀瀾亭");
	set("long", @LONG
這座亭子四角攥尖頂，檐角飛翹，四柱拱托，古拙而又精巧。山下
弧形水渠環繞，水聲潺潺，亭四周山石林立，千資百態。坐立亭中可望
碧波滾滾，令人有臨海觀瀾之感。
LONG
	);

	set("exits", ([
		"southwest" : __DIR__"dufengling",
		"northup"   : __DIR__"xiangqinxie",
		"east"      : __DIR__"meiyupu",
	]));

	set("outdoors","jueqinggu");
	set("no_clean_up", 0);
	set("coor/x", -480);
	set("coor/y", -380);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

