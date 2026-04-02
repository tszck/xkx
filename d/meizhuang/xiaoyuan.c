// /d/meizhuang/xiaoyuan.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;

void create()
{
	set("short", "琴音小院");
	set("long", @LONG
這是一座看起來非常普通的小小的院落，院子的中間建着一間小屋，
小屋也很普通，就是用茅草為頂，磚土為牆，院子裏沒有什麼擺設，只
有幾堆幹木柴(wood)放在角落裏，其中有一捆特別引人注目。 
LONG
	);
	set("weapon_count",1);
	set("exits", ([ /* sizeof() == 2 */
		"south" : __DIR__"xiaodao",
		"enter" : __DIR__"xiaowu",
	]));
	set("item_desc",([
		"wood" : "一大堆乾柴，其中有一捆的顏色比較特別。\n",
	]));
	set("objects", ([
		__DIR__"npc/ding" : 1,
	]));
	set("outdoors", "meizhuang");

	set("coor/x", 3510);
	set("coor/y", -1430);
	set("coor/z", 20);
	setup();
}
void init()
{
	add_action("do_pull", "pull");
	add_action("do_unlock", "unlock");
	if (present("ding jian", environment(this_player())))
		delete("exits/east");
}
int do_unlock(string arg)
{
	object ob;
	if (query("exits/east"))
		return notify_fail("這扇門已經是打開的。\n");
	if (!arg || (arg != "men" && arg != "east"))
		return notify_fail("你要打開什麼？\n");
	if (!(ob = present("hongyu yaoshi", this_player())))
		return notify_fail("你不會撬鎖。\n");
	set("exits/east", __DIR__"mishi2");
	message_vision("$N把紅玉鑰匙放進門的凹陷處，東邊的一扇門無聲的打開了。\n", this_player());
	destruct(ob);
	return 1;
}
int do_pull(string arg)
{
	object ob, me = this_player();
	if (arg == "wood" && !present("sea-wood", me) &&
		query("weapon_count") >= 1)
	{
		add("weapon_count", -1);
		ob=new(WEAPON_DIR"treasure/sea-wood");
		if ( ob->violate_unique() )
		{
			destruct( ob );
			message_vision("$N找了半天，也沒有發現什麼特別的東西。\n", me);
			return 1;
		}
		ob->move(__DIR__"xiaoyuan");
		message_vision("$N在木柴堆裏撥弄着，一根劍形的木棒掉了出來。\n", me);
		return 1;
	}
	else {
		message_vision("$N找了半天，也沒有發現什麼特別的東西。\n", me);
		return 1;
	}
}
