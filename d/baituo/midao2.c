// Room: /d/baituo/midao2.c
// Last Modified by winder on May. 15 2001

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIR"祕道"NOR);
	set("long", @LONG
這條陰暗的祕道在山腹中曲折延伸，不知通往何處。這裏的石壁非
常潮濕，看來附近有水源。從這裏開始迷道分成了左右兩邊，往右走好
象可以看見一點亮光。
LONG);		
	set("exits", ([
		"westdown" : __DIR__"midao3",
		"eastdown" : __DIR__"midao5",
		"eastup"   : __DIR__"midao1",
	]));
	set("no_clean_up", 0);
	set("coor/x", -49940);
	set("coor/y", 20080);
	set("coor/z", 0);
	setup(); 
}

void init()
{
	object me = this_player();
	if (random(me->query("kar")) <8 && me->query_con() < 30)
	{ 
		tell_object(me, HIB"你忽然感到呼吸一緊，原來是這裏的空氣污濁、流通不暢。\n" NOR );
		tell_room(environment(me),me->name()+"突然臉色變得極為難看，並深深地吸了口氣。\n" NOR, ({ me }));
		me->add("neili", -50);
		me->receive_wound("qi", 10);
		me->receive_wound("jing", 20);
	}
}
