// Last Modified by Sir on 9/17/2001
// wg_wuchang3.c

#include <ansi.h>
inherit ROOM;
int do_chuo(string arg);
int do_ti(string arg);
int do_pai(string arg);
int do_zhua(string arg);

void create()
{
	set("short", "北練武場");
	set("long", @LONG
這是間大大的房子，十分寬闊，不少人在這裏汗流浹背的苦練着功
夫，地上有一些練武用的工具，牆角掛着一排大大的沙袋(shadai)，一
些人正在用沙袋練功。
LONG);
	set("outdoors", "wuguan");
	set("exits", ([
		"west" : __DIR__"wg_wuchang1",
		"east" : __DIR__"wg_lang3",
	]));
	set("item_desc", ([
		"shadai" : "一個大沙袋，掛在柱子上，好象有很多用途，幾個人在那裏拍打(da)。\n",
	]));
	set("objects", ([
		__DIR__"npc/wg_nvdizi" : 1,
	]));
	setup();
}

void init()
{
	add_action("do_da", "da");
}
int do_da(string arg)
{
	object me;
	int costj, costq,c_exp,c_skill,skill_num;

	me = this_player();
	if (me->is_busy()) return notify_fail("你現在正忙着呢！\n");
	if (me->is_fighting())
		return notify_fail("你正在戰鬥中，無法專心練功！\n");
	if ( !living(me)) return notify_fail("你發瘋了？\n");
	if( objectp( me->query_temp("weapon")) )
		return notify_fail("只有空手才能打沙袋。\n");
	if ( !arg || arg != "shadai" )
	{
		message_vision("$N伸出手指在空中亂戳亂比一通，好象在鬼畫符！\n",me);
		return 1;
	}
	costj = random((int)me->query("con"))+1;
	costq = random((int)me->query("str"))+1;

	if ((int)me->query("jing") < costj || (int)me->query("qi") < costq)
	{
		message_vision("$N用力過猛，一個不小心，頭碰到了牆上！\n",me);
		me->unconcious();
		return 1;
	}
	me->receive_damage("jing", costj);
	me->receive_damage("qi", costq);       
	message_vision("$N擺了個馬步，運運氣，然後一招向沙袋打去。\n", me);
	c_exp=me->query("combat_exp");
	if ( (int)me->query("combat_exp") < 50000)
	{
		if (random(10)>6 )
		{
			skill_num=random(4);
			switch(skill_num)
			{
				case 0: c_skill=me->query_skill("finger",1);
						if ( ((c_skill*c_skill*c_skill/10)< c_exp) &&
							(int)me->query_skill("finger", 1) < 30 )
						{    
							me->improve_skill("finger", (int)(me->query("int") / 10));
							write(HIM"沙袋左右搖晃，你不知不覺中領悟了些基本指法！\n"NOR);
						}
						else skill_num=1;
				case 1: c_skill=me->query_skill("leg",1);
						if ( ((c_skill*c_skill*c_skill/10)< c_exp) &&
							(int)me->query_skill("leg", 1) < 30 )
						{    
							me->improve_skill("leg", (int)(me->query("int") / 10));
							write(HIM"沙袋左右搖晃，你不知不覺中領悟了些基本腿法！\n"NOR);
						}
						else skill_num=2;
				case 2: c_skill=me->query_skill("claw",1);
						if ( ((c_skill*c_skill*c_skill/10)< c_exp) &&
							(int)me->query_skill("claw", 1) < 30 )
						{    
							me->improve_skill("claw", (int)(me->query("int") / 10));
							write(HIM"沙袋左右搖晃，你不知不覺中領悟了些基本爪法！\n"NOR);
						}
						else skill_num=3;
				case 3: c_skill=me->query_skill("strike",1);
						if ( ((c_skill*c_skill*c_skill/10)< c_exp) &&
							(int)me->query_skill("strike", 1) < 30 )
						{    
							me->improve_skill("strike", (int)(me->query("int") / 10));
							write(HIM"沙袋左右搖晃，你不知不覺中領悟了些基本掌法！\n"NOR);
						}
						else write(HIM"沙袋在你的控制下左右搖晃，看來你已經能熟練應用了！\n"NOR);					       
			}
		}
	
		me->add("potential",random(2));
		me->add("combat_exp",random((int)(me->query("str") / 10)));
	}
	return 1;
}
