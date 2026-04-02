// Obj: /d/nanshaolin/obj/tie-tong.c 
// Last Modified by winder on May. 29 2001

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("大鐵桶", ({"tie tong", "tong"}));
	set_weight(50000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long","一對大鐵桶，比之尋常水桶大了兩倍有餘，只怕有二百多斤重。\n");
		set("unit", "對");
		set("value", 100);
		set("max_liquid", 10);
		set("shaolin", 1);
		set("no_drop", 1);
	}
	// because a container can contain different liquid
	// we set it to contain water at the beginning
	set("liquid", ([
		"type": "water",
		"name": "清水",
		"drunk_supply": 10,
	]));
}

void init()
{
	add_action("do_fill", "fill");
	add_action("do_fill", "zhuang");
	add_action("do_pour", "pour");
	add_action("do_pour", "dao");
}

int do_fill(string arg)
{
	object me = this_player();
	if (!arg || !id(arg)) return 0;
	if (base_name(environment(me)) != "/d/nanshaolin/fxjing")
	{
		write("只有在山外佛心井才能灌水。\n");
		return 1;
	}
	message_vision("$N將$n裝滿清水。\n", me, this_object());
	set("liquid/remaining", query("max_liquid"));
	return 1;
}

int do_pour(string arg)
{
	object me = this_player();
	if (!arg || arg != "gang") return 0;
	if (base_name(environment(me)) != "/d/nanshaolin/houdian")
	{
		write("要到後殿才有水缸讓你倒水。\n");
		return 1;
	}
	if (!query("liquid/remaining"))
	{
		message_vision("$N拿着兩隻空鐵桶對着大水缸比劃着。\n", me);
		return 1;
	}
	if (query("liquid/remaining") < query("max_liquid"))
	{
		message_vision("$N拿着兩隻沒裝滿水的鐵桶對着大水缸比劃着。\n", me);
		return 1;
	}
	message_vision("$N將清水倒入大水缸中。\n", me, this_object());
	me->receive_damage("qi", 100);
	if(me->query_skill("yiwei-dujiang", 1) < 150)
	{
		me->improve_skill("yiwei-dujiang", 2*(me->query("dex")));
	}
	delete("liquid/remaining");
	if (me->add("carry_count", -1) < 1)
	{
		me->delete("carry_count");
		message_vision("$N幹完活，丟下鐐銬和鐵桶，伸了個懶腰。\n", me);
		if (present("liao kao", me)) destruct(present("liao kao", me));
		destruct(this_object());
	}
	return 1;
}

