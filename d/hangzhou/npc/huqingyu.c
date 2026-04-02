// huqingyu.c
#include <ansi.h>
#include <command.h>
//inherit F_CLEAN_UP;
inherit NPC;

void create()
{
	set_name("胡慶餘",({ "hu qingyu","hu" }));
	set("gender", "男性" );
	set("age", 63);
	set("long",
"胡慶餘是當世一大巫醫，他的本事神奇無比。真有生死肉骨之功。\n");
	set("combat_exp", 200000);
	set("attitude", "friendly");
	set("inquiry", ([
		"改名": "五百兩黃金，給你改頭換面，江湖上沒人會知道你的！",
	]) );
	set("chat_chance", 30);
	set("chat_msg",({
		"胡慶餘淡淡說道：“改個名，就是新人了。”\n",
	}));
	setup();
}
void init()
{
	add_action("do_name","name");
//	add_action("do_betrayer","betrayer");
//	add_action("do_age","age");
}
int accept_object(object me, object ob)
{
	if (userp(me))
	{
		if( ob->query("money_id") && ob->value() >= 5000000)
		{
			if(me->query("class") == "bonze" || me->query("class") == "quanzhen")
			{
				say("胡慶餘掩口暗笑：出家人是不能改名字的。我還怕你們掌門師尊派人砸我的小店呢。\n");
				return 0;
			}
			command("nod");
			command("say 好吧，"+me->query("name")+"，你說個章程！\n");
			me->set_temp("marks/huqingyu",1);
			return 1;
		}
	} else return 1;
}
int do_name(string arg,object me)
{
	string *banned_name = ({
		"你", "操", "我", "他", "她", "它", "媽", "爸", "　",
		"翔少爺", "方舟子", "草魚", "時空", "丁",
		"木人", "赫連鐵樹", "單正", "韋小寶",
		"仙子", "天馬行空", "迪陽", "風兒", "演若達多", "凡狗",
		"寒江雪", "天星", "紫志龍","蝦咪碗糕"
	});
	int i;

	me = this_player();
	if(me->query("class") == "bonze" || me->query("class") == "quanzhen")
		return notify_fail("胡慶餘掩口暗笑：出家人是不能改名字的。我還怕你們掌門師尊派人砸我的小店呢。\n");
	if(!(int)me->query_temp("marks/huqingyu"))
	{
		return notify_fail("胡慶餘翻着黑白眼：錢呢？沒給錢想佔便宜？\n");
	}
	if( !arg ) return notify_fail("胡慶餘笑道：名字總該寫全吧。\n");
	if( strwidth(arg) > 10 )
	return notify_fail("胡慶餘驚呼起來：哪有這麼長的名字？\n");
	if( strwidth(arg) < 4 )
	return notify_fail("胡慶餘哼了一聲：這麼短算啥名字？\n");
        i=strwidth(arg);
	while(i--)
	{
		if( arg[i]<=' ' ) {
			write("對不起，你的中文名字不能用控制字元。\n");
			return 1;
		}
		if( (strsrch(arg, "　") >= 0) ||
		    (strsrch(arg, "爸") >= 0)) {
			write("對不起，你的中文名字不能用引起誤會的單字。\n");
			return 1;
		}
		if( i%2==0 && !is_chinese(arg[i..<0]) ) {
			write("對不起，請您用「中文」取名字。\n");
			return 1;
		}
	}
	if( member_array(arg, banned_name)!=-1 ) {
		write("對不起，這種名字會造成其他人的困擾。\n");
		return 1;
	}
	if( (strwidth(arg) < 2) || (strwidth(arg) > 10 ) ) {
		write("對不起，你的中文名字必須是 1 到 5 箇中文字。\n");
		return 1;
	}

	me->delete_temp("marks/huqingyu");
	if (me->query("gender")=="女性")
		message_vision(CYN"胡大夫大筆一揮就改了$N的芳名！真爽呆了....\n"NOR,me);
	else message_vision(CYN"胡大夫大筆一揮就改了$N的大名...真神！\n"NOR,me);
	me->set("name",arg);

	return 1;
}

/*
int do_betrayer(object me)
{
	me = this_player();
	if(!(int)me->query_temp("marks/huqingyu"))
	{
		return notify_fail("胡慶餘翻着黑白眼：錢呢？沒給錢想佔便宜？\n");
	}

	me->delete_temp("marks/huqingyu");
	if (me->query("combat_exp")<10000)
		return notify_fail("真冤枉！你的經驗還可以隨便叛師的！\n");

	me->set("betrayer", me->query("betrayer")+1);
	me->set("title","普通百姓");
	me->set("class","0");
	me->delete("family");
	message_vision(CYN"胡大夫笑道：江湖上海闊天空，都是$N的天地了！不過，你的叛師記錄也多了一次！\n"NOR,me);
	command("sigh");
	return 1;
}

int do_age(object me)
{
	object obj;
	me = this_player();

	return notify_fail("胡慶餘翻着黑白眼：死生有命，你也別太在意了！\n");
	if(!(int)me->query_temp("marks/huqingyu"))
	{
		return notify_fail("胡慶餘翻着黑白眼：錢呢？沒給錢想佔便宜？\n");
	}
	me->delete_temp("marks/huqingyu");

	if (me->query("age") < 21)
	{
//		obj=new("/clone/money/gold");
//		obj->set_amount(100);
//		obj->move(me);
		return notify_fail("胡大夫道：你還很年輕的，這一百兩黃金就送老夫白花了！\n");
	}

	me->add("mud_age", -86400);
	me->add("age", -1);
	me->delete("last_slp");
	me->delete("jingzuo_time");
	log_file( "CHANGEAGE", sprintf("%s at %s: %d\n", me->query("id"), ctime(time()), me->query("age") ) );
	message_vision(CYN"胡大夫道：果然有錢能使鬼推磨，$N現在看是年輕多了！\n"NOR,me);
	return 1;
}
*/
