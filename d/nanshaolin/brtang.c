// Room: /d/nanshaolin/brtang.c
// Last Modified by winder on May. 29 2001

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"般若堂"NOR);
	set("long", @LONG
你面前是一座很大的院落，周圍用高牆圍住，院門匾額上寫着『般
若堂』三個大字。這裏是少林弟子精研天下各家各派武功的所在。有很
多年輕的僧人進進出出，院內傳來陣陣呼喝練功的聲音。
LONG );
	set("exits", ([
		"west" : __DIR__"stoneroad3",
		"east" : __DIR__"lwc16",
	]));
	set("outdoors", "nanshaolin");
	set("objects",([
		CLASS_D("nanshaolin") + "/dahen" : 1,
		__DIR__"npc/xiao-ku" : 1
	]));
	set("coor/x", 1840);
	set("coor/y", -6240);
	set("coor/z", 10);
	setup();
}

int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam = (mapping)me->query("family");

	if ((!myfam || myfam["family_name"] != "南少林派") && dir == "east" &&
		objectp(present("xuannan dashi", environment(me))))
		return notify_fail("玄難喝道：般若堂乃本派弟子習武之處，你非本派弟子，不能入內。\n");
		
	return ::valid_leave(me, dir);
}
