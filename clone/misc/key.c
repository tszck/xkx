// key.c
#include <ansi.h>
inherit ITEM;
int is_key() {return 1;}

void create()
{
	set_name("私房鑰匙", ({"key", "yaoshi"}));
	set("long",
		"這是一把桃花村私人住宅的鑰匙。
可以用來開門(unlock)和關門(lock)。\n");
	set("unit", "把");
	set("weight", 10);
	set("no_put",1);
	set("no_get",1);
	set("no_drop",1);
}

string query_autoload() { return 1 + ""; }	//autoload weapon
void init()
{
        add_action("do_lock","lock");
	add_action("do_unlock","unlock");
}

int do_unlock()
{
	object table, bottle, rose, room, here, me = this_player();
  object *rooms;
  int i;
  if (!present(this_object(), this_player()))
    return 0;

	if (!me->query("home"))
		return notify_fail("你沒私宅呀，在這開什麼開！\n");
	if ((string)environment(me)->query("short")!="桃花坪")
		return notify_fail("你的私宅在桃花谷裏桃花坪上！\n");
	rooms = children("/d/taohuacun/obj/player");
	for (i=0;i < sizeof(rooms);i++)
	{
		if (rooms[i]->query("owner")==me->query("id"))
		 {room=rooms[i];break;}
	}
	if (i == sizeof(rooms))
	{
		seteuid(getuid());
		room = new("/d/taohuacun/obj/player");
	  room -> set("short", me->query("home/home_name"));
	  room -> set("long", me->query("home/home_desc")+"\n");
    room -> set("owner",me->query("id"));
	  table = new("/d/taohuacun/obj/table");
	  bottle = new("/d/taohuacun/obj/bottle");
	  rose = new("/d/taohuacun/obj/rose");
	  rose -> move(bottle);
	  bottle -> move(table);
	  table -> move(room);
	}
	  if(!( here = find_object("/d/taohuacun/taohua5")) )
		  here = load_object("/d/taohuacun/taohua5");
	  here->set("exits/enter", file_name(room) );
	  room->set("exits/out", "/d/taohuacun/taohua5" );
//        set("sleep_room", "1");
	room->set("sleep_room","1");
	message_vision(HIG "$N掏出鑰匙，輕輕一旋，舉手推開房門。\n" NOR,me);
	return 1;
}
int do_lock()
{
	object here;
  object me=this_player();
  object room;
  int i,flag;
  object *inv;
  if (!present(this_object(), this_player()))
    return 0;
	if ((string)environment(me)->query("owner")!=me->query("id")
	 && (string)environment(me)->query("short")!="桃花坪")
		return notify_fail("你的私宅在桃花谷裏桃花坪上！\n");

	if(!( here = find_object("/d/taohuacun/taohua5")) )
		here = load_object("/d/taohuacun/taohua5");
	if ( here->query("exits/enter") && 
	room = find_object(here->query("exits/enter")))
	{
	 	flag=1;
	 	inv=all_inventory(room);
	 	for(i=0;i<sizeof(inv);i++)
	 	 {
	 	 	  if (userp(inv[i]))
	 	 	  {flag=0;break;}
	 	 	}
	 	 if (flag) destruct(room);
	here->delete("exits/enter");
	message_vision(HIG "只聽得碰的一聲響，$N把房門關上了。\n" NOR, this_player());
	}
	else
	{return notify_fail("門沒有開着啊。\n");}
	return 1;
}
void owner_is_killed()
{
        destruct(this_object());
}
