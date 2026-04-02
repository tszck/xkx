//shufang.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short","華山書房");
	set("long",@LONG
這裏是華山派的書房，靠牆是一排書架，裏面堆着亂七八糟的一大
堆書，最近老有人上山尋事，都很久沒人整理書房了，要找啥書都很麻
煩。右側有張書桌，桌上四寶俱備。
LONG);
	set("exits",([
		"north" : __DIR__"garden",
	]));
	if (random(9) == 1)
		set("objects",([
			"/clone/book/zhengqi_book" : 1,
		]));
	if (random(9) == 3)
		set("objects",([
			"/clone/book/ziyun_book1" : 1,
		]));
	if (random(9) == 5)
		set("objects",([
			"/clone/book/ziyun_book2" : 1,
		]));
	if (random(9) == 7)
		set("objects",([
			"/clone/book/ziyun_book3" : 1,
		]));
	set("no_fight", "1");
	set("no_clean_up", 0);
	set("book_count", 1);
	set("coor/x", -870);
	set("coor/y", 210);
	set("coor/z", 120);
	setup();
}
void init()
{
	add_action("do_zhengli", "zhengli");
}
int do_zhengli()
{
	object ob, me=this_player();
	me->add("qi", -5);
	if ((query("book_count") > 0) && (random(5) == 3))
	{
		message_vision( HIY"$N辛辛苦苦整理了好半天，居然在破雜物堆裏發現了一本書。\n"NOR,me);
		ob=new("/clone/book/sword_book2");
		ob->move(me);
		message("channel:rumor", MAG"【謠言】某人："+this_player()->query("name")+"發現了華山劍譜啦。\n"NOR, users());
		add("book_count", -1);
	}
	else message_vision(HIY"$N辛辛苦苦整理了好半天，啥都沒找到，真是白忙了。\n"NOR,me);
	return 1;
}
