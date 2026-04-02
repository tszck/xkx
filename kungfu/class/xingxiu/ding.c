// ding.c 丁春秋
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
inherit F_MANAGER;

#define YINLINFEN "/clone/medicine/poison/yinlinfen"
#define HONGLINFEN "/clone/medicine/poison/honglinfen"
#define DUCHONGFEN "/clone/medicine/poison/duchongfen"
#define BINGPOFEN "/clone/medicine/poison/bingpofen"

string ask_me();
string ask_du1();
string ask_du2();
string ask_ding();
string ask_azi();
string ask_job();
string ask_huoyan();
string ask_yinlinfen();
string ask_bingpofen();
string ask_duchongfen();
string ask_honglinfen();
 
void create()
{
	set_name("丁春秋", ({ "ding chunqiu", "ding" }));
	set("nickname", "星宿老怪");
	set("long", 
		"他臉色紅潤，滿頭白髮，頜下三尺銀髯，童顏鶴髮，當真便如圖\n"
		"畫中的神仙人物一般。\n"
		"他就是星宿派開山祖師、令正派人士深惡痛絕的星宿老怪丁春秋。\n"
		"可是他看起來形貌清奇，仙風道骨。\n");
	set("gender", "男性");
	set("age", 60);
	set("per", 50);
	set("attitude", "friendly");
	set("class", "scholar");
	set("shen_type", -1);
	set("shen", -150000);
	set("str", 25);
	set("int", 30);
	set("con", 28);
	set("dex", 28);
	
	set("max_qi", 4000);
	set("max_jing", 3000);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jiali", 100);
	set("combat_exp", 9000000);
	set("score", 400000);

	set_skill("force", 200);
	set_skill("huagong-dafa", 200);
	set_skill("throwing", 200);
	set_skill("feixing-shu", 300);
	set_skill("dodge", 200);
	set_skill("zhaixinggong", 300);
	set_skill("strike", 200);
	set_skill("chousui-zhang", 300);
	set_skill("claw", 200);
	set_skill("sanyin-wugongzhao", 300);
	set_skill("parry", 200);
	set_skill("staff", 200);
	set_skill("poison", 150);
	set_skill("tianshan-zhang", 300);
	set_skill("literate", 100);

	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("strike", "chousui-zhang");
	map_skill("claw", "sanyin-wugongzhao");
	map_skill("parry", "chousui-zhang");
	map_skill("staff", "tianshan-zhang");
	prepare_skill("strike", "chousui-zhang");
	prepare_skill("claw", "sanyin-wugongzhao");
	set("book_count", 1);
	set("zhen_count", 1);
	set("san_count", 1);
	set("huoyan_count", 1);
	set("ding_count", 0);
	set("di_count", 10);
	set("no_get",1);
	set("chat_chance_combat", 70);  
	set("chat_msg_combat", ({
		(: perform_action, "strike.huoqiu" :),
		(: perform_action, "strike.huoqiang" :),
		(: perform_action, "strike.yinhuo" :),
		(: perform_action, "strike.biyan" :),
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :),
	}) );

	set("inquiry", ([
		"阿紫" : (: ask_azi :),
		"神木王鼎" : (: ask_ding :),
		"毒經" : (: ask_me :),
		"星宿毒經" : (: ask_me :),
		"碧磷針" : (: ask_du1 :),
		"三笑逍遙散" : (: ask_du2 :),
		"逍遙三笑散" : (: ask_du2 :),
//		"火焰" : (: ask_huoyan :),
		"心情"  : (: ask_job :),
		"job"  : (: ask_job :),
		"木鼎" : "抓蟲子練毒用的。你敢偷，就廢了你。",
		"星宿派" : "我老仙乃是星宿派開山祖師, 還不趕快磕頭。", 
		"星宿海" : "你瞎了眼啦, 這兒就是。",
		"星宿" : "這兒方圓幾百裏都是老仙的練功房。",
		"丁春秋" : "沒大沒小的。再叫我廢了你。",
		"老仙" : "我星宿老仙比起古往今來的聖人怎麼樣啊？",
		"星宿老仙" : "以後叫老仙。",
		"吹捧" : "本來就是麼。",
		"銀磷粉"	: (:ask_yinlinfen:),
		"yinlin fen" : (:ask_yinlinfen:),
		"紅磷粉" : (:ask_honglinfen:),
		"honglin fen" : (:ask_honglinfen:),
		"冰魄粉" : (:ask_bingpofen:),
		"bingpo fen" : (:ask_bingpofen:),
		"毒蟲粉": (:ask_duchongfen:),
		"duchong fen": (:ask_duchongfen:),
	]));
	create_family("星宿派", 1, "開山祖師");
	set("class", "taoist");
	setup();
//	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/cloth/dao-cloth")->wear();
}

void init()
{
	object me, ob;
	::init();
	ob = this_player();
	me = this_object();
	if (interactive(ob = this_player()) && !is_fighting()) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}       
	add_action("do_flatter", "flatter");
	add_action("do_xian", "xian");
        add_action("do_qiecuo","qiecuo");
}

void greeting(object me)
{
	mapping myfam;
	int shen;
	
	if (!objectp(me) || environment(me)!=environment()) return;
	myfam = (mapping)me->query("family");
	shen = me->query("shen");

	if(!myfam) command("say 你千里迢迢來天山, 莫不是想加入我星宿派？");
	else if(myfam["family_name"] != "星宿派" && !me->query_temp("xx_job"))
		command("say 你千里迢迢來到天山，是仰慕本老仙我的仁德吧？");
	else if(myfam["family_name"] != "星宿派" && me->query_temp("xx_job"))
	command("nod " + me->query("id"));
	else if(shen > -1000 && shen < 0) command("say 你怎麼搞的？攪和了一身的白道氣息！");
	else if(shen > 0 && shen < 100000) command("say 好哇！你敢和白道的人攪和，不想活了是不是？");
	else if(shen > 100000)
	{
		command("say 你竟敢和白道的人攪和！從我這裏滾出去吧！");
		command("expell " + me->query("id"));
	}
	else command("say 好徒兒，功夫練得怎麼樣了？");
	if((myfam["family_name"] == "星宿派")&&(!me->query_skill("huagong-dafa",1))&&(me->query("combat_exp")>500000))
        {
                command("say 你竟敢放棄本門心法！從我這裏滾出去吧！");
                command("expell " + me->query("id"));
        }
}

void attempt_apprentice(object me)
{
	if ((int)me->query("shen") > -100) {
		command("say 老仙越看你越象白道派來臥底的。");
		return;
	}
	if ((int)me->query("combat_exp") < 10000) {
		command("say 你這點微末道行如何能學到老仙的神妙功夫。");
		return;
	}
	if( me->query_temp("pending/flatter") ) {
		command("say 你如此不把老仙放在眼裏，老仙怎會收你？");
		return;
	} else {
		command("say 我星宿老仙比起古往今來的聖人怎麼樣啊？");
		message_vision("星宿老怪微閉雙眼，手捻長鬚，一副等$N拍馬(flatter)的樣子。\n", me);
		me->set_temp("pending/flatter", 1);
	}
}

int do_flatter(string arg)
{
	object me=this_player(), ob=this_object();

/* 別派也要能拍他馬屁！
	if( !me->query_temp("pending/flatter") )
		return 0;
*/
	if( !arg ) return notify_fail("你説老仙什麼？\n");
//	ob->set_temp("pending/flatter", 0);
	switch(random(5))
	{
		case 0: message_vision("$N對$n大聲讚道：您老人家一蹬足天崩地裂，一搖手日月無光！\n", me,ob); break;
		case 1: message_vision("$N對$n大聲讚道：星宿老仙大袖擺動，口吐真言，叫旁門左道牛鬼蛇神，一個個死無葬身之地！\n", me,ob); break;
		case 2: message_vision("$N對$n大聲讚道：這天下武林盟主一席，非老仙莫屬。只須老仙下令動手，小人赴湯蹈火，萬死不辭！\n", me,ob); break;
		case 3: message_vision("$N對$n大聲讚道：日月無老仙之明，天地無老仙之大，自盤古氏開天闢地以來，更無第二人能有老仙的威德！\n", me,ob); break;
		case 4: message_vision("$N對$n大聲讚道：老仙神功蓋世，天下第一，戰無不勝，功無不克！\n", me,ob); break;
	}
	message_vision("$N大聲説道：" + arg + "\n", me);
	if( strsrch(arg, "星宿老仙") >=0 && (strsrch(arg, "德配天地") >=0 ||
		strsrch(arg, "威震寰宇") >=0 || strsrch(arg, "古今無比") >=0 ))
	{
		if(me->query_temp("pending/flatter"))
		{
			me->set_temp("pending/flatter", 0);
			me->set_temp("ding_flatter", 1);
			command("smile");
			command("say 這還差不多。\n");
			command("recruit " + me->query("id"));
			CHANNEL_D->do_channel(me, "chat",  "星宿老仙，德配天地，威震寰宇，古今無比！");
		}
		else
		{
			command("say 你對老仙我這麼恭敬，今後前途不可限量啊！\n");
			me->set_temp("ding_flatter", 1);
			return 1;
		}
	} else
	{
		command("say 你如此不把老仙放在眼裏，老仙怎會收你？");
	}
	return 1;
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		add("apprentice_available", -1);
}

// 星宿老仙，德配天地，威震寰宇，古今無比

string ask_me()
{
	mapping fam; 
	object ob;
	
	if(!(fam = this_player()->query("family")) ||
		fam["family_name"] != "星宿派")
		return RANK_D->query_respect(this_player()) + "與本派素無來往，不知此話從何談起？";
	if(query("book_count") < 1) return "你來晚了，本派的內功心法不在此處。";
	add("book_count", -1);
	ob = new("/clone/book/dujing_2");
	ob->move(this_player());
	return "好吧，這本「星宿毒經」你拿回去好好鑽研。";
}
string ask_du1()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "星宿派")
		return RANK_D->query_respect(this_player()) + "與本派素無來往，不知此話從何談起？";
	if (this_player()->query_skill("poison",1)<50)
		return "你的毒技火候未到，用不了這種東西。";
	if (query("zhen_count") < 1) return "你來晚了，碧磷針都發完了。";
	add("zhen_count", -1);
	ob = new("/d/xingxiu/obj/bilinzhen");
	ob->move(this_player());
	return "好吧，那你就先用這些針吧。";
}
string ask_du2()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "星宿派")
		return RANK_D->query_respect(this_player()) + "與本派素無來往，不知此話從何談起？";
	if (this_player()->query_skill("poison",1)<100)
		return "你的毒技火候未到，用不了這種東西。";
	if (query("san_count") < 1) return "你來晚了，現在沒什麼剩的了。";
	add("san_count", -1);
	ob = new("/clone/medicine/poison/sanxiaosan");
	ob->move(this_player());
	return "好吧，這包毒藥你拿回去善加利用吧。";
}
string ask_huoyan()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "星宿派")
		return RANK_D->query_respect(this_player()) + "與本派素無來往，不知此話從何談起？";
	if (this_player()->query_skill("poison",1)<100)
		return "你的毒技火候未到，用不了這種東西。";
	if (query("huoyan_count") < -100) return "你來晚了，現在沒什麼剩的了。";
	add("huoyan_count", -1);
	ob = new("/d/xingxiu/npc/obj/huoyan.c");
	ob->move(this_player());
	return "好吧，我就給你堆火焰吧。";
}

string ask_ding()
{
	mapping fam; 
 
	
	if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "星宿派")
		return RANK_D->query_respect(this_player()) + "與本派素無來往，不知此話從何談起？";
	switch (query("ding_count") )
	{
		case 0:
			command("kick1 "+this_player()->query("id"));
			add("ding_count", 1);
			return "養你們這些忘恩負義的狗娘徒弟有什麼用？連個小小的神木王鼎都會偷走！";
		case 1:
			command("sigh "+this_player()->query("id"));
			add("ding_count", 1);
			return "小阿紫把神木王鼎拿走了，誰把她抓回來，誰就是本門大弟子！";
		default: 
			command("grin");
			return "這事我正難受呢，你還這麼沒眼色老揭傷疤。活夠了是不是？";
	}
	return "哼。";
}

string ask_azi()
{
	mapping fam; 
 
	
	if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "星宿派")
		return RANK_D->query_respect(this_player()) + "與本派素無來往，不知此話從何談起？";
	if(query("ding_count") == 2 || this_player()->query_temp("smwd/step"))
	{
		this_player()->set_temp("smwd/step", 1);
		command("kick "+this_player()->query("id"));
		add("ding_count", 1);
		return "阿紫早她孃的跑了！你死人哪！還不快去追？";
	}
	else return "阿紫是個蠻可愛的小馬屁精。老夫我喜歡！";
}

string ask_job()
{
	object ob,me = this_player();
 
	if(!me->query("family") || me->query("family/family_name") != "星宿派")
		return "看你對老仙態度恭敬，何不加入我星宿派呢？";
	if(me->query("combat_exp") < 100000) 
		return "哈哈哈，你再加把力練功，很快就可以為老仙我分憂了。";
	if(me->query("shen") >= 0 ||
		me->query("shen") > -(me->query("combat_exp")/10)) 
		return "徒兒，看來你的心腸還不夠黑啊，有些事你不問也罷。";
	if(interactive(me) && me->query_temp("job_busy")) 
		return "你説要替老仙分憂，怎麼還在這裏發呆？";
	if(interactive(me) && me->query_condition("wait_xx_task")) 
		return "老仙現在心情還好，不用你來為我分憂。";
	if(query("di_count") < 1) 
		return "老仙現在心情還好，再來煩我就別怪老仙心情不好了。";

	ob = new(__DIR__"obj/di");
	add("di_count", -1);
	ob->move(me);
	ob->set("name", BLU"藍玉短笛"NOR);
	ob->set("long", BLU"這玉笛短得出奇，只不來七寸來長、通體碧藍，晶瑩可愛。\n" NOR);
	ob->set("xx_user", getuid(me));
	me->set_temp("xx_job", 1);
	message_vision("$N拿出一隻玉製短笛，交給$n。\n", this_object(), me);
	return "老仙我最近心情不佳，徒兒你要多多為我分憂才是！\n";    
}

int do_xian(string arg)
{
	object who, me, ob;
	mapping quest;
	who = this_player();
	me = this_object();

	if(who->is_busy() || who->is_fighting()) 
		return notify_fail("你正忙着呢。\n");
	if(!arg) return notify_fail("你要獻給老仙什麼東西？\n");
	if(!objectp(ob = present(arg, who)))
		return notify_fail("你身上沒有這樣東西。\n");
	if(!who->query_temp("xx_job"))
		return notify_fail("連老仙現在的心情還沒摸清楚就亂獻東西？\n"); 
	message_vision(HIY "\n$n畢恭畢敬地將"+ob->query("name")+HIY"拿出，雙手捧上，想要獻給$N。\n\n"NOR, me, who);
	if(me->is_busy())
	{
		"/cmds/std/say"->main(this_object(),"我正忙着呢，你等等。");
		return notify_fail("老仙讓你等等。\n");
        }
	if(!mapp(quest = who->query_temp("quest")) )
	{
		"/cmds/std/say"->main(this_object(),"你拿個"+ob->name()+CYN"給我幹嘛？"NOR);
		return notify_fail("老仙對這東西不感興趣。\n");
	}
	if( quest["time"] < time())
	{
		"/cmds/std/say"->main(this_object(),"嗯，這麼久才辦完，你幹什麼去了？給我滾一邊去！");
		who->apply_condition("wait_xx_task", 40);
		return notify_fail("完了，老仙生氣了。\n");
	}
	if(userp(ob))
	{
		command("stare " + who->query("id"));
		"/cmds/std/say"->main(this_object(),"竟敢用假貨來欺騙本老仙，給我滾出去！");
		message_vision("\n説完$N長袖一揮，一股內勁拂出，就將$n掃出洞外！\n\n", me, who);
		who->move("/d/xingxiu/riyuedong1");
		message("vision","只聽“呼”地一聲，緊接着"+who->query("name")+"從日月洞裏直飛了出來，摔了個四腳朝天！\n", environment(who), who);
		who->receive_wound("jing", 200);
		who->receive_wound("qi", 250);
		who->apply_condition("wait_xx_task", 30);
		who->delete_temp("quest");
		who->set_temp("last_id", quest["last_id"]);  
		who->start_busy(5);
		return notify_fail("糟糕，穿邦了！\n");
	}
	if(ob->query("id") != quest["id"])
	{
		command("hmm " + who->query("id"));
		"/cmds/std/say"->main(this_object(),"你拿個"+ob->query("name")+CYN"給老仙我有什麼用？");
		return notify_fail("好象是你獻錯東西了。\n");
	}
	ob->move(me);
	me->start_busy(2);
	call_out("destroying", 0, ob, me);
	call_out("done", 3, who);       
	return 1;
}

void done(object me)
{
	int hgdf, poison;
	mapping fam;
  
	if(!me) return;
	hgdf = me->query_skill("huagong-dafa",1);
	poison = me->query_skill("poison",1);
	fam = (mapping)me->query("family");

	command("pat " + me->query("id"));       
	command("say 不錯不錯，既然你找到了老仙我想要的東西，我就指點指點你吧。");
	if(fam["family_name"] == "星宿派")
	{
		if(hgdf < 180 && SKILL_D("huagong-dafa")->valid_learn(me))
			me->improve_skill("huagong-dafa", me->query("xx_points")*5);   
		if(poison < 150 && SKILL_D("poison")->valid_learn(me))
			me->improve_skill("poison", me->query("xx_points")*5);
		me->add("xx_points", 1);          
		tell_object(me, "你目前已經為老仙分擔了"+chinese_number(me->query("xx_points"))+"次憂愁。\n");
		me->add("family/fealty",me->query("xx_points"));
		tell_object(me, "你的門派忠誠度上升了。\n");
	}
	call_out("ok", 0, me);                    
}

void destroying(object obj, object me)
{
	message_vision("$N拿起$n仔細地端詳了一會兒，滿意地點了點頭，臉上露出了笑容。\n", me, obj);
	destruct(obj);
}

void ok(object me)
{
	mapping quest;
	if(!me) return;
   
	quest = me->query_temp("quest");
	tell_object(me, "你聽了老仙的指點，功夫進步了不少！\n"); 
	tell_object(me, GRN"你獲得出"+chinese_number(quest["pot_reward"])+"點潛能和"+chinese_number(quest["exp_reward"])+"點經驗的獎勵！\n"NOR);
	me->add("combat_exp", quest["exp_reward"]);
	me->add("potential", quest["pot_reward"]);
	me->add("shen", -(quest["exp_reward"]*15));
	me->delete_temp("quest");
	me->set_temp("last_id", quest["last_id"]);     
//	me->apply_condition("job_busy", 3);  
	me->clear_condition("job_busy");
	return;
}

string ask_yinlinfen()
{
	mapping fam; 
	object ob;
	object owner;
	object temp;
	object me=this_player();
	if (!(fam = me->query("family")) ||
		fam["family_name"] != "星宿派")
		return RANK_D->query_respect(this_player()) + "與本派素無來往，不知此話從何談起？";
	if (me->query_skill("poison",1)<100)
		return "你的毒技火候未到，用不了這種東西。";
	ob=new(YINLINFEN);
	if (temp=ob->violate_unique())
	 {
	 	destruct(ob);
	 	ob=temp;
  	owner = environment(ob);
  	if (owner == me)
     return ob->query("name")+"不就在你手中嗎？";
  	if (objectp(owner) && owner != this_object())
     {
      if (! owner->is_character())
           return "你來晚了，"+ob->query("name")+"現在不在我手中。";
      if (owner->query("family/family_name") == "星宿派")
           return ob->query("name")+"現在在本派" + owner->query("name") +"手中，你要用就去找他吧。";
      else
           return "我正為此事擔憂呢，"+ob->query("name")+"現在落入了" + owner->query("name") +"之手，你快去把他殺了，把東西取回來！";
     }
  }
	command("nod");
  ob->move(this_object());
  command("give fen to " + me->query("id"));
  return "這"+ob->query("name")+"你便拿去，希望你能好好利用。";
}

string ask_duchongfen()
{
	mapping fam; 
	object ob;
	object owner;
	object temp;
	object me=this_player();
	if (!(fam = me->query("family")) ||
		fam["family_name"] != "星宿派")
		return RANK_D->query_respect(this_player()) + "與本派素無來往，不知此話從何談起？";
	if (me->query_skill("poison",1)<100)
		return "你的毒技火候未到，用不了這種東西。";
	ob=new(DUCHONGFEN);
	if (temp=ob->violate_unique())
	 {
	 	destruct(ob);
	 	ob=temp;
  	owner = environment(ob);
  	if (owner == me)
     return ob->query("name")+"不就在你手中嗎？";
  	if (objectp(owner) && owner != this_object())
     {
      if (! owner->is_character())
           return "你來晚了，"+ob->query("name")+"現在不在我手中。";
      if (owner->query("family/family_name") == "星宿派")
           return ob->query("name")+"現在在本派" + owner->query("name") +"手中，你要用就去找他吧。";
      else
           return "我正為此事擔憂呢，"+ob->query("name")+"現在落入了" + owner->query("name") +"之手，你快去把他殺了，把東西取回來！";
     }
  }
	command("nod");
  ob->move(this_object());
  command("give fen to " + me->query("id"));
  return "這"+ob->query("name")+"你便拿去，希望你能好好利用。";
}

string ask_honglinfen()
{
	mapping fam; 
	object ob;
	object owner;
	object temp;
	object me=this_player();
	if (!(fam = me->query("family")) ||
		fam["family_name"] != "星宿派")
		return RANK_D->query_respect(this_player()) + "與本派素無來往，不知此話從何談起？";
	if (me->query_skill("poison",1)<100)
		return "你的毒技火候未到，用不了這種東西。";
	ob=new(HONGLINFEN);
	if (temp=ob->violate_unique())
	 {
	 	destruct(ob);
	 	ob=temp;
  	owner = environment(ob);
  	if (owner == me)
     return ob->query("name")+"不就在你手中嗎？";
  	if (objectp(owner) && owner != this_object())
     {
      if (! owner->is_character())
           return "你來晚了，"+ob->query("name")+"現在不在我手中。";
      if (owner->query("family/family_name") == "星宿派")
           return ob->query("name")+"現在在本派" + owner->query("name") +"手中，你要用就去找他吧。";
      else
           return "我正為此事擔憂呢，"+ob->query("name")+"現在落入了" + owner->query("name") +"之手，你快去把他殺了，把東西取回來！";
     }
  }
	command("nod");
  ob->move(this_object());
  command("give fen to " + me->query("id"));
  return "這"+ob->query("name")+"你便拿去，希望你能好好利用。";
}

string ask_bingpofen()
{
	mapping fam; 
	object ob;
	object owner;
	object temp;
	object me=this_player();
	if (!(fam = me->query("family")) ||
		fam["family_name"] != "星宿派")
		return RANK_D->query_respect(this_player()) + "與本派素無來往，不知此話從何談起？";
	if (me->query_skill("poison",1)<100)
		return "你的毒技火候未到，用不了這種東西。";
	ob=new(BINGPOFEN);
	if (temp=ob->violate_unique())
	 {
	 	destruct(ob);
	 	ob=temp;
  	owner = environment(ob);
  	if (owner == me)
     return ob->query("name")+"不就在你手中嗎？";
  	if (objectp(owner) && owner != this_object())
     {
      if (! owner->is_character())
           return "你來晚了，"+ob->query("name")+"現在不在我手中。";
      if (owner->query("family/family_name") == "星宿派")
           return ob->query("name")+"現在在本派" + owner->query("name") +"手中，你要用就去找他吧。";
      else
           return "我正為此事擔憂呢，"+ob->query("name")+"現在落入了" + owner->query("name") +"之手，你快去把他殺了，把東西取回來！";
     }
  }
	command("nod");
  ob->move(this_object());
  command("give fen to " + me->query("id"));
  return "這"+ob->query("name")+"你便拿去，希望你能好好利用。";
}