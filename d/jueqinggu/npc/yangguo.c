// yangguo.c 楊過
// Last Modified by winder on Mar. 8 2001

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_me();

void create()
{
	set_name("楊過", ({"yang guo", "yang", "guo"}));
	set("nickname", HIB"神鵰大俠"NOR);
	set("gender", "男性");
	set("age", 26);
	set("long",
	"他就是神鵰大俠楊過，一張清癯俊秀的臉孔，劍眉入鬢，鳳眼生威。\n"
	"雖然他只有一隻胳膊，但是魁偉的身材仍讓人感覺英氣逼人。\n");
	set("attitude", "friendly");

	set("per", 28);
	set("str", 30);
	set("int", 37);
	set("con", 36);
	set("dex", 38);
	set("chat_chance", 1);
	set("chat_msg", ({
		"楊過喃喃道：“獨孤求敗！獨孤求敗！求一敗而不可得？”\n", 
	}));
	set("chat_chance_combat",50);
	set("chat_msg_combat", ({
		(: perform_action, "unarmed.anran" :),
		(: command("wield jian") :),
		(: command("unwield jian") :),
	}));

	set("qi", 3500);
	set("max_qi", 3500);
	set("jing", 1600);
	set("max_jing", 1600);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jiali", 100);
	set("combat_exp", 2000000);
	set("score", 0);

	set_skill("force", 200);
	set_skill("yunv-xinfa", 200);
	set_skill("sword", 200);
	set_skill("yunv-jian", 200);
	set_skill("quanzhen-jian",200);
	set_skill("dodge", 200);
	set_skill("anran-zhang",220);
	set_skill("yunv-shenfa", 200);
	set_skill("parry", 200);
	set_skill("unarmed",200);
	set_skill("meinv-quan", 200);
	set_skill("literate",120);
	set_skill("qufeng",120);
	set_skill("tanzhi-shentong",200);
	map_skill("force", "yunv-xinfa");
	map_skill("sword", "yunv-jian");
	map_skill("dodge", "yunv-shenfa");
	map_skill("parry", "meinv-quan");
	map_skill("unarmed", "anran-zhang");

	create_family("古墓派", 4, "弟子");
	set("letter_count", 1);

	set("inquiry", ([
		"小龍女"   :  "你也在找我的龍兒？\n",
		"玉女劍法" : "玉女劍法和全真劍法合壁，天下無敵！\n",
		"古墓派"   : "我的林祖師爺爺本來和重陽先師是一對璧人，可是..\n",
		"郭靖"     : "我郭伯父是當世一代大俠。\n",
		"黃蓉"     : "我郭伯母確實是算無遺策。\n",
		"雕兄"     : "雕兄既是我師，亦復我友。\n",
		"神鵰"     : "你問雕兄？\n",
		"玄鐵劍"   : "玄鐵劍在高昌古城。\n",
		"獨孤劍冢" : "獨孤劍冢嘛，自己找吧。\n",
		"dan"      : (: ask_me :),
		"回春丹"   : (: ask_me :),
	]) );
	set("env/wimpy", 40);
	setup();
	carry_object("/clone/cloth/male-cloth")->wear();
	carry_object("/kungfu/class/gumu/obj/junzijian");
}

string ask_me()
{
	object ob;
	string wan_num;
	int wannum;

	wan_num = read_file("/data/HUICHUN", 1, 1);
	wannum = atoi(wan_num);
	if (wannum == 0)
		return "這位"+RANK_D->query_respect(this_player())+"，回春丹需經一年養煉，方克有成。你再等"RED+ chinese_number(12-(int)(uptime()/7200))+CYN"個月再來吧！\n";
	if (wannum == 2)
		return "這位"+RANK_D->query_respect(this_player())+"，回春丹早給別人拿走了。你以後再來吧！\n";
	ob = new("/clone/medicine/nostrum/huichundan");
	ob->move(this_player());
	write_file("/data/HUICHUN", "2", 1);
	command("rumor "+this_player()->query("name")+"拿到回春丹了啦。\n");
	return "好吧，不給你嚐嚐回春丹，你也不知道它的味道吧。";
}

