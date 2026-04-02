// Room: zhengtang.c
#include <ansi.h>
inherit ROOM;
void bt_same(object who,object me);

void create()
{
	set("short", "正堂");
	set("long", @LONG
這裏是揚州府的大堂，堂下衙役分班站立，四周鴉鵲無聲。堂口擺
放着皇上御賜的三口銅鍘。程大人高坐在堂上，臉色陰沉，微有怒色，
看來正在下令捉拿人犯。大堂正中高懸一匾：
	       明      鏡      高      懸
LONG
	);
	set("no_fight", "1");
	set("exits", ([
		"east"      : __DIR__"dongting",
		"west"      : __DIR__"xiting",
		"north"     : __DIR__"neizhai",
		"southdown" : __DIR__"yamenyuan",
	]));
	set("objects", ([
		__DIR__"task3/cheng": 1,
		__DIR__"npc/yayi": 4,
	]));
	set("coor/x", -20);
	set("coor/y", 2);
	set("coor/z", 10);
	setup();
//	replace_program(ROOM);
}

void init ()
{
	add_action("do_work","work");
	add_action("do_finish","finish");
}

int do_work (string arg)
{
	object ob,ob1,me = this_player();
	int bt_npc,bt_whatnpc,worked_num,officerlvl;
	string bt_name,bt_name1,bt_where;

	if (!(int)me->query("officerlvl"))
		return notify_fail("兩旁衙役大聲喝道：大膽刁民，不得咆哮公堂！\n");
	if (!objectp(present("cheng yaofa", environment(me))))
		return notify_fail("衙役笑道：程大人已經退堂了，要想任務明日請早了您。\n");
	if (time()<me->query("bt/time")+2*(me->query("bt/work")-me->query("bt/worked")))
		return notify_fail("程大人大怒：你整天在衙門進進出出不幹活，白拿國家俸祿了！\n");
	if (present("huo qian",me) || me->query_condition("bt_busy"))
		return notify_fail("程大人臉色一沉道：本府前日交與你的差事速去辦理，不得捻輕怕重！\n");
	bt_npc = 1 + random(30);
	bt_whatnpc =1+random(6);
	me->set("bt/whatnpc",bt_whatnpc);
	me->set("bt/time",time());
	me->apply_condition("bt_busy",5+random(5));
	ob = new(__DIR__"task3/huoqian");	//50
	if(bt_whatnpc==1){ob1 = new(__DIR__"task3/tufei1");}
	if(bt_whatnpc==2){ob1 = new(__DIR__"task3/tufei2");}
	if(bt_whatnpc==3){ob1 = new(__DIR__"task3/tufei3");}
	if(bt_whatnpc==4){ob1 = new(__DIR__"task3/tufei4");}
	if(bt_whatnpc==5){ob1 = new(__DIR__"task3/tufei5");}
	if(bt_whatnpc==6){ob1 = new(__DIR__"task3/tufei6");}
	bt_same(ob1,me);
	ob1->move(ob);
	ob ->move(me);
	me->set_temp("bt/npc",bt_npc);
	me->add("bt/work",1);
	if(bt_npc<280) bt_where = "東海某個小島上";
	if(bt_npc<160) bt_where = "揚州以北";
	if(bt_npc<130) bt_where = "揚州以東";
	if(bt_npc<100) bt_where = "揚州以西";
	if(bt_npc<91) bt_where = "京畿一帶";
	if(bt_npc<41) bt_where = "揚州附近";

	if(bt_whatnpc==1){bt_name="蒙面大盜";bt_name1="攔路搶劫,殺人如麻";}
	if(bt_whatnpc==2){bt_name="無影神偷";bt_name1="四處盜竊財物";}
	if(bt_whatnpc==3){bt_name="惡人雲中鶴";bt_name1="常劫掠民女，無惡不作";}
	if(bt_whatnpc==4){bt_name="西夏細作";bt_name1="四處活動";}
	if(bt_whatnpc==5){bt_name="大遼奸細";bt_name1="四處造謠破壞";}
	if(bt_whatnpc==6){bt_name="神祕人";bt_name1="刺殺朝廷命官";}

	me->set_temp("bt/whatnpc",bt_whatnpc);
	me->set_temp("bt/name",bt_name);
	me->set_temp("bt/where",bt_where);
	message_vision("程大人一拍驚堂木怒道：“據查今有"+bt_name+"在"+bt_where+bt_name1+"，\n$N速去破案，不得有誤。”説着手一揚，丟下一條火籤。$N忙俯身撿\n了起來：“得令！”\n",me);
	me->set_temp("bt/working",1);

	officerlvl = me->query("officerlvl");
	worked_num=me->query("bt/worked");
	if (worked_num>=3200 && officerlvl == 8)
		me->set("officerlvl",9);
	if (worked_num>=1600 && worked_num < 3200 && officerlvl == 7)
		me->set("officerlvl",8);
	if (worked_num>=800 && worked_num < 1600 && officerlvl == 6)
		me->set("officerlvl",7);
	if (worked_num>=400 && worked_num < 800  && officerlvl == 5)
		me->set("officerlvl",6);
	if (worked_num>=200 && worked_num < 400 && officerlvl == 4)
		me->set("officerlvl",5);
	if (worked_num>=100 && worked_num < 200 && officerlvl == 3)
		me->set("officerlvl",4);
	if (worked_num>=50 && worked_num < 100 && officerlvl == 2)
		me->set("officerlvl",3);
	if (worked_num>=20 && worked_num < 100 && officerlvl == 1)
		me->set("officerlvl",2);
//	me->set_temp("btwork/time",1);
	me->save();
	return 1;
}
int do_finish (string arg)
{
	object ob;
	int /*bt_npc,bt_whatnpc,*/bt_exp,bt_qn;
	string bt_name/*,bt_name1*/,bt_where;
	object me = this_player();
	ob= present("huo qian",me);
	bt_name = me->query_temp("bt/name");
	bt_where = me->query_temp("bt/where");
	if (!(int)me->query("officerlvl"))
		return notify_fail("兩旁衙役大聲喝道：大膽刁民，不得咆哮公堂！\n");
	if (!objectp(present("cheng yaofa", environment(me))))
		return notify_fail("衙役笑道：程大人已經退堂了，要想交籤明日請早了您。\n");
	if (!me->query_temp("bt/working"))
		return notify_fail("程大人臉色一沉道：本府什麼時候派過你差事啊？\n");
	if (!(int)me->query_temp("bt/finish"))
		return notify_fail("程大人臉色一沉道：本府交你的差使至今還未辦妥，你還有面目來見我？\n");
	if (present("huo qian",me))
	{
		tell_object(me, "你恭恭敬敬的繳上火籤。\n" NOR );
		destruct(present("huo qian",me));
	}
	message_vision ("程大人微微一笑道："+me->query("name")+"在"+bt_where+"破獲"+bt_name+"一案，勞苦功高，趕快下去休息吧！\n",me);
	bt_exp = 600+random(200);
//	bt_qn = 100+random(48);
	bt_qn = 150+random(50);
	me->add("combat_exp",bt_exp);
	me->add("potential",bt_qn);
	me->set_temp("prize_reason","捕快");
	me->set_temp("can_give_prize",1);
	me->set_temp("prize_exp",bt_exp);
	me->set_temp("prize_pot",bt_qn);
	me->add("bt/worked",1);
	me->delete_temp("bt/finish");
	me->delete_temp("bt/working");
	me->clear_condition("bt_busy");
	tell_object(me, "你獲得了" + chinese_number(bt_exp)+ "點經驗。" NOR );
	tell_object(me, "和" + chinese_number(bt_qn)+ "點潛能。\n" NOR );
	if (me->query("bt/worked")==3200)
	{
		me->set("officerlvl",9);
		me->add("weiwang",20);
		message_vision(HIC "$N的江湖威望提高了！\n" NOR,me);
		tell_object(me, "你現在的江湖威望是" + chinese_number((string)(me->query("weiwang")))+"。\n"NOR);
		message_vision (WHT"程大人微笑着説道："+me->query("name")+"連破大案，天下聞名，本府已經奏明聖上。\n昨日朝旨已下，命你進京面聖。你可立即動身，速去速回。"NOR,me);
		me->set("bt/jiangli",1);
	}
	if (me->query("bt/worked")==1600)
	{
		me->set("officerlvl",8);
		me->add("weiwang",20);
		message_vision(HIC "$N的江湖威望提高了！\n" NOR,me);
		tell_object(me, "你現在的江湖威望是" + chinese_number((string)(me->query("weiwang")))+"。\n"NOR);
		message_vision (WHT"程大人微笑着説道："+me->query("name")+"連破大案，天下聞名，本府已經奏明聖上。\n昨日朝旨已下，命你進京面聖。你可立即動身，速去速回。"NOR,me);
	}
	if (me->query("bt/worked")==800)
	{
		me->set("officerlvl",7);
		me->add("weiwang",20);
		message_vision(HIC "$N的江湖威望提高了！\n" NOR,me);
		tell_object(me, "你現在的江湖威望是" + chinese_number((string)(me->query("weiwang")))+"。\n"NOR);
		message_vision (WHT"程大人微笑着説道："+me->query("name")+"連破大案，天下聞名，本府已經奏明聖上。\n昨日朝旨已下，命你進京面聖。你可立即動身，速去速回。"NOR,me);
	}
	if (me->query("bt/worked")==400)
	{
		me->set("officerlvl",6);
		me->add("weiwang",20);
		message_vision(HIC "$N的江湖威望提高了！\n" NOR,me);
		tell_object(me, "你現在的江湖威望是" + chinese_number((string)(me->query("weiwang")))+"。\n"NOR);
		message_vision (WHT"程大人微笑着説道："+me->query("name")+"連破大案，天下聞名，本府已經奏明聖上。\n昨日朝旨已下，命你進京面聖。你可立即動身，速去速回。"NOR,me);
	}
	if (me->query("bt/worked")==200)
	{
		me->set("officerlvl",5);
		me->add("weiwang",20);
		message_vision(HIC "$N的江湖威望提高了！\n" NOR,me);
		tell_object(me, "你現在的江湖威望是" + chinese_number((string)(me->query("weiwang")))+"。\n"NOR);
		message_vision (WHT"程大人微笑着説道："+me->query("name")+"連破大案，天下聞名，本府已經奏明聖上。\n昨日朝旨已下，命你進京面聖。你可立即動身，速去速回。"NOR,me);
	}
	if (me->query("bt/worked")==100)
	{
		me->set("officerlvl",4);
		me->add("weiwang",20);
		message_vision(HIC "$N的江湖威望提高了！\n" NOR,me);
		tell_object(me, "你現在的江湖威望是" + chinese_number((string)(me->query("weiwang")))+"。\n"NOR);
		message_vision (WHT"程大人微笑着説道："+me->query("name")+"連破大案，天下聞名，本府已經奏明聖上。\n昨日朝旨已下，命你進京面聖。你可立即動身，速去速回。"NOR,me);
	}
	if (me->query("bt/worked")==50)
	{
		me->set("officerlvl",3);
		me->add("weiwang",20);
		message_vision(HIC "$N的江湖威望提高了！\n" NOR,me);
		tell_object(me, "你現在的江湖威望是" + chinese_number((string)(me->query("weiwang")))+"。\n"NOR);
		message_vision (WHT"程大人微笑着説道："+me->query("name")+"連破大案，天下聞名，本府已經奏明聖上。\n昨日朝旨已下，命你進京面聖。你可立即動身，速去速回。"NOR,me);
	}
	if (me->query("bt/worked")==20)
	{
		me->set("officerlvl",2);
	}
	me->save();
	return 1;
}
void bt_same(object who,object me)
{
	mapping myscore;
	int maxskill;
	myscore = me->query_entire_dbase();
	who->set("combat_exp", (int)me->query("combat_exp")*9/10);

	who->set("max_qi", (int)myscore["max_qi"]);
	who->set("eff_qi", (int)myscore["eff_qi"]);
	who->set("qi", (int)myscore["max_qi"]);
	who->set("max_jing", (int)myscore["max_jing"]);
	who->set("eff_jing", (int)myscore["eff_jing"]);
	who->set("jing", (int)myscore["max_jing"]);
	who->set("max_neili", (int)myscore["max_neili"]);
	who->set("neili", (int)myscore["max_neili"]);
	who->set("jiali", 0);
	maxskill = me->query_skill("force",1);
	if(maxskill<me->query_skill("parry",1)) maxskill=me->query_skill("parry",1);
	if(maxskill<me->query_skill("dodge",1)) maxskill=me->query_skill("dodge",1);
	if(maxskill<me->query_skill("sword",1)) maxskill=me->query_skill("sword",1);
	if(maxskill<me->query_skill("blade",1)) maxskill=me->query_skill("blade",1);
	if(maxskill<me->query_skill("unarmed",1)) maxskill=me->query_skill("unarmed",1);
	if(maxskill==0) maxskill=20;
	who->set("maxskill",maxskill*11/10);
}
int valid_leave (object who, string dir)
{
	if(who->query_condition("bt_stop")<1)
	{
		return ::valid_leave(who, dir);
	}
	else
	{
		message_vision ("$N爬起來就想往外跑。\n",who);
		return notify_fail(WHT"衙役死死把你按在地上喝道：老實點！\n"NOR);
		return 1;
	}
}