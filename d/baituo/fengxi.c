// Room: /d/baituo/fengxi.c
// Last Modified by winder on May. 15 2001

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "縫隙");
	set("long", @LONG
這裏是石塊與石塊之間的夾縫，光線昏暗。你明顯感覺到四周的沙沙
聲是各種毒蟲爬行的聲音，一股股腥味中也夾雜着一些刺鼻的氣息。你發
現前面有一石塊(shikuai) 隱隱發出淡淡的光芒。
LONG);
	set("objects", ([
		__DIR__"npc/yanjing" : 2
	]));
	set("exits", ([
		"north" : __DIR__"fengxi1",
		"out"   : __DIR__"yuanzi2",
	]));
	set("item_desc", ([		    
		"shikuai":BLU"\n這塊石頭呈藍靛色，散發着陣陣寒氣，石塊上凹陷進去的是個右手手掌形。\n"NOR,
	]));
	set("coor/x", -49910);
	set("coor/y", 20070);
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
	if( (int)me->query_temp("baituo_stone") ) 
		return notify_fail("你已經推動過了石塊。\n");
	if (arg == "shikuai" )
	{
		message_vision("$N深深吸了口氣，伸出右手按住石塊上的手印，緩緩向下推去。\n", me); 
		me->set_temp("baituo_stone", 1);
		message_vision("$N將石塊按下寸許，隱隱約約聽到地下傳來一陣轟隆聲。\n", me); 
		me->start_busy(5);
		call_out("poisoned", 5, me);
		return 1;
	}
}

int poisoned()
{
	object me = this_player();
	if ((int)me->query_skill("poison", 1) < 50 &&
		!me->query_skill("hamagong", 1))
	{
		tell_object(me, BLU"你感到石塊上的陰氣順着手臂慢慢傳了上來。\n\n" NOR );
		message_vision("$N突然身子一顫，好象是中了寒毒！\n", me);
		me->apply_condition("cold_poison", 50);
		return 1;
	}
	if (me->query_skill("hamagong", 1) ||
		me->query_skill("poison", 1) >= 50)
	{
		tell_object(me, BLU"忽然一股陰氣順着手臂從石塊上慢慢傳了上來。\n\n" NOR );
		tell_object(me, HIW"你連忙運功調氣，將侵入手臂的寒氣盡數逼了出去。\n" NOR );
		return 1;
	}
}
