// Room: /d/nanshaolin/fatang.c
// Last Modified by winder on May. 29 2001

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", BLU"法堂"NOR);
	set("long", @LONG
這是一座極大的殿堂，可以同時容納幾百人而絕無問題。這裏是寺
中演説佛經，佛法和阪戒集會的場所。殿內整齊的放着一排排的蒲團，
以供聽經者打坐之用。
LONG );
	set("exits", ([
		"east"      : __DIR__"huilang5",
		"west"      : __DIR__"huilang1",
		"north"     : __DIR__"kchang",
		"southwest" : __DIR__"jietan3",
		"southeast" : __DIR__"jietan4",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1820);
	set("coor/y", -6110);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}

