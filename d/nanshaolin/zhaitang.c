// Room: /d/nanshaolin/zhaitang.c
// Last Modified by winder on May. 29 2001

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIG"齋堂"NOR);
	set("long", @LONG
你面前是一座碩大無比的房屋，這裏便是少林全寺寺僧用齋的齋堂。
它由十幾間房屋相連而成，可以容納全寺的僧人一同用齋。堂前的院內
栽着兩個垂柳，每棵樹下都有一個巨大的鐵缸，裏面盛滿了清水。幾個
僧人正往來忙碌着，將院內打掃得十分乾淨。
LONG );

	set("exits", ([
		"west" : __DIR__"celang-4",
		"east" : __DIR__"fanting1",
		"north" :__DIR__"xjchu",
	]));
	set("objects",([
		CLASS_D("nanshaolin") + "/fangshi" : 1,
	]));
	set("coor/x", 1840);
	set("coor/y", -6270);
	set("coor/z", 10);
	setup();
}

int valid_leave(object me, string dir)
{

	if (  (dir == "west") &&
		(present("mizhi tianou", me) ||
		present("mala doufu", me) ||
		present("furong huagu", me)) &&
		objectp(present("fang shi", environment(me))) )
	switch ( random(2) ) 
	{
		case 0: 
			return notify_fail("方逝和尚把手一伸，説道：食物不得帶出齋堂，這是寺中的規定！\n");
			break;
		case 1:
			message_vision("方逝和尚對$N躬身作了個揖道：主持方丈吩咐過，食物不得帶出齋堂。", me);
			return notify_fail("\n");
			break;
	}
	
	me->delete_temp("marks/sit");
	me->delete_temp("tea_cup");
	return ::valid_leave(me, dir);
}
