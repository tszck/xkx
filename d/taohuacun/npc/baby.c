// baby.c
#include <ansi.h>
inherit NPC;
inherit F_SAVE;

void try_move();

string *reject_msg = ({
	"説道：您太客氣了，這怎麼敢當？\n",
	"像是受寵若驚一樣，説道：請教？這怎麼敢當？\n",
	"笑着説道：您見笑了，我這點雕蟲小技怎夠資格「指點」您什麼？\n",
});
string query_save_file();
int do_save();
int do_do(string msg);
void improve_npcskill(string skill, int amount, int weak_mode);
int exercising(object me);
int halt_exercise(object me);
void update_me();
void create()
{
	seteuid(getuid());
	if (!restore())
	{
		set_name("寶寶", ({"xiao baobao","baby"}) );
		set("gender", "女性");
		set("age", 1);
		set("attitude", "friendly");
		set("long","一個乖寶寶。\n");
		set("combat_exp", 1);
		set("parents",({"dad","mom"}));
   
		set("chat_chance", 2);
		set("chat_msg", ({
			(: random_move :)
		}));

		set("is_baby",1);
		setup();
	}
}

void init()
{
	add_action("do_kill",({"kill","fight","hit","steal"}));
	add_action("do_get","get");
	add_action("do_drop","drop");
	if(member_array(this_player()->query("id"), this_object()->query("parents"))>-1)
	{
		add_action("do_save","bsave");
		add_action("do_teach","bjiao");
		add_action("do_teach","bteach");
		add_action("do_practice","blian");
		add_action("do_practice","bpractice");
		add_action("do_exercise","bdazuo");
		add_action("do_exercise","bexercise");
		add_action("do_learn","blearn");
		add_action("do_learn","bxue");
		add_action("do_study","bstudy");
		add_action("do_study","bdu");
		add_action("do_do","do");
		this_object()->set_leader(this_player());
	}

	remove_call_out("try_move");
	call_out("try_move",1);
}
void unconcious()
{

/*        message("system", HIR "\n你的眼前一黑，接着什麼也不知道了....\n\n" NOR,
this_object());

	 this_object()->disable_player(" <昏迷不醒>");

        set("jing", 0);
        set("qi", 0);

        set_temp("block_msg/all", 1);
        COMBAT_D->announce(this_object(), "unconcious");
*/
	add("die",1);
	set("eff_jing", query("max_jing"));
	set("jing",     query("max_jing"));
	set("eff_qi",   query("max_qi"));
	set("qi",       query("max_qi"));
	save();
	::die();
}

void try_move()
{
	if(random(20)==0)
	{
		remove_call_out("random_move");
		call_out("random_move",5);
	}
}

int do_drop(string arg)
{
	object me=this_object(),who=this_player(),env;
	if(!arg) return 0;
	env = environment(who);
	if(present(arg,who)!=me) return 0;
	if(me->move(env))
	{
		message_vision("$N把$n從懷裏放了下來。\n",who,me);
		return 1;
	}
	return 0;
}

int do_get(string arg)
{
	object me=this_object(),who=this_player(),env;

	if(!arg) return 0;
	env = environment(who);
	if(present(arg,env)!=me) return 0;
	if(member_array(who->query("id"), me->query("parents"))>-1)
	{
		if(me->move(who)) message_vision("$N彎下腰把$n抱了起來，摟在懷裏。\n",who,me);
		else message_vision("$N彎下腰一抱卻沒把$n抱起來，小傢伙好沉哪！\n",who,me);
	}
	else message_vision("$N蹲下身朝$n伸開雙手，$n卻一下子閃開了．．．\n",who,me);
	return 1;
}

int do_kill(string arg)
{	
	object me,who;
	string name,verb,what,obj;
	if (!arg) return 0;
	verb=query_verb();
	me=this_player();
   
	if(verb=="steal")
	{
		if(sscanf(arg, "%s from %s", what, obj)!=2 ) return 0;
	}
	else obj=arg;

	if(!objectp(who=present(obj,environment(me))) 
		|| !living(who)) return 0;
	if(who==this_object())
	{
		switch(verb)
		{
			case "kill":
			case "touxi":
			case "ansuan":
				tell_object(environment(this_object()),who->query("name")+"拼命地哭了起來：爹～～，娘～～，"+me->query("name")+"要殺我．．．快回來呀！\n");
				break;
			case "hit":
				tell_object(environment(this_object()),who->query("name")+"大哭了起來：爹～～，娘～～，"+me->query("name")+"欺負我．．．快回來呀！\n");
				break;
			case "fight":
				tell_object(environment(this_object()),who->query("name")+"哭了起來：爹～～，娘～～，"+me->query("name")+"要搶我的糖喫．．．快回來呀！\n");
				break;
			case "steal":
				tell_object(environment(this_object()),who->query("name")+"哭了起來：爹～～，娘～～，"+me->query("name")+"要偷喫我的糖！\n");
				break;
			case "beg":
				tell_object(environment(this_object()),who->query("name")+"小嘴一歪哭了起來：爹～～，娘～～，"+me->query("name")+"要騙我的糖喫！\n");
				break;
		}
	}
//	command(verb);
	return 0;
}

void relay_emote(object ob, string verb)
{
	if( !userp(ob) ) return;

	switch(verb)
	{
		case "kick":
			command("say 爹～～，娘～～，"  + ob->query("name") + "踢我耶！");
			command("kick " + ob->query("id"));
			break;
		case "slap":
			command("say 爹～～，娘～～，"  + ob->query("name") + "打我耶，好痛啊～～～～");
			command("slap " + ob->query("id"));
			break;
		case "hit":
			command("pain " + ob->query("id"));
			break;
		case "bite":
			command("face " + ob->query("id"));
			break;  
		case "papaya":
			command("angry");
			break;  
	}
}

void relay_whisper(object me, string msg)
{
	if (member_array(me->query("id"),query("parents"))==-1)
	{
		message_vision((string)this_object()->query("name")
			+ "疑惑地看着$N。\n", me);
		return;
	}

	//note, do not allow the order contain "chat", "tell"...
	//may need disable more later...
	if( strsrch(msg, "chat") != -1 || strsrch(msg, "tell") != -1 ||
		strsrch(msg,"follow")!= -1 || strsrch(msg,"apprentice")!= -1 ||
		strsrch(msg, "recruit") != -1 )
		return;

	if (msg)
	{
		remove_call_out ("relaying");
		call_out ("relaying", 1+random(3), msg);
	}
}

void relaying(string msg)
{
	command (msg);
}

int do_do(string msg)
{
	string act, sth;
	if (!msg || sscanf(msg, "%s %s",act,sth) != 2)
		return notify_fail("你要叫你孩子幹什麼？\n");

	if(
	// 〖用戶系統命令〗
	act!="nick" &&
// 〖交流探險命令〗
	act!="follow" && //new
  act!="ask" && 	//new
	act!="drop" &&	//new
	act!="halt" && //new
	act!="put" && //new
	act!="ride" && //new
	act!="unride" && //new
	act!="hit" &&
	act!="fight" && 
	act!="kill"	&& 
	act!="say" && 
	act!="chat" && 
	act!="chat*" && 
	act!="go" && 
	act!="give" && 
	act!="wear" && 
	act!="remove" && 
	act!="get" && 
	act!="eat" && 
	act!="drink" && 
	act!="wield" && 
	act!="unwield" && 
// 〖武功技能命令〗
	act!="abandon" && 
	act!="apprentice" && 
	act!="bei" && 
	act!="du" &&  //bdu功能實現
	act!="enable" && 
	act!="enforce" && 
	act!="exert" && 
	act!="fangqi" && 
	act!="jiali" && 
	act!="jifa" && 
	act!="learn" && 
	act!="perform" && //new
	act!="yong" && //new
	act!="prepare" && 
	act!="study" && // bdu功能實現
	act!="xue" && 
	act!="yun" && 
	act!="bai" &&
	act!="order"  //new 其它命令
	)
		return notify_fail("目前暫時不能叫你孩子幹這事！\n");

	command (msg);
	return 1;
}

string query_save_file()
{ 
	string id;

	if( !stringp(id = query("saveid")) ) return 0;
	return DATA_DIR + "baby/" + id[0..0] + "/" + id;
}

int do_save()
{
	save();
	write(this_object()->query("name")+"存盤完畢。\n");
	return 1;
}

int do_teach(string skill)
{
	object ob=this_object(), me=this_player();
	string skill_name, obname=ob->query("name");
	int student_skill, my_skill, jing_cost, grade, student_combat_exp;

	if (me->is_busy())
		return notify_fail("你現在正忙着呢。\n");
	if(!skill) return notify_fail("你要教"+obname+"什麼技能？\n");
	if( me->is_fighting() )
		return notify_fail("你自己保命都懸。還有空教孩子？\n");
	if( !living(ob) )
		return notify_fail("嗯....你得先把"+obname+"弄醒再説。\n");
	if (ob->is_busy())
		return notify_fail(obname + "現在正忙着呢。\n");
	if( ob->is_fighting() )
		return notify_fail("沒看到"+obname+"快玩完了？還不自己出手！\n");

	if( !my_skill = me->query_skill(skill, 1) )
		return notify_fail("這項技能你還不會呢！\n");

	if( ob->prevent_learn(me, skill) )
		return 0;

	student_skill = ob->query_skill(skill, 1);

	if( my_skill <= student_skill )
		return notify_fail("這項技能"+obname+"的程度已經不輸於你了。\n");

	if( !SKILL_D(skill)->valid_learn(ob) ) 
		return notify_fail("依"+obname+"目前的能力，沒辦法學習這種技能。\n");

	jing_cost = 100 / ((int)me->query("int") + (int)ob->query("int"));

	if( !student_skill )
	{
		jing_cost *= 2;
		ob->set_skill(skill,0);
	}

	if( (int)me->query("learned_points") >= (int)me->query("potential") )
		return notify_fail("你的潛能已經發揮到極限了，沒有辦法再教了。\n");

	if( (int)ob->query("learned_points") >= (int)ob->query("potential") )
		return notify_fail(obname+"的潛能已經發揮到極限了，沒有辦法再成長了。\n");

	printf("你向%s解釋有關「%s」的疑問。\n", obname, to_chinese(skill));

	if( (int)me->query("jing") > jing_cost )
	{
		if( userp(me) ) me->receive_damage("jing", jing_cost );
	} else {
		write("但是你太累了，沒有辦法再教"+obname+"。\n");
		return 1;
	}
		
	student_combat_exp = (int)ob->query("combat_exp");

/*	if(student_combat_exp < 10000)
		grade = 1;
	else if(student_combat_exp < 100000)
		grade = 3;
	else if(student_combat_exp < 1000000)
		grade = 8;
	else
		grade = 14;
*/
	if((int)ob->query("jing") > jing_cost)
	{
		if( (string)SKILL_D(skill)->type()=="martial" && student_skill * student_skill * student_skill / 10 > student_combat_exp)
		{
			tell_object(me, "也許是缺乏實戰經驗，"+obname+"對你的解釋總是無法領會。\n");
		}
		else
		{
			if(skill_name = SKILL_D(skill)->query_skill_name(student_skill))

				tell_object(me, obname+"聽了你的指導，對"+skill_name+"這一招似乎有些心得。\n");
			else
				tell_object(me, obname+"聽了你的指導，似乎有些心得。\n");
             
   			me->add("learned_points", 1);
			ob->add("learned_points", 1);

//			if ( grade < 1 ) grade = 1;
			ob->improve_npcskill(skill, 100);
		}
	}
	else
	{
		jing_cost = ob->query("jing");
		tell_object(me,obname+"今天太累了，結果什麼也沒有學到。\n");
	}
	ob->receive_damage("jing", jing_cost );
	return 1;
}

void improve_npcskill(string skill, int amount, int weak_mode)
{
	int spi;
	object ob=this_object();
	string obname=ob->query("name");

	if( !find_object(SKILL_D(skill))
	&& file_size(SKILL_D(skill)+".c") < 0 )
		error("F_SKILL: No such skill (" + skill + ")\n");

	if( !weak_mode || !userp(ob) )
	{
		if( !mapp(skills) ) skills = ([]);
		if( undefinedp(skills[skill]) ) skills[skill] = 0;
	}

	spi = 30;
	if( sizeof(learned) > spi )
		amount /= sizeof(learned) - spi;

	if( !amount ) amount = 1;

	if( !mapp(learned) ) learned = ([ skill : amount ]);
	else (int)learned[skill] += amount;

	if( (!weak_mode || !userp(ob))
		&& learned[skill] > (skills[skill] + 1) * (skills[skill] + 1) )
	{
		skills[skill]++;
		learned[skill] = 0;
		tell_object(this_player(), HIC+obname+"的「" + to_chinese(skill) + "」進步了！\n" NOR);
		SKILL_D(skill)->skill_improved(ob);
	}
}

int do_practice(string skb)
{
	object ob=this_object(), me=this_player();
	string sknm, obname = ob->query("name");
	int sk, skbasic;

	seteuid(getuid());

        if(ob->is_busy())
                return notify_fail(obname+"現在正忙着呢。\n");
	if(ob->is_fighting())
		return notify_fail(obname+"已在戰鬥中了，學點實戰經驗也好。\n");
	if( !skb) return notify_fail("你要讓"+obname+"練習什麼？\n");
	if( !stringp(sknm = ob->query_skill_mapped(skb)) )
		return notify_fail("你只能讓"+obname+"練習用 enable 指定的特殊技能。\n");

	skbasic = ob->query_skill(skb, 1);
	sk = ob->query_skill(sknm, 1);
	if( sk < 1 )
		return notify_fail(obname+"好像還沒有學過這項技能吧？\n");
	if( skbasic < 1 )
		return notify_fail(obname+"對這方面的技能還是一竅不通，最好從先從基本學起。\n");
	if( skbasic/2 <= sk/3 )
		return notify_fail(obname+"的基本功火候未到，必須先打好基礎才能繼續提高。\n");
	if( !SKILL_D(sknm)->valid_learn(ob) ) 
		return notify_fail("依"+obname+"目前的能力，沒辦法學習這種技能。\n");
	if( SKILL_D(sknm)->practice_skill(ob) )
		return notify_fail("依"+obname+"目前的能力，沒辦法練習這種技能。\n");
	notify_fail(obname+"現在不能練習這項技能。\n");
	if( !SKILL_D(sknm)->valid_learn(ob) ) return 0;

	notify_fail( obname+"試着練習"+to_chinese(sknm)+"，但是並沒有任何進步。\n");
	if (sk*sk*sk/10 > (int)ob->query("combat_exp")) 
	{
		return notify_fail("也許是缺乏實戰經驗，練習總沒法進步。\n");
		return 1;
	}

	ob->receive_damage("qi", 10);
	write(HIC + obname+"試着把" + to_chinese(sknm) + "練了一趟。\n"NOR);
	ob->improve_npcskill(sknm, skbasic * 2);
	write(HIY + obname + to_chinese(sknm) + "進步了！\n" NOR);
	return 1;
}

int do_exercise(string arg)
{
	int exercise_cost;
	object ob=this_object();
	string obname=ob->query("name");

	seteuid(getuid());

	if (ob->is_busy() || ob->query_temp("pending/exercising"))
		return notify_fail(obname+"現在正忙着呢。\n");
	if( ob->is_fighting() )
		return notify_fail("戰鬥中不能練內功，會走火入魔。\n");
	if( !stringp(ob->query_skill_mapped("force")) )
		return notify_fail("你必須先讓"+obname+"選擇要用的內功心法。\n");
	if( !arg || !sscanf(arg, "%d", exercise_cost))
		return notify_fail(obname+"要花多少氣練功？\n");
	if (exercise_cost < 10)
		return notify_fail(obname+"的內功還沒有達到那個境界！\n");
	if( (int)ob->query("qi") < exercise_cost )
		return notify_fail(obname+"現在的氣太少了，無法產生內息運行全身經脈。\n");

	if( (int)ob->query("jing") * 100 / (int)ob->query("max_jing") < 70 )
		return notify_fail(obname+"現在精不夠，無法控制內息的流動！\n");
	write(obname+"坐下來運氣用功，一股內息開始在體內流動。\n");

	ob->set_temp("pending/exercise", 1);
	ob->set_temp("exercise_cost", exercise_cost);
	message_vision("$N盤膝坐下，開始修煉內力。\n", ob);
	ob->start_busy((: exercising :), (:halt_exercise:));
	return 1;
}

int exercising(object ob)
{
	int exercise_cost = (int)ob->query_temp("exercise_cost");
	int neili_gain = 1 + (int)ob->query_skill("force") / 10;
	int max_neili_gain = (int) random(ob->query("max_neili") /500);
	int taixuan;
	object where=environment(ob);
	string obname=ob->query("name");

	if (exercise_cost < 1)
		return 0;
	ob->add("neili", neili_gain);
	ob->set_temp("exercise_cost", exercise_cost -= neili_gain);
// 靈鷲玄冰室
	if(where->query("xuanbing"))
		ob->add("qi", (int)neili_gain/3);
// 太玄功
	if ((int)ob->query_skill("taixuan-gong",1))
	{
		taixuan = (int)ob->query_skill("taixuan-gong",1);
		if(taixuan > 10)
			ob->add("qi", (int)neili_gain * taixuan / 400);
	}
// 神照經
	if ((int)ob->query_skill("shenzhao-jing",1))
	{
		taixuan = (int)ob->query_skill("shenzhao-jing",1);
		if(taixuan > 10)
			ob->add("qi", (int)neili_gain * taixuan / 400);
	}

	if(living(ob))
	ob->add("qi", -neili_gain);
	
	if (exercise_cost > 0)
		return 1;

	ob->set_temp("pending/exercise", 0);
	message_vision("$N運功完畢，深深吸了口氣，站了起來。\n", ob);
	if ((int)ob->query("neili") < (int)ob->query("max_neili") * 2)
		return 0;
	else
	{
		if((int)ob->query("max_neili")>(int)ob->query_skill("force")*10)
		{
			write(obname+"內力修為似乎已達到了瓶頸。\n");
			ob->set("neili", (int)ob->query("max_neili"));
			return 0;
		}
		else {
			if (max_neili_gain>2) max_neili_gain=2;
			ob->add("max_neili", 1+max_neili_gain);
			ob->set("neili", (int)ob->query("max_neili"));
			message_vision(HIC"$N的內力增加了！！\n"NOR, ob);
			return 0;
		}
	}
}

int halt_exercise(object ob)
{
	if ((int)ob->query("neili") > (int)ob->query("max_neili") * 2)
		ob->set("neili", (int)ob->query("max_neili") * 2);
	ob->set_temp("pending/exercise", 0);
	return 1;
}
int do_study(string arg)
{
	object book, ob = this_object();
	string zhao_name, obname = ob->query("name");
	mapping skill;
	int my_skill, cost, i, success=0;

	if(!arg) return notify_fail("你要"+obname+"讀什麼？\n");
        if(ob->is_busy())
                return notify_fail(obname+"現在正忙着呢。\n");
	if(ob->is_fighting() )
		return notify_fail(obname+"無法在戰鬥中專心下來研讀新知！\n");
	if(!objectp(book = present(arg, ob)) )
		return notify_fail(obname+"沒這本書可讀啊？\n");
	if( !mapp(skill = book->query("skill")) )
		return notify_fail(obname+"無法從這樣東西學到任何東西。\n");
	if( !ob->query_skill("literate", 1) )
		return notify_fail(obname+"是個文盲，先學點文化吧。\n");

	message("vision", obname+"正專心地研讀"+book->name()+"。\n", environment(ob), ob);
	if( (int)ob->query("combat_exp") < skill["exp_required"] )
	{
		message_vision(HIC"$N的實戰經驗不足，再怎麼讀也沒用。\n"NOR,ob);
		return 1;
	}

	notify_fail("以"+obname+"目前的能力，還沒有辦法學這個技能。\n");
	if( !SKILL_D(skill["name"])->valid_learn(ob) ) return 0;

	cost = skill["jing_cost"] + skill["jing_cost"] 
		* (skill["difficulty"] - (int)ob->query("int"))/20;
	if (cost < 10) cost = 10; // minimum cost

	if( ob->query_skill(skill["name"], 1) > skill["max_skill"] )
	{
		message_vision(HIR"$N研讀了一會兒，但是發現上面所説的都太淺了，沒有學到任何東西。\n"NOR, ob);
		return 1;
	}
	if( ob->query_skill(skill["name"], 1) < skill["min_skill"] )
	{
		message_vision(HIR"$N研讀了一會兒，但是發現上面所説的都太深奧了，毫無收穫。\n"NOR, ob);
		return 1;
	}

	if( !ob->query_skill(skill["name"],1)) ob->set_skill(skill["name"], 0);

	my_skill = ob->query_skill(skill["name"], 1);

	if( (int)ob->query("jing") > cost )
	{
		if( (string)SKILL_D(skill["name"])->type()=="martial"
		&& my_skill*my_skill*my_skill/10 > (int)ob->query("combat_exp"))
		{
			message_vision("也許是缺乏實戰經驗，$N對$n上面所説的東西總是無法領會。\n", ob, book);
		}
		else
		{
			if(zhao_name = SKILL_D(skill["name"])->query_skill_name(my_skill))
			printf(obname+"研讀了有關%s的技巧，對「%s」這一招似乎有些心得。\n", 
				to_chinese(skill["name"]), zhao_name);
			else
			printf(obname+"研讀了有關%s的技巧，似乎有點心得。\n", to_chinese(skill["name"]));
			ob->improve_npcskill(skill["name"], (int)ob->query_skill("literate", 1)/5+1);
		}
	} else {
		cost = ob->query("jing");
		return notify_fail(obname+"現在過於疲倦，無法專心下來研讀新知。\n");
	}
	ob->receive_damage("jing", cost);

	return 1;
}

int do_learn(string arg)
{
	object obt, ob = this_object();
	string skill, teacher, master, skill_name, obname=ob->query("name");
	int master_skill, my_skill, jing_cost, pertimes;

	if( ob->is_busy()) return notify_fail(obname+"現在正忙着呢。\n");
	if(!arg || (sscanf(arg, "%s %s", teacher, skill) !=2 ))
		return notify_fail("指令格式：blearn | bxue <某人> <技能>\n");
	if( ob->is_fighting() )
		return notify_fail("讓"+obname+"臨陣磨槍？來不及啦。\n");
	if( !(obt = present(teacher, environment(ob))) || !obt->is_character())
		return notify_fail("讓"+obname+"向誰求教？\n");
	if( !living(obt) )
		return notify_fail("嗯....得先把"+obt->name()+"弄醒再説。\n");

	if( !ob->is_apprentice_of(obt) && !(obt->recognize_apprentice(ob)) )
	{
		return notify_fail(obt->name()+reject_msg[random(sizeof(reject_msg))] );
	}

	if( !master_skill = obt->query_skill(skill, 1) )
		return notify_fail("這項技能"+obname+"恐怕必須找別人學了。\n");

	notify_fail(obt->name()+"不願意教"+obname+"這項技能。\n");
	if( obt->prevent_learn(ob, skill) ) return 0;

	my_skill = ob->query_skill(skill, 1);
	if( my_skill >= master_skill )
		return notify_fail("這項技能"+obname+"的程度已經不輸"+obname+"的師父了。\n");
	if( my_skill >= (int)(master_skill - ob->query("betrayer")*2))
		return notify_fail(obt->name()+"皺了皺眉頭，不禁想起"+obname+"過去的叛師經歷。\n");
	notify_fail("依"+obname+"目前的能力，沒有辦法學習這種技能。\n");
	if( !SKILL_D(skill)->valid_learn(ob) ) return 0;
	jing_cost = 100 / (int)ob->query("int");
	if( !my_skill )
	{
		jing_cost *= 2;
		ob->set_skill(skill,0);
	}
	if( (ob->query("potential") - ob->query("learned_points")) < 1)
		return notify_fail(obname+"的潛能不夠學習了。\n");
	printf(HIC+obname+"向%s請教了有關「%s」的疑問。\n"NOR, obt->name(), to_chinese(skill));

	if( obt->query("env/no_teach") )
		return notify_fail("但是"+obt->name()+"現在並不準備回答"+obname+"的問題。\n");

	tell_object(obt, sprintf("%s向你請教有關「%s」的問題。\n",
		obname, to_chinese(skill)));

	if( (int)obt->query("jing") > jing_cost/5 + 1 )
	{
		if( userp(obt) ) obt->receive_damage("jing", jing_cost/5 + 1);
	} else
	{
		write("但是"+obt->name()+"顯然太累了，沒有辦法教"+obname+"什麼。\n");
		tell_object(obt, "但是你太累了，沒有辦法教"+obname+"。\n");
		return 1;
	}
		
	if( (int)ob->query("jing") > jing_cost )
	{
		if( (string)SKILL_D(skill)->type()=="martial"
		&& my_skill*my_skill*my_skill/10 > (int)ob->query("combat_exp"))
		{
			return notify_fail("也許是缺乏實戰經驗，"+obname+"對"+obt->name()+"的回答總是無法領會。\n");
		} else
		{
			if(skill_name = SKILL_D(skill)->query_skill_name(my_skill))
	 			printf(obname+"聽了%s的指導，對「%s」這一招似乎有些心得。\n", obt->name(), skill_name);
			else
				printf(obname+"聽了%s的指導，似乎有些心得。\n", obt->name());
			ob->add("learned_points", 1);
			ob->improve_npcskill(skill, random(ob->query_int()));
		}
	} else
	{
		if (jing_cost > ob->query("jing"))
			jing_cost = ob->query("jing");
		return notify_fail(obname+"今天太累了，結果什麼也沒有學到。\n");
	}
	ob->receive_damage("jing", jing_cost);
	return 1;
}
void update_me()
{
	object obj=this_object();
	obj->set("max_qi",100+obj->query("max_neili")/4);
	obj->set("max_jing",100+obj->query("max_jingli")/4);
}
