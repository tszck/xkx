// ping.c 平一指

#include <ansi.h>
inherit NPC;
inherit F_SAVE;

#define MAX_EXP 100000
#define MIN_EXP 60000
#define PING_FILE "/log/ping"
int ask_wu();
int ask_me();
int ask_heal();
int ask_poison();
int ask_over();
int ask_working();
string ask_work();
string ask_me1();
int add_member(string arg);
int is_member(string arg);
void create()
{
	set_name("平一指", ({ "ping yizhi", "ping", "yizhi" }));
	set("title", "藥鋪老闆");
	set("gender", "男性");
	set("long", "他就是醫術高超的「殺人神醫」平一指。可是他性格古怪，不是什麼人都醫的。聽說江湖中人有想向他學些濟世之術的，也不知他肯不肯傳授。\n");
	set("age", 65);

	set("int", 30);
	set("qi", 1000);
	set("max_qi", 1000);
	set("jing", 1000);
	set("max_jing", 1000);
	set("shen_type", -1);
	set("combat_exp", 500000);
	set("attitude", "heroism");

	set_skill("unarmed", 100);
	set_skill("medicine", 200);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_temp("apply/attack", 120);
	set_temp("apply/defense", 120);
	set_temp("apply/damage", 50);
	set("zhen_count", 1);
	set("shouwu_count", 2);
	set("count", 30);
	set("inquiry", ([
		"何首烏" : (: ask_wu :),
		"療傷"   : (: ask_me :),
		"神藥"   : (: ask_me1 :),
		"大力丸" : (: ask_me1 :),
		"潛能丹" : (: ask_me1 :),
		"治病"   : (: ask_heal :),
		"解毒"   : (: ask_poison :),
		"work"   : (: ask_working :),
		"工作"   : (: ask_working :),
		"分藥"   : (: ask_working :),
		"報酬"   : (: ask_over :),
		"工資"   : (: ask_over :),
		"over"   : (: ask_over :),
		"鍼灸"   : (: ask_work :),
		"銀針"   : (: ask_work :),
		"行醫"   : (: ask_work :),
	]));
	set("party/party_name", HIB"日月神教"NOR);
	set("party/rank", HIW"第八代弟子"NOR);
	create_family("黑木崖", 8, "弟子");

	setup();
	add_money("gold", 1);
	set("no_get",1);
	carry_object("/clone/misc/cloth")->wear();
	carry_object(BOOK_DIR+"medicine1");
	carry_object(BOOK_DIR+"medicine5");
}
void init()
{
	object ob = this_player();
	::init();
	if( interactive(ob) && !is_fighting()&&!ob->query_temp("fengyaoover") )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
 int eff_qi, max_qi, hurt;

	if (!ob || environment(ob)!=environment(this_object()))
		return ;
	tell_object(ob, "\n平一指抬頭看了你幾眼。\n");
	if (ob->query_condition("drunk"))
	{
		message_vision("平一指對$N說道：這位"+RANK_D->query_respect(ob)+"，看你臉紅紅的，一定是喝醉了！\n",ob);
	}
	if (ob->query_condition("killer"))
	{
		message_vision("平一指對$N說道：這位"+RANK_D->query_respect(ob)+"，官府正通緝你呢，你還是快走吧！！\n",ob);
		return;
	}

	eff_qi = ob->query("eff_qi");
	max_qi = ob->query("max_qi");
	if(100*eff_qi/max_qi<=50) hurt = 3;
	else if(100*eff_qi/max_qi<=70) hurt = 2;
	else if(100*eff_qi/max_qi<=95) hurt = 1;
	else hurt = 0;
	switch(hurt)
	{
		case 1 : message_vision("平一指滿臉關切地對$N說道：這位"+RANK_D->query_respect(ob)+"看來受了點輕傷，我這兒有上好的丹藥，不知是否要買些？\n",ob);
			break;
		case 2 : message_vision("平一指對$N說道：這位"+RANK_D->query_respect(ob)+"看來受傷不輕，買些丹藥回去吧！\n",ob);
			break;
		case 3 : message_vision("平一指冷冷地對$N說道：這位"+RANK_D->query_respect(ob)+"傷重垂危，命不久矣，嘿嘿！\n",ob);
			break;
		default: command("look "+ob->query("id"));
			break;
	}
	if(!ob->query_temp("fengyaobegin") &&
		ob->query("combat_exp")>MIN_EXP &&
		ob->query("combat_exp")<MAX_EXP)
		say( "平一指又抬了抬眼皮，說道：小店正缺人手，這位" + RANK_D->query_respect(ob) + "有意的話，可以"CYN" 〖"HIR"ask ping about work"NOR CYN"〗\n"NOR);
}

string value_string(int value)
{
	if( value < 1 ) value = 1;
	else if( value < 100 ) return chinese_number(value) + "文錢";
	else if( value < 10000 ) return chinese_number(value/100) + "兩白銀" + (value%100? "又" + chinese_number(value%100) + "文錢": "");
	else return chinese_number(value/10000) + "兩黃金" +( (value%10000)/100 ? chinese_number((value%10000)/100) + "兩白銀" : "") +( (value%10000)%100 ? "又" + chinese_number((value%10000)%100) + "文錢": "");
}

int ask_wu()
{
	object ob = this_player ( ) ;

message_vision("平一指上上下下打量了$N一下：什麼！何首烏？拿十兩黃金來！\n",ob);
	ob->set_temp ("何首烏" , 1 );
	return 1;
}

int accept_object(object who, object ob)
{
	object obj ;
	if (!(int)who->query_temp("何首烏"))
	{
		if (!(int)who->query_temp("mark/平"))
			who->set_temp("mark/平", 0);
		if (ob->query("money_id") && ob->value() >= 1000)
		{
			message_vision("平一指看來有點想指點$N一些關於濟世之術的問題的意思。\n", who);
			who->add_temp("mark/平", ob->value() / 500);
		}
		else
			message_vision("平一指對$N說：醫一人，殺一人，老夫就不收錢！\n", who);
		return 1;
	}
	if (query("shouwu_count") < 1)
	{
		message_vision("平一指對$N道：你來晚了。本店缺貨！\n", who);
		return 0;
	}
	if (ob->query("money_id") && ob->value() >= 100000)
	{
		message_vision("平一指給了$N何首烏！\n" , who);
		add("shouwu_count", -1);
		this_player()->delete_temp("何首烏" );
		obj=new("/clone/medicine/vegetable/heshouwu");
		obj->move(this_player());
	}
	return 1;
}

int recognize_apprentice(object ob)
{
	if (!(int)ob->query_temp("mark/平")) return 0;
	ob->add_temp("mark/平", -1);
	return 1;
}

int ask_me()
{
	object ob = this_player();
	object me = this_object();
	object where;

	if(me->is_fighting() || me->query_temp("busy"))
	{
		command("say 我現在沒空！");
		return 1;
	}
	if(me->query("count") < 1)
	{
		command("say 傷藥都用完了，我還沒來得及配，你一會再來吧。");
		return 1;
	}
	if(ob->query("shen")>0)
	{
		command("say 你們這些正派中人，我可不敢高攀！");
		return 1;
	}
	if(ob->query("score")<300&&ob->query("combat_exp")>100500)
	{
		command("say 你這點江湖閱歷，也想讓我爲你療傷？");
		return 1;
	}

	if ((int)ob->query("eff_qi") == (int)ob->query("max_qi")
	  && (int)ob->query("eff_jing") == (int)ob->query("max_jing"))
	{
		command("? "+ob->query("id"));
		command("say 你沒有受任何傷啊？");
		return 1;
	}
	else
	{
		message_vision("平一指喂$N服下一顆藥丸，然後盤膝坐下，雙掌貼着$N的背心。\n", ob);
		if (ob->query("combat_exp")>100500)
		{
			if (ob->query("family/family_name") != "黑木崖")
				ob->add("score",-200);
		        else ob->add("score",-100);
		}
		me->add("count", -1);
		me->set_temp("busy",1);
		ob->start_busy(2);
		remove_call_out("recover");
		call_out("recover",2,ob);
		if (me->query("count")<1)
		{
			where = environment(me);
			where->add("no_fight", 1);
			remove_call_out("newyao");
			call_out("newyao",600,me);
		}
		return 1;
	}
}

int recover(object ob)
{
	this_object()->delete_temp("busy");
	ob->set("eff_qi", (int)ob->query("max_qi"));
	ob->set("eff_jing", (int)ob->query("max_jing"));
	message_vision("大約過了一盅茶的時分，平一指慢慢地站了起來。\n",ob);
	command("say 你的傷勢已經全好了,可以走啦。");
	return 1;
}
int newyao(object me)
{
	object where = environment(me);
	this_object()->delete_temp("busy");
	me->add("count",20);
	where->add("no_fight", -1);
	return 1;
}

int ask_heal()
{
	object ob = this_player();
	object me = this_object();
 

        if(me->is_fighting() || me->query_temp("busy"))
        {
		command("say 我現在沒空！");
		return 1;
	}

	if(ob->query("shen")>0)
	{
		command("say 你們這些正派中人，我可不敢高攀！");
		return 1;
	}
	if(ob->query("score")<300&&ob->query("combat_exp")>100000)
	{
		command("say 你這點江湖閱歷，也想讓我爲你治病？");
		return 1;
	}

	if( ob->query_condition("ill_kesou") ||
		ob->query_condition("ill_zhongshu") ||
		ob->query_condition("ill_shanghan") ||
		ob->query_condition("ill_dongshang") ||
		ob->query_condition("ill_fashao"))
	{
		message_vision("平一指輕釦$N脈門，略一思索，隨後轉身從藥簍裏取出幾味草藥，開始爲$N熬藥。\n", ob);
		if (ob->query("combat_exp")>100000)
		{
		if (ob->query("family/family_name") != "黑木崖")
	            ob->add("score",-200);
	        else ob->add("score",-100);
		}
		me->add("count", -1);
		me->set_temp("busy",1);
		ob->start_busy(5);
		remove_call_out("recover_II");
		call_out("recover_II",5,ob);
		return 1;
	}

	else
	{
		command("? "+ob->query("id"));
		command("say 看你的氣色，並沒有生病啊？");
		return 1;
	}

}
int recover_II(object ob)
{
	this_object()->delete_temp("busy");
	if (ob->query_condition("ill_kesou"))
		ob->clear_condition("ill_kesou",0);
	if (ob->query_condition("ill_zhongshu"))
		ob->clear_condition("ill_zhongshu",0);
	if (ob->query_condition("ill_shanghan"))
		ob->clear_condition("ill_shanghan",0);
	if (ob->query_condition("ill_dongshang"))
		ob->clear_condition("ill_dongshang",0);
	if (ob->query_condition("ill_fashao"))
		ob->clear_condition("ill_fashao",0);
	message_vision("大約一柱香過後，平一指讓你喝下一碗剛熬好的熱氣騰騰的中藥。\n",ob);
	command("say 你的身體已無大礙,可以走啦。");
	return 1;
}

int ask_poison()
{
	object ob = this_player();
	object me = this_object();
 

        if(me->is_fighting() || me->query_temp("busy"))
	{
		command("say 我現在沒空！");
		return 1;
	}

	if(ob->query("shen")>0)
	{
		command("say 你們這些正派中人，我可不敢高攀！");
		return 1;
	}
	if(ob->query("score")<500&&ob->query("combat_exp")>100000)
	{
		command("say 你這點江湖閱歷，也想讓我爲你解毒？");
		return 1;
	}

	if(ob->query_condition("chanchu_poison") ||
		ob->query_condition("drunk") ||
		ob->query_condition("flower_poison") ||
		ob->query_condition("ice_poison") ||
		ob->query_condition("iceshock") ||
		ob->query_condition("rose_poison") ||
		ob->query_condition("scorpion_poison") ||
		ob->query_condition("slumber_drug") ||
		ob->query_condition("snake_poison") ||
//		ob->query_condition("ss_poison") ||
		ob->query_condition("wugong_poison") ||
//		ob->query_condition("xx_poison") ||
		ob->query_condition("xiezi_poison") ||
		ob->query_condition("zhizhu_poison") ||
		ob->query_condition("zhua_poison") ||
		ob->query_condition("ice_sting"))
	{
		message_vision("平一指輕釦$N脈門，雙眉深鎖，隨後喂$N服下一顆藥丸，盤膝坐下，雙掌貼着$N的背心，開始爲$N解毒。\n", ob);
		if (ob->query("combat_exp")>100000)
		{
			if (ob->query("family/family_name") != "黑木崖")
				ob->add("score",-300);
			else ob->add("score",-200);
		}
		me->add("count", -1);
		me->set_temp("busy",1);
		ob->start_busy(5);
		remove_call_out("recover_III");
		call_out("recover_III",5,ob);
		return 1;
	}
	else
	{
		command("? "+ob->query("id"));
		command("say 看來我幫不了你什麼忙了！");
		return 1;
	}
}
int recover_III(object ob)
{
	this_object()->delete_temp("busy");
	if (ob->query_condition("chanchu_poison"))
		ob->clear_condition("chanchu_poison",0);
	if (ob->query_condition("drunk"))
		ob->clear_condition("drunk",0);
	if (ob->query_condition("flower_poison"))
		ob->clear_condition("flower_poison",0);
	if (ob->query_condition("ice_poison"))
		ob->clear_condition("ice_poison",0);
	if (ob->query_condition("iceshock"))
		ob->clear_condition("iceshock",0);
	if (ob->query_condition("rose_poison"))
		ob->clear_condition("rose_poison",0);
	if (ob->query_condition("scorpion_poison"))
		ob->clear_condition("scorpion_poison",0);
	if (ob->query_condition("slumber_drug"))
		ob->clear_condition("slumber_drug",0);
	if (ob->query_condition("snake_poison"))
		ob->clear_condition("snake_poison",0);
//	if (ob->query_condition("ss_poison"))
//		ob->clear_condition("ss_poison",0);
	if (ob->query_condition("wugong_poison"))
		ob->clear_condition("wugong_poison",0);
//	if (ob->query_condition("xx_poison"))
//		ob->clear_condition("xx_poison",0);
	if (ob->query_condition("xiezi_poison"))
		ob->clear_condition("xiezi_poison",0);
	if (ob->query_condition("zhizhu_poison"))
		ob->clear_condition("zhizhu_poison",0);
	if (ob->query_condition("zhua_poison"))
		ob->clear_condition("zhua_poison",0);
	if (ob->query_condition("ice_sting"))
		ob->clear_condition("ice_sting", 0);
	message_vision("大約一柱香過後，$N吐出一口紫血，平一指慢慢地站了起來。\n",ob);
	command("say 你體內毒素已清，可以走啦。");
	return 1;
}

int ask_over()
{
	object mon, me = this_player();
	int bonus,exp,pot,tempp,kar;

	kar = me->query("kar");
	if (!me->query_temp("fengyaoover"))
	{
		message_vision("平一指驚訝的對$N說道：“哦！你在開什麼玩笑，我這可不是養老院啊！”\n",me);
		return 1;
	}
	me->delete_temp("fengyaoover");
	if (me->query_temp("fengyaow"))
	{
		if(random(kar)>=11)
		{
			message_vision("平一指哼了一聲，對$N說：“你是怎麼搞的，亂分藥，是想砸我的招牌嗎？\n看在你還努力的份上還是賞你點錢吧。”\n",me);
			exp = 10 + random(10);
			mon = new("/clone/money/silver");
			mon->set_amount(exp/10);
			tell_object(me,HIW"平一指給了你" + chinese_number(exp) + "兩白銀。 \n"NOR);
			mon->move(me);
			me->delete_temp("fengyaow");
			return 1;
		}
		message_vision("平一指哼了一聲，對$N說：你是怎麼搞的，亂分藥，是想砸我的招牌嗎？\n",me);
		return 1;
	}
	message_vision("平一指笑着對$N說：“你還不錯嘛，可以可以，這是你應該得的。”\n",me);
	exp = 10 + random(80);
	pot = 10 + random(40);
	bonus = (int) me->query("combat_exp");
	tempp = bonus;
	bonus += exp;
	me->set("combat_exp", bonus);
	bonus = (int) me->query("potential");
	bonus += pot;
	me->set("potential", bonus);
	mon = new("/clone/money/silver");
	mon->set_amount(exp/10);
	mon->move(me);
	me->start_busy(3);
	tell_object(me,"你被獎勵了："HIR+chinese_number(exp)+NOR"點經驗，"HIR+chinese_number(pot)+NOR"點潛能和"HIW+chinese_number(exp)+NOR"兩白銀。\n");
	bonus=(int) me->query("potential");
	if (me->query("combat_exp")>=MAX_EXP)
	{
		me->set("fenyao_over",1);
	}
	return 1;
}
int ask_working()
{
	object me = this_player();
	object *obs;
	object room2;
	if((int)(me->query("combat_exp")) > MAX_EXP ||
		(int)(me->query("combat_exp")) < MIN_EXP)
	{
		message_vision("平一指對$N說道：“閣下如此身手，小店勞煩不起。呵。。。呵。。。”\n",me);
		return 1;
	}
	if ( me->query("fenyao_over") || is_member(me->query("id") ))
	{
		message_vision("平一指對$N說道：“我記得以前你在這裏打過工，怎麼又來了！”\n",me);
		return 1;
	}
	if (me->query_temp("fengyaobegin"))
	{
		message_vision("平一指對$N說道：“你不是已經要了工作了，還不去幹！”\n",me);
		return 1;
	}
	if ((int)(me->query("qi")) < random(30))
	{
		message_vision("平一指對$N說道：“算了吧你，都這樣了還想工作，把藥分錯了會出人命的。”\n",me);
		return 1;
	}
	//add from here//
	 if (objectp(room2=find_object("d/city/yaopu2")))
   {
   		obs = filter_array(all_inventory(room2),
                           (: interactive($1) &&
                              $1 != $(me) &&
                              ($1->query_temp("fengyao") || $1->query_temp("fengyaobegin")|| $1->query_temp("fengyaoover"))&&
                              query_ip_number($1) == query_ip_number($(me)) :));
   		if (sizeof(obs) > 0)
        {
        	message_vision("平一指對$N說道：“現在已經有" + obs[0]->name() + "幹活呢，你歇着吧。”\n",me);
					return 1;
				}
		}
		else
		{
			message_vision("平一指對$N說道：“你先去藥室看一下藥品全了沒，然後再過來問我。”\n",me);
			return 1;
			}
	//add end//
	if (me->query_temp("fengyaoover"))
	{
		message_vision("平一指對$N說道：“哦？ 你連自己的工資也不要。”\n",me);
		message_vision("平一指對$N說道：“好吧，既然這樣我也就不勉強你了。”\n",me);
		message_vision("平一指對$N說道：“那你就到內室去幫我再分次藥吧。”\n",me);
		me->delete_temp("fengyaow");
		me->delete_temp("fengyaoover");
		me->set_temp("fengyaobegin",1);
		return 1;
	}
	message_vision("平一指對$N說道：“好吧，那你就到內室去幫我分分藥吧。”\n",me);
	me->set_temp("fengyaobegin",1);
	return 1;
}

string ask_me1()
{
	return "我...我不知道！";
}

string ask_work()
{
	object ob, me = this_player();

	if (present("yin zhen", me))
		return "你不是有銀針了麼？還來找我幹嘛？";
	if (query("zhen_count") < 1)
		return "你來晚了，我的銀針已經送人了。";
	if (me->query_skill("medicine", 1) < 50)
		return "你也想行醫？那也得看是不是那塊料啊。";
	if (me->query("medicine_count") < 50)
		return "你想行醫，先得把藥熬好，熟能生巧，磨刀不誤砍柴功，這個道理你也知道，別貪多勿得的。";
	ob = new("/clone/misc/yinzhen");
	ob->move(me);
	add("zhen_count", -1);
	if (me->query_skill("acupuncture",1) > 0)
	{
		return "想行醫？這針你先拿去用吧。可別辱沒了我“醫一人殺一人”的名頭。";
	}
	else
	{
		me->set_skill("acupuncture", 1);
		return "初次行醫吧？我來教你點鍼灸術吧。這樣你就可以帶針上路了。";
	}
}
int add_member(string arg)
{
	return write_file(PING_FILE,arg+"\n");
}
int is_member(string arg)
{
	string file;
	string *recs;
	if (!file=read_file(PING_FILE))
	{
		// tell_object(find_player("qingyun"),"讀取失敗。\n");
		return 0;
	}
	recs=explode(file,"\n");
	if ( member_array(arg,recs)!=-1 ) return 1;
	return 0;
}