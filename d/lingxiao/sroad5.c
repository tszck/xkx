// Room: /d/lingxiao/sroad5.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;  
#include <ansi.h> 
int pick(string);
void create()
{
	set("short","山路");
	set("long",@LONG
越往上走，寒氣愈甚，霜雪漫天紛紛而下。極目遠望，只見滿天雪
白，萬物晶瑩。向北不遠處似乎有個湖泊，山泉瀑布奔騰入湖，綠樹叢
中馥郁的鮮花爭妍鬥豔，讓你不由得加快腳步。路旁結滿了一條條冰柱
（ice） ，倒垂而下，鋒利尖鋭，有時凌霄弟子練劍之時也將其作為兵
器使用。
LONG);
	set("outdoors", "lingxiao");
	set("exits",([ /* sizeof() == 1 */
		"southdown" : __DIR__"sroad4",
		"north"     : __DIR__"sroad6",
	]));
	set("item_desc", ([
		"ice" :"這是一條晶瑩剔透的冰柱，你可以試着扳(pick)下來看看。\n",
	]) );
	set("no_clean_up", 0);
	set("ice_count", 5);
	set("coor/x", -31000);
	set("coor/y", -8960);
	set("coor/z", 110);
	setup();
} 

void init()
{
	add_action("do_pick","pick");
}

void reset_ice()
{
	set("ice_count", 5);
	delete("ice_call_out");
}
int do_pick(string arg)
{
	object me = this_player();

	if (arg == "ice")
	{
		if (query("ice_count"))
		{
			message_vision(HIW"$N小心翼翼地從路旁的樹上扳了一條冰柱下來。\n"NOR, me);
			add("ice_count", -1);
			new(__DIR__"obj/ice")->move(me);
			return 1;
		}
		else {
			if (!query("ice_call_out"))
			{
				remove_call_out("reset_ice");
				set("ice_call_out", 1);
				call_out("reset_ice", 600);
			}
			return notify_fail("冰柱已經被扳完了。\n");
		}
	}
	return 0;
}
