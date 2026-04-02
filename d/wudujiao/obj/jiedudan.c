// jiedudan.c
inherit ITEM;
inherit F_FOOD;
#include <ansi.h>

string *names = ({
	"紅色解毒丹",
	"黃色解毒丹",
	"綠色解毒丹",
	"白色解毒丹",
	"黑色解毒丹",
});
string *name = ({
	"red dan",
	"yellow dan",
	"green dan",
	"white dan",
	"black dan",
});

void create()
{
	set_name("各式解毒丹", ({"jiedu dan", "dan", "yao"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一顆米粒大小的丹丸。\n");
		set("unit", "顆");
		set("value", 20000);
		set("food_remaining", 5);
		set("food_supply", 35);
	}
	set("no_sell",1);
}

void init()
{
	int num = random(sizeof(names));
	if (query("name")=="各式解毒丹")
		set_name(names[num], ({name[num]}));
// ::init();
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
}
int do_eat(string arg)
{
	object me=this_player();
	if(!id(arg)) return notify_fail("你要喫什麼？\n");
	if(!present(this_object(), me))
		return notify_fail("你要喫什麼？\n");
	if(arg=="red dan" ||
		arg=="yellow dan" ||
		arg=="green dan" ||
		arg=="white dan" ||
		arg=="black dan")
	{
		object ob = this_object();
		if((string)ob->query("name")=="紅色解毒丹" && arg=="red dan")
		{
			if((int)this_player()->query_condition("snake_poison") <1)
				tell_object(this_player(), HIG "你喫下一棵紅色解毒丹，但似乎沒有什麼效果！\n" NOR );
			else
			{
				tell_object(this_player(), HIG "你只覺一股清香沁入心肺，頓時靈臺一片空明，神意清爽！\n" NOR );
				this_player()->apply_condition("snake_poison", 0);
			}
			destruct(this_object());
			return 1;
		}
		if((string)ob->query("name")=="黃色解毒丹" && arg=="yellow dan")
		{
			if((int)this_player()->query_condition("wugong_poison") <1)
			tell_object(this_player(), HIG "你喫下一棵黃色解毒丹，但似乎沒有什麼效果！\n" NOR );
			else
			{
				tell_object(this_player(), HIG "你只覺一股清香沁入心肺，頓時靈臺一片空明，神意清爽！\n" NOR );
				this_player()->apply_condition("wugong_poison", 0);
			}
			destruct(this_object());
			return 1;
		}
		if((string)ob->query("name")=="綠色解毒丹"& arg=="green dan")
		{
			if((int)this_player()->query_condition("zhizhu_poison") <1)
				tell_object(this_player(), HIG "你喫下一棵綠色解毒丹，但似乎沒有什麼效果！\n" NOR );
			else
			{
				tell_object(this_player(), HIG "你只覺一股清香沁入心肺，頓時靈臺一片空明，神意清爽！\n" NOR );
				this_player()->apply_condition("zhizhu_poison", 0);
			}
			destruct(this_object());
			return 1;
		}
		if((string)ob->query("name")=="白色解毒丹"& arg=="white dan")
		{
			if((int)this_player()->query_condition("xiezi_poison") <1)
				tell_object(this_player(), HIG "你喫下一棵白色解毒丹，但似乎沒有什麼效果！\n" NOR );
			else
			{
				tell_object(this_player(), HIG "你只覺一股清香沁入心肺，頓時靈臺一片空明，神意清爽！\n" NOR );
				this_player()->apply_condition("xiezi_poison", 0);
			}
			destruct(this_object());
			return 1;
		}
		if((string)ob->query("name")=="黑色解毒丹"& arg=="black dan")
		{
			if((int)this_player()->query_condition("chanchu_poison") <1)
				tell_object(this_player(), HIG "你喫下一棵黑色解毒丹，但似乎沒有什麼效果！\n" NOR );
			else
			{
				tell_object(this_player(), HIG "你只覺一股清香沁入心肺，頓時靈臺一片空明，神意清爽！\n" NOR );
				this_player()->apply_condition("chanchu_poison", 0);
			}
			destruct(this_object());
			return 1;
		}
	}
	return 1;
}
