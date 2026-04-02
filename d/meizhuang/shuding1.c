// /d/meizhuang/shuding1.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "松樹頂");
	set("long", @LONG
你終於爬上了松樹的頂端，在這裏你可以看見一片密密厚厚的樹林，
你踩在這裏，如同踩在一塊草地上一樣，遠處可以看見隱隱約約的一座
巍峨的高山。
LONG
	);
	set("book_count",1);
	set("exits", ([ /* sizeof() == 1 */
		"down" : __DIR__"senlin1",
	]));
	set("item_desc", ([ /* sizeof() == 1 */
		"song zhen" : "這塊地方的松針看起來和其他地方的不太一樣。",
		"松樹"      : "這塊地方的松針看起來和其他地方的不太一樣。",
	]));
	set("outdoors", "meizhuang");
	set("no_clean_up", 0);

	set("coor/x", 3500);
	set("coor/y", -1400);
	set("coor/z", 20);
	setup();
}

void init()
{
	add_action("do_pull", "pull");
}
int do_pull(string arg)
{
	object me , ob;
	me = this_player();
	if (arg == "song zhen" &&
		!present("qinpu", me) &&
		query("book_count") >= 1)
	{
		add("book_count", -1);
		ob=new(BOOK_DIR"qinpu");
		ob->move(__DIR__"shuding1");
		message_vision("$N輕輕的掀開厚厚的松針，哇，下面居然有一本書。\n", me);
		return 1;
	}
	else {
		me->receive_damage("qi", 20);
		message_vision("$N的手已經被松針扎得鮮血淋淋，不要再掀了。\n", me);
		return 1;
	}
}
