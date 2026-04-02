// Room: /d/lingxiao/meiroad2.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
#include <ansi.h> 
void init();
int pick(string);
void create()
{
	set("short","梅道");
	set("long",@LONG 
這也是一條充滿梅花清香的小道。與殿外不同的是，這兒種滿了梅
樹，而且全是如鮮血般燦爛的紅梅，花瓣片片飄落，落到潔白的雪地上，
就如一個溫婉和順的美人，在給自己的心上人刺繡時，不小心刺破了手
指而流出的一滴血，浸到了白絹上一樣。一隻通體雪白的雪鶴在地上翩
然起舞，逍遙自得。
LONG);
	set("outdoors", "lingxiao");
	set("exits",([ /* sizeof() == 1 */
		"west"  : __DIR__"stone",
		"east"  : __DIR__"meiroad1",
	]));
	set("objects", ([
		__DIR__"npc/xuehe" : 1,
		__DIR__"obj/ban" : 1,
	]));
	set("coor/x", -31010);
	set("coor/y", -8890);
	set("coor/z", 140);
	setup();
}

void init()
{
	add_action("do_pick","pick");
}

int do_pick(string arg)
{
	object ob, me = this_player();

	if (!arg || arg!="hua" && arg!="flower")
		return notify_fail("你要摘什麼？\n");
	ob=new(__DIR__"obj/mei");
	ob->move(me);
	message_vision("$N從路旁的樹上摘了一朵"+ob->query("name")+"。\n"NOR,me);
	return 1;
}

