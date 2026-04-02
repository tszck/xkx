// Room: /d/baituo/hswz.c 黑石圍子
// Last Modified by winder on May. 15 2001

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "黑石圍子");
	set("long", @LONG
這個叫做黑石圍子的地方其實是個山前的小湖泊。這裏非常的奇怪，
他四周兩面是大沙漠，一面過去是西域白駝山，往西卻是大草原。周圍
亂七八糟的有幾百個灰褐色的巨石 (stone)，象是自然形成的又象是有
人搬來的。
LONG);
	set("resource/water", 1);
	set("exits", ([
		"south" : __DIR__"gebi",
	]));		 
	set("item_desc", ([
		"stone" : "這裏有一塊特別大的石頭，它後面還有塊石碑，
但被這塊大石擋了，看不見上面有些什麼東西。\n",
	]));
	set("coor/x", -40000);
	set("coor/y", 20010);
	set("coor/z", 0);
	set("outdoors", "baituo");
	setup();
}

void init()
{
	add_action("do_tui", "tui");
	add_action("do_tui", "push");
	add_action("do_kan", "read");
	add_action("do_kan", "look");
}

int do_tui(string arg)
{      
	object me, room;
	int lvl, exp;
	me = this_player();
	room = this_object();
	lvl = me->query_skill("hamagong", 1);
	exp = me->query("combat_exp");
	if( !arg ) return 0;
	if( (int)room->query_temp("stone_pushed") ) 
		return notify_fail("你怎麼這麼喜歡沒事推石頭？\n");	 
	if (arg == "stone" )
	{
		if (me->query_skill_mapped("force") != "hamagong" )
		{
			me->add("neili", -1500);
			message_vision(HIR "$N運氣猛力向巨石一擊，結果不但沒推開它，反而震傷了自己。\n" NOR, me);
			me->unconcious();
			return 1;
		}
		if (me->query("neili") < 1000 || me->query_str() < 25 )
		{
			message_vision("$N運起蛤蟆功使勁推了推巨石，無賴力量不夠，只好做罷。\n", me);
			me->add("neili", -200);
			return 1;
		}	
		else
		{
			me->add("neili", -500);
			message_vision(HIG "$N體內蛤蟆功來回運轉，口中一叫，雙掌推出。\n只聽轟的一聲，巨石竟然被$N推開了，露出了後面的石碑。\n" NOR, me);
			if ( lvl < 50 && lvl*lvl*lvl/10 )
				me->improve_skill("hamagong",me->query("int"));
			room->set_temp("stone_pushed", 1);
			call_out("stone_push", 10);
		}		    
	}
	return 1;
}

int do_kan(string arg)
{      
	object me, room;	
	me = this_player();
	room = this_object();      
	if( !arg ) return 0;	       
	if( !(int)room->query_temp("stone_pushed") ) 
		return notify_fail("隔着塊石頭怎麼看得見？\n");		 
	if ( me->query_skill_mapped("force") != "hamagong" )
		return notify_fail("你看了半天，還是不明白那上面寫了些什麼東西。\n");	      
	tell_object(me, HIB "\n 。。。。。。
此處乃入白陀山莊之祕道，爾既然可以推開巨石，
當已有我蛤蟆功功底，可算白陀山轉之人。可按
如此走法進入山莊。。。\n    
	    白陀山莊莊主西毒歐陽鋒\n\n" NOR);  
	message_vision("$N盯着石碑看了半天，臉上露出欣慰的表情，跟着$N腳步轉了幾轉，走進亂石堆裏不見了。\n", me);
	me->move(__DIR__"midao8");
	tell_object(me, "你兜兜轉轉走了半天，發現自己已經身在山洞中。\n");
	return 1;
}

int stone_push()
{
	object room = this_object();
	if(objectp(room))
	{
		message("vision", "轟的一聲，巨石又滾回來擋住了石碑。\n", this_object());
		room->delete_temp("stone_pushed");
	}
}
int valid_leave(object me, string dir)
{
       if( dir != "northwest" && !userp(me) && !me->query_temp("go"))
		return notify_fail("...\n");	
       return ::valid_leave(me,dir);
}
