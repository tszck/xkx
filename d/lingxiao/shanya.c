// Room: /d/lingxiao/shanya.c
// Last Modified by Winder on Jul. 15 2001

#include <ansi.h>
inherit ROOM;
int do_open(string arg);

void create()
{
	set("short","山崖");
	set("long",
"映照在陽光白雲之間的，是一座巍峨之極的大城。只見城牆高逾三
丈，牆頭牆垣雪白一片，盡是冰雪。城牆上隱隱有人頭晃動，城頭樹着
一面在罡風中招展的大旗，上面寫着三個大字："HIW"
		      凌霄城"NOR"
    城門前有一張厚厚的吊橋（bridge），正緊緊關閉着。如果想要進
入的話，必須要請人開（open）纔行。\n"
);
	set("outdoors", "lingxiao");
	set("exits",([ /* sizeof() == 1 */
	    "east"  : __DIR__"cityout",
	    "west"  : __DIR__"cityout1",
	    "down"  : __DIR__"yuan",
	]));
	set("item_desc", ([
		"bridge": "一張極大的吊橋，是凌霄城守城的一道防線。\n"
	]) );
	set("coor/x", -31000);
	set("coor/y", -8940);
	set("coor/z", 140);
	setup();
}

void init()
{
	add_action("do_open","open");
}

int do_open(string arg)
{
 

	if( !arg || arg != "bridge" ) {
		return notify_fail("你亂叫什麼？\n");
	}
	message_vision("$N運足力氣，大叫一聲：“開門呀！”，\n",this_player());
	message_vision("只聽得城上有人說道：“有人來了，放吊橋吧。”\n只聽得軋軋聲響，吊橋緩緩放下，露出一個方方正正的城門來。\n", this_player());
	set("exits/north", __DIR__"gate");
	remove_call_out("close");
	call_out("close", 10, this_object());
	return 1;
}

void close(object room)
{
	message("vision","吊橋又“嘎嘎”地升了起來，把城門擋住了。\n", room);
	room->delete("exits/north");
}
