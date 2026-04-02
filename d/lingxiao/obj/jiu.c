// Obj: /d/lingxiao/obj/jiu.c 參陽玉酒
// Last Modified by winder on Jul. 15 2001

#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
	if (!wizardp(this_player()))
	{
		set("no_give","這麼珍貴的酒，哪能隨便給人？\n");
		set("no_drop","這麼寶貴的美酒，扔了多可惜呀！\n");
		set("no_sell","這樣的美酒都要賣,你太不解風情了吧。\n");
		set("no_put",1);
	}
	add_action("do_drink", "drink");
}

void create()
{
	set_name( YEL "參陽玉酒" NOR , ({"shenyang yujiu", "jiu"}));
	set_weight(90);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "壺");
		set("long","一壺金黃的粘稠藥酒，是凌霄城的珍藏，飲之於學武大有裨益。\n");
		set("value", 0);
		set("drug_type", "補品");
	}
	set("is_monitored",1);
	setup();
}

int do_drink(string arg)
{
	object me = this_player();

	if(!id(arg)) return notify_fail("你要喫什麼？\n");
	if(!present(this_object(), me))
		return notify_fail("你要喫什麼？\n");
	if( me->is_busy() )
		return notify_fail("別急，慢慢喫，小心別噎着了。\n");

	me->set("eff_jing", (int)me->query("max_jing"));
	me->set("jing", (int)me->query("max_jing"));
	me->set("eff_qi", (int)me->query("max_qi"));
	me->set("qi", (int)me->query("max_qi"));
	me->set("neili", (int)me->query("max_neili"));
	message_vision(HIW "$N舉杯飲下參陽玉酒，只覺小腹間熱氣上衝，跟着胸口間便\n如火燒般熱了起來，只覺通體融和，四骸俱泰。\n" NOR, me);
	destruct(this_object());
	return 1;
}

