//shenxiandan.c 神仙丹
#include <ansi.h>
inherit ITEM;
void setup()
{}
void init()
{
	add_action("do_eat", "eat");
}
void create()
{
	set_name(HIY"神"HIG"仙"HIR"丹"NOR, ({"shenxian dan", "xian dan", "dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "顆");
		set("vegetable", 54);
		set("nostrum", 38);
		set("level", 120);
		set("long", "這是一顆天上仙境的丹藥，乃蝦咪碗糕大仙採仙境之精氣神，
歷時七七四十九天，傾畢生之功煉製而成。\n");
		set("value", 50000);
	}
	setup();
}

int do_eat(string arg)
{
	int fw;
	object me = this_player();

	if (!id(arg))  return notify_fail("你要喫什麼？\n");
	if (!present(this_object(), this_player()))
                return notify_fail("你要喫什麼？\n");

	if (me->is_busy() )
		return notify_fail("別急，慢慢喫，小心別噎着了。\n");
	if(arg=="dan") 
	{
          /*	if(me->query("eff_jing") >= me->query("max_jing") &&
			me->query("eff_qi") >= me->query("max_qi") )
		{
			write("沒傷沒病的，別浪費這麼珍貴的藥啦。\n");
			return 1;
		}*/
		fw = (int)me->max_food_capacity();
		me->set("food", fw);
		fw = (int)me->max_water_capacity();
		me->set("water", fw);
	 	me->set("eff_jing",me->query("max_jing"));
		me->set("jing",me->query("max_jing"));
		me->set("eff_qi",me->query("max_qi"));
		me->set("qi",me->query("max_qi"));
		me->set("neili",me->query("max_neili"));
		me->set("tili",me->query("max_tili"));
message_vision(HIG"$N喫下一顆神仙丹，一股清新涼爽從丹田升起，向全身擴散！剎時，你覺得
體內真氣流動，宛若迸發！\n"NOR,me);
		me->start_busy(1);
		destruct(this_object());
	}
	return 1;
}

