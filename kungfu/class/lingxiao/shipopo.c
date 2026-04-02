// Npc: /d/lingxiao/npc/shipopo.c
// Last Modified by winder on Jul. 15 2001

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void consider();
string ask_book();
string ask_skill();
void create()
{
	set_name("史婆婆",({"shi popo","popo","shi"}));
	set("gender", "女性");
	set("age", 50);
	set("long", "她是雪山派掌門人白自在的妻子，雖説現在人已顯得蒼老，\n"
		"但幾十年前提起“江湖一枝花”史小翠來，武林中卻是無人不知。\n");
	set("attitude", "friendly"); 

	set("str", 30);
	set("con", 30);
	set("int", 30);
	set("dex", 30);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jing", 1500);
	set("max_jing", 1500);
	set("qi", 2000);
	set("max_qi", 2000);
	set("jiali", 50);

	set("combat_exp", 2000000);
	set("inquiry", ([
		"金烏刀譜":(:ask_book:),
		"金烏墜地":(:ask_skill:),
	]) );
	set("shen_type", 0);
	set("score", 50000);

	set("env/wimpy", 60);
	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :)
	}) ); 
	set_skill("force", 150);
	set_skill("dodge", 150);
	set_skill("blade", 200);
	set_skill("parry", 120);
	set_skill("strike", 100);
	set_skill("jinwu-blade", 200);
	set_skill("snowstep", 150); 
	set_skill("bingxue-xinfa", 150); 
	set_skill("snow-strike", 120);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/damage", 35);
	set("count", 1);

	map_skill("blade", "jinwu-blade"); 
	map_skill("force", "bingxue-xinfa"); 
	map_skill("strike", "snow-strike");
	map_skill("parry", "jinwu-blade");
	map_skill("dodge", "snowstep");
	prepare_skill("strike", "snow-strike");
	create_family("凌霄城", 5, "弟子");
	setup();

	carry_object("/clone/weapon/gangdao")->wield();
	carry_object(CLOTH_DIR+"bai")->wear();
}

string ask_book()
{
	object me,ob;
	ob=this_player(); 
	
	if(ob->query("family/master_id")=="bai wanjian")
	{
		if (query("count") == 1)
		{
			command("say 你是萬劍的弟子嗎？那就給你吧。");
			message_vision(HIG"史婆婆掏出一本小冊子，交給$N。\n\n"NOR,ob);
			me=new(BOOK_DIR+"jinwu-book");
			me->move(ob);
			add("count", -1);
			return "你好好讀讀，比老鬼的劍法好多了。\n";
		}
		else return"你來晚啦，刀譜已經讓人拿走了。\n";
	}
	if(ob->query("family/master_id")=="bai zizai")
	{
		if (query("count") == 1)
		{
			command("say 你是老鬼的弟子嗎？那就給你吧。");
			message_vision(HIG"史婆婆掏出一本小冊子，交給$N。\n\n"NOR,ob);
			me=new(BOOK_DIR+"jinwu-book");
			me->move(ob);
			add("count", -1);
			return "你好好讀讀，比老鬼的劍法好多了。\n";
		}
		else return "你來晚啦，刀譜已經讓人拿走了。\n";
	}

	command("say 走開，不然老太婆要發火了？");
	message_vision(HIG"史婆婆哼了一聲，不理$N。\n\n"NOR,ob);

	return "我雖離開了凌霄城，卻也不會亂傳人武功。\n";
}

int recognize_apprentice(object ob)
{
	mapping myfam;
	myfam = (mapping)ob->query("family");
//	if ( myfam["family_name"] == "凌霄城") return 1 ;
	if ((int)ob->query_temp("tmark/shi") == 1 )
	message_vision("史婆婆哼了一聲，對$N説道：老身今天不想再教了，你下次再來吧。\n", ob);
	if (!(int)ob->query_temp("tmark/shi")) return 0; 
	ob->add_temp("tmark/shi", -1);
	return 1;
}

int accept_object(object who, object ob)
{
	
	if ( (string) ob->query("id") =="jinwu-staff" )
	{
		if (!(int)who->query_temp("tmark/shi"))
			who->set_temp("tmark/shi", 0);
		message_vision("史婆婆接過金烏杖，“呵呵”笑了兩聲，摸摸杖身，説道：\n好！好！好！難得你幫我乖孫女辦事，真不錯，好吧！\n老身今天正好有空，就教你一會工夫吧。\n", who);
		who->add_temp("tmark/shi", 900);
		return 1;
	}
	return 0;
}

void attempt_apprentice(object ob)
{
	if (ob->query_int() < 30)
	{
		command("say 你這種資質，一邊去吧！");
		return;
	}
	if ((int)ob->query_skill("bingxue-xinfa",1) < 80 )
	{
		command("say 你的本門內功心法太低了，還是努努力先提高一下吧！");
		return;
	} 
	if ((int)ob->query("shen") < 0 )
	{
		command("say 你這種人，再不滾，我馬上宰了你。"); 
		return;
	} 
	if ((int)ob->query("max_neili") < 800 )
	{
		command("say 你內力不足，先去打熬打熬內力吧。"); 
		return;
	}
	if ((int)ob->query_skill("xueshan-sword",1) < 100 )
	{
		command("say 你的本門劍法太低了，還是先找你師父提高吧！"); 
		return;
	}
	if ((int)ob->query_skill("sword",1) < 100 )
	{  
		command("say 你的基本劍法太低了，還是先提高基本功吧！");
		return; 
	}
	command("say 很好，很好，老身就收你為徒吧。");
	command("recruit " + ob->query("id"));
} 
string ask_skill()
{
	object me=this_object();
	object ob= this_player();
	
	if ((int)ob->query("can_perform/jinwu-blade/jinwu"))
		return "你不是已經學會了嗎，還找我做什麼。";

	if ((string)ob->query("family/master_id") != "shi popo")
		return "你不是我的弟子，走開！";
	
	if ((int)ob->query_skill("jinwu-blade",1) < 100)
		return "你的金烏刀法還不到家，用不了這招。";

	if ((int)ob->query_skill("bingxue-xinfa",1) < 100)
		return "你的冰雪心法法火候不夠，用不了這招。";

	if ((int)ob->query("max_neili")<1000)	
		return "你的內力還差一些，加油吧。";
		
        message_vision( HIY "$n" HIY "道：“你能有今日這個地步，也"
                       "算不錯。今日我\n傳你雪山劍法的破解之法，你"
                       "可記牢了。雪山派劍法有\n七十二招，我金烏派"
                       "武功處處勝他一籌，卻有七十三招。\n咱們七十"
                       "三招破他七十二招，最後一招瞧仔細了！”説\n"
                       "着拔出腰間柴刀從上而下直劈下來，又道：“你"
                       "使這招\n之時，須得躍起半空，和身直劈！”當"
                       "下又教將如何運\n勁，如何封死對方逃遁的空隙"
                       "等竅門慢慢傳給$N" HIY "，$N" HIY "凝\n思半"
                       "晌，依法施為，縱身躍起，半空中揮刀直劈，呼"
                       "的\n一聲，刀鋒離地尚有數尺，地下已是塵沙飛"
                       "揚，敗草落\n葉被刀風激得團團而舞，果然威力"
                       "驚人。\n" NOR, ob, this_object());
        command("heng");
        tell_object(ob, HIC "你學會了「金烏墜地」。\n" NOR);
				ob->set("can_perform/jinwu-blade/jinwu",1);
        return "這一招可盡破雪山劍法，你自己下去練吧。";
}
