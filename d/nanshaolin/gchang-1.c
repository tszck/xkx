// Room: /d/nanshaolin/gchang-1.c
// Last Modified by Winder on May. 29 2001

#include <ansi.h>
inherit ROOM;
void init();
void close_gate();
int do_close(string arg);
string look_gate();
int do_open(string arg);

void create()
{
	set("short", "廣場");
	set("long", @LONG
穿過山門，面前三道平行的青石臺階通向前方的一個廣場。臺階上
精工鏤刻着麒麟，玄龜，松鶴等瑞獸，形態逼真動人。廣場正中放着個
二人高的青銅大香爐，前面擺着個香臺，幾位香客正在虔誠謨拜。再往
前就是天王殿。南邊就是南少林的山門(gate)了。
LONG);
	set("item_desc",([
		"gate" : (: look_gate :),
	]));
	set("exits", ([
		"east"  : __DIR__"gchang-3",
		"west"  : __DIR__"gchang-2",
		"north" : __DIR__"qdian",
	]));

	set("outdoors", "nanshaolin");
	set("objects",([
		__DIR__"npc/seng-bing3" : 2,
	]));
	set("coor/x", 1820);
	set("coor/y", -6290);
	set("coor/z", 10);
	setup();
}

void init()
{
	add_action("do_open", "open");
	add_action("do_close", "close");
}

void close_gate()
{
	object room;

	if(!( room = find_object(__DIR__"shanmen")) )
		room = load_object(__DIR__"shanmen");
	if(objectp(room))
	{
		delete("exits/south");
			message("vision", "僧兵上前把大門關了起來。\n", this_object());
		room->delete("exits/north");
		message("vision", "乒地一聲，裏面有人把大門關上了。\n", room);
	}
}

int do_close(string arg)
{
	if (!query("exits/south"))
		return notify_fail("大門已經是關着的了。\n");

	if (!arg || (arg != "gate" && arg != "south"))
		return notify_fail("你要關什麼？\n");

	message_vision("$N朝僧兵點了點頭。\n", this_player());

	remove_call_out("close_gate");
	call_out("close_gate", 2);
	return 1;
}

int do_open(string arg)
{
	object room;

	if (query("exits/south"))
		return notify_fail("大門已經是開着了。\n");
	if (!arg || (arg != "gate" && arg != "south"))
		return notify_fail("你要開什麼？\n");
	if(!( room = find_object(__DIR__"shanmen")) )
		room = load_object(__DIR__"shanmen");
	if(objectp(room))
	{
		set("exits/south", __DIR__"shanmen");
		message_vision("$N使勁把大門打了開來。\n", this_player());
		room->set("exits/north", __FILE__);
		message("vision", "吱地一聲，裏面有人把大門打開了。\n", room);
		remove_call_out("close_gate");
		call_out("close_gate", 10);
	}

	return 1;
}

string look_gate()
{
	return "一道三丈來高的硃紅杉木包銅大門。\n";
}

int valid_leave(object me, string dir)
{
	if ( me->query("id") == "seng bing" &&  dir == "south" ) return 0;
	return ::valid_leave(me, dir);
}
