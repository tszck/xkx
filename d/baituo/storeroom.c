// Room: /d/baituo/storeroom.c
// Last Modified by winder on May. 15 2001

inherit ROOM;
void init();
int do_open(string);
string* obj = ({
	"/d/xingxiu/obj/fire",
	"/d/xingxiu/obj/hulu",
	"/clone/book/bt_book1",
	"/clone/book/bt_book2",
	"/clone/book/bt_book3",
	"/clone/book/bt_book5",
	"/d/baituo/obj/shepi1",
//	"/d/baituo/obj/yao",
//	"/d/baituo/obj/yao1",
//	"/d/baituo/obj/yao2",       
});

void create()
{
	set("short", "儲藏室");
	set("long", @LONG
這是一個儲藏室，四周密不透風。你一進門便聞到一股黴味，在門
外射進來的陽光的照耀下，你看見這裏滿屋的灰塵，成堆成堆的物品快
堆滿了整間房間。你很是奇怪為什麼僕役們離開時不把這些物品也帶走。
只有關閉着的大門(door)。
LONG	);
	set("item_desc" , ([
		"door" : "一扇木門，也許能打開。\n",
	]) );
	set("no_clean_up", 0);
	set("no_fight", "1");
	set("coor/x", -50000);
	set("coor/y", 20020);
	set("coor/z", 20);
	setup();
}

void init()
{
	add_action("do_open","open");
	add_action("do_find", "find");
	add_action("do_find", "zhao");
	add_action("do_find", "fan");
}

int do_open(string arg)
{
	object me=this_player();
	object room;

	if( me->is_busy()) return notify_fail("你正忙着呢，沒手開門。\n");
	if( !arg|| arg!="door") return notify_fail("你要開什麼？\n");
	if(!( room = find_object(__DIR__"kongdi")) )
		room = load_object(__DIR__"kongdi");
	if(!objectp(room)) return notify_fail("ERROR:not found 'kongdi.c' \n");
	if(room->query_temp("lock")==1)
		return notify_fail("門已經從外面鎖住了。\n");
	message_vision("$N輕輕推開門，走了出去，隨手把門掩了起來。\n",me);
	message("vision", "有人走了出來，隨手把門掩上了。\n",room);
	me->move(room);
	return 1;
}

int do_find()
{
 object me;
	me = this_player();
	if( (int)me->query_temp("baituo_find") ) 
		return notify_fail("你已經發現東西了，拿了就走吧。\n");
	if (me->query_skill("hamagong", 1) > 10 &&
		me->query_skill("xidu-poison", 1) > 30)
	{
		message_vision("$N捏着鼻子在物品堆中亂翻着。\n", me);
		remove_call_out("found");
		call_out("found", 1, me);    
		return 1;
	}
	if (me->query_skill("xidu-poison", 1) < 50)
	{
		message_vision("$N捏着鼻子在物品堆中亂翻着。\n", me);
		if(random((int)me->query("kar")) < 15)
		{
			write("你吸了口氣，突然覺得頭中一陣眩暈。\n");
			me->unconcious();
			return 1;
		}
		else
		{
			remove_call_out("found");
			call_out("found", 1, me);    
			return 1;
		}
	}
	else
	{ 
		message_vision("$N捏着鼻子在物品堆中亂翻着。\n", me);
		write("你吸了口氣，突然覺得頭中一陣眩暈。。不好！你中毒了！\n");
		me->apply_condition("snake_poison", 22);
		me->unconcious();
		return 1;
	}
}

int found(object me)
{
	object ob;
	ob = new(obj[random(sizeof(obj))] );
	ob->move(environment(me));
	message_vision("$N翻了半天，找到了"+ob->query("name")+"。\n", me);
	me->set_temp("baituo_find", 1);
	return 1;
}
