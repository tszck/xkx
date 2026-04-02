// Room: /d/5lt/czoffice.c
inherit  ROOM;

#include <room.h>


void  create  ()
{
	set  ("short",  "村長辦公室");
	set  ("long",  @LONG
這裏就是村長辦公室。不大的房間，卻佈置得井井有條。看到你進
來，屋裏的人都不動聲色地望着你。南邊有一個門(door)。
LONG);
	set("item_desc", ([
		"door" : "這是一扇精巧的木門。\n",
	]));
	set("exits",  ([  //sizeof()  ==  2
		"south"  :  __DIR__"huikeshi",
		"east"   :  __DIR__"chuandashi",
	]));
	set("objects", ([
		__DIR__"npc/fandog" : 1,
	]));

	create_door("south", "木門", "north", DOOR_CLOSED);
	set("no_fight", 1);
	set("coor/x", -170);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
}
