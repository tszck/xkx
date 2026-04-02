// Room: /d/city/jiaowai1.c
// Jan. 8.1998 by Venus
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "草地");
	set("long", @LONG
這是揚州郊外的一片芳草地，落英繽紛，蜂歌蝶舞，朝露夕光，沁
人心脾。真是好時光。偶有幾對小男女結伴踏青，鶯聲麗影，嬉鬧動人。
LONG );

	set("exits", ([
		"north" : __DIR__"dongmen",
		"south" : __DIR__"jiaowai2",
		"east"  : __DIR__"deshengshan",
	]));

	set("no_clean_up", 0);
	set("outdoors", "yangzhoue");
	set("coor/x", 70);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}