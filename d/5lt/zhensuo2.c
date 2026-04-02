// Room: /d/5lt/zhensuo2.c

inherit  ROOM;
int do_pull(string arg);

void  create  ()
{
	set  ("short",  "診所二樓");
	set  ("long",  @LONG
這裏就是佈置簡單的醫生居室。幾張簡潔的小牀，可以讓任何人休息。總有護士
及時地更換被單枕頭。養足精神後人們愜意的微笑就是對診所主人最好的報答。
LONG);
	set("exits",  ([  //sizeof()  ==  1
		"down"  :  __DIR__"zhensuo",
	]));
	set("item_desc", ([
		"chuang" : "這是一張嶄新的鐵架牀，牀底下似乎還有些什麼。\n" ,
		"牀"     : "這是一張嶄新的鐵架牀，牀底下似乎還有些什麼。\n" ,
		"xia"    : "你仔細看了一下木匣，發現裏面似乎放着一本書。\n",
		"木匣"   : "你仔細看了一下木匣，發現裏面似乎放着一本書。\n",
	]));
	set("coor/x", -140);
	set("coor/y", -30);
	set("coor/z", 10);
	setup();
}

void init()
{
	add_action("do_move", "move");
        add_action("do_move", "nuo"); 
        add_action("do_pick", "pick");
}

int do_move(string arg)
{
	object me = this_player();

	if (!arg||arg!="chuang") return notify_fail("你要挪開什麼？\n");
	if (me->query("neili") < 200)
	{
		message_vision("$N倚住牀身，往旁一挪，鐵架牀紋風不動。\n", me);
		me->set("neili", 0);
		return 1;
	}
	if ( query("chuang") )
		return notify_fail("鐵架牀已經挪開了，再挪就到樓下去了！\n");
	message_vision("$N挪開鐵架牀，牀下好像放着一個木匣(xia)。\n", me);
	set("chuang", 1);
	return 1;
}

void reset()
{
	::reset();
	set("get_available" , 1);
}

int do_pick(string arg)
{
	object me,obj;

	me = this_player();
	if( !arg || arg!="book" ) return notify_fail("你要拿什麼？\n");
	if ( query("get_available") )
	{
		obj = new (BOOK_DIR+"medicine5");
		obj->move(me);
		add("get_available", -1);
		message_vision("$N從木匣中取出一本書。\n",me );
	}
	else
		return notify_fail("你要拿起那本書，卻發現你看花了眼，其實那裏什麼都沒有。\n");
	return 1;
}
