// Room: /d/xingxiu/xxh3.c
// Last Modified by winder on Apr. 25 2001

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "星宿海");
	set("long", @LONG
這裏是星宿海。因方圓幾百裏都是一望無際的湖泊和沼澤，當地
牧羊人稱之爲“海”。也因陰暗潮溼，毒蟲繁殖甚富。星宿弟子常來
此捕捉毒蟲，以備練毒之用。這裏通向星宿海的深處。
LONG);
	set("exits", ([
		"east"  : __DIR__"xxh1",
		"west"  : __DIR__"xxh4",
		"south" : __FILE__,
		"north" : __DIR__"xxh2",
	]));
	set("outdoors", "xingxiu");
	set("coor/x", -50000);
	set("coor/y", 20200);
	set("coor/z", 0);
	set("no_clean_up", 0);
	setup();
//	replace_program(ROOM);

}
#include "/d/xingxiu/xxh.h";
