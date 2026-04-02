// chair.c
// Last Modifyed by Winder on Jan. 4 2002

#include <ansi.h>
inherit ITEM;

void create()
{
	string *pname = ({"錦面", "絲繡", "緞面","鵝絨" });
	string *mname = ({"", "大", "靠背", "安樂", "扶手", "摺疊" });
	string *lname = ({"長椅", "躺椅" });
	string name;
	string zname = lname[random(2)];
	name = sprintf("%s%s%s",pname[random(4)],mname[random(6)],zname);
	set_name( name, ({ "chair" }));
	set("class", zname);
	set_weight(30000);
	set("long", "這是一張椅子。\n" );
	set("no_sell", "這樣東西不能隨便買賣");
	set("no_get","公子說了,躺椅是公家的財產,任何人都不能拿走");
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "張");
		set("material", "wood");
		set("value", 2000);
//		set("amount",30);
	}        
	setup();
}
void init()
{
	add_action("do_sit", "sit");
	add_action("do_tang", "tang");
	add_action("do_stand", "stand");
}

int do_sit(string arg)
{
	object ob, who;
//	string str;

	if( !arg || arg == "" ) 
		return notify_fail("你要坐什麼？\n");
	ob = this_object();
	who = this_player();
	if( arg != "chair" && arg != "椅子" && arg != ob->name() )
		return notify_fail("這裏沒有" + arg + "\n");
	if( who->query_temp("rode") )
		return notify_fail("你現在不在地上，怎麼坐？\n");
	if( (int)ob->query("rode") >= 3 ) 
		return notify_fail( ob->name() + "已經坐滿了！\n");
	if( ob->query("class") == "躺椅" && ob->query("tang") ) 
		return notify_fail( ob->name() + "已經有人躺在上面了！\n"); 

	who->set_temp("rode/type", "sit");
	who->set_temp("rode/desc", "坐在" + ob->name() + "上");
	ob->add("rode",1);
	ob->set("no_get", "有人坐在上面哪！\n");
	message_vision("$N一屁股坐在了" + ob->name() + "上。\n", who);
	return 1;
}

int do_stand()
{
	object ob,who;
	int max_qi;
     
	ob = this_object();
	who = this_player();
	if( who->query_temp("rode/type") != "sit")   
		return notify_fail("你本來就沒有坐着！\n");
	who->delete_temp("rode");
	if( ob->query("tang") ) ob->delete("tang");
	else if( ob->query("rode") ) ob->add("rode", -1);
	if( !ob->query("tang") && !ob->query("rode") ) ob->delete("no_get");
	max_qi = (int)who->query("max_qi");
	if( (int)who->query("qi") > ( max_qi - max_qi/4) )                 
		if( random(1) == 1) 
			message_vision("$N一個鯉魚打挺從" + ob->name() + "上彈了起來。\n", who);
		else
			message_vision("$N“嗖”的一聲，從" + ob->name() + "上站了起來。\n", who);
	else
		message_vision("$N懶洋洋地伸了伸手，從" + ob->name() + "上緩緩地站了起來。\n", who);
	return 1;
}
int do_tang(string arg)
{
	object ob,who;
//	string str;

	if( !arg || arg == "" ) 
		return notify_fail("你要躺在什麼上？\n");
	ob = this_object();
	who = this_player();
	if( arg != "chair" && arg != "椅子" && arg != ob->name() )
		return notify_fail("這裏沒有" + arg + "\n");
	if( who->query_temp("rode") )
		return notify_fail("你現在沒站着，不能躺下。\n");
	if( ob->query("tang") )                 
		return notify_fail( ob->name() + "已經有人躺了！\n");
	if( ob->query("rode") )
		return notify_fail( ob->name() + "已經有人坐了！\n");        
	who->set_temp("rode/type", "sit");
	who->set_temp("rode/desc", "躺在" + ob->name() + "上");
	ob->set("tang",1);
	ob->set("no_get", "有人坐在上面哪！\n");
	message_vision("$N象一灘爛泥樣躺在了" + ob->name() + "上。\n", who);
	return 1;
}
