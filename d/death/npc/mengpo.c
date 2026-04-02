// mengpo.c 孟婆

#include <ansi.h>
#include <login.h>
inherit NPC;

string *death_msg = ({
	HIB "孟婆說道：“孩子，你來啦？”\n\n" NOR,
	HIB "孟婆對你微笑着，說：“既然來了，就不要再想家了。”\n\n\n" NOR,
	HIB "孟婆說：“來到陰間，就要把陽間的事情盡數忘掉纔好。”\n\n" NOR,
	HIB "孟婆說：“這碗茶能使你忘記過去的一切，快把它喝了吧。。。。”\n\n孟婆給你一碗茶。\n" NOR,

});

void create()
{
	set_name("孟婆", ({ "meng po" }) );
	set("long",@LONG
孟婆生於東漢末年，一生未曾婚嫁，守齋行善，直到八十多歲仍然
身體健朗，容貌仍似三四十歲一般，被鄉裏尊爲神仙；後來她入深山
修煉道行，終於在一百三十歲時得道成仙。她昇天後，玉皇大帝命令
她到陰間掌管陰司事務。
LONG);
	set("gender","女性");
	set("attitude", "peaceful");
	set("chat_chance", 10);
	set("chat_msg", ({
		"孟婆輕輕地拍了拍你的肩膀，安慰你。\n",
		"孟婆說：“孩子，你是因爲什麼喪命的？告訴婆婆。”\n",
	}) );
	set("age", 1024);
	set("combat_exp", 100000000);
	set("max_jing", 10000);
	set("max_qi", 10000);
	setup();
}

void init()
{
	remove_call_out("tea_give");
	call_out( "tea_give", 3, this_player(),0 );
}

void tea_give(object ob,int stage)
{
	object tea;
	if( !ob || !present(ob) ) return;

	tell_object(ob, death_msg[stage]);
	if( ++stage < sizeof(death_msg) ) {
		call_out( "tea_give", 3, ob, stage );
		return;
	}
	if( !objectp( present( GRN"mengpo tea"NOR ,ob ) ) && !objectp( present( GRN"mengpo tea"NOR , environment( this_object() ) ) ) )
	{
		tea = new(NOSTRUM_DIR"mengpotea");
		tea->move(ob); 
	}
}
int accept_fight(object me)
{
	command("sigh");
	write("孟婆道：“孩子，你真是不可救藥了！”\n");
	kill_ob(me);
	me->fight_ob(this_object());
	return 1;
}

