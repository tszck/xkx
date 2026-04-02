// Last Modified by Winder on May. 15 2001
// food.c

#include <dbase.h>
#include <name.h>

void init()
{
	if (!query("decay") && userp(environment()))
	{
		set("decay", 1);
		remove_call_out("decay");
		call_out("decay", 280);
	}
}

int do_eat(string arg)
{
	if( !living(this_player()) || this_player()->query_temp("noliving") )
		return 1;
	if( this_player()->query("jing")<0 || this_player()->query("qi")<0 )
		return notify_fail("你太累了，實在沒力氣喫什麼了。\n");
	if( !this_object()->id(arg) ) return 0;
	if( !present(this_object(), this_player()))
		return notify_fail("你要喫什麼東西？\n");
	if( this_player()->is_busy() )
		return notify_fail("別急，慢慢喫，小心別噎着了。\n");
	if( !query("food_remaining") )
		return notify_fail( name() + "已經沒什麼好喫的了。\n");
	if( (int)this_player()->query("food") >=
		(int)this_player()->max_food_capacity() )
		return notify_fail("你已經喫太飽了，再也塞不下任何東西了。\n");

	this_player()->add("food", query("food_supply"));
	if( this_player()->is_fighting() ) this_player()->start_busy(2);

	// This allows customization of drinking effect.
	if( query("eat_func") ) return 1;

	set("value", 0);
	add("food_remaining", -1);
	if( !query("food_remaining") )
	{
		message_vision("$N將剩下的"+name()+"喫得乾乾淨淨。\n",this_player());
		if( !this_object()->finish_eat() ) destruct(this_object());
	} else message_vision("$N拿起" + name()+"咬了幾口。\n", this_player());
//	this_player()->start_busy(1);
	return 1;
}

void decay()
{
	object me = this_object(), ob = environment();
	if (!me || !ob) return;
	switch(add("decay", 1))
	{
		case 2:
			set_temp("apply/long",({query("long")+"可是看起來不是很新鮮。\n"}));
			tell_object(ob, me->name()+"的顏色有些不對了。\n");
			break;
		case 3:
			set_temp("apply/long", ({query("long")+"可是正在散發出一股難聞的味道。\n"}));
			tell_object(ob,me->name()+"散發出一股難聞的味道。\n");
			break;
		case 4:
			set_temp("apply/long",({query("long")+"可是有些腐爛了。\n"}));
			tell_object(ob,me->name()+"有些腐爛了，發出刺鼻的味道。\n");
			break;
		default:
			tell_object(ob,me->name()+"整個腐爛掉了。\n");
			destruct(this_object());
			return;
	}
	remove_call_out("decay");
	call_out("decay", 150);
}
