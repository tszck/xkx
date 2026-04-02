// lion.c
// Last Modified by Winder on May. 15 2001

inherit NPC;

void create()
{
	set_name("雄獅", ({ "lion", "xiongshi", "shi" }) );
	set("race", "走獸");
	set("age", 15);
	set("long", "一隻矯健的雄獅，十分威風。\n");
//	set("attitude", "aggressive");
	set("attitude", "peace");
	set("shen_type", -1);
	set("combat_exp", 400000);
	set_temp("apply/attack", 300);
	set_temp("apply/defense", 300);
	set_temp("apply/damage", 150);
	set_temp("apply/armor", 50);

	setup();
	set("chat_chance", 10);
	set("chat_msg", ({
		"雄獅一聲長吼，四下傳來陣陣會響。\n",
		"雄獅後足一蹬，猛地一躍到你的面前。\n",
	}) );
}

