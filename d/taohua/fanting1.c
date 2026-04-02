// Room: /d/taohua/fanting1.c
// Last Modified by winder on Nov. 17 2000

#include <ansi.h>
inherit ROOM;
int do_sit(string arg);
int do_stand();
void delete_served(object me);

void create()
{
	set("short", "飯廳");
	set("long", @LONG
這是桃花島弟子們每日喫飯的地方，飯菜的香味充溢着整個房間。
屋裏擺着一張大桌子(table)和一些椅子(chair)。屋中站着幾個啞僕。
LONG
	);

	set("exits", ([
		"north" : __DIR__"chufang1",
		"west" : __DIR__"chafang1",
		"east" : __DIR__"lianwuchang",
	]));
	
	set("item_desc", ([
		"table" : "一張大八仙桌，上面放着一些碗、盤、筷、勺等器具。\n",
		"chair" : "竹製的坐椅，看上去有些搖搖晃晃。\n",
	]));
	                                

	set("no_fight", 1);
	
	set("coor/x", 8970);
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

int serve_food(object me)
{
	if (!present(me, this_object())) return 0;
	message_vision("啞僕走過來，給$N端來了一碗米飯。\n", me);
	
	new(__DIR__"obj/mifan")->move(me);

	me->set_temp("marks/food_served", 1);
	call_out("delete_served", 120, me);
	return 1;
}

void delete_served(object me)
{
	if ( objectp(me) ) me->delete_temp("marks/food_served");
}

int do_sit(string arg)
{
	object me = this_player();
	string time = NATURE_D->game_time();

	if(me->is_busy() || me->is_fighting()) return notify_fail("你正忙着呢！\n");
	if(arg == "table" || arg == "zhuozi")
		return notify_fail("你要坐在桌子上？那先把你煮熟了再端上來吧。\n");	
	if( !arg || (arg != "chair" && arg != "yizi") )
		return notify_fail("你要坐在地板上？有個性！可惜的是這會影響桃花島的形象。\n");	
	if (me->query_temp("marks/sit"))
		return notify_fail("你已經坐在座位上了。\n");	
	message_vision("$N找了個空位座下，等着喫飯。\n", me);	
	if( (strsrch(time, "辰時") == 0) && (strsrch(time, "午時") == 0) && (strsrch(time, "酉時") == 0) ) 
	{
		message_vision("啞僕走過來對$N打手勢，表示現在不是喫飯時間。\n", me);
		message_vision("$N無奈地又站了起來。\n", me);	
		return notify_fail("");
	}
	if( me->query_temp("marks/food_served") )
	{
		message_vision("啞僕走過來對$N打手勢，表示喫飽了的就不要再喫了。\n",me);
		message_vision("$N發覺衆人的眼光都在盯着自己，忙站起身來，尷尬地說：我只是試試這椅子結實不結實。\n", me);
		return notify_fail("");
	}
	me->set_temp("marks/sit", 1);
	call_out("serve_food", 1, me);
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
	if ((dir == "north") && present("dami fan", me))
//	if (random(3)) 
		return notify_fail("啞僕跑過來打手勢，表示不能把沒喫完的帶走。\n");
	return ::valid_leave(me, dir);
}
