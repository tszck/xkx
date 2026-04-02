// tyroad13.c 桃園小路
// by Marz 

inherit ROOM;
#include "feng.h"
string* npcs = ({
	"little_monkey",
	"monkey",
	"little_monkey",
	"little_bee",
	"bee",
	"little_bee",
});
				
void do_tao();
int do_zhai(string arg);
void create()
{
	int i = random(sizeof(npcs));
	    
	set("short", "桃園");
	set("long", @LONG
眼前豁然開朗，你輕鬆地走在桃園的小路上。兩邊是桃樹林(tree)，
樹上盛開着粉紅的桃花，紅雲一片，望不到邊。不時有蜜蜂「嗡嗡」地
飛過，消失在在花叢中；幾隻猴子在樹上互相追逐着，嘰嘰喳喳地爭搶
桃子。遠處是高高的天柱峯(feng)。
LONG );
	set("outdoors", "wudang");

	set("exits", ([
		"east" : __DIR__"gyroad1",
		"west" : __DIR__"tyroad12",
	]));
	set("item_desc", ([
		"feng" : (:look_feng:),
		"tree" : 
"這是一片桃林，上面結滿了水蜜桃，引得人哈喇子都掉下來了。\n"
	]));
	set("objects", ([
		__DIR__"npc/"+npcs[i] : 1
	]));
	set("taocount",2);
	set("coor/x", -1940);
	set("coor/y", -930);
	set("coor/z", 30);
	setup();
}
void init()
{
	add_action("look_feng", "look");
	add_action("do_zhai","zhai");
}

int do_zhai(string arg)
{
	object tao, me = this_player();

	if( !arg || arg=="" )
	{
		message_vision("你想摘什麼？\n", me);
		return 1;
	}
	if( arg=="tao"||arg=="taozi" )
	{
		if(query("taocount") > 0)
		{
			message_vision("$N桃樹上摘下一個熟透的水蜜桃。\n", me);
			tao = new(__DIR__"obj/mitao");
			tao->move(me);
			add("taocount",-1);
			return 1;
		}
		else
			message_vision("你這麼着急呀？桃還沒熟呢。\n", me);
		remove_call_out("do_tao");
		call_out("do_tao",60);
		return 1;	     
	}
	return 0;
}
void do_tao()
{
	set("taocount",2);
}
