//laoban.c 老闆
#include <ansi.h>
inherit NPC;
string do_ask();
string do_tool();
string do_abort();
string do_finish();

void create()
{
	set_name("老闆",({"lao ban","lao"}));
	set("long","他就是華山採石場的老闆，一副很精明的樣子，右手
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
	
	if (me->query_str()<18 || me->query("combat_exp")<5000)
	return ("“這位"+RANK_D->query_respect(me)+"也太瘦弱了吧，出了事我可負擔不起。”\n");
	if (me->query_temp("caishi/count")>=1)
	return ("“這位"+RANK_D->query_respect(me)+"不是已經有工作了嗎？不想做就放棄吧。”\n");
	titles=replace_string( me->query("title"), HIW" 採石工人"NOR, "");
	me->set("title",titles);
	me->add("title",HIW" 採石工人"NOR);
	me->set_temp("caishi/count",1);
	return("“好吧，這位"+RANK_D->query_respect(me)+"你就在這裏好好幹吧！”\n");
}

string do_tool()
{
	object me=this_player();
	object ob;
	if (present("hammer",me))
		return ("“這位"+RANK_D->query_respect(me)+"你身上已經有工具了。\n");
	ob=new("/clone/weapon/hammer");
	ob->move(me);
	message_vision("老闆給$N一把鐵錘。\n",me);
	return ("“這位"+RANK_D->query_respect(me)+"請把工具收好，別弄丟了。”\n");
}

string do_abort()
{
	object me=this_player();
	string titles;
	if (me->query_temp("caishi/count")<1)
		return ("“這位"+RANK_D->query_respect(me)+"還沒工作就想放棄？來搗亂的吧。”\n");
	titles=replace_string( me->query("title"), HIW" 採石工人"NOR, "");
	me->delete_temp("caishi/count");
	me->delete_temp("caishi/finish");
	return("“其實這份工也很不錯的，真是可惜！”\n");
}

string do_finish()
{
	object me=this_player();
	object ob;
	string titles;
//      if (!strsrch(me->query("title"),HIW"採石工人"NOR))
	if (me->query_temp("caishi/count")<1)
		return ("“這位"+RANK_D->query_respect(me)+"什麼時候替我做過事啊？”\n");
	if (!me->query_temp("caishi/finish") )
		return ("“這位"+RANK_D->query_respect(me)+"做事要有恆心，不想做就趁早放棄!\n");
	else 
	{
		titles=replace_string(me->query("title"),HIW" 採石工人"NOR, "");
		me->delete_temp("caishi/count");
		me->delete_temp("caishi/finish");	       
//		me->add("potential",2+random(2));
//		me->add("combat_exp",5+random(7));
		me->delete_temp("caishi/finish");
		me->set("title",titles);
		ob=new("/clone/money/silver");
		ob->set_amount(10);
		ob->move(me);
		return("“嗯，這位"+RANK_D->query_respect(me)+"幹得真是不錯，這是你的工錢，請收好了。”\n");
	}
}
