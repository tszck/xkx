// Npc: /d/lingxiao/npc/wolf.c
// Last Modified by winder on Jul. 15 2001

inherit NPC;

void create()
{
	set_name("雪狼", ({ "xue lang","wolf", "lang" }) );
	set("race", "走獸");
	set("age", 5);
	set("long","一頭雪白的雪狼，昂首直立，兩眼放着綠光，是大雪山上兇猛的野獸。\n");
	set("attitude", "aggressive");
	set("str", 26);
	set("cor", 30);
	set("combat_exp", 5000);

	set("chat_chance",50);
	set_temp("apply/attack", 25);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 18);
	set_temp("apply/defence",20);

	setup();
}

