// Room: /d/nanshaolin/duanya.c
// Last Modified by winder on May. 29 2001

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{ 
	set("short",CYN"斷崖坪"NOR);
	set("long", @LONG
出得屋來，對面便是危崖一片。左面是一座孤峯刺天，右面是絕壑
無地。只中央一片平地。對崖看去險峻已極，難以攀援。且壁間遍生青
苔，其滑如油，竟似無路可上。
LONG );
	set("exits", ([
		"south"  : __DIR__"xctang",
	]));
	set("no_clean_up", 0);
	set("outdoors","nanshaolin");
	set("coor/x", 1820);
	set("coor/y", -6080);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
