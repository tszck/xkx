// Room: /d/baituo/midao8.c
// Last Modified by winder on May. 15 2001
inherit ROOM;

#include <ansi.h>

void create()
{
	set("short", HIR"祕道"NOR);
	set("long", @LONG
這條陰暗的祕道在山腹中曲折延伸，不知通往何處。前面的道路越
來越暗，你快要看不見東西了。這裏空氣污濁，還夾雜着一股刺鼻的味
道，你一走過來便覺得頭腦發暈，象是中毒了。
LONG);	
	set("objects", ([
		__DIR__"npc/zhuye" : 1,
		__DIR__"npc/fushe" : 1,
		__DIR__"npc/hama" : 1,			 
	]));
	set("exits", ([
		"west"  : __DIR__"midao7",
		"north" : __DIR__"midao6",
		"south" : __FILE__,
		"east"  : __FILE__,
	]));
	set("coor/x", -49000);
	set("coor/y", 20080);
	set("coor/z", -20);
	setup(); 
}

void init()
{
	object me = this_player();
	if (random(me->query("kar")) <15 && me->query_con() < 35)
	{
		tell_object(me, HIB"你忽然感到呼吸一緊，原來是這裏的空氣污濁、流通不暢。\n" NOR );
		tell_room(environment(me),me->name()+"突然臉色變得極為難看，並深深地吸了口氣。\n" NOR, ({ me }));
		me->add("neili", -50);
		me->receive_wound("qi", 10);
		me->receive_wound("jing", 20);
	}
	add_action("do_use", "use");
}

int do_use(string arg)
{
	object me = this_player();
	if( !arg || arg=="" ) return 0;
	if (!present("fire", me)) return 0;
	if( arg=="fire" )
	{
		write(
"你點燃了火折，只見地上鋪滿了一堆堆的蛇骨，這裏的毒氣便
是由這多年堆積的毒蛇屍骨所產生。由於此處空氣不流通，所以
毒素越積越多，常人已無法忍受。\n");
		me->set_temp("learn_poison", 1);
		return 1;
	}
}
