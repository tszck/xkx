// renyy.c
#include <ansi.h>
inherit NPC;
string ask_ling();
int ask_tuijiao();

void create()
{
	set_name("任盈盈", ({ "ren yingying","ren","ying"}) );
	set("gender", "女性" );
	set("long", "她睫毛甚長，容貌麗都，秀麗絕倫，不過十七八歲年紀。");
	set("age", 18);
	set("shen_type", 1);
	set("combat_exp", 500000);
	set("env/wimpy", 40);
	set("per", 30);
	set("str", 16);
	set("dex", 27);
	set("con", 17);
	set("int", 18);
	set("attitude", "friendly");
	
	set("max_qi", 3000);
	set("max_jing", 2000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 200);
	set("combat_exp", 1200000);

	set_skill("luteplaying", 200);      // 繞樑琴藝
	set_skill("literate", 100);         // 讀書識字
	set_skill("force", 180);            // 基本內功
	set_skill("dodge", 180);            // 基本躲閃
	set_skill("unarmed", 180);          // 基本拳腳
	set_skill("parry", 180);            // 基本招架
	set_skill("dagger", 180);           // 基本刺法
        set_skill("shigu-bifa", 180);       // 石鼓打穴筆法
	set_skill("piaoyibu", 180);         // 飄逸步法
	set_skill("kuihua-xinfa", 180);     // 葵花心法
	set_skill("xixing-dafa", 50);       // 吸星大法
	set_skill("changquan", 180);        // 太祖長拳

	map_skill("force", "xixing-dafa");
	map_skill("dagger", "shigu-bifa");
	map_skill("unarmed", "changquan");
	map_skill("dodge", "piaoyibu");
	map_skill("parry", "shigu-bifa");

	set("chat_chance",60);
    	set("chat_msg",({
	"任盈盈説道：你若能把這封信捎給他，可太謝謝你了.............\n",
	"任盈盈緩緩説道：“咱們武林中人，只怕是註定要不得好死的了。他日後倘若對我負心，我也不盼望他天打雷劈，我……我……我寧可親手一劍刺死了他。”\n",
	"任盈盈説道：也不知藍鳳凰見沒見到他，可真急死我了......\n",
	}) );
       
	set("party/party_name", HIB"日月神教"NOR);
	set("party/rank", MAG"聖姑"NOR);
	create_family("黑木崖", 8, "弟子");
	set("inquiry",([
		"令狐沖"  : (: ask_ling :),
		"退教"    : (: ask_tuijiao :),
		"tuijiao" : (: ask_tuijiao :),
	]) );
	set_temp("letter",1);
	setup();
	carry_object(CLOTH_DIR"female-cloth")->wear();
	carry_object(CLOTH_DIR"female-shoe")->wear();
	carry_object(WEAPON_DIR"dagger")->wield();
	carry_object("/d/heimuya/npc/obj/letter");
}

string ask_ling()
{
	object me=this_player();
	object obn;

	message_vision("任盈盈説道：去年上華山一去就再無音信，他不會忘記我吧......\n", me );
	if(query_temp("letter")==0)
	{
		message_vision("任盈盈又説道：這位"+ RANK_D->query_respect(me)+"，我已經派藍鳳凰去尋找了，也不知道怎麼樣了。\n",me);
		return "";
	}
	message_vision("任盈盈又説道：這位"+ RANK_D->query_respect(me)+"，我這裏有信，你要是找到令狐沖，就把信交給他，他會明白的。\n" , me);
	obn=new("/d/heimuya/npc/obj/letter");
	obn->move(me);
	set_temp("letter",0);
   
	return ("這封信煩你交給令狐沖。\n");
}
int ask_tuijiao()
{
        object ob;
        ob=this_player();

        if(ob->query("party/party_name") != HIB"日月神教"NOR)
        {
		message_vision("盈盈淺淺一笑，對$N説道：你還沒加入我神教呢，就想退教？\n",ob);
		return 1;
        }
        if(ob->query("family/family_name") == "黑木崖" )
        {
	message_vision("盈盈抬起俏臉對$N説道：你已經是黑木崖弟子，如何能退教？\n", ob);
                return 1;
        }

        command("look "+ob->query("id"));
        command("sigh ");
        command("nod ");
        ob->delete("party");
        return 1;
}

void attempt_apprentice(object ob)
{
	if(!ob->query("party")||ob->query("party/party_name")!=HIB"日月神教"NOR)
	{
		command("say 我只收神教弟子，你找四大堂長老入教去！\n");
		return;
	}
	if ((int)ob->query_skill("kuihua-xinfa", 1) < 60)
	{
		command("say 想學我教功夫，在內功上，" + RANK_D->query_respect(ob) + "是否還應該多下點功夫？");
		return;
	}
	command("say 好吧，本姑娘就收下你了。");
	command("recruit " + ob->query("id"));
}

