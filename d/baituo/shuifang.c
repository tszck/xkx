// Room: /d/baituo/shuifang.c
// Last Modified by Winder on May. 15 2001

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "睡房");
	set("long", @LONG
這間睡房寬敞明亮，想來便是莊主的臥室了。有一張書桌，桌子上
放有幾本書，卻是《易經》之類。牆邊有一大箱子。整個房間看上去極
為單調。
LONG);
	set("no_fight", "1");
	set("objects", ([
		BOOK_DIR"bt_book5" : 1,
		BOOK_DIR"bt_book1" : 1,
	]));
	set("book_count",1);
	set("exits", ([
		"west" : __DIR__"tangwu",
	]));
	set("coor/x", -50000);
	set("coor/y", 20052);
	set("coor/z", 30);
	setup(); 
}

void init()
{
	object book, me = this_player();

	if (random(me->query("kar")) > 20 && query("book_count") >= 1)
	{
		write("你走進屋裏，隨手在牀邊一翻，忽然發現牀單下蓋着什麼東西。\n");
		write("掀開牀單一看，原來是一本薄薄的線裝書。\n");
		book = new("/clone/book/bt_book");
		book->move(environment(me));
	}
	add("book_count", -1);
}
