// wang.c 王重陽

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
inherit F_MANAGER;

string ask_jiuyin();
string ask_zhipu();
string ask_duan();

void create()
{
	set_name("王重陽", ({"wang chongyang", "wang"}));
	set("gender", "男性");
	set("age", 66);
	set("class", "quanzhen");
	set("nickname",HIW"中神通"NOR);
	set("long",
		"他就是全真教的開山祖師、首代掌教王重陽王真人。他白鬚飄\n"
		"飄，寬袍緩袖，眉目清癯，頗有些仙風道骨的味道。他本來一\n"
		"腔熱血欲報效國家力抗金兵，可惜朝廷腐敗，於是心灰意冷，\n"
		"又從道德經中悟得了天地滋生的大道，手創全真教。\n");
	set("attitude", "peaceful");
	set("shen_type",1);
	set("str", 45);
	set("int", 45);
	set("con", 45);
	set("dex", 45);

	set("no_get",1);
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :),
		(: perform_action, "strike.ju" :),
		(: perform_action, "sword.ding" :),
		(: perform_action, "sword.sanqing" :),
		(: command("unwield changjian") :),
		(: command("wield changjian") :),
		(: perform_action, "finger.qiankun" :),
		(: perform_action, "strike.ju" :),
	}));

	set("qi", 6500);
	set("max_qi", 6500);
	set("jing", 2400);
	set("max_jing", 2400);
	set("neili", 9000);
	set("max_neili", 9000);
	set("jiali", 100);

	set("combat_exp", 3000000);
	set("score", 500000);

	set_skill("array", 150);
	set_skill("force", 200);
	set_skill("xiantian-qigong", 200);    //先天氣功
	set_skill("sword", 200);
	set_skill("quanzhen-jian", 300);  //全真劍
	set_skill("dodge", 200);
	set_skill("jinyan-gong", 300);   //金雁功
	set_skill("parry", 200);
	set_skill("unarmed", 200);
	set_skill("strike", 200);
	set_skill("haotian-zhang", 300);    //昊天掌
	set_skill("cuff", 200);
	set_skill("chunyang-quan", 300);    //純陽拳
	set_skill("whip", 200);
	set_skill("duanyun-bian", 300);    //斷雲鞭
	set_skill("literate", 140);
	set_skill("taoism", 150);
	set_skill("finger", 200);
	set_skill("sun-finger", 200);  //一陽指
	map_skill("force", "xiantian-qigong");
	map_skill("sword", "quanzhen-jian");
	map_skill("dodge", "jinyan-gong");
	map_skill("parry", "quanzhen-jian");
	map_skill("finger","sun-finger");
	map_skill("whip", "duanyun-bian");
	map_skill("strike", "haotian-zhang");
	map_skill("cuff", "chunyang-quan");
	prepare_skill("cuff", "chunyang-quan");
	prepare_skill("strike", "haotian-zhang");

	create_family("全真教", 1, "掌教");

	set("book_count",1);
	set("inquiry", ([
		"全真教" :  "我全真教是天下道家玄門正宗。\n",
		"九陰真經" : (: ask_jiuyin :),
		"一陽指" : (: ask_zhipu :),
		"段皇爺" : (: ask_duan :),
	]) );

	setup();

	carry_object(WEAPON_DIR"changjian")->wield();
	carry_object(__DIR__"obj/whiterobe")->wear();
}
void init()
{
    add_action("do_qiecuo","qiecuo");
}
void attempt_apprentice(object ob)
{
	string new_name;
/*
	if (!ob->query("qixing"))
	{
		command("say 你要先過天罡北斗陣，再來找我學藝。");
		return;
	}
*/
	if (ob->query("class") != "quanzhen")
	{
		command("say 你不是玄門清修之士，所以，請回吧。");
		return;
	}
	if (ob->query_int() < 30)
	{
		command("say 你的資質不夠，還是先找我那幾個徒弟學習吧。");
		return;
	}
	if ((int)ob->query_skill("xiantian-qigong",1) < 140 )
	{
		command("say 你的本門內功心法火候不足，難以領略更高深的武功。");
		return;
	}
	if ((int)ob->query("shen")<100000)
	{
		command( "say 我輩武人份當行俠仗義除暴安良，你若能多為俠義之舉，當能承我衣缽。\n");
		return;
	}
	command("say 好吧，依你資質，定可傳我衣缽，我就收下你這個徒弟了。");
	command("recruit " + ob->query("id"));
	new_name=ob->query("name");
	if(new_name[1..1]=="志")
	{
		new_name=new_name[0..0]+"處"+new_name[2..2];
		ob->set("name", new_name);
		command("say 從今以後你的道號叫做"+new_name+ "，你現在是全真教處字輩弟子了。");
	}
}

string ask_jiuyin()
{
	mapping fam;
	int lvl_force;

	if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "全真教")
		return RANK_D->query_respect(this_player()) +"與本教毫無瓜葛，這話從何説起？";
	if (!(lvl_force = this_player()->query_skill("force",1)) ||
		lvl_force < 50)
		return RANK_D->query_respect(this_player()) +"的基本內功火候如此之淺，強練真經上的上乘武功有害無益。";
	return "九陰真經是天下武學正宗，我已交給我師弟周伯通保管，\n不過....在古墓派的石棺內，我還刻着一些圖形。\n";
}

string ask_duan()
{
	object me=this_player();
	if(me->query_temp("tmark/指")==2)
	{
		me->add_temp("tmark/指",1);
		return("段皇爺號稱‘南帝’，家傳的一陽指是天下最厲害的指法。\n");
	}
	else {
		me->set_temp("tmark/指",0);
		return("你問段皇爺做甚麼，莫非想與他為難？\n");
	}
}

string ask_zhipu()
{
	object ob,me=this_player();
	if(me->query_temp("tmark/指")==3)
	{
		me->set_temp("tmark/指",0);
		if(query("book_count")>0)
	{
			ob=new(BOOK_DIR"sun_book");
			ob->move(me);
			add("book_count",-1);
message("channel:rumor",MAG"【謠言】某人："+this_player()->query("name")+"拿了一陽指訣啦。\n"NOR, users());
			return("好吧，你歷經艱苦，意志甚堅，這本指法譜就交給你了。\n");
		}
		else return("你來晚了，指法譜已經被人取走了。\n");
	}
	else {
		me->set_temp("tmark/指",0);
		return  RANK_D->query_respect(me) + "不是想跟我較量較量吧？\n";
	}
}
