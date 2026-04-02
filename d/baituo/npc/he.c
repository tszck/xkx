// he.c
// Last Modified by winder on May. 15 2001

#include <ansi.h>
inherit NPC;
void create()
{
	set_name(HIW"丹頂鶴"NOR, ({ "danding he", "he", "danding" }) );
	set("race", "飛禽");
	set("age", 170);
	set("long", "一隻罕見的丹頂鶴，通身雪白，頭上的赤頂卻是紅光閃閃。
卻見它左腳被一條鐵鏈拴住，鐵鏈的另一頭梆在一塊大石上。\n");
	set("attitude", "peaceful");
	set("str", 30);
	set("dex", 80);
	set("con", 50);
	set("combat_exp", 150000);
	set_temp("apply/attack", 80);
	set_temp("apply/defense", 150);
	set_temp("apply/dodge", 250);
	set_temp("apply/damage", 50);
	set_temp("apply/armor", 10);
	setup();
}

void die()
{
	object ob;
	message_vision("$N悽慘地鳴叫了幾聲，撲動了幾下就不動了。\n", this_object());
	ob = new("/d/baituo/obj/hdh");
	ob->move(environment(this_object()));
	destruct(this_object());
}
	
