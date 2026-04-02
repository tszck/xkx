// /d/beijing/aobai1.c
// Last Modified by winder on Jan. 18 2002

inherit ROOM;

void create()
{
	set("short","街道");
	set("long", @LONG
再往西就是鰲拜府了，誰也不敢往那兒去。東面是王府井大街。路
邊有個狗洞(dong)，幾隻懶狗正在那裏探頭。
LONG );
	set("outdoors", "beijing");
	set("exits", ([
		"west" : __DIR__"aobai2",
		"east" : __DIR__"wangfu1",
	]));
	set("item_desc", ([
		"dong" : "黑呼呼的狗洞，不知道有多深。\n",
	]));
	set("objects", ([
		"/d/city/npc/bing" : 2,
	]));
	set("coor/x", -190);
	set("coor/y", 4050);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_enter", "enter");
	add_action("do_enter", "zuan");
}

int do_enter(string arg)
{
	object me = this_player();
	mapping fam;

	if( !arg || arg=="" ) return 0;
	if( arg=="dong" )
	{
		if( (fam = me->query("family")) && fam["family_name"] == "丐幫")
		{
			message("vision", me->name() + "運起丐幫縮骨功，一彎腰往狗洞裏鑽了進去。", environment(me), ({me}) );
			me->move("/d/gaibang/underbj");
			message("vision", me->name() + "從洞裏走了進來。\n", environment(me), ({me}) );
			return 1;
		}
		else return notify_fail("這麼小的洞，你鑽得進去嗎？\n");
	}
}
