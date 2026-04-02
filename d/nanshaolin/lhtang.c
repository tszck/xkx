// Room: /d/nanshaolin/lhtang.c
// Last Modified by winder on May. 29 2001

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"羅漢堂"NOR);
	set("long", @LONG
你面前是一座很大的院落，周圍用高牆圍住，院門匾額上寫着『羅
漢堂』三個大字。這裏是少林弟子練習本門基本武功的所在。有很多年
輕的僧人進進出出，院內傳來陣陣呼喝練功的聲音。
LONG );
	set("exits", ([
		"east" : __DIR__"stoneroad4",
		"west" : __DIR__"lwc1",
	]));
	set("outdoors", "nanshaolin");
	set("objects",([
		CLASS_D("nanshaolin")+"/daji" : 1,
	]));
	set("coor/x", 1800);
	set("coor/y", -6240);
	set("coor/z", 10);
	setup();
}
void init()
{ 
	add_action("do_jump","zong");
}
int do_jump(string arg)
{ 
	object me = this_player();   
	if (arg!="bian") return 0;  
	if(me->query_skill("dodge",1)<130)  
		return notify_fail("你功力不夠，跳不上匾額。\n");  
	message("vision",me->name()+"凝氣守中，平空拔起數丈，輕輕落在匾額之後。\n",this_object());
	me->move(__DIR__"bianhou");
	me->set_temp("baitie",1);  return 1; 
}

int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam = (mapping)me->query("family");

	if ((!myfam || myfam["family_name"] != "南少林派") && dir == "west" &&
		objectp(present("xuanku dashi", environment(me))))
		return notify_fail("大疾大師喝道：羅漢堂乃本派弟子習武之處，你非本派弟子，不能入內。\n");
	return ::valid_leave(me, dir);
}
 
