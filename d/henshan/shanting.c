// Room: /d/henshan/shanting.c
// Date: Sep.1 2001 by ahda

inherit ROOM;

void create()
{
	set("short", "膳廳");
	set("long", @LONG
這兒是劉府的膳廳，幾個燒飯師傅正在忙得油頭黑麪地燒火做飯，
供應（serve）劉府客人的伙食。
LONG );
	set("exits", ([
		"south" : __DIR__"liufudating",
	]));
	set("objects", ([
		__DIR__"npc/shaofanshifu" : 1,
	]));
	set("coor/x", -400);
	set("coor/y", -1160);
	set("coor/z", 0);
	set("no_fight", 1);
	set("ricewater", 30);
	setup();
}

int valid_leave(object me, string dir)
{
	if ( present("soup", me) || present("rice", me))
	return notify_fail("燒飯師傅瞪着一雙怪眼：喫不了要兜着走啊？\n");
	return ::valid_leave(me, dir);
}

void init()
{
        add_action("do_serve","serve");
}

int do_serve()
{
	object me;
	object food;
	object water;
	me=this_player();
        if(present("rice",this_player()) ) 
		return notify_fail("燒飯師傅道：喫完了再拿，別浪費食物。\n");
        if(present("rice",this_object()) ) 
		return notify_fail("燒飯師傅道：喫完了再拿，別浪費食物。\n");
	if (query("ricewater")>0)
	{
		message_vision("燒飯師傅給$N一碗米飯和一碗湯。\n",me);
		food=new(__DIR__"obj/rice");
		water=new(__DIR__"obj/soup");
		food->move(me);
		water->move(me);
		add("ricewater",-1);
	}
	else 
		message_vision("燒飯師傅對$N歉聲道: 嗨，喫的喝的都沒了。\n",me);
	return 1; 
}
