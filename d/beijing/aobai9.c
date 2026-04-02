// Modified by Zeratul 4.12 2001 匕首和寶甲修改為唯一物品
#include <room.h>
inherit ROOM;

void close_gate();
int do_open(string arg);
int do_close(string arg);

void create()
{
	object ob;
	set("short", "暗室");
	set("long", @LONG
這裏是鰲拜藏寶的地方，各種珠寶玉器，應有盡有，有幾樣尤其顯眼。
LONG );

	set("objects", ([
//		WEAPON_DIR"treasure/bishou" : 1,
//		ARMOR_DIR"treasure/baojia" : 1,
		__DIR__"obj/shouzhuo" : 1,
		__DIR__"obj/jinduan" : 1,
		__DIR__"obj/book14_1" : 1,
		__DIR__"obj/book14_7" : 1,
	]));
	set("coor/x", -202);
	set("coor/y", 4052);
	set("coor/z", 0);
	setup();
  ob=new(WEAPON_DIR"treasure/bishou");
  if ( ob->violate_unique() || 	uptime() < 300)
    destruct(ob);
  else
    ob->move(this_object()); 
  ob=new(ARMOR_DIR"treasure/baojia");
  if ( ob->violate_unique() || 	uptime() < 300)
    destruct(ob);
  else
    ob->move(this_object()); 
}

void init()
{
	add_action("do_open", "open");
	add_action("do_open", "unlock");
}

void close_gate()
{
	object room;

	if(!( room = find_object(__DIR__"aobai7")) )
		room = load_object(__DIR__"aobai7");
	if(objectp(room))
	{
		delete("exits/south");
		message("vision","只聽乒地一聲，暗門自動關了起來。\n",this_object());
                message("vision","你腦海中閃過一個念頭：壞了！出不去了！\n" ,
			this_object());
		room->delete("exits/north");
		message("vision","只聽乒地一聲，暗門自動關了起來。\n",room);
                message("vision","你腦海中閃過一個念頭：哎喲！又進不去了！\n" ,
			room );
	}
}

int do_open(string arg)
{
	object room;

	if (query("exits/south"))
		return notify_fail("暗門已經是開着了。\n");

	if (!arg || (arg != "door" && arg != "south"))
		return notify_fail("你要開什麼？\n");

	if(!( room = find_object(__DIR__"aobai7")) )
		room = load_object(__DIR__"aobai7");
	if(objectp(room))
	{
		set("exits/south", __DIR__"aobai7");
		message_vision("$N使勁把暗門打了開來。\n",this_player());
		room->set("exits/north", __FILE__);
		message("vision","裏面有人把暗門打開了。\n",room);
		remove_call_out("close_gate");
		call_out("close_gate", 10);
	}
	return 1;
}
