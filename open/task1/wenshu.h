// Room: /d/city/wenshu.h

#include <ansi.h>

void init()
{
        call_out("dest", 1800);
	add_action("do_guankan", ({"guankan","kan"}));
	add_action("do_wancheng", ({"wancheng"}));
}

int do_guankan(string arg)
{
	int now_time, time;
	object me;

	me = this_player();
	now_time = me->query_condition("guanfu_task"); 
	time = me->query_temp("guanfu_time");

	if(!arg) return 0;
	if( arg=="wenshu" )
	{
		write( "\n這是一張揚州知府懸賞捉拿江洋大盜的文書，上面栩栩如生的畫着一個\n人的頭像，下面有一行小字，上面寫着：\n“江洋大盜「"+me->query_temp("guanfu_targetnm")+"」，懸賞捉拿”。\n據飛鴿傳書，該犯目前出沒於「"+me->query_temp("ch_weizhi")+"」附近。\n");
		if(now_time>time*3/4) write("你現在有充足的時間去尋找目標。\n");
		if(now_time>time/2 && now_time<=time*3/4 ) write("已經過去一小半時間了。\n");
		if(now_time>time/4 && now_time<=time/2 ) write("你還有一半的時間去追蹤目標。\n");
		if(now_time>time/8 && now_time<=time/4 ) write("你的時間已經不多了。\n");
		if(now_time>0 && now_time<=time/8) write("官府好象已經快有新的目標了，你要抓緊時間了！\n");
		return 1;
	}
}

int do_wancheng(string arg)
{
//	object ob;
	object me, target;
	int exp,pot,gfjob_times,now_time;

	if(!arg) return notify_fail("你要幹什麼？\n");
	me = this_player();
	target = present(arg, environment(me));
	now_time = me->query_condition("guanfu_task");

	if(!target) return notify_fail("找不到這個東西。\n");
	if(target->query("id") != "corpse") return notify_fail("你並沒有完成任務。\n");
	if(target->query("victim_id") != me->query_temp("guanfu_target"))
		return notify_fail("那個並不是目標！\n");
	if(target->query("victim_user"))
		return notify_fail("嘿嘿，想作弊？！\n");
	if(target->query("kill_by") != me)
		return notify_fail("你晚了一步，目標已經被人殺了。\n");
        if(target->query_temp("mark/dune1"))
		return notify_fail("那已經是一具已經被人殺過的屍體了。\n");

	me->add("gf_job",1);
	gfjob_times=(int)me->query("gf_job");
	if (gfjob_times < 1) gfjob_times = 1;
	message_vision(HIW "$N冷笑一聲，從懷中掏出文書看了看，微運內勁將文書向空中飛射出去。\n但見文書化做片片雪片，飛落在$n身上。\n"NOR, me, target);
	write(WHT "很好！你成功地完成了任務。目前你已經爲官府做了"+chinese_number(gfjob_times)+"次貢獻。\n"NOR);
	target->set("long", target->query("long")+"上面飛落着許多紙片。\n");
        target->set_temp("mark/dune1",1);
//	if(me->query("potential") > me->query("max_pot")) 
//	me->set("potential", me->query("max_pot"));
	me->delete_temp("guanfu_time");
	me->clear_condition("guanfu_task");
	me->delete_temp("guanfu_target");
	me->delete_temp("guanfu_targetnm");
	me->delete_temp("ch_weizhi");
	me->delete_temp("path_rooms");
	me->delete_temp("gstart_rooms");
	me->delete_temp("mark/gkill3");


/*	if ((int)me->query("combat_exp")<120000)
	{
		pot=50+random(me->query("max_pot")*3/2);
                pot=200+random(100);                
		if (pot > 180) pot =180;
		exp=((1+random(3))*90); 
		me->add("potential",pot);
		me->add("combat_exp",exp);
		destruct(this_object());
		return 1;
	}
	if ((int)me->query("combat_exp")>120000 && 
		me->query("combat_exp")<380000)
	{
		pot=60+random(me->query("max_pot"));
		       if (pot >150) pot =150;
		exp=((1+random(3))*100); 
		me->add("potential",pot);
		me->add("combat_exp",exp);
		destruct(this_object());
		return 1;
	}
	if ((int)me->query("combat_exp")>380000 && 
		me->query("combat_exp")<780000)
	{
		pot=60+random(me->query("max_pot")*3/2);
		if (pot > 180) pot =180;
		exp=((2+random(3))*90); 
		me->add("potential",pot);
		me->add("combat_exp",exp);
		destruct(this_object());
		return 1;
	}
	if ((int)me->query("combat_exp")>780000 && 
		me->query("combat_exp")<1000000)
	{
		pot=60+random(me->query("max_pot")*3/2);
		if (pot > 200) pot =200;
		exp=((2+random(3))*90); 
		me->add("potential",pot);
		me->add("combat_exp",exp);
		destruct(this_object());
		return 1;
	}
	pot=60+random(me->query("max_pot")*3/2);
	if (pot > 200) pot =200;
	exp=((1+random(4))*100); */
//調高一些獎勵 	
	pot=250+random(100);
	if (pot > 300) pot = 300;
	exp=800+random(400);
	if (exp > 1000) exp=1000;
	me->add("potential",pot);
	me->add("combat_exp",exp);
	me->add("gf_job",1);	
	write(HIW"你被獎勵了：\n" + 
	       chinese_number(exp) + "點實戰經驗\n" +
	       chinese_number(pot) + "點潛能\n"NOR);
	destruct(this_object());       
	return 1;	

}

void dest()
{
	object me = this_player();
	write("文書已經被你揉的模糊不清了，看來已經沒什麼用了，你只好隨手丟掉。\n", me);  
	destruct(this_object());
}
