// longnv.c 小龍女
// Last Modified by winder on Feb. 28 2001

#include <ansi.h>
inherit F_MASTER;
inherit NPC;
string ask_me();

void create()
{
	set_name("小龍女", ({"long nv", "long"}));
	set("gender", "女性");
	set("age", 18);
	set("long",
	"盈盈而站着一位秀美絕俗的女子，肌膚間少了一層血色，顯得蒼白異常。\n"
	"披著一襲輕紗般的白衣，猶似身在煙中霧裏。\n"
	"當真如風拂玉樹，雪裹瓊苞，兼之生性清冷，\n"
	"實當得起“冷浸溶溶月”的形容。\n");
	set("attitude", "friendly");

	set("per", 30);
	set("str", 30);
	set("int", 37);
	set("con", 36);
	set("dex", 38);

	set("chat_chance_combat", 9);
	set("chat_msg_combat", ({
		(: exert_function, "recover" :),
		(: perform_action, "sword.he" :),
	}) );

	set("qi", 3500);
	set("max_qi", 3500);
	set("jing", 1600);
	set("max_jing", 1600);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jiali", 100);
	set("combat_exp", 800000);
	set("score", 0);
	set_skill("force", 150);
	set_skill("yunv-xinfa", 150);    //玉女心法
	set_skill("sword", 150);
	set_skill("yunv-jian", 150);     //玉女劍
	set_skill("quanzhen-jian",140);  //全真劍
	set_skill("dodge", 160);
	set_skill("yunv-shenfa", 160);   //玉女身法
	set_skill("parry", 150);
	set_skill("hubo", 120);	  //雙手互搏
	set_skill("unarmed",150);
	set_skill("meinv-quan", 160);    //美女拳法
	set_skill("literate",120);
	set_skill("qufeng",200);	 //驅蜂之術

	map_skill("force", "yunv-xinfa");
	map_skill("sword", "yunv-jian");
	map_skill("dodge", "yunv-shenfa");
	map_skill("parry", "meinv-quan");
	map_skill("unarmed", "meinv-quan");

	create_family("古墓派", 3, "弟子");
	set("inquiry", ([
		"楊過"     :"過兒不就在這麼？\n",
		"玉女劍法" :"玉女劍法和全真劍法合壁，天下無敵！\n",
		"古墓派"   :"我的林祖師爺爺本來和重陽先師是一對璧人，可是...\n",
		"養顏丹"   :(: ask_me :),
		"dan"      :(: ask_me :),
	]) );

	set("env/wimpy", 40);
	setup();
	carry_object("/kungfu/class/gumu/obj/shunvjian")->wield();
	carry_object("/kungfu/class/gumu/obj/baipao")->wear();
}

string ask_me()
{
	object ob;
	string wan_num;
	int wannum;

	wan_num = read_file("/data/YANGYAN", 1, 1);
	wannum = atoi(wan_num);
	if (wannum == 0)
		return "這位"+RANK_D->query_respect(this_player())+"，養顏丹是經我半年呵養而成的。你再等"GRN+chinese_number(6-(int)(uptime()/7200))+CYN"個月再來吧！\n";
	if (wannum == 2)
		return "這位"+RANK_D->query_respect(this_player())+"，養顏丹早給別人拿走了。你以後再來吧！\n";
	ob = new("/clone/medicine/nostrum/yangyandan");
	ob->move(this_player());
	write_file("/data/YANGYAN", "2", 1);
	command("rumor "+this_player()->query("name")+"拿到養顏丹了啦。\n");
	return "好吧，這粒養顏丹經我玉女心經半年修煉而得，你既有緣，就拿去吧。";
}

