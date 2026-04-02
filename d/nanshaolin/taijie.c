// Room: /d/nanshaolin/taijie.c
// Last Modified by winder on May. 29 2001

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "臺階");
	set("long", @LONG
這裏是一段向上的臺階，全部用整條的青石鋪設而成，臺階兩側的
扶欄上雕刻着佛經上的名言警句。這裏一個人也沒有，顯得很寂靜，看
來寺中的僧人也不常到這裏來。
LONG );
	set("exits", ([
		"northup" : __DIR__"lxting",
		"south"   : __DIR__"houdian",
	]));
	set("no_clean_up", 0);
	set("outdoors","nanshaolin");
	set("coor/x", 1820);
	set("coor/y", -6170);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

