// lin.c 林朝英
// Last Modified by winder on Feb. 28 2001

#include <ansi.h>

inherit F_MASTER;
inherit F_MANAGER;
inherit NPC;
string ask_yunv();

void create()
{
	set_name("林朝英", ({"lin chaoying", "lin"}));
	set("gender", "女性");
	set("age", 42);
	set("long",
		"她就是古墓派的開山祖師林朝英，雖然已經是四十許人，望之卻\n"
		"還如同三十出頭。當年她與全真教主王重陽本是一對癡心愛侶，\n"
		"只可惜有緣無份，只得獨自在這古墓上幽居。\n");
	set("attitude", "friendly");

	set("per", 30);
	set("str", 37);
	set("int", 42);
	set("con", 45);
	set("dex", 42);

	set("chat_chance_combat", 6);
	set("chat_msg_combat", ({
		(: exert_function, "recover" :),
	}) );
	set("chat_chance", 1);
	set("chat_msg", ({
		(: perform_action, "sword.he" :),
		(: perform_action, "sword.he" :),
		(: perform_action, "sword.he" :),
	}));

	set("qi", 6000);
	set("max_qi", 6000);
	set("jing", 2400);
	set("max_jing", 2400);
	set("neili", 9000);
	set("max_neili", 9000);
	set("jiali", 100);

	set("combat_exp", 3000000);
	set("score", 0);

	set_skill("force", 200);
	set_skill("yunv-xinfa", 200);    //玉女心法
	set_skill("sword", 200);
	set_skill("yunv-jian", 300);     //玉女劍
	set_skill("quanzhen-jian",300);  //全真劍
	set_skill("dodge", 200);
	set_skill("yunv-shenfa", 300);   //玉女身法
	set_skill("parry", 200);
	set_skill("whip",200);
        set_skill("qiufeng-chenfa",300);
        set_skill("unarmed",200);
	set_skill("meinv-quan", 300);    //美女拳法
	set_skill("literate",120);
//	set_skill("taoism",140);

	map_skill("force", "yunv-xinfa");
	map_skill("sword", "yunv-jian");
	map_skill("dodge", "yunv-shenfa");
	map_skill("parry", "meinv-quan");
	map_skill("unarmed", "meinv-quan");
        map_skill("whip","qiufeng-chenfa");

	create_family("古墓派", 1, "開山祖師");

	set("book_count",1);
	set("inquiry", ([
		"王重陽"   : "大膽後輩小子，也敢直呼重陽祖師之名？\n",
		"重陽祖師" : "重陽是全真教的掌教，自號“活死人”。\n",
		"古墓派"   : "是啊，這裏就是我一手創下的古墓派\n",
		"玉女心經" : (: ask_yunv :),
	]) );
	set("no_get",1);

	setup();

	carry_object("/clone/weapon/changjian")->wield();
	carry_object(__DIR__"obj/qingyi")->wear();

}
void init()
{
 	object ob; 
	ob = this_player();

	::init();
	if( interactive(ob) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_qiecuo","qiecuo");
}


void greeting(object me)
{
       
       	mapping myfam;
	myfam = (mapping)me->query("family");
	if((myfam["family_name"] == "古墓派")&&(!me->query_skill("yunv-xinfa",1))&&(me->query("combat_exp")>500000))
        {
                command("say 你竟敢放棄本門心法！從我這裏滾出去吧！");
                command("expell " + me->query("id"));
        }
        
}

void attempt_apprentice(object ob)
{
	if (ob->query_int() < 30) {
		command("say 我古墓派的功夫最講一個悟字，你的資質不夠。");
		return;
	}
	if ((int)ob->query_skill("yunv-xinfa",1) < 70 ) {
		command("say 你的玉女心法火候不足,難以領略更高深的武功。");
		return;
	}
	command("say 好吧，看你也是性情中人，我就收下你這個徒弟了。");
	command("recruit " + ob->query("id"));
}

string ask_yunv()
{
	mapping fam;
	object ob;
	int lvl_yunv;

	if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "古墓派")
		return RANK_D->query_respect(this_player()) +
		"與本派毫無瓜葛，何以問起本派的心經？";
	if (!(lvl_yunv = this_player()->query_skill("yunv-xinfa",1)) ||
		lvl_yunv < 55)
		return RANK_D->query_respect(this_player()) +
		"的玉女心法火候不足，我不能將玉女心經交給你";
	if (query("book_count") < 1)
		return "你來晚了，本派的玉女心經已經被人取走了。";
	add("book_count", -1);
	ob = new("/clone/book/yunvjing2");
	ob->move(this_player());
	return "好吧，這本「玉女心經」你拿回去好好研讀。";
}
