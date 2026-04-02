// Room: /d/heimuya/up4.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void check_trigger();
void on_board();
void arrive();
void close_passage();
void reset();
int do_insert(string arg);

void create()
{
	set("short", "懸崖");
	set("long", @TEXT
又一座陡峭的懸崖立在了你的面前。懸崖上彷彿有座白色的建築，
可雲煙繚繞，看不清晰。崖上又垂下一條繩索(rope)，看上去象是懸崖
上下互通消息的工具，要想辦法找其他的牌子啊。繩索的上面似乎隱約
有一個吊籃(basket)，懸崖的牆上似乎有一個匣子(xiazi)。
TEXT );
	set("outdoors", "heimuya");
	set("exits", ([
		"westdown" : __DIR__"up3",
	]));
	set("item_desc", ([
		"basket" : "那是一個掉籃，看樣子有些古怪。\n",
		"rope"   : "繩子就是繩子，可能是向上的工具。\n",
		"xiazi"  : "這是一個匣子，看樣子是一個開關，匣子的側面有一個插孔。\n",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3260);
	set("coor/y", 4200);
	set("coor/z", 90);
	setup();
}

void init()
{
	add_action("do_insert", "insert");
}

void check_trigger()
{
	object room;

	if(!query("exits/enter") )
	{
		if( !(room = find_object(__DIR__"basket")) )
			room = load_object(__DIR__"basket");
		if( room = find_object(__DIR__"basket") )
		{
			if((int)room->query("insert_trigger")==0 )
			{
				room->set("insert_trigger", 1);
				set("exits/enter", __DIR__"basket");
				room->set("exits/out", __FILE__);
				message("vision","只見一個掉籃(basket)從天而降，你不禁一怔！\n" , this_object() );
				set("item_desc", ([
					"basket" : "這是一個掉籃，是傳説中的交通工具。\n",
				]));
				remove_call_out("on_board");
				call_out("on_board", 15);
			}
			else
				message("vision", "看樣子你得等下撥兒。\n",this_object() );
		}
		else
			message("vision", "ERROR: basket not found\n", this_object() );
	}
}

void on_board()
{
	object room;

	if( !query("exits/enter") ) return;
	message("vision","只見掉籃緩緩向上，四周無限美好，\n你似乎置身於一處人間仙境無異。\n", this_object() );
	if( room = find_object(__DIR__"basket") )
	{
		room->delete("exits/out");
	}
	delete("exits/enter");
	remove_call_out("arrive");
	call_out("arrive",20);
}

void arrive()
{
	object room;
	if( room = find_object(__DIR__"basket") )
	{
		room->set("exits/out", __DIR__"chengdedian");
		message("vision","你眼前一亮，一幢幢白色建築屹立眼前，霎是輝煌。\n",room );
	}
	remove_call_out("close_passage");
	call_out("close_passage", 20);
}

void close_passage()
{
	object room;
	if( room = find_object(__DIR__"basket") )
	{
		room->delete("exits/out");
		room->delete("insert_trigger");
	}
}

int do_insert(string arg)
{
 
	object ob, me = this_player();

	if( !arg || arg=="" ) return 0;
	if( arg=="卡" ) arg = "card4";   
	if( arg=="card4")
	{
		if( !objectp(ob = present(arg, me)) )
			return notify_fail("你身上沒有這樣東西。\n");
		if( !me->query_temp("mark/cards") )
			me->set_temp("mark/cards",1);
		if( me->query_temp("mark/cards")==4)
		{
			check_trigger();
			me->delete_temp("mark/cards");
		}
		else
		{
			me->add_temp("mark/cards",1);
			message("vision","噔的一聲，你看到掉籃向下一節。\n",me);
		}
	}
	return 1;
}