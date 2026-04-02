// shedaogao.c
inherit ITEM;
void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
}

void create()
{
	set_name("蛇膽膏", ({"shedan gao", "gao"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "塊");
		set("long", "這是珍貴補品『蛇膽膏』。\n");
		set("value", 1000);
	}
	setup();
}

int do_eat(string arg)
{
	object me = this_player();
	if(!id(arg)) return notify_fail("你要喫什麼？\n");
	if(!present(this_object(), me))
		return notify_fail("你要喫什麼？\n");
	if( me->is_busy() )
		return notify_fail("別急，慢慢喫，小心別噎着了。\n");

	if((me->query("max_jing")>=200)||(me->query("max_qi")>=200))
		return notify_fail("你喫『蛇膽膏』已無效用！\n");
	if(me->query("max_jing")<180)
	{
		me->add("max_jing", 10);
		me->add("jing",10);
		me->add("max_qi",10);
		me->add("qi",10);
	}
	else
	{
		me->add("max_jing",2);
		me->add("jing",2);
		me->add("max_qi",2);
		me->add("qi",2);
	}
	message_vision( "$N喫下一塊蛇膽膏，頓覺一股浩蕩真氣直湧上來，精，氣大增...\n" , me);
	destruct(this_object());
	return 1;
}
