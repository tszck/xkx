// ma.c 馬鈺
// last modified 01/05/05

#include <ansi.h>
inherit NPC;

string ask_me();
string ask_ling();
string ask_array();
string ask_shu();
int do_qixing(object me, object ob);

void create()
{
        set_name("馬鈺", ({"ma yu", "ma"}));
        set("gender", "男性");
        set("age", 42);
        set("class", "quanzhen");
        set("nickname",MAG"丹陽子"NOR);
        set("long",
                "他就是王重陽的大弟子，全真七子之首，丹陽子馬鈺馬真人。\n"
                "他慈眉善目，和藹可親，正笑着看着你。\n"
                "你可以向他要求全真令挑戰你的師尊。\n");
        set("attitude", "peaceful");
        set("shen_type",1);
        set("str", 28);
        set("int", 32);
        set("con", 31);
        set("dex", 30);

        set("title","全真七子之首");

//       set("env/wimpy", 60);
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
        	(: exert_function, "powerup" :),
                (: exert_function, "recover" :),
                (: exert_function, "recover" :),
                (: perform_action, "strike.ju" :),                
                (: perform_action, "whip.wuguang" :),                                
                (: perform_action, "sword.ding" :),
                (: perform_action, "sword.sanqing" :),  
		(: command("wield changjian") :),
        }));

        set("qi", 4000);
        set("max_qi", 4000);
        set("jing", 1600);
        set("max_jing", 1600);
        set("neili", 6000);
        set("max_neili", 6000);
        set("jiali", 100);

        set("combat_exp", 500000);
        set("score", 300000);

        set_skill("array", 100);
        set_skill("force", 150);
        set_skill("xiantian-qigong", 150);    //先天氣功
        set_skill("sword", 140);
        set_skill("quanzhen-jian",210);  //全真劍
        set_skill("dodge", 120);
        set_skill("jinyan-gong", 180);   //金雁功
        set_skill("parry", 150);
        set_skill("unarmed", 140);
        set_skill("strike", 120);
        set_skill("haotian-zhang", 180);    //昊天掌
        set_skill("cuff", 120);
        set_skill("chunyang-quan", 180);    //純陽拳
        set_skill("whip", 120);
        set_skill("duanyun-bian", 180);    //斷雲拳
        set_skill("literate", 100);
        set_skill("taoism", 110);

        map_skill("force", "xiantian-qigong");
        map_skill("sword", "quanzhen-jian");
        map_skill("dodge", "jinyan-gong");
        map_skill("parry", "duanyun-bian");
        map_skill("whip", "duanyun-bian");
        map_skill("strike", "haotian-zhang");
        map_skill("cuff", "chunyang-quan");
        prepare_skill("cuff", "chunyang-quan");
        prepare_skill("strike", "haotian-zhang");

        create_family("全真教", 2, "弟子");

        set("book_count",1);
        set("shu_count",1);
        set("inquiry", ([
                "全真教" :  "我全真教是天下道家玄門正宗。\n",
                "全真令" :  (: ask_ling :),
                "升級"   :  (: ask_ling :),
                "金雁功" :   (: ask_me :),
                "金雁圖譜" : (: ask_me :),
                "天罡北斗陣" : (: ask_array :),
                "北斗七星陣" : (: ask_array :),
                "祕籍"      : (: ask_shu :),
                "鞭法總訣"   : (: ask_shu :),
                "shu" : (: ask_shu :),
                ]) );

        setup();

        carry_object("/clone/weapon/changbian")->wield();
        carry_object("/clone/weapon/changjian");
        carry_object(__DIR__"obj/greenrobe")->wear();
}

string ask_me()
{
        mapping fam;
        object ob;

        if (!(fam=this_player()->query("family"))||fam["family_name"]!="全真教")
                return RANK_D->query_respect(this_player()) +
                "與本教毫無瓜葛，我教的武功典籍可不能交給你。";
        if (query("book_count") < 1)
                return "你來晚了，金雁圖譜已經被人取走了。";
        add("book_count", -1);
        ob = new("/clone/book/jinyantu");
        ob->move(this_player());
        return "好吧，這本「金雁圖譜」你拿回去好好研讀。";
}

string ask_shu()
{
	object ob;
	
	if (this_player()->query("family/master_id")!="ma yu")
		return RANK_D->query_respect(this_player()) + 
		"非我弟子，不知此話從何談起？";
	if (query("shu_count") < 1)
		return "你來晚了，本派的祕籍不在此處。";
	add("shu_count", -1);
	ob = new("/clone/book/whip");
	ob->move(this_player());
	command("rumor "+this_player()->query("name")+"拿到鞭法總訣啦。\n");
	return "好吧，這本「鞭法總訣」你拿回去好好鑽研。";
}

string ask_ling()
{
	mapping fam, skl; 
	object ob, me = this_player();
	string *skillname;
	int i;
	
	if (!(fam = me->query("family")) || fam["family_name"] != "全真教")
		return RANK_D->query_respect(me) + 
		"與本教毫無瓜葛，不知此話從何談起？";

	skl = me->query_skills();
	skillname  = sort_array( keys(skl), (: strcmp :) );

	for(i=0; i<sizeof(skl); i++) {
		if (skl[skillname[i]] < 30) 
		return RANK_D->query_respect(me) + "功力不夠，不能領取全真令。";
	}

	ob = new("/d/quanzhen/obj/quanzhen-ling");
	ob->move(me);
	message_vision("$N獲得一面全真令。\n", me);

	return "好吧，憑這面全真令，你可自由向你的師尊挑戰。";
}

string ask_array()
{
	object room, qizi, obj, ob = this_player(), me = this_object();
	mapping ob_fam, skl; 
	string *skillname;
	int i;

	ob_fam  = ob->query("family");
	skl = ob->query_skills();

	if (sizeof(skl) <= 1)
		return RANK_D->query_respect(ob) + 
		"功力不夠，不夠資格闖天罡北斗陣。";
	if (ob->query("score") < 20000)
	        return RANK_D->query_respect(ob) + 
		"閱歷不足，不夠資格闖天罡北斗陣。";

	skillname  = keys(skl);
	for(i=0; i<sizeof(skl); i++) {
		if ((skl[skillname[i]] < 80) || (sizeof(skl) == 0))
		return RANK_D->query_respect(ob) + 
		"功力不夠，不夠資格闖天罡北斗陣。";
	}
	if( ob->query("qixing") )
		return RANK_D->query_respect(ob) + 
		"已然闖過天罡北斗陣，可不要拿老道開這等玩笑。";
/*
	if ( ob_fam["family_name"] != "全真教" || ob_fam["generation"] != 3)
		return RANK_D->query_respect(ob) + "，你沒資格闖天罡北斗陣。";
*/
	if ( me->query("assigned_qixing") )
		return RANK_D->query_respect(ob) + "，今日有人挑戰天罡北斗陣，你過一段時間再來吧。";

	me->set("assigned_qixing", ob->query("id")); 		
	command("smile");
	say("\n馬鈺道長說道：好吧，我去召集衆師弟。稍候在大校場上等你。\n");
        message_vision("\n馬鈺道長往南離開。\n\n", ob);

/* 譚處端 */
	if(!( room = find_object("/d/quanzhen/rongwutang")) )
		room = load_object("/d/quanzhen/rongwutang");
  		me->move(room);
	if( !objectp(obj = present("tan chuduan", room) ))
	{
		me->move("/d/quanzhen/shiweishi");
		message_vision("\n馬鈺道長走了過來。\n\n", ob);
		return "真是對不起，全真七子有人不在，無法布天罡北斗陣。\n";	
	}
	message("vision","\n馬鈺道長走了過來，跟譚處端說了幾句。\n", room, obj);
	obj->move("/d/quanzhen/daxiaochang");
	message("vision", "譚處端點了點頭，快步跟了出去。\n", room, obj);

/* 劉處玄 */
	if(!( room = find_object("/d/quanzhen/jingxiushi")) )
		room = load_object("/d/quanzhen/jingxiushi");
  		me->move(room);
	if( !objectp(obj = present("liu chuxuan", room) ))
	{
		me->move("/d/quanzhen/shiweishi");
		message_vision("\n馬鈺道長走了過來。\n\n", ob);
		return "真是對不起，全真七子有人不在，無法布天罡北斗陣。\n";	
	}
	message("vision","\n馬鈺道長走了過來，跟劉處玄說了幾句。\n", room, obj);
	obj->move("/d/quanzhen/daxiaochang");
	message("vision", "劉處玄點了點頭，快步跟了出去。\n", room, obj);

/* 丘處機 */
	if(!( room = find_object("/d/quanzhen/laojundian")) )
		room = load_object("/d/quanzhen/laojundian");
  		me->move(room);
	if( !objectp(obj = present("qiu chuji", room) ))
	{
		me->move("/d/quanzhen/shiweishi");
		message_vision("\n馬鈺道長走了過來。\n\n", ob);
		return "真是對不起，全真七子有人不在，無法布天罡北斗陣。\n";	
	}
	message("vision","\n馬鈺道長走了過來，跟丘處機說了幾句。\n", room, obj);
	obj->move("/d/quanzhen/daxiaochang");
	message("vision", "丘處機點了點頭，快步跟了出去。\n", room, obj);

/* 王處一 */
	if(!( room = find_object("/d/quanzhen/wanwutang")) )
		room = load_object("/d/quanzhen/wanwutang");
  		me->move(room);
	if( !objectp(obj = present("wang chuyi", room) ))
	{
		me->move("/d/quanzhen/shiweishi");
		message_vision("\n馬鈺道長走了過來。\n\n", ob);
		return "真是對不起，全真七子有人不在，無法布天罡北斗陣。\n";	
	}
	message("vision","\n馬鈺道長走了過來，跟王處一說了幾句。\n", room, obj);
	obj->move("/d/quanzhen/daxiaochang");
	message("vision", "王處一點了點頭，快步跟了出去。\n", room, obj);

/* 郝大通 */
	if(!( room = find_object("/d/quanzhen/guangning")) )
		room = load_object("/d/quanzhen/guangning");
  		me->move(room);
	if( !objectp(obj = present("hao datong", room) ))
	{
		me->move("/d/quanzhen/shiweishi");
		message_vision("\n馬鈺道長走了過來。\n\n", ob);
		return "真是對不起，全真七子有人不在，無法布天罡北斗陣。\n";	
	}
	message("vision","\n馬鈺道長走了過來，跟郝大通說了幾句。\n", room, obj);
	obj->move("/d/quanzhen/daxiaochang");
	message("vision", "郝大通點了點頭，快步跟了出去。\n", room, obj);

/* 孫不二 */
	if(!( room = find_object("/d/quanzhen/qingjing")) )
		room = load_object("/d/quanzhen/qingjing");
  		me->move(room);
	if( !objectp(obj = present("sun buer", room) ))
	{
		me->move("/d/quanzhen/shiweishi");
		message_vision("\n馬鈺道長走了過來。\n\n", ob);
		return "真是對不起，全真七子有人不在，無法布天罡北斗陣。\n";	
	}
	message("vision","\n馬鈺道長走了過來，跟孫不二說了幾句。\n", room, obj);
	obj->move("/d/quanzhen/daxiaochang");
	message("vision", "孫不二點了點頭，快步跟了出去。\n", room, obj);
	ob->set_temp("pre_qixing", 1);

        me->move("/d/quanzhen/daxiaochang");
        call_out("waiting", 1, me,1);
	return "好！大家都出來了。\n";
}

int waiting(object me,int wait_time)
{
	object ob;

	if( wait_time == 300 )
	{
		say( "馬鈺說道：看來他不會來了，我們回去罷！\n\n");
		call_out("do_back", 0, me);
		ob->add("score",-5000);				
	}
	else if(!objectp(ob = present(me->query("assigned_qixing"),environment(me))))
	{
		wait_time++;
		call_out("waiting", 1, me,wait_time);
	}
	else call_out("preparing", 0, me, ob);

	return 1;
}

int preparing(object me, object ob)
{
	object *obs, room, obj1, obj2, obj3, obj4, obj5, obj6;
	string myname = me->query("name");
	int i;

	if(!( room = find_object("/d/quanzhen/daxiaochang")) )
	room = load_object("/d/quanzhen/daxiaochang");
	if(!objectp( obj1 = present("tan chuduan", environment(me))))
		return notify_fail("二師弟怎麼不在？\n");
	if(!objectp( obj2 = present("liu chuxuan", environment(me))))
		return notify_fail("三師弟怎麼不在？\n");
	if(!objectp( obj3 = present("qiu chuji", environment(me))))
		return notify_fail("四師弟怎麼不在？\n");
	if(!objectp( obj4 = present("wang chuyi", environment(me))))
		return notify_fail("五師弟怎麼不在？\n");
	if(!objectp( obj5 = present("hao datong", environment(me))))
		return notify_fail("六師弟怎麼不在？\n");
	if(!objectp( obj6 = present("sun buer", environment(me))))
		return notify_fail("小師妹怎麼不在？\n");

	me->dismiss_team();
	me->set_leader();
	me->add_team_member(obj1);
	me->add_team_member(obj2);
	me->add_team_member(obj3);
	me->add_team_member(obj4);
	me->add_team_member(obj5);
	me->add_team_member(obj6);

	say( "馬鈺說道：不相干的人，如不欲觀摩天罡北斗陣，請即刻離開。\n");


  obs=me->query_team();
	for(i=0;i<sizeof(obs);i++)
	{
		ob->fight_ob(obs[i]);
		obs[i]->fight_ob(ob);
		if(obs[i] != me)
			message_vision(myname+"道："+obs[i]->query("name")+"請做好準備！\n",me);
	}
//	command("say chat " + ob->query("title") + ob->query("name") + 
//		"於今日" + NATURE_D->game_time() + "挑戰全真天罡北斗陣！\n");
	message("channel:snow", HIC"【闖陣】馬鈺[Ma yu]：" + ob->query("title") + ob->query("name") + 
		HIC+"於今日" + NATURE_D->game_time() + "挑戰全真天罡北斗陣！\n"NOR,users());
	say(HIC"馬鈺吟道：“一住行窩幾十年。”\n");
	say("譚處端吟道：“蓬頭長日走如顛。”\n");
	say("劉處玄吟道：“海棠亭下重陽子。”\n");
	say("丘處機接口道：“蓮葉舟中太乙仙。”\n");
	say("王處一吟道：“無物可離虛殼外。”\n");
	say("郝大通吟道：“有人能悟未生前。”\n");
	say("孫不二吟道：“出門一笑無拘礙。”\n");
	say("馬鈺收句道：“雲在西湖月在天！”\n\n\n"NOR);

	message_vision(myname+ "清了清喉嚨，大聲說道：好，時辰已到，現在開始啓動「天罡北斗陣」！\n",me);
	message_vision(myname+ "突然身形移動，發動衆全真弟子搶佔位置，左邊四人，右邊三人，正是擺的「天罡北斗陣」陣法。\n",me);
	say("馬鈺位當天樞，譚處端位當天璇，劉處玄位當天璣，丘處機位當天權，四人組成斗魁；\n");
	say("王處一位當玉衡，郝大通位當開陽，孫不二位當搖光，三人組成斗柄。\n");
	remove_call_out("do_qixing");
	call_out("do_qixing", 2, me, ob);
	return 1;
}


int do_qixing(object me, object en)
{
	object *obs, weapon, enweapon;
	int i, j, power;
	string err;
	string *where = ({
		"天樞",
		"天璇",
		"天璣",
		"天權",
		"玉衡",
		"開陽",
		"搖光"
	});

	if(pointerp(obs=me->query_team()) )
	switch (random (4))
	{
		case 0:
message_vision("天罡北斗陣氣勢宏大，前攻後擊，連環相接，讓人眼花撩亂，方寸頓失。\n",me);
			break;
		case 1:
message_vision("天罡北斗陣法滾滾推動，攻勢連綿不絕，瞬間將敵人圍在垓心。\n",me);
			break;
		case 2:
message_vision("天罡北斗陣越縮越小，無形劍氣象浪潮一般逼向中央，令人有窒息之感。\n",me);
			break;
		case 3:
message_vision("只見天罡北斗陣暗合五行八卦之理，陣中人步法精妙，攻守配合得天衣無縫，威力之大，讓人歎爲觀止。\n",me);
			break;
	}
	for(i=0;i<sizeof(obs);i++)
	{
		weapon = obs[i]->query_temp("weapon");
		power = obs[i]->query_skill("force",1)/10;
	  obs[i]->add_temp("apply/attack", power);
	  obs[i]->add_temp("apply/damage", power);
		switch (random(2))
		{
			case 0:
message_vision("\n"+where[i]+"位上的"+obs[i]->query("name")+ "氣沉丹田，暗運神功，猛然吐氣開聲，身形往前一縱, 但見", me);
				break;
			case 1:
message_vision("\n"+where[i]+"位上的"+obs[i]->query("name")+ "挺身而出，步法精妙，長袖飄飄，攻勢如虹。只見", me);
				break;
//	               default:
		}
	  err=catch(COMBAT_D->do_attack(obs[i],en,weapon,0));
	  if (err)
	  {
		  message("channel:debug","天罡北斗陣攻擊出錯 err="+err,users());
	  	return 1;
	  }
		obs[i]->add_temp("apply/attack", -power);
		obs[i]->add_temp("apply/damage", -power);
		if(en->query("qi")*2 <= en->query("max_qi"))
		{
			en->remove_all_enemy();
			remove_call_out("do_end");
			call_out("do_end", 1, me, en, 0);
			return 1;
		}
	}
	j = random(sizeof(me->query_team()));
	enweapon = en->query_temp("weapon");
	if (enweapon)
  	COMBAT_D->do_attack(en,obs[j], enweapon);
	else 
  	COMBAT_D->do_attack(en,obs[j], enweapon);
	if(obs[j]->query("qi")*2 <= obs[j]->query("max_qi"))
	{
		message_vision(HIR+obs[j]->query("name")+"一跤趴在地上，摔出北斗陣。\n"NOR,me);
		en->remove_all_enemy();
		remove_call_out("do_end");
		call_out("do_end", 1, me, en, 1);
		return 1;
	}
	else if(obs[j]->query("qi")*3 <= obs[j]->query("max_qi")*2)
	{
		message_vision(obs[j]->query("name")+ "踉蹌了一步，差點摔出北斗陣。\n",me);
	}
	else if(obs[j]->query("qi")*5 <= obs[j]->query("max_qi")*4)
		message_vision(obs[j]->query("name")+"被打得晃了幾晃，不過又站穩了步子。\n",me);

	remove_call_out("do_qixing");
	call_out("do_qixing", 1, me, en);
	return 1;
}
int do_end(object me, object en, int result)
{
	if( result == 1)
	{
		if(en->query_temp("pre_qixing"))
		{
			en->set("qixing", 1);
		}
		en->delete_temp("pre_qixing");
		en->add("combat_exp",50000);
		en->add("score",30000);
		en->add("potential",10000);	
		message_vision(HIR"\n天罡北斗陣被"+en->query("name")+"打破了。\n\n"NOR,me);
		message("channel:snow", HIR"【通告】"HIY + en->query("name")+"打破天罡北斗陣了！\n"NOR, users());
	}
	else
	{
		en->delete_temp("pre_qixing");
		message("channel:snow", HIR"【通告】"HIY + en->query("name")+"沒能闖出天罡北斗陣！\n"NOR, users());
    message_vision(HIR"\n$N笑了笑：天罡北斗陣不愧爲全真鎮教之寶。\n"NOR,me);
		en->add("score",-3000);	   
	}
	remove_call_out("do_back");
	call_out("do_back", 1, me);
	return 1;
}
int do_back(object me)
{
	object *obs, weapon;
	int i;

	if(pointerp(obs=me->query_team()) )
	{
		for(i=0;i<sizeof(obs);i++)
		{
			if (objectp(weapon = obs[i]->query_temp("weapon"))
				&& (string)weapon->query("skill_type")=="sword")
message_vision("$N身子向後一縱，使一招『收劍式』，將劍挽了一個劍花，往懷中一抱，退出「天罡北斗陣」。\n", obs[i]);
			else
message_vision("$N身子向後一縱，使一招『收山式』，右拳劃了一圈，左掌往懷中一抱，退出「天罡北斗陣」。\n", obs[i]);

message_vision("$N作了個楫道：貧道先告退了！說完就快步離開了。\n", obs[i]);
			if (obs[i]->query("name")== "馬鈺")
				obs[i]->move("/d/quanzhen/shiweishi");
			if (obs[i]->query("name")== "譚處端")
				obs[i]->move("/d/quanzhen/rongwutang");
			if (obs[i]->query("name")== "劉處玄")
				obs[i]->move("/d/quanzhen/jingxiushi");
			if (obs[i]->query("name")== "丘處機")
				obs[i]->move("/d/quanzhen/laojundian");
			if (obs[i]->query("name")== "王處一")
				obs[i]->move("/d/quanzhen/wanwutang");
			if (obs[i]->query("name")== "郝大通")
				obs[i]->move("/d/quanzhen/guangning");
			if (obs[i]->query("name")== "孫不二")
				obs[i]->move("/d/quanzhen/qingjing");
		}
	}///d/quanzhen/shiweishi
	me->dismiss_team();
}

#include "chu.h";
