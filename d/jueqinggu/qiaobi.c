// Room: /d/jueqinggu/qiaobi.c
// Last Modified by winder on Feb. 17 2001

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "峭壁");
	set("long", @LONG
這裏是一塊較平坦的岩石，只能一兩個人容身。巖壁上模模糊糊有
幾行字(zi)，似乎是利器劃刻上去的，大概是因為時間久遠，只能勉強
認得。下望是霧氣瀰漫的深谷谷底。
LONG
	);
	set("item_desc", ([
		"zi" : HIW "十六年後，在此相會，夫妻情深，勿失信約。
小龍女書囑夫君楊郎，珍重萬千，務求相聚。\n"NOR,]));
	set("outdoors","jueqinggu");
	set("no_clean_up", 0);
	set("coor/x", -530);
	set("coor/y", -330);
	set("coor/z", 50);
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

	if( !arg || arg == "" || (arg != "gudi" && arg != "谷底") ) return 0;
	if((int)(me->query_encumbrance()*100/me->query_max_encumbrance())>=20)
		return notify_fail("你身上負重太多，爬不下去。\n");
 
	if((int)me->query_skill("dodge",1) < 100 )  
	return notify_fail("以你目前的輕功修為，很難爬下去。\n"); 
	message_vision("$N扒住岩石，小心的爬了下去。\n", me);
	me->move(__DIR__"gudi1");
	tell_room(environment(me), me->name() + "從上面爬了下來。\n", ({ me }));
	return 1;
	
}
int do_jump(string arg)
{
	object me;
	me = this_player(); 
	if (arg != "duanchang ya" && arg != "斷腸崖" && arg != "ya") return 0;
	if ( !arg ) return 0;
 
	
	if (!living(me)) return 0;
	if((int)(me->query_encumbrance()*100/me->query_max_encumbrance())>=20) 
	return notify_fail("你身上負重太多，無法跳過去。\n");
 
	if((int)me->query_skill("dodge",1) < 100 )  
		return notify_fail("以你目前的輕功修為，無法跳過去。\n"); 
	message_vision("$N縱身向上面的斷腸崖跳過去。\n", me);
	me->move(__DIR__"duanchangya");
	tell_room(environment(me), me->name() + "從峭壁跳了過來。\n", ({ me }));
	return 1;
}
