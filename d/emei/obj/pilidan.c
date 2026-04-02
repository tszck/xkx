// pilidan.c 霹靂彈
#include <ansi.h>
#include <command.h>
inherit ITEM;
void create()
{
	set_name(HIC"霹靂彈"NOR, ({"pilidan", "dan"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一粒精緻但威力無比的霹靂彈。\n");
		set("unit", "粒");
		set("value", 100);
	}
}

void init()
{
	add_action("do_apply","apply");
}
int do_apply(string arg)
{
	object me,ob;
	object *inv;
	int i;

	me = this_player();
	if( environment(me)->query("no_fight") )
		return notify_fail("你要搞破壞啊。\n");
	if(!id(arg)) return notify_fail("你要搞什麼？\n");
	if(!present(this_object(), me))
		return notify_fail("你要搞什麼？\n");

	if (me->is_busy()) return notify_fail("你正在忙啊。\n");

	tell_room(environment(me),me->query("name")+"的手猛地向下一擲，一聲巨響，大傢什麼也看不見，一片混亂中四散逃開。\n"NOR);

	inv = all_inventory(environment(me));
	for(i=0; i<sizeof(inv); i++)
	{
		ob=inv[i];
		ob->set_temp("no_follow",1);
		if( (ob->is_character()) && (!ob->is_corpse()) )
		{
			GO_CMD->do_flee(ob);
		}
	}

	destruct(this_object());
	return 1;
}
