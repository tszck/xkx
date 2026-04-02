// a-xiu.c
// Last Modified by winder on Jul. 15 2001

#include <ansi.h>

inherit NPC;

string ask_staff();
void create()
{
	set_name("阿繡",({"a xiu","xiu"}));
	set("gender", "女性");
	set("age", 16);
	set("long", 
	       "她是凌霄城主的孫女，年方十多歲，聰明伶俐，天真可愛，\n簡直便是大雪山凌霄城的小公主。\n");
	set("attitude", "peaceful");
	set("str", 25);
	set("count",1);
	set("con", 30);
	set("per", 30);
	set("int", 24);
	set("dex", 30);
	set("neili", 1000);
	set("max_neili", 1000);
	set("qi", 800);
	set("max_qi", 800);
	set("jing", 500);
	set("max_jing", 500);
	set("inquiry", ([
		"石破天"   : "天哥去了俠客島，不知道他現在怎麼樣了？",
		"大糉子"   : "只有我才能這麼叫他，你怎麼能這麼叫他？",
		"石中玉"   : "我很討厭他---你去把他給我殺了吧。",
		"白萬劍"   : "那是我爹呀。",
		"白自在"   : "那是我爺爺呀。",
		"金烏杖" : (: ask_staff :),
	]) );
	set("combat_exp", 50000);
	set("shen_type", 0);
	set("chat_chance", 5);
	set("chat_msg", ({
		"阿繡凝視着平靜的潭水，説：這潭很奇怪，裏面好象有什麼東西。\n",
		"阿繡看着遠山的悠悠白雲，嘆道：你要什麼時候才從俠客島回來。\n",
		"阿繡忽然皺顰不快，好象想起了什麼可氣之事。\n",
	}) );
	set("score", 2000);
	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: exert_function, "recover" :)
	}) );

	set_skill("strike", 40);
	set_skill("sword", 60);
	set_skill("force", 60);
	set_skill("parry", 60);
	set_skill("dodge", 60);
	set_skill("literate", 40);

	set_skill("xueshan-sword", 60);
	set_skill("bingxue-xinfa", 60);
	set_skill("snow-strike", 60);
	set_skill("snowstep", 60);

	map_skill("sword", "xueshan-sword");
	map_skill("parry", "xueshan-sword");
	map_skill("force", "bingxue-xinfa");
	map_skill("strike", "snow-strike");
	map_skill("dodge", "snowstep");
	prepare_skill("strike", "snow-strike");

	create_family("凌霄城", 7, "弟子");
	setup();

	carry_object("/clone/weapon/changjian")->wield();
	carry_object(CLOTH_DIR+"bai")->wear();
}
string ask_staff()
{
	object ob;
	object me;
	me = this_player();

	if(query("count") < 1)
		return "這位" +RANK_D->query_respect(me)+"，真是抱歉，金烏杖已經有人幫我給奶奶帶去了。";
	if(me->query("combat_exp")<200000)
		return "你武功尚未到家，我怎敢把金烏杖交給你？";
	add("count", -1);
	ob=new(WEAPON_DIR"treasure/jinwu-staff");
	if ( ob->violate_unique() )
	{
		destruct( ob );
		return "你武功尚未到家，我怎敢把金烏杖交給你？";
	}
	else
	{
		ob->move(this_player());
		return "這位" +RANK_D->query_respect(me)+"，請幫我把這把金烏杖帶給我奶奶，真是多謝了。";
	}
}

void attempt_apprentice(object ob)
{
	command("say 我是不收徒的，你進城找我師兄們好了。");
}

