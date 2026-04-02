// Room: /d/5lt/huikeshi.c
inherit  ROOM;

#include <room.h>


void  create  ()
{
	set  ("short",  "會客室");
	set  ("long",  @LONG
這裏是村支部的會客室。室裏琳琅滿目的錦旗、獎狀和榮譽證書，
讓你不禁看花了眼。
LONG);
	set("exits",  ([  //sizeof()  ==  1
		"north"  :  __DIR__"czoffice",
	]));
	set("objects",  ([
	]));

        create_door("north", "木門", "south", DOOR_CLOSED);
	set("no_fight", 1);
	set("coor/x", -170);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
}
