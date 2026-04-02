//NPC /d/baituo/npc/ouyangke.c
#include <ansi.h>
inherit F_MASTER;
inherit F_UNIQUE;
inherit NPC;
void greeting(object ob);
int do_give(string arg);
void do_back();
void create()
{
	seteuid(getuid());
	set_name("歐陽克", ({ "ouyang ke", "ouyang", "ke" }));
	set("long", "他一身飄逸的白色長衫，手搖摺扇，風流儒雅。\n");
	set("title", "白駝山少莊主");
	set("nickname", HIM "玉面蛇心" NOR);
	set("gender", "男性");
	set("age", 27);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("env/wimpy", 60);
	set("no_get",1);

	set("str", 25);
	set("int", 24);
	set("con", 25);
	set("dex", 26);

	set("qi", 1000);
	set("max_qi", 1000);
	set("jing", 800);
	set("max_jing", 800);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 10);

	set("combat_exp", 200000);
	set("score", 40000);

	set_skill("hand", 80);
	set_skill("dodge", 120);
	set_skill("parry", 90);
	set_skill("force", 90);
	set_skill("staff", 80);
	set_skill("training", 50);
	set_skill("cuff", 100);
	set_skill("hand",80);
	set_skill("strike",80);
	set_skill("literate", 100);
	set_skill("xidu-poison", 100);

	set_skill("hamagong",90);
	set_skill("chanchu-bufa", 180);
	set_skill("shexing-diaoshou", 120);
	set_skill("lingshe-zhangfa", 120);
	set_skill("hamaquan", 150);
	map_skill("force", "hamagong");
	map_skill("dodge", "chanchu-bufa");
	map_skill("cuff", "hamaquan");
	map_skill("strike", "hamagong");
	map_skill("hand", "shexing-diaoshou");
	map_skill("parry", "lingshe-zhangfa");
	map_skill("staff", "lingshe-zhangfa");
	prepare_skill("strike", "hamagong");
	prepare_skill("hand", "shexing-diaoshou");

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "staff.shoot" :),
		(: perform_action, "staff.saoye" :),
		(: perform_action, "strike.hama" :),
		(: exert_function, "powerup" :),
		(: exert_function, "reserve" :),
		(: exert_function, "recover" :),
	}) );
	create_family("白駝山派",2,"弟子");
	set("chat_chance", 10);
	set("chat_msg", ({
		"歐陽克唱道: 漂亮姑娘你請留步￣￣讓我多看你一眼￣￣\n",
		"歐陽克色迷迷地看着街邊的小姑娘。\n",
		"歐陽克把紙扇一展，轉過身去，深情地吟道：紅顏知己最難得￣\n",
		(: random_move :)
	}) );

	setup();
	carry_object(__DIR__"obj/baipao")->wear();
	carry_object(__DIR__"obj/shexing")->wield();
	add_money("silver",10);
}

void init()
{
	object ob;

	::init();

	if( interactive(ob = this_player()) && !is_fighting() ) 
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
  add_action("do_give","give");
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
   if (ob->query("family/family_name")=="白駝山派")
     {
                command("nod " + ob->query("id"));
                return;
      }
	if ((string)ob->query("gender")=="女性")
	{ 
		if (ob->query("per") < 20)
                        return;

    if (ob->query("sex/歐陽克"))
        {
           command("kiss " + ob->query("id"));
           command("say 怎麼樣，要不要再來幾次？");
        } else
		switch(random(3))
		{
			case 0:command("rose "+(string)ob->query("id"));break;
			case 1:command("kiss "+(string)ob->query("id"));break;
			case 2:command("love "+(string)ob->query("id"));break;
		}
	}
	else say("歐陽克嘆了一口氣説：這位"+RANK_D->query_respect(ob)+",你要是能給我弄一個女人來就好了。\n");
	return;
}

void attempt_apprentice(object ob)
{
	if ((string)ob->query("family/family_name") == "白駝山派")
	{
		if((int)ob->query("combat_exp")<10000)
			command("say 你的經驗太低，我還不能收你。繼續努力吧。\n");
		else
		{
			command("say 你跟着我要好好學。\n");		
			command("recruit "+ob->query("id"));
		}
		return;
	}
	if ((string)ob->query("gender") == "女性")
		message_vision("歐陽克動情地説道：這位" + RANK_D->query_respect(ob) + "真乃我的紅顏知己，\n我現在還不能收你，只能送你上白駝山。\n",ob);
	else
		message_vision("歐陽克笑笑説：這位"+RANK_D->query_respect(ob) + "，我現在還不能收你，只能送你上白駝山。\n",ob);
	write(HIY "只見歐陽克把紙扇往你眼前一晃，\n
	你覺得眼前一閃，身體輕飄飄地飛了出去￣￣\n" NOR);
	ob->move("/d/baituo/liangong");
}

int accept_fight(object ob)
{
	if ((string)ob->query("gender") == "女性")
	{
		message_vision("歐陽克擺擺手説道：這位"+RANK_D->query_respect(ob)+ "，我怎能欺負女孩子呢！\n", ob);
		return 0;
	}
	if ((string)ob->query("family/family_name") == "白駝山派")
	{
		if((int)ob->query("combat_exp")<100000)
			return notify_fail("歐陽克笑道：你的經驗太低了，再練幾年吧。！\n");
	}
	message_vision("歐陽克一拱手説道：這位"+RANK_D->query_respect(ob)+ "，在下領教了。\n", ob);
	return 1;
}
 
//int accept_object(object who, object ob)
int do_give(string arg)
{
	object who=this_player();
	object obn;
	object ob;
	string item,target;
	int amount;
	if (!arg) return 0;
	if( sscanf(arg, "%s to %s", item, target)!=2 &&
		sscanf(arg, "%s %s", target, item)!=2 )
	return 0;
  if (!id(target)) return 0;
	ob=present(item,this_player());
	if ( !ob || !objectp(ob) || !ob->is_character()) return 0;
	if ( query_ip_name(this_player()) == query_ip_name(ob) )
	  return notify_fail("賣自己？真是生財有道了。\n");
	if (  (string)ob->query("gender") != "女性")
	{
		say("歐陽克不需要這件東西。\n");
		return 1;
	}
	if (ob->is_corpse())
	{
		command("slap " + who->query("id"));
		command("say 好嘛你，居然拿具屍體來糊弄我，找晦氣啊？");
		return 1;
	}
	 if ((string)ob->query("family/family_name") == "白駝山派")
   {
     command("kick " + who->query("id"));
     command("slap " + who->query("id"));
     command("say 我靠！你膽子可真不小，連我的胞妹你也敢欺負？");
                return 1;
    }

	if( environment(this_object())->query("short") == "麗春院" )
	{
		say("歐陽克笑道：本大爺剛快活完，這種爛貨你自己留着吧。\n");
		return 1;
	}
	if ( (int)ob->query("age") <18 )
	{
		say("歐陽克大驚失色道：未成年少女我怎敢要！\n");
		return 1;
	}
	if ( (int)ob->query("age") >40 )
	{
		say("歐陽克輕蔑地一笑道：這種老古董還是留給你自己吧！\n");
		return 1;
	}
	if (ob->query("sex/歐陽克") >= 3)
    {
                command("shake");
                command("say 這婆娘我已經玩膩了，你自個留着吧。");
                return 1;
    }       
  amount=0;
  if (userp(ob))
    {
      if (sizeof(ob->query("sex")) > 2 + 2 ) 
        {
           command("say 靠！這種女人人盡可夫，我歐陽克可不想要。");
           return 1;
        }

        if (ob->query("per") < 25)
        {
           command("shrug");
           command("say 這……這種貨色也未免差了點，你"
				"也找個漂亮些的啊。");
                        return 1;
         }
         amount += ob->query("per");
          if (!ob->query("sex"))
                {
                        command("say 哇，這還是個處女，怎麼也得多給"
			        "你點辛苦費！");
                        amount += 30;
                }
        command("rumor "+ob->query("name")+"被人送給歐陽克了，足足賺了"+chinese_number(amount+30)+"兩白花花的銀子。");
     }
     else
     {
        ob->set("chat_chance", 15);
        ob->set("chat_msg", ({CYN + ob->name() + CYN "不住的抽泣。\n" NOR,
                   CYN + ob->name() + CYN "嗚咽道：" + this_object()->name() +
                   CYN "，他…他…他這個壞東西。\n" NOR,
                   CYN + ob->name() + CYN "哭了起來：我不想活了！\n" NOR,
                }) );

     	}
  obn=new("/clone/money/silver");
	obn->set_amount(30+amount);
	obn->move(who);
	message_vision("歐陽克一把把"+ob->query("name")+ "攬在懷裏，對$N説這點銀子是你的辛苦費，咱回頭見。\n説完，就攜着"+ob->query("name")+"往麗春院奔去...\n",who);
	move("/d/city/lichunyuan",1);
  ob->move("/d/city/lichunyuan",1);
  message_vision("$N抱着昏迷不醒的$n走了進來。\n", this_object(), ob);

  ob->add("sex/歐陽克", 1);
  ob->add("sex/times",  1);
  if (ob->query("sex/times") == 1)
        ob->set("sex/first", "歐陽克");
  ob->remove_call_out("revive");
  ob->revive();
  tell_object(ob, HIY "你剛剛掙開眼睛，卻發現一個人"
		        "正抱着你，你大叫一聲，幾乎暈了過去。\n\n" NOR);
        command("kiss " + ob->query("id"));
        command("say 嘻嘻，你慌什麼麼嘛，可是" + who->name() + "把你送過來的啊。");
        remove_call_out("do_back");
        call_out("do_back", 30 + random(10));

	return 1;
}
void do_back()
{
        remove_call_out("do_back");
        if (base_name(environment()) == query("startroom"))
                return;

        if (! living(this_object()) ||
            is_busy() || is_fighting())
        {
                call_out("do_back", 10 + random(10));
                return;
        }

        message_vision(HIW "$N" HIW "輕搖羽扇，飄然而去。\n" NOR, this_object());
        move(query("startroom"));
        message_vision(HIW "$N" HIW "輕搖羽扇，施施然的走了過來。\n" NOR, this_object());
}