#include <ansi.h>

inherit NPC;

int give_tools();

void create()
{
	set_name("老李",({ "lao li", "li" }) );
	set("gender", "男性" );
	set("age", 45);
	set("long","他是揚州武館裏管物品工具的，人們都習慣稱他老李，真名反而倒沒什麼人知道了。\n");
	set("combat_exp", 25000);
	set("attitude", "friendly");
	set("inquiry", ([
		"工具" : (: give_tools :),
	]) );
	setup();
	carry_object("clone/cloth/cloth")->wear();
}
void init()
{
	object ob;
	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
    }
}
	
int give_tools()
{
	object tools,ob,me;
	me = this_object();
	ob = this_player();

	if(ob->query_temp("mark/工具"))
		return notify_fail("老李說：你已經領了工具了，怎麼沒還又來領了？");
	if(ob->query_temp("mark/還了"))
		return notify_fail("老李說：你還沒覆命領新活吧，跑來要什麼工具。");

	if(!((ob->query_temp("job_name")=="鋸木頭" ) ||
		(ob->query_temp("job_name")=="鋤草" ) ||
		(ob->query_temp("job_name")=="澆菜地" ) ||
		(ob->query_temp("job_name")=="劈柴" ) ||
		(ob->query_temp("job_name")=="挑水" ) ||
		(ob->query_temp("job_name")=="打掃馬房")))
		return notify_fail("老李說：你沒跟張總管領活吧，跑來要什麼工具。");
 
	if(ob->query_temp("job_name")=="鋤草")
		tools = new((__DIR__"obj/wg_chutou"));
	else if(ob->query_temp("job_name")=="澆菜地")
		tools = new((__DIR__"obj/wg_piao"));
	else if(ob->query_temp("job_name")=="鋸木頭")
		tools = new((__DIR__"obj/wg_juzi"));
	else if(ob->query_temp("job_name")=="劈柴")
		tools = new((__DIR__"obj/wg_chaidao"));
	else if(ob->query_temp("job_name")=="挑水")
		tools = new((__DIR__"obj/wg_shuitong"));
	else tools = new((__DIR__"obj/wg_saozhou"));
	tools->move(this_player());
	command("say 既然你已經領了活，我就給你這把工具，小心保管，別弄丟了。");
	message_vision("$N交給$n一把工具。\n", me, ob);
	ob->set_temp("mark/工具",1);
	return 1;
}

int accept_object(object me, object obj)
{
	object ob;
	me=this_object();
	ob=this_player();

	if(!(ob->query_temp("mark/劈完了") ||
		ob->query_temp("mark/澆完了") ||
		ob->query_temp("mark/鋤完了") ||
		ob->query_temp("mark/挑完了") ||
		ob->query_temp("mark/鋸完了") ||
		ob->query_temp("mark/掃完了")))
	{
		command("say 你還沒完成工作，怎麼就回來還工具了，偷懶嗎？");
		return 0;
	}
	if ((obj->query("id")!="juzi") &&
		(obj->query("id")!="chutou") &&
		(obj->query("id")!="piao") &&
		(obj->query("id")!="saozhou") &&
		(obj->query("id") != "shuitong") &&
		(obj->query("id") != "chaidao"))
	{
		command("say 你還錯東西了吧，我從沒有發過這樣工具。");
		return 0;
	}
	if(!ob->query_temp("job_name"))
	{
		command("shake");
		command("say 我沒有發給你過東西，你是不是還錯了？");
		return 0;
	}
	command("nod");
	command("say 歡迎下次再來！");
	ob->set_temp("mark/還了",1);
	call_out("destroying", 1, me, obj);	   
	return 1;
}
void destroying(object me, object obj)
{
	destruct(obj);
	return;
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if(ob->query_temp("mark/工具")) return 0; 

	if(ob->query_temp("mark/劈完了") ||
		ob->query_temp("mark/澆完了") ||
		ob->query_temp("mark/鋤完了") ||
		ob->query_temp("mark/鋸完了") ||
		ob->query_temp("mark/掃完了") ||
		ob->query_temp("mark/挑完了"))
	{
		command("smile"+ob->query("id"));
		command("say 工作做完了，可以還工具"HIR"(give xxx to laoli)"NOR"給我了! \n");
		return; 
	}
	if((ob->query_temp("job_name")=="鋸木頭" ) ||
		(ob->query_temp("job_name")=="鋤草" ) ||
		(ob->query_temp("job_name")=="澆菜地" ) ||
		(ob->query_temp("job_name")=="劈柴" ) ||
		(ob->query_temp("job_name")=="挑水" ) ||
		(ob->query_temp("job_name")=="打掃馬房" ))
	{
		command("bow "+ob->query("id"));
		command("say 這位" + RANK_D->query_respect(ob) + "，到我這領工具(ask li about 工具)吧。\n");
	}
}				

