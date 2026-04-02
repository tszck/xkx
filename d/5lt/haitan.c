// Room: /d/5lt/haitan.c

inherit ROOM;
int do_jump(string arg);

void create()
{
	set("short", "海灘");
	set("long", @LONG
潔白的沙灘、清澈的海水、涼爽的海風、明媚的陽光、高聳婆娑的
椰林，每天都有很多村民到這裏欣賞美妙的大自然風光。
LONG);
	set("outdoors", "5lt");
	set("exits", ([
		"west"   : __DIR__"yuchang",
		"south"  : __DIR__"xiaolu",
	]));
	set("coor/x", -195);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_jump", ({"jump", "tiao"}));
}

int do_jump(string arg)
{
	object me = this_player();

	if (me->is_busy()) return notify_fail("你正忙着呢！\n");

	if (arg != "chao" && arg != "tide")
		return notify_fail("你要往哪裏跳？\n");

	if (me->query_dex() < 59)
		return notify_fail("你試圖跳進海潮裏，卻總覺得力不從心。\n");

	if (me->query_skill("dodge") < 80)
		return notify_fail("你試圖跳進海潮裏，卻發現自己的輕功修爲還沒有達到這麼高的境界。\n");
	message_vision("$N聳身一躍，跳進了海潮中！\n", me);
	me->move(__DIR__"tide");
	return 1;
}