// qqren.c 裘千仞
// Last Modified by winder on Nov. 17 2001

inherit NPC;
int ask_qiubai();
inherit F_MASTER;
inherit F_MANAGER;

void create()
{
	set_name("裘千仞", ({ "qiu qianren", "qiu", "qianren", "ren"}));
	set("nickname", "鐵掌水上漂");
	set("long", "他就是威震川湘的鐵掌幫的幫主-鐵掌水上漂裘千仞。\n"
	"他是一個白鬚老頭，身穿黃葛短衫，右手揮着一把大蒲扇。\n");
	set("gender", "男性");
	set("age", 60);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 35);
	set("int", 30);
	set("con", 28);
	set("dex", 35);
	
	set("max_qi", 4000);
	set("max_jing", 3000);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jiali", 200);
	set("combat_exp", 3000000);
	set("score", 400000);

	set_skill("force", 160);
	set_skill("guiyuan-tunafa", 160);
	set_skill("dodge", 160);
	set_skill("shuishangpiao", 220);
	set_skill("spear", 160);
	set_skill("tiexue-qiang", 220);
	set_skill("strike", 180);
	set_skill("zhusha-zhang", 220);
	set_skill("tiezhang-zhangfa", 220);
	set_skill("parry", 160);
	set_skill("literate", 100);

	map_skill("force", "guiyuan-tunafa");
	map_skill("dodge", "shuishangpiao");
	map_skill("strike", "tiezhang-zhangfa");
	map_skill("spear", "tiexue-qiang");
	map_skill("parry", "tiezhang-zhangfa");
	prepare_skill("strike", "tiezhang-zhangfa");

	set("no_get",1);
	set("chat_chance_combat", 70);
	set("chat_msg_combat", ({
		(: perform_action, "strike.zhangdao" :),
		(: perform_action, "strike.tianlei" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
	}) );

	create_family("鐵掌幫", 14, "幫主");

	set("inquiry", ([
		"name" : "老夫便是“鐵掌水上漂”裘千仞，你問老夫姓名有什麼事麼？\n",
		"here" : "這裏就是鐵掌幫的總壇所在，你如沒事，不要四處亂走，免招殺身之禍！！！\n",
		"上官劍南" : (: ask_qiubai :),
	]));
	setup();
	carry_object(__DIR__"obj/yellowcloth")->wear();
}
void init()
{
    add_action("do_qiecuo","qiecuo");
}
void attempt_apprentice(object me)
{
	if ((int)me->query("shen") > -10000)
	{
		command("hehe");
		command("say 我裘千仞可不收心慈手軟的人做徒弟。");
		return;
	}
	command("say 好吧，我就收下你了。希望你苦練鐵掌神功，將之發揚光大。");
	command("recruit " + me->query("id"));
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		add("apprentice_available", -1);
}
int ask_qiubai()
{
	say("他是我師父。我在十三歲那年曾救過他，之後他感恩圖報，將全\n"
	"身武功傾囊相受。可惜十年前，他在湖北遭人圍攻而死！唉！\n");
	return 1;
}

