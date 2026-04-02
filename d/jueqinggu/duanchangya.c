// Room: /d/jueqinggu/duanchangya.c
// Last Modified by winder on Feb. 17 2001

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "斷腸崖");
	set("long", @LONG
這裏是絕情谷後山峯頂，人跡鮮至，站到崖前，俯視深谷，但見灰
霧茫茫。
LONG
	);
	set("exits", ([
		"southdown" : __DIR__"shanlu3",
	]));
	set("no_clean_up", 0);
	set("outdoors","jueqinggu");
	set("coor/x", -540);
	set("coor/y", -330);
	set("coor/z", 50);
	setup();
 
}
void init()
{
	add_action("do_look", "look");
	add_action("do_jump", "jump");
}
int do_look(string arg)
{
	if( !arg || arg == "" || (arg !=  "ya" && arg!="崖")) return 0;
	write("你仔細打量四周。發現在不遠處有一塊突出來的峭壁，可以勉強容身。\n");
	this_player()->set_temp("jqg_look1", 1);
	return 1;
	
}
int do_jump(string arg)
{
	object me;
	me = this_player(); 
	if (arg != "qiaobi" && arg != "峭壁" ) return 0;
	if (!arg ) return 0;
	if (!me->query_temp("jqg_look1"))
		return notify_fail("你要往那裏跳？\n");
	
	if (!living(me)) return 0;
	if ((int)(me->query_encumbrance()*100/me->query_max_encumbrance())>=50)
		return notify_fail("你身上負重太多，無法跳過去。\n");
 
	if((int)me->query_skill("dodge",1) < 100 )  
		return notify_fail("以你目前的輕功修爲，無法跳過去。\n"); 
	message_vision("$N縱身向前面的峭壁跳了過去。\n", me);
	me->move(__DIR__"qiaobi");
	tell_room(environment(me), me->name()+"從斷腸崖跳了過來。\n", ({ me }));
	me->delete_temp("jqg_look1");
	return 1;
}
