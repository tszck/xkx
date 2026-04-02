// /kungfu/class/gumu/limochou.c
// Last Modified by winder on Feb. 28 2001

#include <ansi.h>
inherit F_MASTER;
inherit NPC;

int do_look(string var);
int ask_me();

void create()
{
	object ob;
	set_name("李莫愁", ({ "li mochou", "li", "mochou" }));
	set("long", "她生得極爲美貌，但冰冷的目光讓人不寒而慄。\n");
	set("nickname", "赤練仙子");
	set("gender", "女性");
	set("rank_info/respect", "道姑");
	set("age", 27);
	set("attitude","heroism");
	set("str", 30);
	set("dex", 35);
	set("per", 30);
	set("con", 17);
	set("int", 25);
	set("shen_type", -1);

	set_skill("unarmed", 90);
	set_skill("force", 80);
	set_skill("dodge", 100);
	set_skill("whip",130);
	set_skill("qiufeng-chenfa",180);
	set_skill("yunv-xinfa", 100);    //玉女心法	
	set_skill("throwing",130);
	set_skill("meinv-quan",100);
	map_skill("force", "yunv-xinfa");
	map_skill("whip","qiufeng-chenfa");
	map_skill("unarmed","meinv-quan");
	set("jiali",50);

	set("combat_exp", 95000);

	set("max_qi", 1500);
	set("max_jing", 100);
	set("neili", 500);
	set("max_neili", 500);

	set("inquiry", ([
		"name" : "站遠點！",
		"here" : "我不是本地人，不知道。",
		"情" : "你如何能理解其中相思之苦、惆悵之意？",
		"陸展元" : "你問那個薄情的小畜生做什麼？",
		"何沅君" : (: ask_me :),
		"小龍女" : "那是我的師妹。你問她想幹什麼？",
		"林朝英" : "那是我的師祖，不該你問的你別問，小心我宰了你。",
	]) );

         create_family("古墓派", 3, "弟子");
 
	set("chat_chance", 10);
	set("chat_msg", ({
		"李莫愁縱聲而歌，音調悽婉，歌道：「問世間，情是何物，直教生死相許？」\n",
		"李莫愁歌道：「天南地北雙飛客，老翅幾回寒暑？」\n",
		"李莫愁唱道：「歡樂趣，離別苦，就中更有癡兒女。」\n",
		"李莫愁唱道：「君應有語，渺萬裏層雲，千山暮雪，隻影向誰去？」\n",
		"李莫愁詞意悲切，聲調更是哀怨，唱道：「橫汾路，寂寞當年簫鼓。荒煙依舊平楚。」\n",
		"李莫愁歌道：「招魂些何嗟及，山鬼自啼風雨。」\n",
		"李莫愁唱道：「天也妒，未信與，鶯兒燕子俱黃土。」\n",
		"李莫愁唱道：「千秋萬古，爲留待騷人，狂歌痛飲，來訪雁丘處。」\n",
	}) );

	setup();
	carry_object("/d/quanzhou/obj/fuchen")->wield();
	carry_object("/d/wudang/obj/greenrobe")->wear();
	ob=new(__DIR__"obj/yinzhen");
	ob->set_amount(10);
	ob->move(this_object());
}
void attempt_apprentice(object ob)
{
	if(ob->query("per") < 20)
	{
        	command("say 尊容實在不敢恭維，恐怕學不了玉女心法。\n");
	}
	if ((string)ob->query("gender") != "女性")
	{     
	      message("vision", HIY "李莫愁大怒，喝道：我最恨你們這些薄情的臭男人！去死吧！\n李莫愁決心殺死" + ob->name() +"\n" NOR, environment(), this_object() );
	      kill_ob(this_player());
	}		
	else
	{
	        command("say 好吧，我就收下你這個徒弟了。\n");
        	command("recruit " + ob->query("id"));
	}
}
void init()
{
	::init();
	add_action("do_look","look");
	add_action("do_look","hug");
	add_action("do_look","mo");
	add_action("do_look","18mo");
	add_action("do_look","kiss");

}

int ask_me()
{
	object me;
 
	me = this_player();
	message("vision", HIY"李莫愁冷笑一聲：『我這就送你去見她』\n李莫愁決心殺死" + me->name() +"\n" NOR, environment(), this_object() );
	kill_ob(this_player());
	return 1;
}

int do_look(string target)
{
	object me;
 
	me = this_player();
	if (target=="li" || target=="li mochou" || target=="mochou" ) 
		if ((string)me->query("gender") != "女性")
		{
			message("vision", HIY "李莫愁大怒，喝道：我最恨你們這些薄情的臭男人！去死吧！\n李莫愁決心殺死" + me->name() +"\n" NOR, environment(), this_object() );
			kill_ob(this_player());
		}
}

