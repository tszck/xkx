// moda.c 衡山派掌門 莫大
// Last Modified by ahda on Sep.1 2001
inherit NPC;
inherit F_MASTER;
inherit F_MANAGER;
#define ZHENYUE "/clone/weapon/treasure/zhenyue"
mixed ask_jian();
#include <ansi.h>
void create()
{
	object ob;
	set_name("莫大", ({ "mo da", "mo" }) );
	set("nickname", "瀟湘夜雨");
	set("gender", "男性");
	set("class", "swordsman");
	set("age", 55);
	set("attitude", "peaceful");
	set("per", 22);
	set("str", 26);
	set("con", 30);
	set("dex", 30);
	set("int", 28);

	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 60);
	set("max_qi",2500);
	set("max_jing",1800);
	set("combat_exp", 3000000);
	set("shen_type", 1);

	set_skill("hand", 200);
	set_skill("unarmed",200);
	set_skill("sword", 200);
	set_skill("force", 200);
	set_skill("parry", 200);
	set_skill("dodge", 200);
	set_skill("strike", 200);
	set_skill("hengshan-sword", 300);
	set_skill("huiyan-xinfa",200);
	set_skill("luoyan-hand",300);
	set_skill("biluo-zhang",300);
	set_skill("qiuyan-nanhui",300);
	set_skill("literate",180);
	set_skill("luteplaying",180);

	map_skill("sword", "hengshan-sword");
	map_skill("parry", "hengshan-sword");
	map_skill("dodge", "qiuyan-nanhui");
	map_skill("force", "huiyan-xinfa");
	map_skill("hand", "luoyan-hand");
	map_skill("strike", "biluo-zhang");
	prepare_skill("hand", "luoyan-hand");
	prepare_skill("strike", "biluo-zhang");
  set("inquiry", ([
			"鎮嶽尚方" : (: ask_jian :),
			"寶劍" : (: ask_jian :),
			"祝融劍法" : "本門劍法之一的祝融劍法，自師尊華山一役後便失傳了。",
			]));	 
	set("env/wimpy", 60);
	set("chat_chance_combat", 70);
	set("chat_msg_combat", ({
		(: command("haha") :),
		(: perform_action, "sword.luoyan" :),
		(: perform_action, "sword.luoyan" :),
		(: perform_action, "sword.yunwu" :),
		(: perform_action, "hand.jinghan" :),
		(: perform_action, "strike.huan" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
	}) );
	create_family("衡山派", 13, "掌門");
	setup();
	set("count",1);
  if (clonep())
  {
     	ob=new(ZHENYUE);
     	if ( ob-> violate_unique())
     	{
     		destruct(ob);
     		ob=new(__DIR__"obj/qinjian");
    		}
     ob->move(this_object());
     ob->wield();
  }

//  carry_object(__DIR__"obj/qinjian")->wield();
	carry_object("/clone/cloth/cloth")->wear();
}

void init()
{
    add_action("do_qiecuo","qiecuo");
}

void attempt_apprentice(object ob)
{
	if((int)ob->query("int")<20)
	{
		command("say 你的悟性太低了，不適合學習我的功夫。");
		return;
	}
	if((int)ob->query_skill("literate",1) < 150)
	{
		command("say 你的讀書寫字太低了，還是先多加修習吧。");
		return;
	}
/*
	if((int)ob->query("kar")<25)
	{
		command("say 你與衡山絕學無緣，請回吧。");
		return;
	}
*/
	if ((int)ob->query_skill("huiyan-xinfa",1) < 180 ) 
	{
		command("say 你的本門內功心法火候不足,難以領略更高深的武功。");
		return;
	}
	if((string)ob->query("gender")=="無性")
	{
		command("say 你秉性陰陽不定，習我功夫恐將走火如魔。");
		return;
	}
	if((int)ob->query("shen") <= 50000)
	{
		command("say 你應當多作些行俠仗義的事，以修身心。");
		return;
	}

	command("say 入我門來，定須光大我衡山一派。");
	command("recruit " + ob->query("id"));
}

mixed ask_jian()
{
        object me;
        object ob;
        object owner;
        
        object temp;
        

        me = this_player();
        if (me->query("shen")<0)
        {
                if (me->query("family/family_name") == "衡山派")
                        message_vision(CYN "$N" CYN "大怒，對$n" CYN "道：“你身爲衡山弟子，"
                                       "反而誤入魔道，還不快快醒轉？”\n" NOR,
                                       this_object(), me);
                else
                        message_vision(CYN "$N" CYN "大怒，對$n" CYN "喝道：“好一個邪魔外"
                                       "道，居然敢窺我鎮嶽尚方？”\n" NOR,
                                       this_object(), me);
                return 1;
        }

        if (me->query("family/family_name") != "衡山派")
                return "鎮嶽尚方是我護身之寶，你打聽它幹什麼？";

        if (me->query("family/master_id") != query("id"))
                return "只有我的弟子才能用鎮嶽尚方，你還是請回吧。";

        if (me->query("shen") < 60000)
                return "你行俠仗義的事情做得不夠，我不能把鎮嶽尚方交給你。";
				if (present("zhenyue shangfang",me))
								return "鎮嶽尚方不是在你的手中麼，怎麼反而來找我呢？";

        ob=new(ZHENYUE);
        if ( temp=ob->violate_unique())
         {
         destruct(ob);
         ob=temp;
				 owner = environment(ob);
  			 if (owner == me)
	         	return "鎮嶽尚方不是在你的手中麼，怎麼反而來找我呢？";
        if ( owner->is_character() && owner!= this_object())
           {
                if (owner->query("family/family_name") == query("family/family_name"))
                        return "鎮嶽尚方現在在" + owner->query("name") +
                               "手中，你要想用就去找他吧。";
                else
                        return "本派至寶鎮嶽尚方現在落在" + owner->query("name") +
                               "手中，你快去殺了他把劍拿回來。";
        	 }
         }
        	
				ob->move(this_object());
        message_vision(CYN "$N" CYN "點點頭道：“好，你用這鎮嶽尚方要多作一些行"
		       "俠仗義的事情！”\n" NOR, this_object(), me);
        command("give zhenyue shangfang to " + me->query("id"));
        add("count",-1);
        return 1;
}
