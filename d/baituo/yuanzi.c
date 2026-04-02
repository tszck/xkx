// Room: /d/baituo/yuanzi.c
// Last Modified by winder on May. 15 2001

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "小花園");
	set("long", @LONG
這是個不大的花園，中間一堆假山，一條小溪。旁邊種滿了各類花
草，芳香宜人。北面有一道鎖着的鐵門(tiemen)，可以通往另一個院子。
LONG);
	set("exits", ([
		"west" : __DIR__"tuitang",
	]));
	set("item_desc", ([		
		"tiemen" : "\n這道鐵門極其沉重，看來沒有幾百斤臂力推它不動。真是奇怪為\n何會有如此鐵門在此，就連一般人都可以翻越(climb)旁邊的矮牆。\n",
	]));
	set("outdoors", "baituo");
	set("coor/x", -49900);
	set("coor/y", 20055);
	set("coor/z", 30);
	setup(); 
}

void init()
{
	add_action("do_fan", "fan");
	add_action("do_fan", "pa");
	add_action("do_fan", "climb");
	add_action("do_push", "push");
	add_action("do_push", "tui");
	add_action("do_push", "strike");
	add_action("do_wen", "wen");
	add_action("do_wen", "smell");
}

int do_fan(string arg)
{
	int dex;
	object me;	
	dex = this_player()->query_dex();
	me = this_player();	
	if( (int)me->query("hamagong") ) 
		return notify_fail("你正想翻過牆去，突然有了一股想推開鐵門的衝動。\n");
	if (dex < 18 )
		return notify_fail("這矮牆雖矮，你卻怎麼也翻不過去。\n");
	if (dex > 17 && dex < 25)
	{
		message_vision("$N雙手在矮牆上一按，一翻身便縱了過去。\n", me);
		me->set_temp("baituo_climb", 1);
		me->move(__DIR__"shetan");
		me->start_busy(2);
		return 1;
	}
	if (dex > 24 && dex < 36)
	{
		message_vision("$N運功提氣輕輕一縱，便躍了過去。\n", me);
		me->set_temp("baituo_climb1", 1);
		me->move(__DIR__"shetan");
		me->start_busy(2);
		return 1;
	}
	if (dex > 35)
	{
		message_vision("$N腳尖輕輕一點，高高躍起，飄了進去。\n", me);
		me->set_temp("baituo_climb2", 1);
		me->move(__DIR__"shetan");
		me->start_busy(2);
		return 1;
	}	
}

int do_push(string arg)
{
	int str;
	object me;
	str = this_player()->query_str();
	me = this_player();
	if( !arg || arg=="" ) return 0;
	if (arg == "tiemen" )
	{
		if( (int)me->query_skill("hamagong", 1))
		{
			message_vision("$N蹲下身子，雙掌平伸推向鐵門。\n", me);
			message_vision("鐵門突然打開，$N一沒留神滾了進去。鐵門卻又合上了。\n", me);
			me->add("neili", -100);
			me->receive_damage("qi", 50);
			me->move(__DIR__"yuanzi1");
			return 1;
		}
		if (str < 21 )
			return notify_fail("你使出了喫奶的力氣，可就是推不動這鐵門。\n");
		if (str > 20 && str < 30)
		{
			message_vision("$N使出全身力氣推向鐵門，可鐵門只輕輕動了一下。\n", me);
			me->add("neili", -300);
			me->receive_damage("qi", 200);
			return 1;
		}
		if (str > 29 && str < 38)
		{
			message_vision("$N運功提氣猛地推向鐵門，鐵門發出了轟轟的震動聲，看來馬上就可以推開了。\n可這時$N的力氣剛好使完，只得作罷。\n", me);
			me->add("neili", -300);
			me->receive_damage("qi", 200);
			return 1;
		}
		if (str > 37)
		{
			message_vision("$N內勁運轉，雙掌平伸推向鐵門。\n", me);
			message_vision("鐵門突然打開，$N一沒留神滾了進去。鐵門卻又合上了。\n", me);
			me->add("neili", -300);
			me->receive_damage("qi", 200);
			me->move(__DIR__"yuanzi1");
			return 1;
		} 
	}
	return 1;	
}

int do_wen(string arg)
{
	int con;
	con = this_player()->query_con();

	if ( con > 29 && con < 37)
		write( "你輕輕吸了吸氣，突然感覺到花香中隱隱帶有股腥味。但聞不出是從哪兒來的。\n");
	if ( con > 36 )
		write( "你輕輕吸了吸氣，突然感覺到花香中隱隱帶有股腥味。好象是從鐵門那邊的院子飄來的。\n");
	if ( con < 30 )
		write("你輕輕吸了吸氣，全是芬芳的花香，你都快醉了。\n");
	return 1;	
}

int valid_leave(object me, string dir)
{	
	me->delete_temp("baituo_climb");
	me->delete_temp("baituo_climb1");
	me->delete_temp("baituo_climb2");
	return ::valid_leave(me, dir);
}
