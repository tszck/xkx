// Room: /d/taohua/chafang1.c
// Last Modified by winder on Nov. 17 2000

#include <ansi.h>
inherit ROOM;
int do_sit(string arg);
int do_stand();
void delete_served(object me);

void create()
{
	set("short", "茶房");
	set("long", @LONG
這是桃花島弟子們喝茶休息的地方，滿屋的茶香，沁人心脾。屋裏
擺着幾張桌子(table)和椅子(chair)，坐着幾個正在喝茶聊天的男女弟
子。屋中有幾個啞僕正在忙着爲大家上茶。
LONG
	);

	set("exits", ([
		"east" : __DIR__"fanting1",
	]));
	
	set("item_desc", ([
		"table" : "典雅的桃木小桌，上面放着水果盤和飲茶器具。\n",
		"chair" : "竹製的坐椅，看上去有些搖搖晃晃。\n",
	]));
	                                

	set("no_fight", 1);
	
	set("coor/x", 8960);
	set("coor/y", -3010);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_stand", "stand");
	add_action("do_stand", "zhan");
	add_action("do_sit", "sit");
	add_action("do_sit", "zuo");
}

int serve_tea(object me)
{
	if (!present(me, this_object())) return 0;
	message_vision("啞僕走過來，給$N端來了一杯茉莉花茶。\n", me);
	
	new(__DIR__"obj/huacha")->move(me);

	me->set_temp("marks/tea_served", 1);
	call_out("delete_served", 120, me);
	return 1;
}

void delete_served(object me)
{
	if ( objectp(me) ) me->delete_temp("marks/tea_served");
}

int do_sit(string arg)
{
	object me = this_player();

	if (me->is_busy() || me->is_fighting())	return notify_fail("你正忙着呢！\n");
	if (arg == "table" || arg == "zhuozi")
		return notify_fail("你要坐在桌子上？那先把你擠出汁再端上來吧。\n");	

	if ( !arg || (arg != "chair" && arg != "yizi") )
		return notify_fail("你要坐在地板上？有個性！可惜的是這會影響桃花島的形象。\n");	
	
	if (me->query_temp("marks/sit"))
		return notify_fail("你已經坐在座位上了。\n");	
			
	message_vision("$N找了個空位座下，等着上茶。\n", me);	
	if( me->query_temp("marks/tea_served") ) {
		message_vision("啞僕走過來對$N打手勢，表示喝飽了的就別再喝了。\n", me);
		message_vision("$N發覺衆人的眼光都在盯着自己，忙站起身來，尷尬地說：我只是試試這椅子結實不結實。\n", me);
		return notify_fail("");
	}
	me->set_temp("marks/sit", 1);

	call_out("serve_tea", 1, me);
	return 1;
}

int do_stand()
{
	object me = this_player();

	if (!me->query_temp("marks/sit"))
		return notify_fail("你已經站着了，是不是站久了有點發昏啊？\n");	
			
	message_vision("$N拍拍屁股，站了起來。\n", me);	
	me->delete_temp("marks/sit");
	return 1;
}

int valid_leave(object me, string dir)
{
	if (me->query_temp("marks/sit"))
		return notify_fail("你打算連椅子也搬出去？\n");	

	if (dir == "east" && present("moli huacha", me))
//	if (random(3)) 
		return notify_fail("啞僕跑過來打手勢，表示不能把沒喝完的帶走。\n");
	
	return ::valid_leave(me, dir);
}