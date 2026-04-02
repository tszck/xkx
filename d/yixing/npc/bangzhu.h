// /d/yixing/npc/bangzhu.h
// Last Modified by winder on Jul. 12 2002
#include <ansi.h>
#include <dbase.h>
#include <login.h>
#include <move.h>

void init()
{
	object ob = this_player();

	::init();

	if( !is_fighting() && interactive(ob) )
	{
		remove_call_out("checking");
		call_out("checking", 1, ob);
	}

	add_action("do_check", "exert");
	add_action("do_check", "yun");
	add_action("do_xue", "xue");
}

void checking(object ob)
{
	object me = this_object();

	if( !living(me) || is_fighting() ) return;
	if( environment() != environment(ob) ) return;
	if( ob->query("party/party_name") == query("party/party_name") )
	{
		message_vision("$N拍了拍$n的頭説道：加油！長樂幫發了自有你的好處！\n", me, ob);
		return;
	}
	if( !random(2) )
		message_vision("$N雙手抱拳，牛裏牛氣地説道：見到本幫主，難道沒有任何表示嗎？\n", me);
	else message_vision("$N説道：還不趕快加入" + query("party/party_name") + "！！！\n", me);
}

int do_check(string arg)
{
	string what, who;

	if( !arg ) return notify_fail("");
	if( arg != "play" )
	{
		 if( sscanf(arg, "%s %s", what, who) != 2 )
			return notify_fail("");
		 if( what != "play" ) return notify_fail("");
	}
	call_other(BANGSKILLS+"/play2", "exert", this_player(), this_player());
	return 1;
}

int ask_join()
{
	object ob = this_player(), obj;
	string myfam, ob_fam;
	int exp = ob->query("combat_exp");

	ob_fam = (string)ob->query("family/family_name");
	if( ob_fam == "丐幫" )
	{
		say(name() + "大怒道：" + RANK_D->query_rude(ob) + "一定是丐幫派來臥底的吧！\n");
		return 1;
	}
	if( ob_fam == "大理段家" )
	{
		say(name() + "大怒道：" + RANK_D->query_rude(ob) + "一定是大理國派來臥底的吧！\n");
		return 1;
	}

	if( ob_fam == "桃花島" )
	{
		say(name() + "説道：貴派祖師黃藥師一向不與江湖人士往來，我怎麼能隨便收容他老人家的門下！\n");
		return 1;
	}

	if( ob_fam == "武當派" || ob_fam == "峨嵋派" || ob_fam == "華山派" ||
		 ob_fam == "少林派" || ob_fam == "南少林派" )
	{
		say(name() + "大怒道：" + RANK_D->query_rude(ob) + "一定是名門正派派來臥底的吧！\n");
		return 1;
	}
	myfam = (string)query("party/party_name");
	if( (string)ob->query("party/party_name") == myfam )
	{
		say(name() + "大怒道：" + RANK_D->query_rude(ob) + "！竟敢開幫主的玩笑！！！\n");
		return 1;
	}
	if( exp > query("combat_exp") && !wizardp(ob))
	{
		say(name()+"雙手一抱拳道："+RANK_D->query_respect(ob)+ "莫非是開玩笑吧。\n");
		return 1;
	}
	if( time() < (int)ob->query("party/enter_time") + 600 )
	{
		say(name() + "大怒道：" + RANK_D->query_rude(ob) + "，你如此反覆無常豈能容身於江湖！！！\n");
		return 1;
	}
	message_vision("$N重重地拍了一下$n的肩膀，喝道：好樣的！從今以後跟兄弟們有難同當！\n", this_object(), ob);

	ob->set_temp("apply/short", ({ HIR + myfam + "幫眾"NOR + ob->query("name")+"("+capitalize(ob->query("id"))+")" }));
	ob->delete("party");
	ob->set("party/party_name", myfam);
	ob->set("party/rank", "幫眾");
	ob->set("party/enter_time", time());
	if( obj = present("bang ling", ob) ) destruct(obj);

	obj = new(BANGLING);
	obj->set("owner", ob->query("id"));
	obj->set("fam", myfam);
	obj->set("combat_exp", query("combat_exp"));
	obj->set("long", "這是" + myfam + "的幫令，上面刻着「" + ob->query("name") + "」。\n");
	obj->move(ob);
	message_vision("$N把一" + obj->query("unit") + obj->name() + "扔給$n。\n", this_object(), ob);
	log_file("partyjoin", sprintf("%s於%s時加入%s\n", ob->query("name"), ctime(time()), myfam));
	return 1;
}

// duty 2 teach skills

string ask_skills()
{
	object ling, me = this_player();
	int amount;

	if( is_fighting() )
		return RANK_D->query_rude(me) + "瞎了眼沒見我正忙着？！";

	if( (string)me->query("party/party_name") != (string)query("party/party_name") )
		return RANK_D->query_rude(me) + "莫非是想打聽我幫的祕密吧。";

	if( !(ling = present("bang ling", me)) )
		return RANK_D->query_rude(me) + "竟連自己的幫令都管不住！";

	if( (string)ling->query("owner") != me->query("id") )
		return RANK_D->query_rude(me) + "竟連自己的幫令都管不住！";

	if( (amount = (int)ling->query("score")) < 10 )
		return RANK_D->query_rude(me)+"再加把勁，幫主才會指點你一下！";

	if( amount > 100 )
	{
		me->set("party/skills_asked", 100);
		ling->add("score", -100);
	} else {
		me->set("party/skills_asked", amount);
		ling->delete("score");
	}

	tell_object(me, "請鍵入：武功的英文名字。\n");
	return "好吧。";
}

int do_xue(string arg)
{
	object me = this_player();
	string *sname;
	int i, amount, level, mylvl;

	if( !(amount = (int)me->query("party/skills_asked")) )
	{
		write("你還沒徵求幫主同意呢。\n");
		return 1;
	}

	if( is_fighting() )
	{
		say(name() + "大怒道：" + RANK_D->query_rude(me) + "瞎了眼沒見我正忙着？！");
		return 1;
	}
	if( !arg )
	{
		sname = keys(query_skills());
		write("\n" + name() + "所學過的技能：\n\n");
		for(i = 0; i < sizeof(sname); i++)
			write(to_chinese(sname[i]) + " (" + sname[i] + ")" + "\n");
		return 1;
	}
	if( (level = (int)query_skill(arg, 1)) < 1 )
	{
		say(name() + "搖了搖頭道：幫主沒學過。\n");
		return 1;
	}

	mylvl = (int)me->query_skill(arg, 1);
	if( level < mylvl )
	{
		say(name() + "大怒道：" + RANK_D->query_rude(me) + "居然超過老子了。\n");
		return 1;
	}
	if( mylvl > 80 )
	{
		say(name() + "搖了搖頭道：你得去門派中正式拜師才能繼續提高" + to_chinese(arg) + "。\n");
		return 1;
	}
	if( (int)me->query("jing") + 10 < (int)me->query("max_jing") )
	{ 
		write("你先歇會兒吧。\n");
		return 1;
	}
	me->set("jing", 10);
	me->improve_skill(arg, amount * me->query("int") / 3); 
	me->delete("party/skills_asked");
	message_vision("$N向$n請教有關「" + to_chinese(arg) + "」的疑問。\n", me, this_object());
	tell_object(me, "你聽了幫主的指導，對「" + to_chinese(arg) + "」似乎有些心得。\n");
	return 1;
}

// duty 3 died to give bangyin

void die()
{
	object ob, corpse, killer;

	if( !living(this_object()) ) revive(1);
//	clear_condition();

	if( objectp(killer = query_temp("last_damage_from")) )
	{
		ob = new(BANGYIN);
		ob->set("long", query("fam") + ob->query("name") + "。\n");
		ob->move(environment());
		message_vision(HIR"\n突然從$N衣袋中掉下一" + ob->query("unit") + ob->name() + "。\n"NOR, this_object());
		set_temp("my_killer", killer->query("id"));
		ob->set("my_killer",  killer->query("id"));
		ob->set("combat_exp", query("combat_exp"));
	}
	COMBAT_D->announce(this_object(), "dead");
	if( objectp(corpse = CHAR_D->make_corpse(this_object(), killer)) )
		corpse->move(environment());
	remove_all_killer();
	all_inventory(environment())->remove_killer(this_object());

	dismiss_team();
	destruct(this_object());
}
