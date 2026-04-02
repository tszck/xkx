//Room: ssyb.c 捨身崖壁
//Date: Oct. 21 1997 by That
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short","捨身崖壁");
	set("long",@LONG
你終於游到崖壁。抬頭上望，微見天光。壁面潮溼，裂縫中微有水滲
出。腳下是污濁的臭水，四周的景物都看不清。向東就是你來時的水潭。
LONG);
	set("outdoors","emei");
	set("objects", ([
		__DIR__"npc/frog" : 1,
	]) );
	set("exits",([ /* sizeof() == 1 */
		"east" : __DIR__"st8", 
	]));
	set("no_clean_up", 0);
	set("no_fight",1);
	set("sword_count",1);
	set("coor/x", -6220);
	set("coor/y", -1170);
	set("coor/z", 20);
	setup();
}
void init()
{
	add_action("do_dig","dig");
	add_action("do_climb","climb");
}
int do_climb()
{
	object me = this_player();
	message("vision", me->name()+"使勁爬上去，花了九牛二虎之力。\n", environment(me), ({me}) );
	me->move(__DIR__"gudelin1");
	message("vision", me->name()+"花了九牛二虎之力，到了這個地方，卻不知道在哪裏？\n", environment(me), ({me}) );
	return 1;
}
int do_dig()
{
	object ob, me = this_player();

	if (query("sword_count") <1)
	{
		message_vision("這裏什麼也沒有了，$N深深嘆了口氣。\n",me);
		return 1;
	}

	if (me->query("marks/skysword") )
	{
		if ( uptime() > 1800 && (random(10))==3 )
		{
			add("sword_count", -1);
			me->delete("marks/skysword");
			ob = new(WEAPON_DIR"treasure/skysword");
			if ( ob->violate_unique() )
			{
				destruct( ob );
				message_vision("這裏什麼也沒有了，$N深深嘆了口氣。\n",me);
				return 1;
			}
			message_vision("$N忽然挖到個硬的東西。撿起來抹了土看看，高興的大笑起來。\n", me);
			write("夢寐以求的倚天劍啊！\n");
			ob->move(me);
			message("channel:rumor", MAG"【謠言】某人："+me->query("name")+"拿到倚天劍啦。\n"NOR, users());
		}
		else
		{
			me->receive_damage("qi", 20);
			message_vision("$N使勁往石壁上挖，手都挖出血了。真是白忙了。\n", me);
		}
		return 1;
	} 
	else
	{
		message_vision("$N使勁往石壁上挖，手都挖出血了。挖啥呢？\n",me);
		return 1;
	}
}
