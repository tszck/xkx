//Room: jiejianyan.c 解劍巖
//Date: Sep 22 1997

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","解劍巖");
	set("long",@LONG
這是武林中極負盛名的武當解劍巖，巖下解劍池水明澈照人。武林
人士經此都自覺解劍，以示對武當派的尊敬。千百年來，概無例外。
LONG);
	set("objects", ([
	   CLASS_D("wudang") +"/shan": 1,
	   "/clone/misc/dache" : 1,
	]));
	set("outdoors", "wudang");
	set("exits",([ /* sizeof() == 1 */
		"eastdown"  : __DIR__"slxl2",
		"westup"    : __DIR__"pine_road",
//		"westup"    : __DIR__"slxl3",
	]));
	set("coor/x", -2030);
	set("coor/y", -800);
	set("coor/z", 10);
	setup();
}

int valid_leave(object me, string dir)
{
//	mapping myfam;

	if ((me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		 && dir == "westup"
		 && objectp(present("zhang cuishan", environment(me))))
	{
		return notify_fail(HIR"張翠山道：“各色人等，到解劍巖都需解劍，千百年來概無例外！”\n"NOR);
	}
	return ::valid_leave(me, dir);
}