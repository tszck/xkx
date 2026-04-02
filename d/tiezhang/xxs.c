// Room: /d/tiezhang/xxs.c
// Last Modified by winder on Nov. 17 2000

#include <room.h>
inherit ROOM;
void init();
int do_open();
int do_close();
void create()
{
	set("short", "休息室");
	set("long", @LONG
這是一個黑暗的大房間。窗戶用厚厚的簾子遮住，不露絲毫光亮。
屋內整齊的排列着十幾張木板搭成的牀鋪，可以讓練功後的幫眾及時得
到休息。這裏靜悄悄的，黑暗中偶爾傳來清微的鼾聲。
LONG );
	set("sleep_room", 1);
	set("no_fight", 1);
	set("no_clean_up", 0);
	set("coor/x", -2020);
	set("coor/y", -1950);
	set("coor/z", 30);
	setup();
}

void init()
{
	add_action("do_tui", "tui");
	add_action("do_tui", "push");
}
void close_men()
{
	object room;

	if(!( room = find_object(__DIR__"zoulang4")) )
		room = load_object(__DIR__"zoulang4");
	if(objectp(room))
	{
		delete("exits/south");
			message("vision", "門吱吱呀呀地自己合上了。\n", this_object());
		room->delete("exits/north");
		message("vision", "門吱吱呀呀地自己合上了。\n", room);
	}
}
int do_tui(string arg)
{
	object room;
	object me = this_player();

	if (query("exits/south"))
		return notify_fail("大門已經是開着了。\n");

	if (arg != "men" && arg != "door" && arg != "south")
		return notify_fail("你要開什麼？\n");

	if(!( room = find_object(__DIR__"zoulang4")) )
		room = load_object(__DIR__"zoulang4");
	if(objectp(room))
	{
		set("exits/south", __DIR__"zoulang4");
		message_vision("$N輕手輕腳地把門打開。\n", this_player());
		room->set("exits/north", __FILE__);
		
		if (me->query_temp("sleeped"))
		{
			message("vision", "吱地一聲，"+me->query("name")+"從裏面把門打開了。\n", room);
		} else 
		{
			message("vision", "吱地一聲，"+me->query("name")+"從裏面把門打開。\n", room);
		}	
		remove_call_out("close_men");
		call_out("close_men", 10);
	}

	return 1;
}
