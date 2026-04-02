// Room: /d/taohua/haitan.c
// Last Modified by winder on Nov. 17 2000

#include <ansi.h>
inherit ROOM;
void rtaohua( object ob ) ;

void create()
{
	set("short", "海灘");
	set("long", @LONG
這是桃花島的海灘。藍藍的海藍藍的天，金黃色的沙灘，粉紅的桃
花，這一切都是那麼美。海邊泊着一艘大船(chuan)。
LONG );
	set("item_desc", ([
		"chuan" : "這是桃花島對外聯繫的大船。島上的客人或弟子只要\n上船(enter)就可以回中原。\n",
	]));
	set("exits",([
		"west" :__DIR__"zoulang5",
	]));
	set("no_clean_up", 0);
	set("outdoors", "taohua");
	set("coor/x", 10000);
	set("coor/y", -3000);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_enter", "enter");
}
int do_enter ( string arg )
{
	object ob = this_player () ;
 
	if( !arg || arg !="chuan" ) 
	{
		tell_object(this_player() , "你要 enter 哪兒？\n" ) ;
		return 1 ;
	}
	message_vision("船伕一見有人上船，忙叫了一聲：開船嘍！\n", ob);
	message_vision("船伕升起帆，船就向西方航行。\n", ob);
	ob ->move("/d/taohua/dahai") ;
	tell_object(ob, BLU "你在海上航行了很久很久.......\n" NOR ) ;
	call_out("rtaohua", 10 , ob );
	return 1 ;
}
void rtaohua( object ob )
{
	tell_object(ob , "大船終於抵達了中原的一個繁華城市。你走下船來。\n" ) ;
	ob->move ("/d/jiaxing/jiaxinggang") ;
}