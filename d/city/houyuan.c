// houyuan.c 財主後院

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "財主後院");
	set("long", @LONG
這裏是財主後院，各種古玩琳琅滿目，商周的青銅、漢瓦當、唐三
彩……，應有盡有，只要擁有一件，就夠你喫一輩子了。崔員外正坐在
琉璃榻上，慢悠悠地喝着蔘湯。東側有一扇門(men)。
LONG );
	set("item_desc", ([
		"men" : "這扇門似乎通向一間密室。\n",
	]));
	set("exits", ([
//		"east" : __DIR__"dongxiang",
		"south" : __DIR__"dayuan",
		"west" : __DIR__"xixiang",
	]));
	set("objects", ([
		__DIR__"npc/cui" : 1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", -30);
	set("coor/y", -13);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_unlock", "unlock");
	if (present("cui yuanwai", environment(this_player())))
		delete("exits/east");
}
int do_unlock(string arg)
{
	object ob;
	if (query("exits/east"))
		return notify_fail("這扇門已經是打開的。\n");
	if (!arg || (arg != "men" && arg != "east"))
		return notify_fail("你要打開什麼？\n");
	if (!(ob = present("laofang key", this_player())))
		return notify_fail("你不會撬鎖。\n");
	set("exits/east", __DIR__"dongxiang");
	message_vision("$N用一把鑰匙打開了祕門，可是鑰匙卻斷了。\n", this_player());
	destruct(ob);
	return 1;
}

int valid_leave(object me, string dir)
{
	if (!wizardp(me) && objectp(present("cui yuanwai", environment(me))) && 
                     dir == "west" && living(present("cui yuanwai", environment(me))))
		return notify_fail("崔員外擋住了你。\n");
	return ::valid_leave(me, dir);
}