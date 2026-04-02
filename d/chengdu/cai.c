// Room: /d/chengdu/cai.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "菜場");
	set("long", @LONG
這裏是個小菜場，一般成都的居民都到這裏買菜。雖然場地不是很
大，但品種還是比較齊全的。所以，周圍到也沒有第二家。開菜場的是
老大娘，平日喜歡跟人拉拉家常。只見牆角處似乎有個洞(dong)。
LONG );
	set("exits", ([
		"northeast" : __DIR__"nanjie",
	]));
	set("objects", ([
		__DIR__"npc/oldwomen" : 1,
	]));
	set("item_desc", ([
		"dong" : "這是一個黑不溜湫的洞，裏面不知道有些什麼古怪。\n",
	]));
	set("coor/x", -8060);
	set("coor/y", -3040);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_enter", "enter");
	UPDATE_D->check_user(this_player());
}

int do_enter(string arg)
{
	object me = this_player();
	if( !arg || arg=="" ) return 0;
	if( arg=="dong" )
	{
		message("vision",
			me->name() + "一彎腰往洞裏走了進去。\n",
			environment(me), ({me}) );
		me->move(__DIR__"ruin1");
		message("vision", me->name() + "從洞裏走了進來。\n", environment(me), ({me}) );
		return 1;
	}
}	

