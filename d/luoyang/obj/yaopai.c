// yaopai.c

#include <weapon.h>
#include <ansi.h>

inherit DAGGER;

void create()
{
	set_name("腰牌", ({ "yao pai", "yaopai" }));
	set("long", "這是一塊幫會的腰牌。\n"+
"    憑此腰牌，可以提升(tisheng) 和降黜(jiangchu)本幫會內所有
下屬人眾，甚至將其驅逐(quzhu) 出幫會。被驅逐者損失一定存款和
閲歷。如果對本幫會十分失望，可以自行退出(tuichu)所屬幫會，代
價一定的存款和閲歷。
     幫(門、教)主無法退會。但可以讓位(rangwei) 給本幫會眾，
功成身退。對於違命背叛的下屬，可以限時派出本幫會刑堂的執法弟
子前往懲處(chengchu)。
    如果想提升一位非本幫會人員成為本幫一般人眾，被提升者為表
示忠誠之決心，必須先割一個腦袋瓜來作為加盟投名狀。
    所有入會人等均能獲得一塊腰牌，並按自己的權限憑腰牌行使上
述權力。
      教(幫、門)主    提升 降黜 懲處 驅逐 任命 創立 讓位
      副教(幫、門)主  提升 降黜 懲處 驅逐 退出
      長老            提升 降黜 懲處 退出
      香主            提升 降黜 退出
      旗主            退出
      一般人眾        退出
其中第三、四、五階層人等可以任命(renming)專名。如傳功長老、
紅旗香主、風雲旗主等等。任何人等均可用party命令查閲本幫會名
單。
    如果不幸丟失本腰牌，可以到關林對着關夫子像猛磕頭(ketou)，
好好思過。
\n");
	set("weight", 300);
	set("no_get", 1);
	set("no_get_from", 1);
	set("no_give", 1);
	set("no_drop", 1);
	set("no_put", 1);
	set("no_steal", 1);
	set("no_beg", 1);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "塊");
		set("value", 1);
		set("material", "玉");
	}
	setup();
	init_dagger(5);
}

void init()
{
	add_action("do_tisheng","tisheng");
	add_action("do_jiangchu","jiangchu");
	add_action("do_renming","renming");
	add_action("do_quzhu","quzhu");
	add_action("do_tuichu","tuichu");
	add_action("do_chengchu","chengchu");
	add_action("do_rangwei","rangwei");
}

int do_tisheng(string arg)
{
	object where, ob, pai, me = this_player();
	string partynm;
	int i, mylvl, oblvl;

	if(!arg) return notify_fail("你要提升誰的職司？\n");
	if(!me->query("party"))
		return notify_fail("你不屬於任何幫會！\n");
	if(!me->query("party/player"))
		return notify_fail("玩家創立的幫會才能使用腰牌！\n");
	where = environment(me);
	if ((string)where->query("short")!="關林")
		return notify_fail("只能在關帝林中才能提升職司！\n");
	if( me->is_busy() )
		return notify_fail("你上一個動作還沒有完成！\n");
	if(!objectp(ob = present(arg, environment(me))) || !living(ob))
		return notify_fail("這裏沒有這個人。\n");
	if(ob == me) return notify_fail("真是聰明的方法。\n");
	if(!userp(ob))
		return notify_fail("你只能提升玩家。\n");
	partynm = me->query("party/party_name");
	i = strwidth(partynm);
	mylvl = me->query("party/level");
	if (mylvl > 5) return notify_fail("你無權提升任何人。\n");
	if(!ob->query("party"))
	{
		if(me->query_temp("party/toumingzhuang") != ob->query("id"))
			return notify_fail("對方要先給你個人頭作投名狀，然後你才能接引人家。\n");
		ob->set("party/party_name", partynm);
		ob->set("party/rank", "一般人眾");
		ob->set("party/player", 1);
		ob->set("party/level", 6);
		ob->set("party/enter_time", time());
		pai=new(__DIR__"yaopai");
		pai->move(ob);
		message_vision("$N獲得一塊腰牌！\n", ob);
		message("channel:chat", HIR"【通告】"+ob->query("name")+"於"+NATURE_D->game_time()+"由"HIG+me->query("party/rank")+me->query("name")+HIR"接引，加入"+partynm+"！\n"NOR,users());
		return 1;
	}

	if(ob->query("party/party_name") != partynm)
		return notify_fail(ob->query("name")+"好象是別的幫會的耶！\n");
	oblvl = ob->query("party/level");
	if(oblvl <= mylvl)
		return notify_fail(ob->query("name")+"的職司不比你低，你忙乎個啥勁呀！\n");
	if(oblvl - mylvl == 1)
		return notify_fail("只能提升對方成為你的下屬。\n");

	ob->set("party/level", oblvl - 1);
	switch (oblvl)
	{
		case 3: ob->set("party/rank", "副"+partynm[i-2..i]+"主"); break;
		case 4: ob->set("party/rank", "長老"); break;
		case 5: ob->set("party/rank", "香主"); break;
		case 6: ob->set("party/rank", "旗主"); break;
	}
	message_vision("$N衝着關帝像俯身下去，恭恭敬敬磕了三響頭！\n", ob);
	message("channel:chat", HIR"【通告】"HIY+ob->query("name")+"於"+NATURE_D->game_time()+"被"HIG+me->query("party/rank")+me->query("name")+HIY"提升為"+partynm+ob->query("party/rank")+"！\n"NOR, users());
	return 1;
}

int do_jiangchu(string arg)
{
	object ob, me = this_player();
	string partynm;
	int i, mylvl, oblvl;

	if(!arg) return notify_fail("你要降黜誰的職司？\n");
	if(!me->query("party"))
		return notify_fail("你不屬於任何幫會！\n");
	if(!me->query("party/player"))
		return notify_fail("玩家創立的幫會才能使用腰牌！\n");
	if( me->is_busy() )
		return notify_fail("你上一個動作還沒有完成！\n");
	if(!objectp(ob = present(arg, environment(me))) || !living(ob))
		return notify_fail("這裏沒有這個人。\n");
	if(ob == me) return notify_fail("真是聰明的方法。\n");

	partynm = me->query("party/party_name");
	i = strwidth(partynm);
	mylvl = me->query("party/level");
	if (mylvl > 5) return notify_fail("你無權降黜任何人。\n");
	if(!ob->query("party"))
		return notify_fail(ob->query("name")+"好象沒加入什麼幫會耶！\n");
	if(ob->query("party/party_name") != partynm)
		return notify_fail(ob->query("name")+"好象是別的幫會的耶！\n");
	oblvl = ob->query("party/level");
	if(oblvl == 6)
		return notify_fail(ob->query("name")+"的職司已經沒法降了，想懲罰只有驅逐出去了！\n");
	if(oblvl <= mylvl)
		return notify_fail(ob->query("name")+"的職司不比你低，你想犯上？\n");
	ob->set("party/level", oblvl + 1);
	switch (oblvl)
	{
		case 2: ob->set("party/rank", "長老"); break;
		case 3: ob->set("party/rank", "香主"); break;
		case 4: ob->set("party/rank", "旗主"); break;
		case 5: ob->set("party/rank", "一般人眾"); break;
	}
	message("channel:chat", HIR"【通告】"HIY+ob->query("name")+"於"+NATURE_D->game_time()+"被"HIG+me->query("party/rank")+me->query("name")+HIY"降黜為"+partynm+ob->query("party/rank")+"！\n"NOR, users());
	return 1;
}

int do_renming(string arg)
{
 object where, ob, me = this_player();
	string obname, rankname, partynm;
	int i, mylvl, oblvl;

	if(!arg) return notify_fail("你要任命誰的職司？\n");
	if(!me->query("party"))
		return notify_fail("你不屬於任何幫會！\n");
	if(!me->query("party/player"))
		return notify_fail("玩家創立的幫會才能使用腰牌！\n");
	where = environment(me);
	if ((string)where->query("short")!="關林")
		return notify_fail("只能在關帝林中才能任命職司！\n");
	if( me->is_busy() )
		return notify_fail("你上一個動作還沒有完成！\n");
	if( sscanf(arg, "%s to %s", obname, rankname) !=2)
		return notify_fail("renming 誰 to 專名\n");
	if(!objectp(ob = present(obname, environment(me))) || !living(ob))
		return notify_fail("這裏沒有這個人。\n");
	if(ob == me) return notify_fail("真是聰明的方法。\n");

	partynm = me->query("party/party_name");
	mylvl = me->query("party/level");
	if(mylvl > 1)
		return notify_fail("只有最高首領才能任命專名！\n");
	if(!ob->query("party"))
		return notify_fail(ob->query("name")+"沒有加入任何幫會，你任命個啥勁哪！\n");
	if(ob->query("party/party_name") != partynm)
		return notify_fail(ob->query("name")+"好象是別的幫會的耶！\n");
	i = strwidth(rankname);
	if( (strwidth(rankname) < 4) || (strwidth(rankname) > 6 ) )
	{
		return notify_fail("對不起，任命名稱必須是兩三個中文字。\n");
	}
	while(i--)
	{
		if( rankname[i]<=' ' )
		{
			return notify_fail("任命名稱不能用控制字元。\n");
		}
		if( i%2==0 && !is_chinese(rankname[i..<0]) )
		{
			return notify_fail("任命名稱必須是「中文」。\n");
		}
	}

	oblvl = ob->query("party/level");
	switch (oblvl)
	{
		case 3: ob->set("party/rank", rankname+"長老"); break;
		case 4: ob->set("party/rank", rankname+"香主"); break;
		case 5: ob->set("party/rank", rankname+"旗主"); break;
		default: return notify_fail(ob->query("name")+"的職司不能任命專名！\n");
	}
	message_vision("$N衝着關帝像俯身下去，恭恭敬敬磕了三響頭！\n", ob);
	message("channel:chat", HIR"【通告】"HIY+ob->query("name")+"於"+NATURE_D->game_time()+"被"+me->query("name")+"任命為"+partynm+ob->query("party/rank")+"！\n"NOR, users());
	return 1;
}

int do_quzhu(string arg)
{
 object *inv, ob, me = this_player();
	string partynm;
	int i, j, mylvl, oblvl;

	if(!arg) return notify_fail("你要驅逐誰？\n");
	if(!me->query("party"))
		return notify_fail("你不屬於任何幫會！\n");
	if(!me->query("party/player"))
		return notify_fail("玩家創立的幫會才能使用腰牌！\n");
	if( me->is_busy() )
		return notify_fail("你上一個動作還沒有完成！\n");
	if(!objectp(ob = present(arg, environment(me))) || !living(ob))
		return notify_fail("這裏沒有這個人。\n");
	if(ob == me) return notify_fail("真是聰明的方法。\n");

	partynm = me->query("party/party_name");
	mylvl = me->query("party/level");
	if(mylvl > 2)
		return notify_fail("你沒有權力驅逐別人。\n");
	if(!ob->query("party"))
		return notify_fail(ob->query("name")+"沒有加入任何幫會，你驅逐個啥勁哪！\n");
	if(ob->query("party/party_name") != partynm)
		return notify_fail(ob->query("name")+"好象是別的幫會的耶！\n");
	oblvl = ob->query("party/level");
	if(oblvl <= mylvl)
		return notify_fail(ob->query("name")+"的職司不比你低，你想幹嘛！\n");
	ob->delete("party");
	inv = all_inventory(ob);
	i = sizeof(inv);
	for (j = 0; j < i; j++)
	{
		if(inv[j]->query("id") == "yao pai") destruct(inv[j]);
	}
//	ob->set("combat_exp", ob->query("combat_exp")*99/100);
	if ((int) ob->query("balance")>0 )
	   ob->set("balance",ob->query("balance")*99/100);
	ob->set("score", ob->query("score")*99/100);
	message_vision("$N從$n身上收回一塊腰牌！\n", me, ob);
	message("channel:chat", HIR"【通告】"HIY+ob->query("name")+"於"+NATURE_D->game_time()+"被"HIG+me->query("party/rank")+me->query("name")+HIY"驅逐出"+partynm+"！以後此人所為，與"+partynm+"無涉！\n"NOR, users());
	return 1;
}

int do_tuichu()
{
 object  me = this_player();
	string partynm;
 int  mylvl;

	if( me->is_busy() )
		return notify_fail("你上一個動作還沒有完成！\n");
	if(!me->query("party"))
		return notify_fail("你沒有加入任何幫會，看你還能往哪退吧！\n");
	if(!me->query("party/player"))
		return notify_fail("玩家創立的幫會才能使用腰牌！\n");
	partynm = me->query("party/party_name");
	mylvl = me->query("party/level");
	if(mylvl == 1)
		return notify_fail(partynm+"是你手創，你怎麼能退出呢！\n");
	me->delete("party");
//	me->set("combat_exp", me->query("combat_exp")*98/100);
	if ((int) me->query("balance")>0 )
	   me->set("balance",me->query("balance")*98/100);
	me->set("score", (int)me->query("score")*98/100);
	message_vision("$N取出腰牌，狠狠砸碎在地上，以示決裂！\n", me);
	message("channel:chat", HIR"【通告】"HIY+me->query("name")+"："+RANK_D->query_self_rude(me)+"已於"+NATURE_D->game_time()+"自願退出"+partynm+"！以後"+partynm+"一切所為，與"+RANK_D->query_self_rude(me)+"一概無涉！\n"NOR, users());
	destruct(this_object());
	return 1;
}

int do_chengchu(string arg)
{
	object where, killer, ob, me = this_player();
	string partynm;
	int mylvl, oblvl, obskill;

	if(!arg) return notify_fail("你要懲處誰？\n");
	if(!me->query("party"))
		return notify_fail("你不屬於任何幫會！\n");
	if(!me->query("party/player"))
		return notify_fail("玩家創立的幫會才能使用腰牌！\n");
	if( me->is_busy() )
		return notify_fail("你上一個動作還沒有完成！\n");
	partynm = me->query("party/party_name");
	mylvl = me->query("party/level");
	if(me->query("party/chengchu") + 3600 > time())
		return notify_fail(partynm+"執法弟子不在刑堂，無法派出！\n");
	if(mylvl > 3)
		return notify_fail("你沒有權力懲處別人。\n");
	ob = find_player(arg);
	if(!ob) return notify_fail("你要懲處的人不在江湖中。\n");
	if(!ob->query("party"))
		return notify_fail(ob->query("name")+"沒有加入任何幫會，你懲處個啥勁哪！\n");
	if(ob->query("party/party_name") != partynm)
		return notify_fail(ob->query("name")+"好象是別的幫會的耶！\n");
	oblvl = ob->query("party/level");
	obskill = ob->query_skill("parry",1);
	if(oblvl <= mylvl)
		return notify_fail(ob->query("name")+"的職司不比你低，你想和人家玩可不成啊！\n");
	where = environment(ob);

	killer = new("/d/luoyang/npc/zhifa");
	killer->set("target", ob->query("id"));
	killer->set("owner", me->query("name"));
	killer->set("party/party_name", partynm);
	killer->set("party/rank", HIC"刑堂"NOR);
	killer->set("combat_exp", ob->query("combat_exp") * 3 / 2);
	killer->set_skill("unarmed", obskill);
	killer->set_skill("parry", obskill);
	killer->set_skill("sword", obskill);
	killer->set_skill("dodge", obskill);
	killer->set_skill("force", obskill);
	killer->set_skill("taiji-shengong", obskill);
	killer->set_skill("taiji-quan", obskill);
	killer->set_skill("taiji-jian", obskill);
	killer->set_skill("liangyi-jian", obskill);
	killer->set_skill("tiyunzong", obskill);
	killer->map_skill("force", "taiji-shengong");
	killer->map_skill("unarmed", "taiji-quan");
	killer->map_skill("parry", "taiji-jian");
	killer->map_skill("sword", "liangyi-jian");
	killer->map_skill("dodge", "tiyunzong");
	killer->move(where);

	me->set("party/chengchu", time());
        tell_room(where, killer->query("name")+"走了過來。\n", ({killer}));
	return notify_fail("已經派出執法弟子前往"+ob->query("name")+"所在之處了！\n");
}
int do_rangwei(string arg)
{
 object *inv, ob, me = this_player();
	string partynm;
 int i, j, mylvl;

	if(!arg) return notify_fail("你要讓位給誰？\n");
	if(!me->query("party"))
		return notify_fail("你不屬於任何幫會！\n");
	if(!me->query("party/player"))
		return notify_fail("玩家創立的幫會才能使用腰牌！\n");
	if(me->is_busy() )
		return notify_fail("你上一個動作還沒有完成！\n");

	if(!objectp(ob = present(arg, environment(me))) || !living(ob))
		return notify_fail("這裏沒有這個人。\n");
	if(ob == me) return notify_fail("真是聰明的方法。\n");

	partynm = me->query("party/party_name");
	mylvl = me->query("party/level");
	if(mylvl > 1)
		return notify_fail("你這個職份讓什麼位！臭顯啊！\n");
	if(!ob->query("party"))
		return notify_fail(ob->query("name")+"沒有加入任何幫會，你讓不成位啦！\n");
	if(ob->query("party/party_name") != partynm)
		return notify_fail(ob->query("name")+"好象是別的幫會的耶！\n");
	if(ob->query("age") < 50 || ob->query("combat_exp") < 5000000)
		return notify_fail(ob->query("name")+"好象嫩得很，不足擔此大任！\n");
	ob->set("party/level", 1);
	ob->set("party/rank", me->query("party/rank"));
	message_vision("$N向$n交回一塊腰牌！\n", me, ob);
	message("channel:chat", HIR"【通告】"HIY+me->query("name")+"："+RANK_D->query_self(me)+"於"+NATURE_D->game_time()+"將"HIG+partynm+me->query("party/rank")+HIY"之位讓予"+ob->query("name")+"！望各位江湖同道捧場！"HIR"恭喜新"+me->query("party/rank")+"！\n"NOR, users());
	me->delete("party");
	inv = all_inventory(me);
	i = sizeof(inv);
	for (j = 0; j < i; j++)
	{
		if(inv[j]->query("id") == "yao pai") destruct(inv[j]);
	}
	return 1;
}

string query_autoload()
{
	return 1 + "";
}
void owner_is_killed()
{
	destruct(this_object());
}