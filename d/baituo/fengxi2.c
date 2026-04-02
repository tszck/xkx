// Room: /d/baituo/fengxi2.c
// Last Modified by winder on May. 15 2001

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "縫隙");
	set("long", @LONG
這裏是石塊與石塊之間的夾縫，光線昏暗。你明顯感覺到四周的沙
沙聲是各種毒蟲爬行的聲音，一股股腥味中也夾雜着一些刺鼻的氣息。
你發現前面有一石塊(shikuai) 隱隱發出淡淡的光芒。
LONG);
	set("objects", ([
		__DIR__"npc/yanjing1" : 1,
		__DIR__"npc/hama" : 1,
	]));
	set("exits", ([
		"east" : __DIR__"fengxi1",
		"out"  : __DIR__"yuanzi4",
	]));
	set("item_desc", ([		    
		"shikuai":HIW"\n這塊石頭呈乳白色，散發着陣陣暖氣，石面有一道五彩色的細線，\n石塊上凹陷進去的是個左右兩個手掌的手掌形。\n"NOR,
	]));
	set("coor/x", -49920);
	set("coor/y", 20080);
	set("coor/z", 20);
	setup(); 
}

void init()
{
	add_action("do_push", "tui");
	add_action("do_push", "push");	
}

int do_push(string arg)
{
	object me;
	me = this_player();
	if( !arg || arg=="" ) return 0;
	if( !me->query_temp("baituo_stone1") ) return 0;
	if( (int)me->query_temp("baituo_stone2") ) 
		return notify_fail("你已經推動過了石塊。\n");
	if (arg == "shikuai" )
	{
		message_vision("$N深深吸了口氣，伸出雙手按住石塊上的手印，緩緩向下推去。\n", me);	   
		me->set_temp("baituo_stone2", 1);
		message_vision("$N將石塊按下寸許，隱隱約約聽到地下傳來一陣轟隆聲。\n", me);	    
		me->start_busy(5);	
		call_out("poisoned", 5, me);
		return 1;
	}	
}

int poisoned()
{
	object me = this_player();
	if ((int)me->query_skill("poison", 1) < 120 &&
		!me->query_skill("hamagong", 1))
	{
		tell_object(me, MAG"你感到手心一涼，那道五彩細線已經附在你的手心上。\n" NOR );
		message_vision("$N突然身子一顫，好象是中了毒！\n", me);
		me->apply_condition("bt_poison", 50);
		me->delete_temp("baituo_stone1");
		return 1;
	}   
	if (me->query_skill("hamagong", 1) ||
		me->query_skill("poison", 1) >= 120)
	{
		tell_object(me, MAG"忽然你的手心一涼，那道五彩細線已經附在你的手上。\n" NOR );
		tell_object(me, HIW"你連忙運功調氣，將手心的五彩細線逼出了大半。\n" NOR );
		me->apply_condition("snake_poison", 30);
		me->delete_temp("baituo_stone1");
		return 1;
	}
}
