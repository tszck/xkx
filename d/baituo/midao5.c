// Room: /d/baituo/midao5.c
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
	set("exits", ([
		"westup"   : __DIR__"midao2",
		"eastdown" : __DIR__"midao6",
	]));
	set("no_clean_up", 0);
	set("coor/x", -49930);
	set("coor/y", 20080);
	set("coor/z", -10);
	setup(); 
}

void init()
{
	object me = this_player();
	if (random(me->query("kar")) <13 && me->query_con() < 33)
	{
		tell_object(me, HIB"你忽然感到呼吸一緊，原來是這裏的空氣污濁、流通不暢。\n" NOR );	
		tell_room(environment(me),me->name()+"突然臉色變得極爲難看，並深深地吸了口氣。\n" NOR, ({ me }));
		me->add("neili", -50);
		me->receive_wound("qi", 10);
		me->receive_wound("jing", 20);
	}
}
