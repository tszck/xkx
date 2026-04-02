// gytoad2.c 果園小路
// by Java

inherit ROOM;
#include <ansi.h>
int do_zhai(string arg);
void create()
{
	set("short", "果園");
	set("long", @LONG
你輕鬆地走進果園。園中落英繽紛，兩邊是桃樹林，盛開着粉紅的
桃花，紅雲一片，望不到邊。中間卻是一株冠蓋數畝的大樹(tree)，遮
住地面好大一片綠蔭。
LONG );
	set("outdoors", "wudang");
	set("item_desc", ([
		"tree" : 
"這是一株人蔘果樹，上面結着人蔘果，據說摘下喫了對武功進益很有好處。\n"
	]));
	set("exits", ([
		"west" : __DIR__"gyroad1",
	]));
	set("no_clean_up", 0);
	set("guocount",1);
	set("coor/x", -1920);
	set("coor/y", -930);
	set("coor/z", 30);
	setup();
}

void init()
{
	add_action("do_zhai","zhai");
}

int do_zhai(string arg)
{
	object guo;
	if( !arg || arg=="" )
	{
		message_vision("你想摘什麼？\n", this_player());
		return 1;
	}
	if( arg=="guo"||arg=="renshen guo" )
	{
		if(uptime() < 1800)
		{
	message_vision("人蔘果未熟呢，$N等一會再來吧。\n",this_player());
			return 1;
		}
		if(query("guocount") > 0 && random(2)==1)
		{
//message("channel:rumor", MAG"【謠言】某人："+this_player()->query("name")+"得到一個人蔘果了。\n"NOR, users());
	message_vision("$N從人蔘果樹上摘下一個熟透的"HIR"人蔘果。\n"NOR,
			this_player());
			guo = new("/clone/medicine/nostrum/renshenguo");
			guo->move(this_player());
			add("guocount",-1);
			return 1;
		}
		else
		{
			set("guocount",0);
			message_vision("$N真是好可憐啊？人蔘果剛被摘走。\n",this_player());
			return 1;	     
		}
	}
	return 0;
}
