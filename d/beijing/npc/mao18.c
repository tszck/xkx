// mao18.c 茅十八


#include <ansi.h>
inherit NPC;
//inherit F_SKILL;
int ask_weiwang();

void create()
{
	set_name("茅十八", ({ "mao shiba", "mao", "shiba" }));
	set("gender", "男性");
	set("age", 30);
	set("str", 25);
	set("dex", 16);
	set("long", "他虯髯如亂草，滿臉血污，好象曾受過很重的傷，可以看得見\n"
		"他左腿上血跡未乾。但他雙目炯炯，卻又有着説不出的威風。\n");
	set("combat_exp", 35000);
	set("shen_type", 1);
	set("score", 4000);
	set("attitude", "peaceful");
	set("startroom","/d/city/lichunyuan");

	set_skill("unarmed", 50);
	set_skill("force", 60);
	set_skill("blade", 80);
	set_skill("dodge", 50);
	set_skill("parry", 50);

	set_skill("wuhu-duanmendao", 70);
	map_skill("blade", "wuhu-duanmendao");
	map_skill("parry", "wuhu-duanmendao");

	set_temp("apply/attack", 30);
	set_temp("apply/defense", 30);
	set_temp("apply/armor", 5);
	set_temp("apply/damage", 10);

	set("neili", 200); 
	set("max_neili", 200);
	set("jiali", 20);
	set("inquiry", ([
		"史松" : "殺了史松可以提高江湖威望。\n",
		"鰲拜" : "殺鰲拜救人可以提高江湖威望。\n",
		"威望" : (: ask_weiwang :),
		"江湖威望" : (: ask_weiwang :),
	]) );
	set("chat_chance", 20);
	set("chat_msg", ({
		"茅十八説道: 他奶奶的，我就不信鰲拜有這等厲害,\n"
		"我正要上北京去鬥他一鬥。" ,
		"茅十八嘆道: 用我這五虎斷門刀法對付鹽梟可是綽綽有餘,只不知對付鰲拜行不行。\n",
		"茅十八説道: 江湖威望很重要！威望高大有好處啊...\n",
		"茅十八説道: 他奶奶的，誰幫我殺了史松，兄弟我謝謝你了！\n",
		"茅十八説道: 老聽人説，那鰲拜是滿洲第一武士，他媽的，\n"
		"還有人説他是天下第一勇士，我可不服氣，要上北京去跟他比劃比劃。\n" ,
		"茅十八朗聲説道：江湖有言：“為人不識陳近南，就稱英雄也枉然。”\n",
		(: random_move :)
	}) );
	setup();
	carry_object(CLOTH_DIR"cloth")->wear();
	carry_object(WEAPON_DIR"gangdao")->wield();
}

int ask_weiwang()
{
	command("tell "+this_player()->query("id")+" 你現在的江湖威望是 " +(string)(this_player()->query("weiwang")));
	say( "茅十八説：如果你威望值很高，有些人見了你不但不會殺你，還會教你武功，送你寶貝。\n而且你還可以加入幫會，率領會眾去攻打目標，就連去錢莊取錢也會有利息 。。。。。\n");
	say("茅十八又説：殺某些壞人或救某些好人可以提高江湖威望。\n");
	return 1;
}

void init()
{
	object ob; 
	ob = this_player();
	::init();
	remove_call_out("greeting");
	call_out("greeting", 1, ob);
}

void greeting(object ob)
{
 
	if( !ob || environment(ob) != environment() ) return;
	message_vision(	"\n$N拱手道：兄弟腿上不方便，不能起立行禮了。\n", this_object());
}

void die()
{
	say( "茅十八哈哈大笑道：託韋兄弟的福，我見過了陳近南總舵主，雖死無憾啊！\n");
	message_vision("$N大笑兩聲，死了！\n", this_object());
	::die();
}

int accept_object(object me, object ob)
{
	int i;	
  	if( !me || environment(me) != environment() ) return 0;
	if ( !objectp(ob) ) return 0; 
	if ( !present(ob, me) ) return notify_fail("你沒有這件東西。");
	if ( (string)ob->query("id") == "heilong bian") 
	{
		i=(int)me->query("weiwang");
		if(i<20) 
	{
	i=i+10;
	me->set("weiwang",i);
	message_vision(HIC "\n$N的江湖威望提高了！\n" NOR,this_player());
	}
	command("tell "+this_player()->query("id")+" 你現在的江湖威望是 " +(string)(i));
	}
	else 
	{
		 command("shake ");
		 command("say 這種東西鬼才要！老子宰了你！");
		 remove_call_out("kill_ob");
		 call_out("kill_ob", 1, this_player());
	}
	return 1;
}