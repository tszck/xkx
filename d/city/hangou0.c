// Room: /city/hangou0.c
// Last Modified by winder on Apr. 10 2000

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "古邗溝邊");
	set("long", @LONG
古邗溝最後是要匯入南北大運河的，這一段的大運河稱為真楚運河。
古邗溝就是在此匯入真楚運河的。由於靠近河口，這裏的交通更加繁忙，
而在岸上，這裏的村莊也格外的稠密，常有村民駕小舟出沒於大船之間，
其技術不能不讓人讚歎。 
LONG );
	set("exits", ([
		"west" : __DIR__"hangou1",
	]));
	set("outdoors", "yangzhouw");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

