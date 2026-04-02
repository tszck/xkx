// Room: /d/nanshaolin/slyuan.c
// Last Modified by winder on May. 29 2001

inherit ROOM;
#include <ansi.h>
#include <room.h>

void create()
{
	set("short", HIY"舍利院"NOR);
	set("long", @LONG
這是一座寂靜的小院，院中堆滿的劈好的木柴，幾名身穿白布僧衣
的僧人正在往來忙碌着。這裏是寺中僧人圓寂後，焚化歸西的場所。院
落的西面有一道小門。
LONG );
        set("no_fight",1);
	set("outdoors","nanshaolin");
	set("exits", ([
		"east" : __DIR__ "huaishu4",
		"west" : __DIR__ "talin1",
        ]));
        create_door("west", "木門", "east", DOOR_CLOSED);
	set("no_clean_up", 0);
	set("coor/x", 1790);
	set("coor/y", -6210);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

