// jinsheduye.c
#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat","eat");
}

void create()
{
	set_name("金蛇毒液", ({"jinshe duye" ,"jd"}));

	set("unit", "瓶");
	set("long", "這是一瓶劇毒的金蛇毒液。\n");
	set("value", 100);
//	set("no_drop", "這樣東西不能離開你。\n");
	set_weight(100);
	setup();
}

int do_eat(string arg)
{
	object me = this_player();
	object ob = this_object();
	if (arg != "jinshe duye"&& arg !="jd") return 0;
	tell_object(me, "你想死啊，用suicide比較快一點。\n" );
	return 1;
}
