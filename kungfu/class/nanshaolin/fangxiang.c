// Npc: /kungfu/class/nanshaolin/fangxiang.c
// Last Modified by winder on May. 29 2001

inherit F_MASTER;
inherit NPC;
string ask_me();
string ask_fangzhang();
int do_massage(string arg);

void create()
{
	set_name("方相", ({ "fang xiang", "fang", "xiang"}));
	set("long", "他是一位身穿黃布袈裟的青年僧人。臉上稚氣未脫，身手卻已相\n"
		"當矯捷，看來似乎學過一點武功。\n");
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 20);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 500);
	set("max_jing", 300);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 100);
	set("combat_exp", 100000);
	set("score", 50);

	set_skill("literate", 50);
	set_skill("buddhism", 50);
	set_skill("parry", 50);
	set_skill("force", 50);
	set_skill("zhanzhuang-gong", 50);
	set_skill("dodge", 50);
	set_skill("yiwei-dujiang", 50);
	set_skill("cuff", 50);
	set_skill("shaolin-cuff", 50);
	set_skill("luohan-cuff", 50);
	set_skill("strike", 50);
	set_skill("weituo-strike", 50);
	set_skill("sanhua-strike", 50);
	set_skill("finger", 50);
	set_skill("mohe-finger", 50);
	set_skill("sword", 50);
	set_skill("damo-sword", 50);

	map_skill("force", "zhanzhuang-gong");
	map_skill("dodge", "yiwei-dujiang");
	map_skill("cuff", "luohan-cuff");
	map_skill("strike", "sanhua-strike");
	map_skill("finger", "mohe-finger");
	map_skill("sword", "damo-sword");
	map_skill("parry", "damo-sword");
	prepare_skill("strike", "sanhua-strike");
	prepare_skill("finger", "mohe-finger");

	set("inquiry", ([
		"手諭"       : (: ask_me :),
		"七十二絕藝" : (: ask_me :),
		"服侍方丈"   : (: ask_fangzhang :),
	]));
	create_family("南少林派", 21, "弟子");
	setup();
	carry_object("/d/shaolin/obj/xu-cloth")->wear();
	carry_object(WEAPON_DIR+"sword/changjian")->wield();
}

void init()
{
	add_action("do_massage","massage");
}

string ask_me()
{
	mapping fam, skl; 
	object ob;
	string *sname;
	int i;

	if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "南少林派")
		return RANK_D->query_respect(this_player()) +"與本派素無來往，不知此話從何談起？";
	if ( (int)this_player()->query("guilty") > 0 )
		return RANK_D->query_respect(this_player()) +"你累犯數戒，身帶重罪，我如何能給你這手諭！";
	if ( (int)this_player()->query_int() < 30 )
		return RANK_D->query_respect(this_player()) +"資質不夠，不能進入藏經樓。";
	skl = this_player()->query_skills();
	sname = sort_array( keys(skl), (: strcmp :) );
	for(i=0; i<sizeof(skl); i++)
	{
		if (skl[sname[i]] < 50) 
		return RANK_D->query_respect(this_player()) +"功力不夠，不夠資格領取手諭。";
	}
	if ( (int)this_player()->query_skill("buddhism",1) < 80 )
		return RANK_D->query_respect(this_player()) +"想學習上乘武功，先要以高深佛法化解它們的戾氣。";
	ob = new("/d/nanshaolin/obj/allow-letter");
	ob->move(this_player());
	message_vision("$N獲得一封手諭。\n",this_player());
	return "好吧，憑這封手諭，你可自由進入藏經閣二樓研習上乘武功。";
}

string ask_fangzhang()
{
	mapping fam, skl; 
	object ob=this_player(), me=this_object();

	if(ob->query("massage_name"))
		return ("已經有人在服侍方丈了。\n");
	if(ob->query("combat_exp") >= 10000 && !wizardp(ob))
		return ("你已經有了基礎了，沒必要再找我來領活了。\n");
	if((string)ob->query("family/family_name") != "南少林派")
		return ("非南少林弟子不能領工作。");
	if((string)ob->query("class") != "bonze" && !wizardp(ob))
		return ("俗家弟子不能領工作。");
	if(ob->query_temp("job_name"))
		return ("你不是已經領了工作嗎？還不快去做。\n");
	me->set("massage_name",ob->query("name"));
	ob->set_temp("job_name","服侍方丈");
	ob->set_temp("massage", 1);
	return "來這裏就是服侍方丈。你進去吧。";
}

int do_massage(string arg)
{
	object ob=this_player(), me=this_object();

	if(!arg || arg != "ok") return 0;
	if(!ob->query_temp("massage")) return 0;
	if(!ob->query_temp("mark/按摩完")) return 0;
	if(ob->query("name")==me->query("massage_name")) 
	{
		command("pat "+ob->query("id"));
		command("say 真難爲你了，方丈去休息了，阿彌陀佛！");
		ob->add("potential",(int)(ob->query_skill("buddhism",1)/10)+30);
		ob->add("combat_exp",(int)(ob->query_skill("buddhism",1)/4)+90);
		me->delete("massage_name");
		ob->delete_temp("job_name");
		ob->delete_temp("massage");
		ob->delete_temp("massageed");
		ob->delete_temp("mark/按摩完");
		return 1;
	}
	return notify_fail("方相問道：你剛纔進去服侍方丈了？\n");
}
#include "/kungfu/class/nanshaolin/fang.h";

