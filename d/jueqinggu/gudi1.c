// Room: /d/jueqinggu/gudi1.c
// Last Modified by winder on Feb. 17 2001
 
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "絕情谷底");
	set("long", @LONG
只見空谷無人，四周花草茂盛。不遠處有一寒潭，潭水清澈，潭邊
削壁環列，宛似身處一口大井之底。
LONG
	);
	set("no_clean_up", 0);
	set("coor/x", -530);
	set("coor/y", -330);
	set("coor/z", 0);
	set("outdoors","jueqinggu");
	setup();
 
}
void init()
{
	add_action("do_pa", "pa");
	add_action("do_jump", "jump");
}
int do_pa(string arg)
{
	object me = this_player();

	if( !arg || arg == "" || arg !=  "up") return 0;
	if((int)(me->query_encumbrance()*100/me->query_max_encumbrance())>= 20) 
		return notify_fail("你身上負重太多，爬不上去。\n");
 
	if((int)me->query_skill("dodge",1) < 100 )  
	return notify_fail("以你目前的輕功修為，很難爬上去。\n"); 
	message_vision("$N扒住岩石，小心的爬了上去。\n", me);
	me->move(__DIR__"qiaobi");
	tell_room(environment(me), me->name() + "從谷底爬了上來。\n", ({ me }));
	return 1;
	
}
int do_jump(string arg)
{
	object me;
	me = this_player(); 
	if (arg != "tan di" && arg != "han tan" && arg != "寒潭") return 0;
	if ( !arg ) return 0;
	if (!living(me)) return 0;
	message_vision("$N縱身向寒潭跳了進去。\n", me);
	me->move(__DIR__"hantan1");
	tell_room(environment(me), me->name() + "從岸上跳了進來。\n", ({ me }));
	return 1;
}
