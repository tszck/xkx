// Room: /d/lingxiao/car.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
#include <ansi.h> 
int do_take(string arg);
void create()
{
	set("short","冰車");
	set("long",@LONG
這裏是凌霄城的冰車（bing che）下山之處，此冰車是凌霄城爲了
能直達揚州，所特製而成，能從這雪山之巔飛速滑下，是從雪山去往揚
州的交通工具。你可以乘坐（take）它滑往揚州。
LONG);
	set("outdoors", "lingxiao");
	set("exits",([ /* sizeof() == 1 */
		"east" : __DIR__"iceroad3",
	])); 
	set("objects", ([
		__DIR__"npc/dizi" : 1,
	])); 
	set("item_desc", ([
		"bing che" : "一臺上好紅杉木所制的冰車，供凌霄弟子下山之用。\n"
	]) );
	set("coor/x", -31010);
	set("coor/y", -8900);
	set("coor/z", 140);
	setup();
}
void init()
{
	add_action("do_take", "take");
}
int do_take(string arg)
{
	object me=this_player();

	if( !arg || arg != "bing che" )
	{
		return notify_fail("你要坐什麼？\n");
	}
	if (me->query("family/family_name") != "凌霄城")
		return notify_fail("凌霄弟子道：你又不是凌霄城的，走開。\n");

	message_vision(HIW"$N穩穩當當坐上冰車，向凌霄弟子打個手勢。\n那弟子點了點頭，將開關一扳，冰車就如離弦之箭，向下飛射而出。\n"NOR, me);
	message_vision(HIW"萬裏雪山在$N身邊逝過，如白駒之逝，飛翼之行。$N心神大快，忍不住縱聲長嘯。\n"NOR, me);
	me->move("/d/city/shilijie4");
	return 1;
}

