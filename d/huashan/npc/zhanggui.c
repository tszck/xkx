//laoban.c 老闆
#include <ansi.h>
#define MIN_EXP 20000
#define MAX_EXP 60000
inherit NPC;
string do_ask();
string do_tool();
string do_abort();
string do_finish();

void create()
{
	set_name("掌櫃",({"zhang gui","boss"}));
	set("long","他就是華山採石場的掌櫃，一副很精明的樣子，右手
正拿着算盤，小眼睛眯縫着，透過老花鏡打量着你。\n");
	set("gender","男性");
	set("title",CYN"採石場"NOR);
	set("age",50);
	set("inquiry",([
	      "工作" : (:do_ask:),
	      "採石" : (:do_ask:),
	      "work" : (:do_ask:),
	      "工具" : (:do_tool:),
	      "tool" : (:do_tool:),
	      "放棄" : (:do_abort:),
	      "abort" : (:do_abort:),
	      "交工" : (:do_finish:),
	      "finish" : (:do_finish:),
	]) );
	set("per",18);
	set("kar",22);
	
	set_skill("force",20);
	set_skill("dodge",20);
	set_skill("parry",20);
	set_skill("unarmed",20);
	setup();
	carry_object("/clone/cloth/cloth")->wear();
}

string do_ask()
{
	object me=this_player();
	string titles;
	object room;
	object *inv;
	int i;
	
	if (me->query("combat_exp")>=MAX_EXP)
		return("大俠您就不要來和小輩們攪和了吧。");
	if (me->query_str()<18 || me->query("combat_exp")<MIN_EXP)
	return ("“這位"+RANK_D->query_respect(me)+"也太瘦弱了吧，出了事我可負擔不起。”");
	if (me->query_temp("caishi/count")>=1)
	return ("“這位"+RANK_D->query_respect(me)+"不是已經有工作了嗎？不想做就放棄吧。”");
	room = find_object("/d/huashan/caishi");
	if (!room) room = load_object("/d/huashan/caishi");
	inv = all_inventory(room);
	for (i=0;i<sizeof(inv);i++)
	{
		if (inv[i] != me 
		&& (query_ip_name(inv[i])==query_ip_name(me))
		&& inv[i]->query_temp("caishi/count"))
		return "你先歇會兒吧，這裏已經有人幫忙了。";
	}
	titles=replace_string( me->query("title"), HIW"石匠"NOR, "");
	me->set("title",titles);
	me->add("title",HIW"石匠"NOR);
	me->set_temp("caishi/count",1);
	return("“好吧，這位"+RANK_D->query_respect(me)+"你就在這裏好好幹吧！”");
}

string do_tool()
{
	object me=this_player();
	object ob;
	if (present("hammer",me))
		return ("“這位"+RANK_D->query_respect(me)+"你身上已經有工具了。");
	ob=new(__DIR__"obj/hammer");
	ob->move(me);
	message_vision("老闆給$N一把鐵錘。\n",me);
	return ("“這位"+RANK_D->query_respect(me)+"請把工具收好，別弄丟了。”");
}

string do_abort()
{
	object me=this_player();
	string titles;
	if (me->query_temp("caishi/count")<1)
		return ("“這位"+RANK_D->query_respect(me)+"還沒工作就想放棄？來搗亂的吧。”");
	titles=replace_string( me->query("title"), HIW"石匠"NOR, "");
	me->delete_temp("caishi/count");
	me->delete_temp("caishi/finish");
	return("“其實這份工也很不錯的，真是可惜！”\n");
}

string do_finish()
{
	object me=this_player();
	object ob1;
	string titles;
	int add_exp,add_pot,add_score;
//      if (!strsrch(me->query("title"),HIW"石匠"NOR))
	if (me->query_temp("caishi/count")<1)
		return ("“這位"+RANK_D->query_respect(me)+"什麼時候替我做過事啊？”");
	if (!me->query_temp("caishi/finish") )
		return ("“這位"+RANK_D->query_respect(me)+"做事要有恆心，不想做就趁早放棄!”");
	else 
	{
		titles=replace_string(me->query("title"),HIW"石匠"NOR, "");
		me->delete_temp("caishi/count");
		me->delete_temp("caishi/finish");	       
//		me->add("potential",2+random(2));
//		me->add("combat_exp",5+random(7));
		me->delete_temp("caishi/finish");
		me->set("title",titles);
		add_exp=60+random(20);
		add_pot=30+random(10);
		add_score=10+random(5);
		me->add("combat_exp",add_exp);
		me->add("potential",add_pot);
		me->add("score",add_score);
		ob1 = new("/clone/money/silver");
		ob1->set_amount(add_pot);
		ob1->move(me);	
		tell_object(me,HIW"你得到了:"
			+ chinese_number(add_exp) + "點實戰經驗，"
			+ chinese_number(add_pot) + "點潛能，"
			+ chinese_number(add_score) + "點江湖閲歷。\n"NOR);
		return("“嗯，這位"+RANK_D->query_respect(me)+"幹得真是不錯，這是你的工錢，請收好了。”");
	}
}
