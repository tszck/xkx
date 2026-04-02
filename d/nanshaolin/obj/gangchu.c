// Obj: /d/nanshaolin/obj/gangchu.c
// Last Modified by winder on May. 29 2001

#include <weapon.h>
#include <ansi.h>

inherit STAFF;

void create()
{
	set_name(HIW"鋼杵"NOR,({"gang chu","chu"}));
	set_weight(100000);
	if (clonep())
		set_default_object(__FILE__);
	else{
		set("unit","根");
		set("value",100);
		set("material","black_steel");
		set("long", HIW"這是一根精鋼所鑄的降魔杵，千錘百煉，反射出閃閃的寒光。\n"NOR);
	       set("unwield_msg","$N一聲長嘯，將鋼杵放回背後。\n");
	}
	init_staff(30);

}
void init()
{
	add_action("do_wield","wield");
}
int do_wield(string arg)
{
	object me,ob;
	me=this_player();
	ob=this_object();
	if(!arg) return 0;
	if (arg =="gang chu"|| arg =="chu")
	{ 
		if((int)me->query_str() < 30)
		{
			tell_object(me,"你想舉起鋼杵，奈何過於沉重，拿不動。\n");
			return 1;
		}     
		ob->wield();
		message_vision( HIW"$N雙手用力一舉，將一根沉重的鋼杵高高舉了起來。\n"NOR, me);
		return 1; 
	}
	return 0;
}
