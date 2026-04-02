// tiger.c 老虎
// Last Modified by Winder on May. 15 2001
// Date: Sep.22 1997

inherit NPC;

void create()
{
	set_name("老虎", ({ "tiger", "laohu", "hu" }) );
	set("race", "走獸");
	set("age", 20);
	set("long", @LONG
一隻斑斕猛虎，雄偉極了。

         _.-'"''--..__.("\-''-'")
 ('.__.-' (  *  ) .-'    ( @ _@'
  `-..-''.' _.'  (   _.  `(._Y_)
         `. `._`--\  \_-.._`--'.._
          `-.!))  `.(il)   ''-.(li)

LONG);

//	set("attitude", "aggressive");
	set("attitude", "peace");
	set("combat_exp", 30000);
	set_temp("apply/attack", 180);
	set_temp("apply/defense", 180);
	set_temp("apply/damage", 90);
	set_temp("apply/armor", 50);

	setup();

	set("chat_chance", 10);
	set("chat_msg", ({
		"老虎在浚巡，嚇得你大氣都不敢出。\n",
		"老虎仰天長嘯，聲震山谷，黃葉紛墜。\n",
	}) );
}


void die()
{
	object ob, corpse;
	message_vision("$N發出震天動地的一聲長嘯，轟地倒在地上，死了！\n", this_object());
	if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
	ob = new("/clone/medicine/vegetable/hugu");
	ob->move(corpse);

	corpse->move(environment(this_object()));
	destruct(this_object());
}
