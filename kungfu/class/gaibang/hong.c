// hong.c

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
inherit F_MANAGER;
int try_to_learn_ds();

void create()
{
	set_name("洪七公", ({"hong qigong", "hong", "qigong"}));
	set("nickname", "九指神丐");
	set("gender", "男性");
	set("age", 75);
	set("long", 
		"他就是丐幫第十七任幫主，號稱“北丐”的洪七公老爺子。\n");
	set("attitude", "peaceful");
	set("class", "beggar");
 	set("beggarlvl", 10);
	
	set("str", 30);
	set("int", 24);
	set("con", 30);
	set("dex", 24);

	set("chat_chance", 1);
	set("chat_msg", ({
	"洪七公嘆了口氣道：“唉……何時能再喫到蓉兒做的「叫化雞」啊……”\n",
	"洪七公説道：“俗話説「喫在江南」，所以老叫化特地跑來揚州看看。”\n",
	"洪七公喃喃道：“我們丐幫的「降龍十八掌」是天下最霸道的掌法。”\n",
	}));
	set("inquiry", ([
		"青竹林" : "東北西北東西北。\n",
		"丐幫" : "東北西北東西北。\n",
	]));
	set("no_teach", ([
				"xianglong-zhang" : (: try_to_learn_ds :),
	]));
	set("qi", 2500);
	set("max_qi", 2500);
	set("jing", 800);
	set("max_jing", 800);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 300);
	
	set("combat_exp", 3000000);
	set("score", 200000);
	set("shen", 100000);
	 
	set_skill("force", 200);             // 基本內功
	set_skill("huntian-qigong", 200);    // 混天氣功
	set_skill("unarmed", 200);           // 基本拳腳
	set_skill("dodge", 200);      	     // 基本躲閃
	set_skill("xiaoyaoyou", 300);        // 逍遙遊
	set_skill("parry", 200);             // 基本招架
	set_skill("strike", 200);            // 基本掌法
	set_skill("xianglong-zhang", 300);   // 降龍十八掌
	set_skill("hand", 200);              // 基本手法
	set_skill("suohou-hand", 300);       // 鎖喉擒拿手
	set_skill("blade", 200);             // 基本刀法
	set_skill("liuhe-blade", 300);       // 四象六合刀
	set_skill("staff", 200);             // 基本杖法
	set_skill("fengmo-staff", 300);      // 瘋魔杖法
	set_skill("stick", 200);             // 基本棒法
	set_skill("dagou-bang", 300);        // 打狗棒法
	set_skill("begging", 100);           // 叫化絕活
	set_skill("checking", 100);          // 道聽途説
	set_skill("training", 100);         // 馭獸術
	set_skill("lianhua-zhang",100);      // 蓮花掌
	
	map_skill("force", "huntian-qigong");
	map_skill("strike", "lianhua-zhang");
	map_skill("hand",  "suohou-hand");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("blade", "liuhe-blade");
	map_skill("parry", "dagou-bang");
	map_skill("stick", "dagou-bang");
	map_skill("staff", "fengmo-staff");
	prepare_skill("hand",  "suohou-hand");
	prepare_skill("strike", "lianhua-zhang");
  

	set("party/party_name", HIC"丐幫"NOR);
	set("party/rank", HIR"幫主"NOR);
	set("party/level", 10);
	create_family("丐幫", 17, "幫主");

	setup();
	
	carry_object(__DIR__"obj/lvyv_bang")->wield();
	carry_object(__DIR__"obj/jiaohuaji");
	carry_object(__DIR__"obj/cloth")->wear();
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
	if((myfam["family_name"] == "丐幫")&&(!me->query_skill("huntian-qigong",1))&&(me->query("combat_exp")>500000))
        {
                command("say 你竟敢放棄本門心法！從我這裏滾出去吧！");
                command("expell " + me->query("id"));
        }
        
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query_str() < 20 || (int)ob->query_con() < 20) {
		command("say 當叫化子需要能喫苦耐勞，依我看" + RANK_D->query_respect(ob) + "的資質似乎不適合當叫化子？");
		return;
	}
	if ((string)ob->query("family/family_name") != "" &&
	    (string)ob->query("family/family_name") != "丐幫")
	{
		command("say " + RANK_D->query_respect(ob) + "既然已有名師指點，何必又來拜老叫化呢？");
		return;
	}
	if (ob->query_temp("jiahuoji")) command("recruit "+ob->query("id"));
	else
	command("say " + RANK_D->query_respect(ob) + "各項條件都不錯，只可惜老叫化現在沒力氣收徒……");
	
}

int accept_object(object who, object ob)
{
        int lv;
        string by,hid;
        object hob;
        object me=this_object();
        if (ob->query("food_supply") <= 0)
        	return 0;
        if ((string)ob->query("id") != "jiaohua ji" && !ob->query("values"))
        {
        	"/cmds/std/say"->main(this_object(),"老叫化對" + (string)ob->query("name") + CYN+"沒什麼興趣……");
        	return 0;
        }
        if (query("food") >= max_food_capacity() - ob->query("food_supply")) {
        	command("say 老叫化現在飽得很。");
        	return 0;
        }
        if((string)ob->query("id") == "jiaohua ji")
        {
        	command("say 啊……這正是我想喫的叫化雞呀！");
          command("eat ji");
          who->set_temp("jiahuoji",1);
          return 1;
        }
        lv = ob->query("values");
        by  = ob->query("make_by");
        if (lv < 100)
        {
                message_vision(CYN "$N" CYN "嗅了嗅" + ob->name() +
                               CYN "，皺眉道：這東西你還是自個留着"
                               "吧。\n" NOR, me);
                return 0;
        }

        if (lv < 120)
        {
                message_vision(CYN "$N" CYN "嗅了嗅" + ob->name() +
                               CYN "道：味道不錯，可還是稍微欠那麼"
                               "點兒火候。\n" NOR, me);
                return 0;
        }

        message_vision(HIW "$N" HIW "嗅了嗅$n" HIW "遞來的" + ob->name() +
                       HIW "，嚐了幾口，直咂舌頭，連聲稱讚。\n" NOR, me, who);

        if (! who->id(by))
        {

                command("say 可惜不知道是誰做的，有空可得給我引見引見。");
                return 1;
        }

        if (who->query("gender") != "女性")
        {
                command("say 想不到你一個大老爺們手藝也不錯。難得，難得。");
                return 1;
        }

        if (who->query("family/family_name") == query("family/family_name"))
        {
                command("say 幫裏有你這樣的人真不錯，以後就靠你多照顧了。");
                return 1;
        }

        if (ob->query("id")!="yudiluomei")
        {
                "/cmds/std/say"->main(this_object(),"老叫花我喫遍大江南北，你這"+ob->query("name")+CYN+"也算是人間美味啊！不錯，不錯。");
                return 1;
        }

        if (who->query("can_learn/hong/xiaoyaoyou") >= 1)
        {
                command("pat " + who->query("id"));
                command("say 又給老叫花解攙來了？多謝，多謝。");
                return 1;
        }
        command("stuff");
        command("say 老叫花沒啥值錢的，就傳你一套身法作為報答吧。");

        tell_object(who, HIC "\n洪七公同意傳授你「逍遙遊身法」。\n" NOR);
        who->set("can_learn/hong/xiaoyaoyou", 1);

        if (lv >= 200)
        {
                message_vision(CYN "\n$N" CYN "沉思良久，又道：想不"
                               "到除了黃丫頭，居然還有人能做出如此美"
                               "味。\n" NOR, me, who);

                if (! stringp(hid = who->query("couple/couple_id")))
                {
                        command("say 卻不知你如今有婆家了沒有，可要"
                                "老叫花給你介紹？");
                        return 1;
                }

                if (! objectp(hob = find_player(hid)))
                {
                        command("sigh");
                        command("say 可惜你那位不在，否則我倒是可以"
                                "傳他兩手功夫。罷了，罷了。");
                        return 1;
                }

                if (hob->query("family/family_name") == query("family/family_name"))
                {
                        command("say " + hob->name(1) + "能娶到你這"
                                "樣的老婆，也不枉了。");
                        return 1;
                }
                command("say 什麼時候空了也叫你那位來，我也教他點東西。");

                tell_object(hob, HIC "\n洪七公同意傳授你「降龍十八掌」。\n" NOR);
                hob->set("can_learn/hong/sub-xianglong-zhang", 1);
//                hob->improve_skill("martial-cognize", 1500000);
        }
        destruct(ob);
        return 1;
}

int recognize_apprentice(object me, string skill)
{
        if (! me->query("can_learn/hong/sub-xianglong-zhang")
           && ! me->query("can_learn/hong/xiaoyaoyou"))
        {
                command("say 你是誰？哪裏來的？要幹啥？");
                return notify_fail("");
        }

        if ((me->query("can_learn/hong/sub-xianglong-zhang")
           && skill != "xianglong-zhang"
           && skill != "strike")
           || (me->query("can_learn/hong/xiaoyaoyou")
           && skill != "xiaoyaoyou"
           && skill != "dodge"))
        {
                command("say 老叫化教你什麼就學什麼，你不學就算了。");
                return notify_fail("");
        }

        if ((skill == "strike"
           && me->query_skill("strike", 1) > 179)
           || (skill == "dodge"
           && me->query_skill("dodge", 1) > 179))
        {
                command("say 到此為止，你的功力也不差了，剩下的自己去練。");
                return notify_fail("");
        }
        return 1;
}

int try_to_learn_ds()
{
        object me;
        object sob;
        int i;
        int flag;
        string *sub_skills;

        me = this_player();

        if (me->query("family/family_name") == query("family/family_name")
           && me->query("party/level") < 9)
        {
                command("say 你要學降龍十八掌？等你升到本幫長老再説吧！");
                return 1;
        }

        if (me->query("family/family_name") != query("family/family_name")
           && ! me->query("can_learn/hong/sub-xianglong-zhang"))
        {
                command("say 你是哪裏來的？一邊待著去。");
                return 1;
        }

        if (me->query("shen") < 80000)
        {
                command("say 你的俠義正事還做得不夠，我可不放心傳你絕技。");
                return 1;
        }

        sob = find_object(SKILL_D("xianglong-zhang"));

        if (! sob)
                sob = load_object(SKILL_D("xianglong-zhang"));

 //       if (! sob->valid_learn(me))
 //               return 0;

        if (me->query_skill("xianglong-zhang", 1))
        {
                command("say 你不是已經會了麼？自己好好練吧。");
                return 1;
        }
        
        if ((int)me->query("max_neili") < 3000)
        {
            command("say 你的內力太弱，還無法練降龍十八掌。");
            return 1;
        }
        if ((int)me->query("str") < 25)
        {
            command("say 你的先天膂力孱弱，難以修煉降龍十八掌。");
            return 1;
        }
        if ((int)me->query("con") < 20)
        {
            command("say 你的先天根骨孱弱，難以修煉降龍十八掌。");
            return 1;
        }
        if ((int)me->query_skill("strike", 1) < 180)
        {
            command("say 你的基本掌法火候不夠，難以修煉降龍十八掌。");
            return 1;
        }

        sub_skills = keys(sob->query_sub_skills());

        flag = 0;
        for (i = 0; i < sizeof(sub_skills); i++)
        {
                if (me->query_skill(sub_skills[i], 1) >= 10)
                        continue;

                me->set_skill(sub_skills[i], 10);

                if (! flag)
                {
                        flag = 1;
                        command("nod");
                        command("say 我將十八路掌法傳授與你，假以時"
                                "日，必能融會貫通。");
                }
                write(HIC "你對" + to_chinese(sub_skills[i]) + "有了"
                      "一些領悟。\n" NOR);
        }

        if (! flag)
        {
                command("say 不是説了待到你融會貫通再來向我討教嗎？");
                return 1;
        }

        me->set("can_learn/hong/sub-xianglong-zhang",1);
        command("say 你先將這十八路掌法融會貫通，合而為一再説吧。");
        notify_fail("你自己下去好好練習吧。\n");
        return 1;
}