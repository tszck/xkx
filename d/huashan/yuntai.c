// Room: /d/huashan/yuntai.c
// Last Modified by winder on Aug. 1 2002

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "雲臺峯");
	set("long", @LONG
太華北峯又名雲臺峯，它和南面的諸峯連成一條崎嶇的長嶺，構成
了一條魚椎脊似的登峯天梯。香爐峯和梁張峯拱立左右，崢嶸兀突。雲
臺四面都是懸崖絕壁，十分險峻。峯頂建有真武宮，朝南通道上立着石
牌樓兩座，高鑲“北峯頂”三字。
LONG );
	set("exits", ([ /* sizeof() == 4 */
		"southdown" : __DIR__"canglong",
	]));
	set("no_clean_up", 0);
	set("outdoors", "huashan");
	set("coor/x", -880);
	set("coor/y", 220);
	set("coor/z", 110);
	setup();
}
 
void init()
{
	object me = this_player();
	if (me->query_temp("xunshan")) me->set_temp("xunshan/yuntai", 1);
	return;
}
