//Edited by fandog, 02/15/2000
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(YEL"木盒"NOR, ({"mu he", "box"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", YEL"這木盒古樸典雅，沉甸甸的，裏面也許有什麼寶貴的物事。\n"NOR);
		set("unit", "個");
		set("open_count", 1);
		set("weight", 20000);
	}
}

void init()
{
	add_action("do_open","open");
}
int do_open()
{
	object ob, me = this_player();
	if (query("open_count") > 0 && uptime() > 300)
	{
		add("open_count", -1);
		ob = new(WEAPON_DIR"treasure/yuewang-jian");
		if ( ob->violate_unique() )
		{
			destruct( ob );
  		ob = new(__DIR__"muhe1");
	  	ob -> move(me);
	  	destruct(this_object());
			message_vision("木盒裏什麼也沒有，$N深深嘆了口氣。\n",me);
			return 1;
		}
		message_vision(HIR "$N伸手打開木盒，只見寒光閃閃，裏面竟是把絕世寶劍！\n" NOR, this_player());
		ob -> move(me);
		ob = new(__DIR__"muhe1");
		ob -> move(environment(this_object()));
		destruct(this_object());
		return 1;
	}
	ob = new(__DIR__"muhe1");
	ob -> move(me);
	destruct(this_object());
	return notify_fail("木盒已經被別人打開過了。\n");
}