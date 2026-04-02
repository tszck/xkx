// bshangfan.c

inherit NPC;

void create()
{
	set_name("臺夷商販", ({ "shang fan", "shang", "fan" }) );
	set("gender", "女性" );
	set("age", 32);
	set("long", "一個臺夷婦女，揹着個竹簍販賣些絲織物品和手工藝品。\n");
	set("combat_exp", 2500);
	set("per", 17);
	set("str", 17);
	set("dex", 20);
	set("con", 17);
	set("int", 22);
	set("attitude", "friendly");
	setup();
	carry_object(__DIR__"obj/bduanqun")->wear();
	add_money("coin", 100);
}

