// Last Modified by winder on Nov. 17 2000
// zhou.c 桃花島周伯通

#include <skill.h>
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

int ask_jieyi();
int ask_jiuyin();
int ask_hubo();
int do_draw(string arg);
int do_fangyuan();
int do_learn(string arg);
string ask_skill1();

void create()
{
	set_name("周伯通", ({ "zhou botong", "zhou", "botong" }) );
	set("nickname",	"老頑童");
	set("title", "全真派第一代弟子");
	set("long", 
		"他滿頭長髮，直垂至地，長眉長鬚，鼻子嘴巴都被遮掩住了。\n"
		"他鬚髮蒼然，並未全白，只是不知有多少年不剃，就如野人一般毛茸茸地甚是嚇人。\n"
		"他的舉止猶如孩童一樣。\n");
	set("gender", "男性" );
	set("age", 48);
	set("attitude", "peaceful");
	set("apprentice", 1);
	set("str",28);
	set("int",25);
	set("con",27);
	set("dex",29);
	set("max_qi", 4000);
	set("max_jing", 2500);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jiali", 100);
	set("combat_exp", 2200000);
	set("score", 500000);

	set_skill("hubo", 250);
	set_skill("force", 200);
	set_skill("xiantian-qigong", 200);
	set_skill("dodge", 200);
	set_skill("jinyan-gong", 190);
	set_skill("unarmed", 200);
	set_skill("kongming-quan", 200);
	set_skill("cuff", 200);
	set_skill("chunyang-quan", 200);
	set_skill("strike", 200);
	set_skill("haotian-zhang", 200);
	set_skill("parry", 200);
	set_skill("sword", 200);
	set_skill("quanzhen-jian", 200);
	set_skill("taoism", 50);
	set_skill("literate", 100);

	map_skill("force", "xiantian-qigong");
	map_skill("dodge", "jinyan-gong");
	map_skill("unarmed", "kongming-quan");
	map_skill("cuff", "chunyang-quan");
	map_skill("strike", "haotian-zhang");
	map_skill("sword", "quanzhen-jian");
	map_skill("parry", "quanzhen-jian");
	prepare_skill("cuff", "chunyang-quan");
	prepare_skill("strike", "haotian-zhang");

	set("rank_info/respect", "老頑童");
	set("shen_type", 1);
	create_family("全真教", 1, "弟子");
	set("class", "taoist");
	set("no_get",1);

	set("inquiry", ([
		"name"    : "叫我周伯通就好了。",
		"rumors"  : "我被那個臭東邪關在這裏十幾年，每天就是一個啞僕來送飯。",
		"東邪"    : "是黃藥師這個無恥的傢伙，騙了我的九....去看。",
		"黃藥師"  : "這個無恥的傢伙，騙了我的九....去看。",
		"中神通"  :"我的師兄是天下武功最高的，第一次華山論劍時公推為第一高手。",
		"王重陽"  :"我的師兄是天下武功最高的，第一次華山論劍時公推為第一高手。",
		"周伯通"  : "找我有什麼事嗎？",
		"瑛姑"    : "四張機，鴛鴦織就欲雙飛....",
		"劉瑛"    : "四張機，鴛鴦織就欲雙飛....",
		"段皇爺"  : "老頑童做事對不起他，沒臉再見他了。",
		"段智興"  : "老頑童做事對不起他，沒臉再見他了。",
		"南帝"    : "老頑童做事對不起他，沒臉再見他了。",
		"老頑童"  : "我就是啊，找我有什麼事嗎？",
		"空明拳"  : "空明拳共七十二路，口訣是：空朦洞松、風通容夢、衝窮中弄、童庸弓蟲。",
		"kongming-quan": "空明拳共七十二路，口訣是：空朦洞松、風通容夢、衝窮中弄、童庸弓蟲。",
		"黃蓉"    : "是幾個月前來陪我聊天的那個小姑娘嗎？",
		"郭靖"    : "那是我的結義兄弟，人雖然傻，心腸倒好。",
		"桃花島"  : "這裏就是桃花島。寒雨那個小壞蛋在這裏加了無數的ｑｕｅｓｔ，看你能不能找全了。",
		"方"      : "方要正方！",
		"fang"    : "方要正方！",
		"圓"      : "圓要渾圓！",
		"yuan"    : "圓要渾圓！",
                "九陰真經" : "「九陰真經」就在我牀上，你有本事殺了我或把我逼出山洞就可以取走！\n",
		"雙手互搏": (: ask_hubo :),
		"左右互搏": (: ask_hubo :),
		"hubo"    : (: ask_hubo :),
		"結義"    : (: ask_jieyi :),
		"結拜"    : (: ask_jieyi :),
		"jiebai"  : (: ask_jieyi :),
		"jieyi"   : (: ask_jieyi :),
		"空明"    : (: ask_skill1 :),
	]) );

	setup();

	carry_object("/clone/misc/cloth.c")->wear();
}

void attempt_apprentice(object ob)
{
	return;
}

void init()
{
	object ob = this_player();

	add_action("do_fangyuan","fangyuan");
	add_action("do_draw","draw");
	add_action("do_draw","hua");
 	add_action("do_learn","learn");
 	add_action("do_learn","xue");
	::init();
	if (ob->query("family/family_name") == "全真教")
	{
		command("angry " + ob->query("id"));
		command("say 怎麼你到今天才來找我？！明天我就去和處機説讓他打你屁股。");
	}
}

void kill_ob(object me)
{
	command("chat* crazy " + me->query("id"));
	::kill_ob(me);
}

void unconcious()
{
	command( "chat* 嘆道：老頑童今日是要歸天了，到陰世玩玩兩隻鬼打架，那些大頭鬼、無常鬼一定瞧得莫名其妙，鬼色大變。");
	::unconcious();
}

int accept_object(object who, object ob)
{
	if (ob->query("id") == "du she")
	{
		message_vision("$N拿出一條毒蛇在老頑童的眼前晃了晃．．．．．．\n老頑童嚇得跳了起來，衝出洞外！邊跑邊喊：糟糕透了，老玩童這番死定了！\n\n\n聲音漸漸遠去，終於不復耳聞。\n" ,who);
		destruct(this_object());
		return 0;
	}
	return 0;
}

int ask_jieyi()
{
	object ob=this_player();

	if (ob->query("zhou/jieyi"))
	{
		command("? " + ob->query("id"));
		command("say 咱倆不是結拜過了嗎？");
		return 1;
	}
	if (ob->query("age") < 16)
	{
		command( "say 我本來也想與你結拜，可又擔心你是大米。");
		return 1;
	}
	if (ob->query("gender") != "男性" && ob->query("gender") != "女性")
	{
		if (ob->query("age") > 48) 
			command( "say 我本來也想與你結拜，就是不知是兄弟相稱還是姐弟相稱？");
		else
			command( "say 我本來也想與你結拜，就是不知是兄弟相稱還是兄妹相稱？");
		command("laugh");
		return 1;
	}
	if (ob->query("int") > 25)
	{
		command("shake");
		command("say 你這個人鬼靈精，保不準打着什麼主意呢。");
		return 1;
	}
	if ((int)ob->query("shen") <= -1000)
	{
		command("shake");
		command("say 我雖然天性隨便，但師尊教誨不敢忘，於正邪之道還是要分清的。");
		return 1;
	}
	command("nod " + ob->query("id"));
	if (ob->query("gender") == "男性")
	{
		command("say 好吧，你我就結拜為兄弟吧。");
	}
	else if (ob->query("gender") == "女性")
		{
		if (ob->query("age") > 48) 
			command("say 好吧，你我就結拜為姐弟吧。");
		else
			command("say 好吧，你我就結拜為兄妹吧。");
		}
	message_vision("周伯通與$N並肩而跪，朗聲説道：“老頑童周伯通，今日與" + ob->name()+"義結金蘭，日後有福共享，有難共當。若是違此盟誓，教我武功全失，連小狗小貓也打不過。”\n", ob);
	ob->set("zhou/jieyi", 1);
	return 1;
}

int ask_hubo()
{
	object ob=this_player();
	int hubo;

	if( !ob->query("zhou/jieyi"))
	{
		write("周伯通奇怪地看着你，問道：你是誰呀？\n");
		return	1;
	}
	if (ob->query("double_attack"))
	{
		command("? " + ob->query("id"));
		command("say 你不是已經學會了嗎？");
		return 1;
	}
	hubo = ob->query_temp("zuoyou_hubo");
	if (hubo == 22)
	{
		command("say 接着練第一課！");
		return 1;
	}
	if (hubo == 1)
	{
		command("say 讓你練你就快練嘛！");
		return 1;
	}
	if (hubo > 1 && hubo <= 21)
	{
		command("say 怎麼樣，練不會吧？就象黃蓉那女孩兒玲瓏剔透，一顆心兒上生了十七八個竅，可是這門功夫她便始終學不會！");
		return 1;
	}
	if (ob->query_skill("force") < 100 ||
		ob->query("max_neili") < 500 ||
		ob->query("combat_exp") < 10000)
	{
		command("say 你還是先打好武學基礎再説吧。");
		return 1;
	}
	command("say 這門功夫是我在洞中無聊之時想出來的玩意兒，説難是難到極處，説容易也容易之至。有的人一學便會，有的人一輩子也學不了，越是聰明，越是不成。");
	command("say 你先練練這第一課：左手畫方(fang)，右手畫圓(yuan)。");
	ob->set_temp("zuoyou_hubo", 1);
	return 1;
}

int do_fangyuan()
{
	object ob=this_player();
	int hubo;

	if (ob->is_busy() || ob->is_fighting())
		return notify_fail("你正忙着呢！\n");
	hubo = ob->query_temp("zuoyou_hubo");
	if (!hubo) return 0;
	if (hubo < 21)
	{
		message_vision("$N伸出兩根食指在地上劃畫，但畫出來的方塊有點象圓圈，圓圈又有點象方塊。\n", ob);
		ob->add_temp("zuoyou_hubo", 1);
		return 1;
	}
	if (hubo == 21)
	{
		message_vision("$N伸出兩根食指在地上劃畫，但畫出來的方塊有點象圓圈，圓圈又有點象方塊。\n", ob);
		command("haha " + ob->query("id"));
		command("say 是麼？你這一下便辦不到！");
		ob->add_temp("zuoyou_hubo", 1);
		return 1;
	}
	if (hubo == 22)
	{
		if (ob->query("cps") >= 20)
		{
			message_vision("$N微微一笑，凝神守一，心地空明，隨隨便便的伸出雙手手指，左手畫了一個方塊，右手畫了一個圓圈，方者正方，圓者渾圓。\n", ob);
			say( "周伯通大喫一驚，過了半晌才道：“這定是你從孃胎裏學來的本領，那便易辦了。”\n");
			message_vision("周伯通將他領悟出來的這門天下無比的奇功，一古腦兒都教給了$N。\n", ob);
			ob->delete_temp("zuoyou_hubo");
			if (ob->query_skill("force") < 100 ||
				ob->query("max_neili") < 500)
				message_vision("可惜$N因為內功修為有限，終於還是沒能理解。\n", ob);
			else
			ob->set("double_attack", 1);;
			return 1;
		}
		message_vision("$N又伸出兩根食指在地上劃畫，但畫出來的仍舊是方塊有點象圓圈，圓圈又有點象方塊。\n", ob);
		message_vision("$N終於發現自己是一輩子也練不會這門功夫了。\n", ob);
		ob->delete_temp("zuoyou_hubo");
		command("disapp " + ob->query("id"));
		return 1;
	}
	return 0;
}

int do_draw(string arg)
{
	object ob=this_player();

	if (!ob->query_temp("zuoyou_hubo")) return 0;
	if (arg == "fang" || arg == "方" || arg == "yuan" || arg == "圓")
		return notify_fail("周伯通怒道：讓你同時畫方圓！\n");
	if (arg == "fang yuan" || arg == "方圓") return do_fangyuan();
	return 0;
}

int do_learn(string arg)
{
	object me=this_player();
	string skill, teacher, skill_name;
	object ob;
	int master_skill, my_skill, gin_cost, rand;

	if (me->is_busy()) return 0;
	if (!arg || (sscanf(arg, "%s %s", teacher, skill)!=2 ))
	{
		write("周伯通道：向我討教應該是 learn zhou 技能名\n");
		return 1;
	}
//	if (skill == "hubo") return 1;
	if (teacher != "zhou" && teacher != "botong") return 0;
	if( me->is_fighting() ) return 0;
	if( !(ob = present(teacher, environment(me))) || !ob->is_character()) {
		write("你要向誰求教？\n");
		return 1;
	}
	if( !living(ob) )
	{
		write("嗯....你得先把" + ob->name() + "弄醒再説。\n");
		return 1;
	}
	if( !me->query("zhou/jieyi"))
	{
		write("周伯通奇怪地看着你，問道：你是誰呀？\n");
		return 1;
	}
	if (skill != "kongming-quan" && skill != "hubo")
	{
		write("這項技能你恐怕必須找別人學了。\n");
		return 1;
	}
	my_skill = me->query_skill(skill, 1);
	master_skill = ob->query_skill(skill, 1);
	if( my_skill >= master_skill )
	{
		write("你在"+to_chinese(skill)+"上的造詣已經不下老頑童了！\n");
		return 1;
	}
	if( me->query_skill("qimen-wuxing"))
    {
    write("你的雜學太多，一時無法領會"+to_chinese(skill)+"！\n");
		return 1;
	}
	if( !SKILL_D(skill)->valid_learn(me) )
	{
		write("你的資質不適合學習"+to_chinese(skill)+"。\n");
		return 1;
	}
	gin_cost = 150 / (int)me->query("int");

	if( !my_skill ) {
		gin_cost *= 2;
		me->set_skill(skill,0);
	}
	rand = random(20);
	if (rand == 4) gin_cost *= 2;
	else if (rand == 15) gin_cost += 4;
	if(me->query("potential") - me->query("learned_points") < 1)
	{
		write("你的潛能已經發揮到極限了，沒有辦法再學了。\n");
		return 1;
	}

	message_vision("$N向$n請教有關「"+to_chinese(skill)+"」的問題。\n", me, ob);
	if( (int)me->query("jing") > gin_cost )
	{
		if(skill == "kongming-quan")
		{
			write( "周伯通念道：老子《道德經》裏有句話道：“埏植以為器，當其無，有器之用。鑿戶牖以為室，當其無，有室之用。”\n");
			write("周伯通吟口訣道：大成若缺，其用不弊，大盈若衝，其用不窮。\n");
		}
		else
		{
			write( "周伯通念道：“分心二用，神遊於外，任意所之。”\n");
		}
		if( (string)SKILL_D(skill)->type()=="martial" &&
			my_skill * my_skill * my_skill / 10 >
			(int)me->query("combat_exp") )
		{
			write("也許是缺乏實戰經驗，你對老頑童的講解總是無法領會。\n");
		} 
		else
		{
			if (rand == 13)
			{
				write( "就在你試圖領悟其中道理的時候，老頑童忽然在你旁邊大做鬼臉，又故意放了個屁來搗亂，搞得你心煩意亂。\n");
				write("結果你什麼都沒學到。\n");
				return 1;
			}
			else if (rand == 5)
			{
				write( "周伯通講解了兩句，忽然不耐煩起來，拉着你道：“咱倆玩四個人打架可好？”\n");
				write("結果你只好陪他玩耍了一陣。\n");
				return 1;
			}
			else if (rand == 4)
			{
				write( "就在你試圖領悟其中道理的時候，老頑童忽然在你旁邊大做鬼臉，又故意放了個屁來搗亂，搞得你心煩意亂。\n");
				write("結果你花了比平常多一倍的精力。\n");
			}
			else if (rand == 15)
			{
				write( "就在你試圖領悟其中道理的時候，老頑童忽然在你旁邊大做鬼臉，又故意放了個屁來搗亂，搞得你心煩意亂。\n");
				write("結果你花了比平常多得多的精力。\n");
			}
			if(skill_name = SKILL_D(skill)->query_skill_name(my_skill))
				write("你聽了老頑童的指導，對「" + skill_name + "」這一招似乎有些心得。\n");
			else
				write("你聽了老頑童的指導，似乎有些心得。\n");
			me->add("learned_points", 1);
			me->improve_skill(skill, random(me->query_int()));
		}
	} 
	else {
		gin_cost = me->query("jing");
		write("你今天太累了，結果什麼也沒有學到。\n");
	}
	me->receive_damage("jing", gin_cost );
	return 1;
}
string ask_skill1()
{
	object me = this_player();
	object zhou = this_object();
	
	if (me->query("can_perform/kongming-quan/kongming"))
		return "還問這個幹嘛？不如來陪我玩玩。";

	if (!me->query("zhou/jieyi"))
		return "你是誰，我怎麼不認識你？";

	return teach_perform(this_player(),this_object(),([
                                "perform" : "kongming",				//pfm的代碼必需參數
	                              "name"		: "空明",		//pfm的名稱
                                "sk1"			: "kongming-quan",//主要的武功的id
                                "lv1"			: 150,					//主要的武功的等級
                                "sk2"			: "unarmed",		//需要武功sk2的id
	                              "lv2"			: 150,					//需要武功sk2 的等級
	                              "neili"		: 1000,					//需要內力多少
	                              "free"		: 1, 						//free=1不需要同一門派
  	                            "shen"		: 50000,					//需要的shen
	                            "msg1"		: HIY "$N" HIY "抓了抓頭，滿不情願的嘀咕了兩句，這"
                     "才説道：“小子，我把口訣説給你聽，然後你就自己下去"
                     "練，別再來煩我了。”説完便一把將$n" HIY "楸到身邊"
                     "，在$n" HIY "耳旁唧唧咕咕説了半天。" NOR,
	                            "msg2"		: "好了，好了，你快走吧。",
										
																]));
}