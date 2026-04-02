// smith.c
#include "ansi.h"
inherit NPC;
inherit F_DEALER;

string ask_blade();
string ask_sword();
void create()
{
	set_name("鐵匠", ({ "tiejiang", "smith" }));
	set("title", "鐵匠鋪老闆");
	set("shen_type", 1);

	set("gender", "男性" );
	set("age", 33);
	set("long", "鐵匠正用鐵鉗夾住一塊紅熱的鐵塊放進爐中。\n");

	set("combat_exp", 400);
	set("attitude", "friendly");
	set("vendor_goods",({
		"/kungfu/class/dali/obj/axe",
		"/d/city/obj/changjian",
		"/d/city/obj/hammer",
		"/d/beijing/obj/tudao",
		"/d/city/obj/dagger",
		"/d/xingxiu/obj/tiegun",
		"/d/city/obj/gangdao",
		"/d/city/npc/obj/tiejia",
	}));
	
	set("inquiry", ([
	    "寶劍": (: ask_sword :),
            "寶刀": (: ask_blade :),
	]) );
	setup();

	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}

int accept_object(object who, object ob)
{
	object weapon;
	object me = this_player();
		
	if (ob->query("money_id") && ob->value() >= 3000000) 
	{
		if(me->query_temp("blade_temp"))
		
		{
		weapon = new("/d/city/npc/obj/baodao",1);
		weapon ->move(me);
		me->delete_temp("blade_temp");
		}
		else if(me->query_temp("sword_temp"))
		{
		weapon = new("/d/city/npc/obj/baojian",1);
		weapon ->move(me);
		me->delete_temp("sword_temp");
		}
		else return 1;
		message_vision(HIY"鐵匠掏出一把金光閃閃的兵器給你\n"NOR,who);
		
	
	}	
			

	return 1;

}

string ask_blade()
{
	object me=this_player();
	me->set_temp("blade_temp",1);
	return "寶刀是有，就看你出得起價錢麼......\n";
	
}


string ask_sword()
{
	object me=this_player();
	me->set_temp("sword_temp",1);
	return "寶劍是有，就看你出得起價錢麼......\n";
}

/*
int buy_object(object who, string what)
{
	if( what=="hammer" ) return 300;
	if( what=="changjian" ) return 700;
	return 0;
}

void compelete_trade(object who, string what)
{
	object ob;

	if( what=="hammer" ) ob = new(__DIR__"obj/hammer");
	if( what=="changjian" ) ob = new(__DIR__"changjian");
	ob->move(who);
	if( what=="hammer" )
message_vision("$N交給$n一把沈甸甸的打鐵用鐵錘。\n", this_object(), who);
	if( what=="changjian" )
message_vision("$N交給$n一把青光閃閃的長劍。\n", this_object(), who);
}
*/
