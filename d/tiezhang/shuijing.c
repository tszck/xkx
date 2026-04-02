// Room: /d/tiezhang/shuijing.c
// Last Modified by winder on Nov. 17 2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIM"蝴蝶泉"NOR);
	set("long", @LONG
在向前行，一路上嫣紅奼紫，遍山遍野都是鮮花。春光爛漫已極。
轉過一樹花叢，眼前出現一眼泉水，泉水清澈見底，散發出一種沁人心
脾的清涼。泉水的旁邊，飛舞一羣羣的蝴蝶，或花或白，或黑或紫，翩
翩起舞。蝴蝶並不畏人，飛近時便在人們的身上停留。
LONG	);
	set("outdoors", "tiezhang");
	set("exits", ([ /* sizeof() == 1 */
		"northwest" : __DIR__"guajia",
	]));
	set("no_clean_up", 0);
	set("resource/water", 1);

	set("coor/x", -2020);
	set("coor/y", -1980);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}