// /d/meizhuang/didao3.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void cloth_path();
void create()
{
	set("short", "梅莊密道");
	set("long", @LONG
這是一條昏暗潮濕的地道，地道很長，兩邊點着兩根不太明亮的火
把，地道兩旁的牆壁上畫着很多不知道出自何人之手的壁畫，而且畫得
相當難看，你加快腳步，想知道地道的盡頭是什麼地方。突然之間你發
現這裏的地面已經是木板拼成的了。
LONG
	);
	set("exits", ([
	    "south" : __DIR__"didao2",
	]));
	set("item_desc", ([
		"floor": "這層木板似乎可以拉開(pull)。\n",
	]) );

	set("coor/x", 3490);
	set("coor/y", -1480);
	set("coor/z", 20);
	setup();
}
void init()
{
	add_action("do_open", "pull");
}
int do_open(string arg)
{
 object  me = this_player();

	if(!arg || arg=="")
	{
		write("你要打開什麼？\n");
		return 1;
	}
	if( arg == "floor")
	{
		message_vision("$N拉起地上的木板，發現下面是空的。\n", me);
		if( !query("exits/down") )
		{
			set("exits/down", __DIR__"didao4");
			call_out("close_path", 1);
		}
		return 1;
	}
	else
	{
		write("你不可以打開"+arg+"\n");
		return 1;
	}
}
void close_path()
{
	if( !query("exits/down") ) return;
	message("vision", "木板又彈了回來，遮住了下面的密道。\n", this_object() );
	delete("exits/down");
}