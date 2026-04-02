// Room: /d/jueqinggu/gudi2.c
// Last Modified by winder on Feb. 17 2001

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "絕情谷底");
	set("long", @LONG
你只覺陽光耀眼，花香撲鼻，竟是別有天地，他不即爬起，遊目四
顧，只見繁花青草，便如同一個極大的花園，然花影不動，幽谷無人。
你又驚又喜，縱身出水，見十餘丈外有幾間茅屋。
LONG
	);
	set("exits", ([
		"enter" : __DIR__"maowu",
	]));
	set("no_clean_up", 0);
	set("outdoors","jueqinggu");
	set("coor/x", -530);
	set("coor/y", -330);
	set("coor/z", 0);
	setup();
}
void init()
{
	add_action("do_jump","jump");
}

int do_jump(string arg)
{
	object me;
	me = this_player(); 
	if (arg != "tan di" ) return 0;
	if ( !arg ) return 0;
	if (!living(me)) return 0;

	message_vision("$N縱身向寒潭跳了進去。\n", me);
	me->move(__DIR__"hantan1");
	tell_room(environment(me), me->name() + "從岸上跳了進來。\n", ({ me }));
	return 1;
}
