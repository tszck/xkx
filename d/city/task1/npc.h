// Room: /d/city/npc.c

#include <ansi.h>

mapping *dizhia=({
	(["cdizhi":	"白駝山",
	"weizhi2" :	"/d/baituo/cao1",]),
	(["cdizhi":	"長城",
	"weizhi2" :	"/d/changcheng/changcheng13",]),
	(["cdizhi":	"揚州城",
	"weizhi2" :	"/d/city/bingyin",]),
	(["cdizhi":	"北京城",
	"weizhi2" :	"/d/beijing/huayuan",]),
	(["cdizhi":	"成都城",
	"weizhi2" :	"/d/chengdu/wuhouci",]),
	(["cdizhi":	"長安城",
	"weizhi2" :	"/d/changan/chaguan",]),
	(["cdizhi":	"大理城",
	"weizhi2" :	"/d/dali/tingyuan",]),
	(["cdizhi":	"峨嵋山",
	"weizhi2" :	"/d/emei/jieyindian",]),
	(["cdizhi":	"佛山鎮",
	"weizhi2" :	"/d/foshan/street4",]),
	(["cdizhi":	"福州城",
	"weizhi2" :	"/d/fuzhou/luoxingta",]),
	(["cdizhi":	"關外",
	"weizhi2" :	"/d/guanwai/xuedi2",]),
	(["cdizhi":	"杭州城",
	"weizhi2" :	"/d/hangzhou/shiwudong",]),
	(["cdizhi":	"黑木崖",
	"weizhi2" :	"/d/heimuya/shijie2",]),
	(["cdizhi":	"恆山",
	"weizhi2" :	"/d/hengshan/yuyang",]),
	(["cdizhi":	"衡山",
	"weizhi2" :	"/d/henshan/nantaisi",]),
	(["cdizhi":	"黃河",
	"weizhi2" :	"/d/huanghe/weifen",]),
	(["cdizhi":	"華山",
	"weizhi2" :	"/d/huashan/yunuci",]),
	(["cdizhi":	"江陵城",
	"weizhi2" :	"/d/jiangling/longzhong",]),
	(["cdizhi":	"嘉興城",
	"weizhi2" :	"/d/jiaxing/njroad2",]),
	(["cdizhi":	"崑崙山",
	"weizhi2" :	"/d/kunlun/jiuqulang2",]),
	(["cdizhi":	"蘭州城",
	"weizhi2" :	"/d/lanzhou/street1",]),
	(["cdizhi":	"靈鷲峯",
	"weizhi2" :	"/d/lingjiu/jian",]),
	(["cdizhi":	"靈州城",
	"weizhi2" :	"/d/lingzhou/kongdi",]),
	(["cdizhi":	"洛陽城",
	"weizhi2" :	"/d/luoyang/wanghuating",]),
	(["cdizhi":	"光明頂",
	"weizhi2" :	"/d/mingjiao/tohsq1",]),
	(["cdizhi":	"祁連山",
	"weizhi2" :	"/d/qilian/zhutishan",]),
	(["cdizhi":	"青城山",
	"weizhi2" :	"/d/qingcheng/huyingting",]),
	(["cdizhi":	"嵩山",
	"weizhi2" :	"/d/songshan/junjigate",]),
	(["cdizhi":	"蘇州城",
	"weizhi2" :	"/d/suzhou/liuyuan",]),
	(["cdizhi":	"泰山",
	"weizhi2" :	"/d/taishan/tianjie",]),
	(["cdizhi":	"天龍寺",
	"weizhi2" :	"/d/tianlongsi/tading",]),
	(["cdizhi":	"鐵掌峯",
	"weizhi2" :	"/d/tiezhang/guangchang",]),
	(["cdizhi":	"華山村",
	"weizhi2" :	"/d/village/wexit",]),
	(["cdizhi":	"萬劫谷",
	"weizhi2" :	"/d/wanjiegu/port2",]),
	(["cdizhi":	"五毒教",
	"weizhi2" :	"/d/wudujiao/wdsl2",]),
	(["cdizhi":	"無量山",
	"weizhi2" :	"/d/wuliang/road4",]),
	(["cdizhi":	"無錫城",
	"weizhi2" :	"/d/wuxi/road15",]),
	(["cdizhi":	"襄陽城",
	"weizhi2" :	"/d/xiangyang/walle3",]),
	(["cdizhi":	"星宿海",
	"weizhi2" :	"/d/xingxiu/shidao",]),
	(["cdizhi":	"雪域",
	"weizhi2" :	"/d/xuedao/shandong2",]),
	(["cdizhi":	"大輪寺",
	"weizhi2" :	"/d/xueshan/zoulang2",]),
	(["cdizhi":	"燕子塢",
	"weizhi2" :	"/d/yanziwu/qiushuan",]),
	(["cdizhi":	"泉州",
	"weizhi2" :	"/d/quanzhou/jiangjunfu1",]),
	(["cdizhi":	"漠北",
	"weizhi2" :	"/d/mobei/caocong1",]),
});

void init()
{
	object ob, me;
	mapping dizhis,hp_status;
	int exp, nei, nei1;

	::init();
     if (!query("inited"))
      {
         set("chat_chance", 10);
    	   set("chat_msg", ({
   		   (: random_move :)
	                  }) );
   		   remove_call_out("dest");
         call_out("dest",2000);
         set("inited",1);
      }
	ob = this_player();
  me = this_object();

	if (interactive(ob)
		&& !environment(ob)->query("no_fight")
//		&& ob->query_condition("guanfu_task")
		&& present("wenshu", ob)
		&& (string)me->query("id") == ob->query_temp("guanfu_target"))
	{
	nei = me->query("neili",1);
	nei1 = ob->query("neili",1);
	hp_status = ob->query_entire_dbase();

	dizhis = dizhia[random(sizeof(dizhia))];
	exp = ob->query("combat_exp");

///第一次追殺
	if (ob->query_temp("mark/gkill1") )
	{
	  message_vision( HIR"$n看到$N目光冷冷注視着自己一動不動，不由停下了腳步。\n"NOR, ob, me);
	 if ((string)me->query("name") == ob->query_temp("guanf_huida1"))
		{
			message_vision( HIR"$n看到$N走到近前，狠狠的罵道，不識抬舉的東西，我好言相勸沒用，\n今天就讓你嚐嚐大爺的厲害。\n"NOR,ob,me);
			me->set_leader(ob);
			remove_call_out("kill_ob");
			call_out("kill_ob", 0, ob);
			ob->delete_temp("guanf_huida1");
			ob->delete_temp("mark/gkill1");

			if ((int)exp<3000000)
			    me->set("combat_exp",exp*3/2);
			else
			    me->set("combat_exp",exp*2);
     if ((hp_status["max_qi"]*3/2)<1500)
     {
        me->set("max_qi", 1500);
        me->set("eff_qi", 1500);
        me->set("qi",     1500);
     }
     else
	   {
	      me->set("max_qi", hp_status["max_qi"]*3/2);
	      me->set("eff_qi", hp_status["max_qi"]*3/2);
	      me->set("qi",     hp_status["max_qi"]*3/2);
	   }

     if ((hp_status["max_neili"])<1500)
        me->set("max_neili",1500);
     else
        me->set("max_neili", hp_status["max_neili"]);

     if((hp_status["neili"])<1500)
        me->set("neili",1500);
     else
        me->set("neili", hp_status["neili"]);
	   me->set("jiali",nei1/20);
	 }
   else
   {

			switch(random(4))
			{
				case 0:
					message_vision("$n嘿嘿奸笑幾聲，連忙賠笑道，這位"+RANK_D->query_respect(ob)+ "是官府的捕頭吧？！大家都是武林中人，今天能否高抬貴手？我必有重謝！你好好斟酌一下，是否願意？\n",ob,me);
					write (HIY"你可以選擇同意(yes)或者拒絕(no)。\n"NOR);
					ob->set_temp("guanf_huida1", me->query("name"));
					break;
				case 1:
					message_vision( HIR"$n陰笑一聲説道，這麼多不怕死的？再來十個大爺我也不怕！\n隨即眼睛一瞪，向着$N就衝了過去！\n"NOR,ob,me);
					me->set_leader(ob);
					remove_call_out("kill_ob");
					call_out("kill_ob", 0, ob);
					ob->delete_temp("mark/gkill1");
					break;
				case 2:
					message_vision( WHT"$n待$N走到近前，冷冷一笑，説道，你千里追到這裏，我看你又能奈我何！\n"NOR,ob,me);
					write(WHT"你感到一股無形的殺氣，心中不由一顫。\n"NOR);
					ob->delete_temp("mark/gkill1");
					break;
				case 3:
					message_vision("$n忽然淚流滿面，一幅可憐的神情對$N説道，小人上有老下有小，而且完全是官府被\n陷害才落此地步，望你老明察秋毫，網開一面，我今生一定感激不盡。\n",ob,me);
					ob->delete_temp("mark/gkill1");
			}
		}
	}
// end///  第二次追殺
		if (ob->query_temp("mark/gkill2"))
		{
			switch(random(2))
			{
				case 0:
					message_vision( HIR"$n額頭青筋跳動，冷哼了一聲，瞪着通紅的眼睛向着$N就衝了過去。\n"NOR, ob,me);
					me->set_leader(ob);
					if ((int)exp<3000000)
			                   me->set("combat_exp",exp*3/2);
			                else
			                   me->set("combat_exp",exp*2);
			                me->set("jiali",nei1/15);
					remove_call_out("kill_ob");
					call_out("kill_ob", 0, ob);
					break;
				case 1:
					message_vision( HIY"$n一看到$N，嘿嘿一笑，頭也不回擠進行人之中，腳下抹油溜了。\n"NOR,ob,me);
					ob->delete_temp("mark/gkill2");
					ob->set_temp("mark/gkill3",1);
					write(WHT"「"+ob->query_temp("guanfu_targetnm")+"」好象往「"+dizhis["cdizhi"]+"」的方向逃去了。\n"NOR);
					me->move(dizhis["weizhi2"]);
					me->random_move();
					me->random_move();
					me->random_move();
					return;
			}
		}
		//第三次
		if (ob->query_temp("mark/gkill3"))
		{
			message_vision(HIR "$n氣急敗壞的對$N嚷道，殺人不過頭點地，你一再苦苦相逼，大爺今天就和你拼個魚死網破。\n"NOR,ob,me);
			if(nei<nei1&& (!me->query_temp("gf_nlset")))
			{
				me->set("max_neili",ob->query("max_neili"));
				me->set("neili",nei1);
				me->set_temp("gf_nlset",1);
			}
			me->set_leader(ob);
			remove_call_out("kill_ob");
			call_out("kill_ob", 0, ob);
			if ((int)exp<3000000)
			    me->set("combat_exp",exp*3/2);
			else
			    me->set("combat_exp",exp*2);
			me->set("jiali",nei1/15);
			me->reincarnate();
		}
	}
	add_action("do_yes","yes");
  add_action("do_no","no");

//	call_out("dest", 2000);
/*        add_action("do_hit","hit");
        add_action("do_hit","kill");
        add_action("do_hit","touxi");
        add_action("do_hit","ansuan");
        add_action("do_hit","steal");
*/
}

/*int do_hit(string arg)
{
        object ob = this_object();
        object me = this_player();
        if (!arg || arg != ob->query("id"))
                return 0;

        if (!(me->query_temp("guanfu_target")==ob->query("id")))
        {
                if (userp(me) )
                {
                        tell_object(me,HIW"不是你要抓的人，湊什麼熱鬧！\n"NOR);
                        return 1;
                }
                else return 0;
        }
}*/
int accept_hit(object who)
{
	object me = this_player();
	object ob = this_object();
	if (!(me->query_temp("guanfu_target")==ob->query("id")))
		return notify_fail(HIW"不是你要抓的人，湊什麼熱鬧！\n"NOR);
    return 1;
}

int accept_kill(object who)	{return accept_hit(who);}
int accept_ansuan(object who) {return accept_hit(who);}
int accept_touxi(object who)	{return accept_hit(who);}


void random_move()
{
/*        mapping exits;
        string *dirs, dir, dest;

        if( !mapp(exits = environment()->query("exits")) ) return 0;
        dirs = keys(exits);
        dir = dirs[random(sizeof(dirs))];
        dest = exits[dir];
        if (!find_object(dest)) load_object(dest);
        if( find_object(dest)->query("no_fight")) return 0;
        if( this_object()->is_fighting() ) return 0;
        command("go " + dir);
        return 1;
*/
	NPC_D->random_move(this_object());
}

int do_yes()
{
	object r_shen, me, ob;
	me = this_object();
	ob = this_player();

	if (!ob->query_temp("guanf_huida1")) return 0;
	if (ob->query_temp("guanf_huida1") != (string)me->query("name"))
		return 0;
	if ((int)ob->query("shen") < 1 && ob->query("combat_exp",1) < 180000)
	{
		command("say 這位"+RANK_D->query_respect(ob)+"一定前途遠大，嘿嘿，我是不會虧待你的。\n");
		me->add_money("gold",20+random(20));
		command("give "+ob->query("id")+" gold");
		message_vision("$N嘿嘿一笑，轉身離開，一眨眼就消失不見了。\n",me);
		destruct(me);
		return 1;
	}
	if ((int)ob->query("shen") < 1 &&
		ob->query("combat_exp",1) > 180000 &&
		ob->query("combat_exp",1) < 500000)
	{
		command("say 我早就看出這位"+RANK_D->query_respect(ob)+"是當世的俊傑，嘿嘿，這點小禮物請務必收下。\n");
		message_vision("$N嘿嘿奸笑兩聲，悄悄塞給了$n一棵人蔘。\n",me,ob);
		r_shen=new("/clone/medicine/vegetable/renshen");
		r_shen->move(ob);
		command("give "+ob->query("id")+" gold");
		message_vision("$N嘿嘿一笑，轉身離開，一眨眼就消失不見了。\n",me);
		destruct(me);
		return 1;
	}
	if ((int)ob->query("shen") < 1 && ob->query("combat_exp",1) > 500000)
	{
		command( "say 您老人家功夫如此出眾，小的實在想不出拿什麼孝敬您老，回頭我想起在説吧。\n");
		message_vision("$N嘿嘿一笑，轉身離開，一眨眼就消失不見了。\n",me);
		destruct(me);
		return 1;
	}
	if ((int)ob->query("shen") > 1 && ob->query("combat_exp",1) < 120000)
	{
		command("say 這位"+RANK_D->query_respect(ob)+"前途遠大，一身正氣，嘿嘿，佩服。\n");
		me->add_money("gold",20+random(30));
		command("give "+ob->query("id")+" gold");
		ob->add("shen",-1000);
		message_vision("$N嘿嘿一笑，轉身離開，一眨眼就消失不見了。\n",me);
		destruct(me);
		return 1;
	}
	if ((int)ob->query("shen") > 1 &&
		ob->query("combat_exp",1) > 120000 &&
		ob->query("combat_exp",1) < 500000)
	{
		command("say 這位"+RANK_D->query_respect(ob)+"真是義薄雲天，這個小禮物敬請務必收下。\n");
		me->add_money("gold",30+random(30));
		command("give "+ob->query("id")+" gold");
		message_vision("$N嘿嘿奸笑兩聲，悄悄塞給了$n一棵人蔘。\n",me,ob);
		r_shen=new("/clone/medicine/vegetable/renshen");
		r_shen->move(ob);
		ob->add("shen",-3000);
		message_vision("$N嘿嘿一笑，轉身離開，一眨眼就消失不見了。\n",me);
		destruct(me);
		return 1;
	}
	command("say 自古邪正勢不兩立，在下不過開個小小玩笑，千萬不要當真啊。\n");
	command("laugh " + ob->query("id"));
	write("對方好象在拿你取笑，你不由怒火中燒。\n");
	tell_room(environment(me), me->query("name")+"縱身跳入行人之中，轉眼就不見了。\n", ({me}));
	destruct(me);
	return 1;
}


int do_no()
{
	object me, ob;
	me = this_object();
	ob = this_player();

	if (!ob->query_temp("guanf_huida1")) return 0;
	if (ob->query_temp("guanf_huida1") != (string)me->query("name"))
		return 0;
	if ((int)ob->query("shen") < 1)
	{
		command("say 這位"+RANK_D->query_respect(ob)+"一身瘴氣，你我本是一路貨色，卻在這裏裝什麼俠義英雄呢？！\n");
		ob->delete_temp("guanf_huida1");
		ob->delete_temp("mark/gkill1");
		return 1;
	}
	command("say 這位"+RANK_D->query_respect(ob)+"一身正氣，不愧名門正派弟子，不過不知道功夫怎麼樣？！\n");
	command("hehe " + ob->query("id"));
	ob->delete_temp("guanf_huida1");
	ob->delete_temp("mark/gkill1");
	return 1;
}

void die()
{
	object ob, me,newob;
	mapping dizhis;

	ob = this_object();
	me = query_temp("last_damage_from");
	dizhis = dizhia[random(sizeof(dizhia))];

	if (!me->query_temp("mark/gkill3") &&
		!me->query_temp("mark/gkill2") &&
		(string)ob->query("id") == me->query_temp("guanfu_target"))
	{
		message_vision(WHT "$N深吸口氣，冷笑道：“好身手！”説完強忍傷痛縱身向「"+dizhis["cdizhi"]+"」處逃走。\n"NOR,ob,me);
		me->set_temp("mark/gkill2",1);
//		message_vision(WHT"「"+ob->query_temp("guanfu_targetnm")+"」好象往「"+dizhis["cdizhi"]+"」的方向逃去了。\n"NOR);
		newob = new(me->query_temp("path_rooms"));
		newob->move(dizhis["weizhi2"]);
		newob->random_move();
		newob->random_move();
		newob->random_move();
		destruct(ob);
		return;
	}
	if (me->query_temp("mark/gkill2") &&
		(string)ob->query("id") == me->query_temp("guanfu_target"))
	{
		message_vision(WHT "$N冷笑一聲，説道：“好俊的功夫！”説完縱身向「"+dizhis["cdizhi"]+"」處逃走。\n"NOR,ob,me);
		me->delete_temp("mark/gkill2");
		me->set_temp("mark/gkill3",1);
//		message_vision(WHT"「"+ob->query_temp("guanfu_targetnm")+"」好象往「"+dizhis["cdizhi"]+"」的方向逃去了。\n"NOR);
//		new(me->query_temp("path_rooms"))->move(dizhis["weizhi2"]);
		newob = new(me->query_temp("path_rooms"));
		newob->move(dizhis["weizhi2"]);
		newob->random_move();
		newob->random_move();
		newob->random_move();
		destruct(ob);
		return;
	}
	if((string)ob->query("id") != me->query_temp("guanfu_target"))
	{
		message_vision(WHT "突然$N一躍而起，道：“再見了各位！”就消失得無影無蹤了。\n"NOR,ob,me);
		destruct(ob);
		return;
	}
	::die();
}
int accept_fight(object me)
{
	command("say 大爺我正要趕路，沒心思和你動手。");
	return 0;
}
void dest()
{
	object ob;
	ob = this_object();
	if (environment())
	message_vision("只見$N忽然急轉身行，縱身鑽進行人中，轉眼就蹤跡皆無。\n", ob);
	destruct(this_object());
}
