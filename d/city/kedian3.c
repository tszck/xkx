// Room: /yangzhou/kedian3.c
// Last Modified by Winder on Jul. 15 2000

inherit ROOM;

void create()
{
	set("short", "秦淮客店客房");
	set("long", @LONG
這是一間很大的客房，陳設十分簡陋。靠牆放了十幾張小木牀，不
少客人正和衣而臥，滿屋子都是呼呼的打酣聲。西邊有張牀是空的，你
躡手躡腳地走了過去。
LONG );
	set_light(0);
	set("sleep_room", "1");
	set("no_fight", "1");
        set("hotel",1);
	set("no_clean_up", 0);
	set("exits", ([
		"out" : __DIR__"kedian2",
	]));
	set("coor/x", 20);
	set("coor/y", -19);
	set("coor/z", 10);
	setup();
}

void init()
{
	add_action("do_shui", "sleep");
}

int do_shui(string arg)
{
	object me = this_player();
	object where = environment(me);	
	if ((me->query("mud_age")-me->query("last_slp"))<120)
		return notify_fail("你剛睡過一覺，先活動活動吧。 \n");
	me->set("last_slp",me->query("mud_age"));
	message_vision("\n$N一歪身，倒在牀上，不一會便鼾聲大作，進入了夢鄉。\n",me);	
	me->set_temp("block_msg/all",1);
	me->set_temp("noliving/sleeped", 1);
	call_out("wakeup", 10 + random(40 - me->query("con")), me, where);
	return 1;
}

void wakeup(object me)
{
 
	if (!me) return;
	while( environment(me)->is_character() )
	me->move(environment(environment(me)));
	me->set("qi", me->query("eff_qi"));
	me->set("jing", me->query("eff_jing"));
	me->add("neili", me->query("max_neili")/2 - me->query("neili")/2 );
	me->delete_temp("noliving");
	message_vision("$N一覺醒來，精力充沛地活動了一下筋骨。\n",me);
	me->delete_temp("block_msg/all");
	tell_object(me, "你一覺醒來，覺得精力充沛，該活動一下了。\n");
}



int valid_leave(object me, string dir)
{
	if ( dir == "out" ) me->delete_temp("rent_paid");

	return ::valid_leave(me, dir);
}