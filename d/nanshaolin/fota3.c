// Room: /d/nanshaolin/fota3.c
// Last Modified by winder on May. 29 2001

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "佛塔三層");
	set("long", @LONG
你進到佛塔裏面，四周陰暗，寂靜無聲，隱約看到正中有一尊積滿
灰塵，蛛網密佈的佛龕。忽然一陣冷風不知從哪吹了過來，你不禁打了
個寒噤。
LONG );
	set("exits", ([
		"down"     : __DIR__"fota2", 
	]));
	set("no_clean_up", 0);
	set("coor/x", 1750);
	set("coor/y", -6190);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}

