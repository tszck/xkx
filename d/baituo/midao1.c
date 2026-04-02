// Room: /d/baituo/midao1.c
// Last Modified by winder on May. 15 2001

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIR"祕道"NOR);
	set("long", @LONG
這條陰暗的祕道在山腹中曲折延伸，不知通往何處。這裏的石壁非
常潮溼，看來附近有水源。
LONG);
	set("objects", ([
		__DIR__"npc/hama" : 1,
	]));
	set("exits", ([
		"westdown" : __DIR__"midao2",
		"east"     : __DIR__"midao0",
	]));
	set("coor/x", -49930);
	set("coor/y", 20080);
	set("coor/z", 10);
	setup(); 
}

void init()
{
	object me = this_player();
	if (random(me->query("kar")) <8 && me->query_con() < 30)
	{ 
		tell_object(me, HIB"你忽然感到呼吸一緊，原來是這裏的空氣污濁、流通不暢。\n" NOR );
		tell_room(environment(me),me->name()+"突然臉色變得極爲難看，並深深地吸了口氣。\n" NOR, ({ me }));
		me->add("neili", -50);
		me->receive_wound("qi", 10);
		me->receive_wound("jing", 20);
	}
}
