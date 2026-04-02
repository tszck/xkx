// Room: /d/chengdu/qianzhuang.c
// Last Modifyed by Winder on Jan. 4 2002

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "川號錢莊");
	set("long", @LONG
這裏是城裏最有名的錢莊：川號錢莊，利息雖低但決不拖欠。聽説
主人是青城俗家弟子，曾經在川中橫行數世，流氓土匪一般都不來這找
麻煩。所以這裏一向是生意很好。
LONG	);
	set("exits", ([ 
		"east" : __DIR__"chunxilu2",
	]) );
	set("objects", ([
		__DIR__"npc/boss3" : 1,
	]));
	set("coor/x", -8070);
	set("coor/y", -2980);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	tell_object(this_player(),WHT "你拍了拍口袋，嘆了口氣，走出了錢莊。\n"NOR,this_player());
	return 1;
}
