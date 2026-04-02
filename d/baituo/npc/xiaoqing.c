// /npc/xiaoqing.c
// Last Modified by Winder on May. 15 2001

#include <ansi.h>
inherit NPC;

void greeting(object);
void init();
string inquiry_gao();

void create()
{
	set_name("小青", ( { "qing", "xiao qing" }) );
	set("title", "藥劑師");
	set("gender", "女性" );
	set("age", 16);
	set("long","這是個聰明乖巧的小姑娘，打扮的很樸素，一襲青衣，卻也顯得落落有致。\n小青對人非常熱情。你要是跟她打過交道就會理解這一點！\n");
	set("attitude", "friendly");
	set("shen_type", -1);

	set("str", 20);
	set("int", 29);
	set("con", 23);
	set("dex", 22);

	set("max_qi", 130);
	set("max_jing", 120);
	set("neili", 120);
	set("max_neili", 120);

	set("combat_exp", 60000);
	set("score", 1000);

	set_skill("force", 26);
	set_skill("dodge", 23);
	set_skill("unarmed", 24);
	set_skill("parry", 22);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 15);
	set_temp("apply/damage", 17);
	set_temp("apply/armor", 10);

	set_temp("dan",0);
	set_temp("times",5);
	create_family("白駝山派", 3, "弟子");

	set("inquiry", ([
		"海口大碗": "這『海口大碗』你可以拿到頂東頭小院兒去，灌水喝。\n",
		"藥罐"    : "藥罐在那兒，你自己看吧！\n",
		"蛇膽膏"  : (: inquiry_gao :),
		"gao"     : (: inquiry_gao :),
	]));
	setup();
	carry_object("/d/baituo/obj/qingpao")->wear();
}

void init()
{
	object ob;

	::init();

	if( interactive(ob = this_player()) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{

	if( !ob || environment(ob) != environment() ) return;
	if(random(2)==1)
	{
		say("小青笑吟吟地說道：這位" + RANK_D->query_respect(ob) + "請進，見到你真高興。\n");
		return;
	}
	else
	{
		say("小青笑了笑說道：這位" + RANK_D->query_respect(ob) + "快請進吧。 \n");
		return;
	}
}

string inquiry_gao()
{
	object ob=this_player();
	if(query_temp("dan")==3) return "你沒見我已經作好了嘛！\n";
	if(query_temp("times")==0)
		return "師傅現在已經不叫我做『蛇膽膏』了！\n";
	say("這位"+RANK_D->query_respect(ob)+"不瞞您說。師傅讓我作『蛇膽膏』，\n可我",ob);
	switch (query_temp("dan"))
	{
		case 0: write(HIY "差一隻青蛇膽，一隻金蛇膽。\n" NOR);
			break;
		case 1: write(HIY "還差一隻金蛇膽。\n" NOR);
			break;
		case 2: write(HIY "還差一隻青蛇膽。\n" NOR);
			break;
	}
	return "不知哪位好心人能幫幫我呢？\n";
}

int accept_object(object who, object ob)
{
	object obn;

	if( !who || environment(who) != environment() ) return 0;
	if ( !objectp(ob) ) return 0;
	if ( !present(ob, who) ) return notify_fail("你沒有這件東西。\n");

	if (  (string)ob->query("id") != "qing dan" &&
		(string)ob->query("id") != "jin dan"  )
		return notify_fail("小青不需要這件東西。\n");
	if ( query_temp("times")==0 )
		return notify_fail("小青現在已經不做『蛇膽膏』了。\n");
	if ( (string)ob->query("id") == "jin dan" )
	{
		if (query_temp("dan")==2)
		{
			message_vision("小青一看是金蛇膽，滿臉遺憾地對$N說：我還差青蛇膽，不缺金蛇膽。\n",who);
			return 0;
		}
		add_temp("dan",2);
		if (query_temp("dan")==2)
		{
			message_vision("小青看到金蛇膽，高興得跳了起來。摟着$N的脖子說：還差青蛇膽就大功告成了！\n",who);
			return 1;
		}
	}
	if ( (string)ob->query("id") == "qing dan" )
	{
		if (query_temp("dan")==1)
		{
			message_vision("小青一看是，滿臉遺憾地對$N說：我還差金蛇膽，不缺青蛇膽。\n",who);
			return 0;
		}
		add_temp("dan",1);
		if (query_temp("dan")==1)
		{
			message_vision("小青看到青蛇膽，高興得跳了起來。摟着$N的脖子說：還差就金蛇膽大功告成了！\n",who);
			return 1;
		}
	}
	command("kiss "+(string)who->query("id"));
	write( HIY "只見小青手腳麻利地把兩隻蛇膽投入藥罐中，又加入一些不\n知是什麼的藥粉，然後把稀里嘩啦一搖，嘿！『蛇膽膏』做\n成了。\n" NOR );
	message_vision("小青很神祕地湊近$N悄悄說了些什麼。\n", who);
	tell_object(who,"“我偷偷拿了一點『蛇膽膏』送給你，師傅不會發現的。”\n");
	message_vision("小青深情地望了$N一眼，臉紅了。\n",who);
	obn = new("/clone/medicine/nostrum/shedangao");
	obn->move(who);
	set_temp("dan",0);
	add_temp("times",-1);
	return 1;
}

