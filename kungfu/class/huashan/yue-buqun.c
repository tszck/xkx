// yue-buqun.c lasted updated by cocacola on 2.19 for adding chushi
// 嶽不羣
inherit NPC;
inherit F_MASTER;
inherit F_MANAGER;
#include <ansi.h>
int do_xunshan();
/*
mixed out_master(mixed arg);
mixed out_master(mixed arg)
{
	object me;
	me = this_player();
	if( (string)me->query("family/family_name")!="華山派")
	{
		tell_object(me,"嶽不羣疑惑地對你說:哇拷!有沒有搞錯啊!\n");
		return 1;
	}
	if(me->query("gender")=="女性"){
		tell_object(me,"這位小姑娘,你是我內人的徒弟,你該出找她出師纔是!\n");
		return 1;
	}
	if(me->query("combat_exp") <= 100000) {
		tell_object(me,"嶽不羣對"+me->query("name")+
		"怒道:功夫還沒學到家就想出去丟臉.\n");
		return 1;
	}

	tell_object(me,"嶽不羣沉吟了一會,對"+me->query("name")+"說道:要想出師,
		你必須接我三招不死(accept test).\n");
	add_action("do_accept","accept");
	return 1;
}
int do_accept(string arg)
{
        mapping guild;

        if( arg== "test" ) {

		say("\n嶽不羣點了點頭，說道：很好，小心了　，這是第一招....\n\n");
		COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon"));
		if( (int)this_player()->query("kee") < 0
			|| !present(this_player(), environment()))
		{
		say("嶽不羣嘆了口氣，說道：嘻嘻，連第一招都撐不過，真是自不量力....\n");
                       return 1;
                }
                say("\n嶽不羣喝道：第二招....\n\n");
                COMBAT_D->do_attack(this_object(), this_player(),query_temp("weapon"));
                if( (int)this_player()->query("kee") < 0
                || !present(this_player(), environment())) {
			say("嶽不羣嘆道：這樣子還想出師,唉.....\n");
			return 1;
                }
                say("\n嶽不羣怒道：第三招，你去死吧!....\n\n");
                COMBAT_D->do_attack(this_object(), this_player(),query_temp("weapon"));
                if( (int)this_player()->query("kee") < 0
                || !present(this_player(), environment())) {
			say("嶽不羣笑道：嘿嘿，看樣子薑還是老的辣,哼.....\n");
                        return 1;
	}
	say("\n嶽不羣冷笑道：恭喜,你出師了.你我師徒一場，師傅沒什麼好送的 .
	\n爲師送你八字真言:天外有天,人外有人!徒兒,喔,不...大俠你好自爲知.\n\n");
	this_player()->set("betrayer",this_player()->query("betrayer")-1);
	this_player()->set("title","隱士");
	this_player()->set("family/family_name","華山派");
	this_player()->set("family/generation",13);
	this_player()->set("family/master_name",0);
	command("chat " + this_player()->query("name")+"已脫離華山，日後一切江湖恩怨均與本派無關。\n");
                return 1;
        }
        return 0;
}
*/
void create()
{
        set_name("嶽不羣", ({ "yue buqun", "yue" }) );
        set("title", "華山派掌門");
        set("nickname", "君子劍");
        set("gender", "男性");
        set("class", "swordsman");
        set("age", 55);
        set("long", "嶽不羣自幼執掌華山派，乃當今武林中一等一的高手。\n");
        set("attitude", "peaceful");
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 28);

        set("neili", 2400);
        set("max_neili", 2400);
        set("jiali", 30);
        set("max_qi",2000);
        set("max_jing",1200);

        set("combat_exp", 3000000);
        set("shen", -200000);
        set("xunshan", 3);
        set("apprentice_available", 3);
        set("no_get",1);

        
        
        set("inquiry", ([
//		"出師": (: out_master :),
		"巡山": (: do_xunshan :),
        ]) );

        set_skill("unarmed", 200);
        set_skill("sword", 200);
        set_skill("force", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("literate", 100);
        set_skill("huashan-sword", 300);
        set_skill("zixia-shengong", 200);
        set_skill("huashan-ken", 300);
        set_skill("feiyan-huixiang", 300);
        set_skill("bixie-sword",300);
        set_skill("zhengqijue",100);
        set_skill("ziyunyin",100);

        map_skill("sword", "huashan-sword");
        map_skill("parry", "huashan-sword");
        map_skill("force", "zixia-shengong");
        map_skill("unarmed", "huashan-ken");
        map_skill("dodge", "feiyan-huixiang");       
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "sword.jianzhang" :),
		(: perform_action, "sword.feilong" :),		
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );

        create_family("華山派", 13, "掌門");
        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
        carry_object("/clone/book/zixia_book");
}
void init()
{
    	object ob;
	mapping myfam;

	::init();
    	
    	if (interactive(ob=this_player()) && ob->query("family"))
	{ 
		myfam = (mapping)ob->query("family");
		if((myfam["family_name"] == "華山派")
		  &&(!ob->query_skill("zixia-shengong",1))
		    &&(ob->query("combat_exp")>500000))
       		{
                command("say 你竟敢放棄本門心法！從我這裏滾出去吧！");
                command("expell " + ob->query("id"));
        	}
	    add_action("do_qiecuo","qiecuo");
	}
}

void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) {
                if( find_call_out("do_recruit") != -1 )
                        command("say 慢著，一個一個來。");
                else
                        call_out("do_recruit", 2, ob);
        } else {
                command("say 老夫今天已經收了三個弟子，不想再收徒了。");
        }
}

void do_recruit(object ob)
{
        if( (int)ob->query("int") < 20 )
                command("say 我華山派以劍法爲主，依我看"+RANK_D->query_respect(ob)+"不適合於學劍法。");
        else {
                command("say 好，好，好，很好。");
                command("recruit " + ob->query("id") );
        }
}
/*
void die()
{
message("channel:rumor", MAG"【謠言】某人："+this_player()->query("name")+"搶了紫霞祕芨啦。\n"NOR, users());
	::die();
}
*/
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
        add("apprentice_availavble", -1);
}
void reset()
{
//        delete_temp("learned");
        set("apprentice_available", 3);
}
int do_xunshan()
{       
        int exp, pot, score, num, times;

        object me = this_player();       	        
        if ( me->query_temp("xunshan"))
        {
               if (!me->query_temp("xunshan/chaoyang"))
               {
                      message_vision("$N對着$n說：你朝陽峯沒去看看？這算巡的什麼山？\n", this_object(), me);
                      return 1;
               }
               if (!me->query_temp("xunshan/lianhua"))
               {
                      message_vision("$N對着$n說：你蓮花峯沒去看看？這算巡的什麼山？\n", this_object(), me);
                      return 1;
               }
               if (!me->query_temp("xunshan/yuntai"))
               {
                      message_vision("$N對着$n說：你雲臺峯沒去看看？這算巡的什麼山？\n", this_object(), me);
                      return 1;
               }
               if (!me->query_temp("xunshan/sheshen"))
               {
                      message_vision("$N對着$n說：你怎麼沒去捨身崖？這算巡的什麼山？\n", this_object(), me);
                      return 1;
               }
               if (!me->query_temp("xunshan/siguo"))
               {
                      message_vision("$N對着$n說：你到了思過崖去了？這算巡的什麼山？\n", this_object(), me);
                      return 1;
               }
               if (!me->query_temp("xunshan/yunu"))
               {
                      message_vision("$N對着$n說：你到玉女峯後面華山小築去看過了？這算巡的什麼山？\n", this_object(), me);
                      return 1;
               }              
               message_vision("$N對着$n說：不錯，辛苦了。你這就去休息去吧。\n", this_object(), me);
               me->delete_temp("xunshan");                      
               
               num=(int)me->query("perform/number")+1;
	       if (num<4) times=num;
	        else times=4;
               
               exp=random(100);
               pot=random(30);
               score=random(10)+ 10 * times;

               me->add("combat_exp",exp );
               me->add("potential",pot);
               me->add("family/fealty",score);
               tell_object(me,HIW"好！任務完成,你被獎勵了：\n" + 
	       chinese_number(exp) + "點實戰經驗\n" +
	       chinese_number(pot) + "點潛能\n"+
	       chinese_number(score) + "點忠誠度\n");


               
               return 1;
        }
        else
        {
               if ( query("xunshan") < 1)
               {
                      message_vision("$N對着$n說：今天已經有人巡山去了。你明天再來吧。\n", this_object(), me);
                      return 1;
               }
               if( me->query("family/family_name") != "華山派")
               {
                      message_vision("$N對着$n大喝一聲：本派弟子才能巡山。你是哪來的奸細？休怪我劍下不留情！\n", this_object(), me);
                     // this_object()->kill_ob(me);
                      return 1;
               }
               else
               {
                      add("xunshan", -1);
                      message_vision("$N對着$n說：本派弟子例當巡山。你，很好，很好！這就去吧。\n", this_object(), me);
                      me->set_temp("xunshan/start", 1);
                      me->set_temp("xunshan/time", time());
                      return 1;
               }
        }
}
