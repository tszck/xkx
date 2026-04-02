// Room: /d/lingxiao/gate.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
#include <ansi.h>
void init(); 
void close_bridge();
int do_close(string arg);
string look_bridge();
int do_open(string arg);
void create()
{
	set("short", "凌霄內門");
	set("long", 
"這裏是大雪山凌霄城的城門。本來凌霄城少有外敵入侵，但由於地
處西域，隆冬之際常有餓狼前來侵襲，故修築此大城以做抵擋。向城內
望去，只見人頭攘攘，很是繁華，想不到在這西域雪山絕頂，卻有着一
個如此去處。\n"
);
	set("outdoors", "lingxiao");
	set("exits", ([
		"eastup" : __DIR__"walle1",
		"westup" : __DIR__"wallw1",
		"north"  : __DIR__"iceroad1",
	]));
	set("objects", ([
		__DIR__"npc/dizi" : 3,
		__DIR__"npc/wen" : 1,
	]));
	set("coor/x", -31000);
	set("coor/y", -8930);
	set("coor/z", 140);
	setup();
} 
void init()
{
	add_action("do_open", "open"); 
	add_action("do_close", "close");
} 
void close_bridge()
{
	object room;

	if(!( room = find_object(__DIR__"shanya")) )
		room = load_object(__DIR__"shanya");
	if(objectp(room))
	{
		delete("exits/south");
		message("vision","凌霄弟子把吊橋關了起來。\n", this_object());
		room->delete("exits/north");
		message("vision","只聽“嘎嘎”幾聲，吊橋又被關了起來。\n",room);
	}
}
int do_close(string arg)
{
	if (!query("exits/south"))
		return notify_fail("吊橋已經是關着的了。\n");
	if (!arg || (arg != "bridge" && arg != "south"))
		return notify_fail("你要關什麼？\n");
	message_vision("$N朝凌霄弟子招了一下手，他們點了點頭，把吊橋吊了上去。\n", this_player());
	remove_call_out("close_bridge");
	call_out("close_bridge", 2);
	return 1;
}
int do_open(string arg)
{
	object room;

	if (query("exits/south"))
		return notify_fail("吊橋已經放下來了。\n");
	if (!arg || (arg != "bridge" && arg != "south"))
		return notify_fail("你要開什麼？\n");
	if(!( room = find_object(__DIR__"shanya")) )
		room = load_object(__DIR__"shanya");
	if(objectp(room))
	{
		set("exits/south", __DIR__"shanya");
		message_vision("$N讓凌霄弟子把吊橋放了下來。\n", this_player());
		room->set("exits/north", __FILE__);
		message("vision", "“嘎嘎”幾聲，吊橋放了下來。\n", room);
		remove_call_out("close_bridge");
		call_out("close_bridge", 10);
	}
	return 1;
}
string look_bridge()
{
	return "一張極大的吊橋，是凌霄城的一道防線。\n";
}
int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

	if ( (!myfam || myfam["family_name"] != "凌霄城") &&
		dir == "north" &&
		me->query("combat_exp") >= 100 &&
		present("wen wanfu", environment(me)) &&
		living(present("wen wanfu", environment(me))))
	{
		return notify_fail("聞萬夫拔劍攔道：何方高人駕凌敝城，裏面乃本派重地。這位" + RANK_D->query_respect(me) + "請止步。\n");
	}
	else return ::valid_leave(me, dir);
}

