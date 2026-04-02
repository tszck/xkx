// damage.c
// Last Modified by Sir on 2004.1.13  華山論劍不死
#include <ansi.h>
#include <dbase.h>
#include <login.h>
#include <move.h>

#define ENTRY_ROOM      "/d/huashan/sheshen"
int ghost = 0;
int is_ghost() { return ghost; }
void set_ghost(int i) { ghost=i; }

//varargs int receive_damage(string type, int damage, object who)
varargs int receive_damage(string type, int damage, mixed reason)
{
	int val;
  	int imp;

	if( damage < 0 ) error("F_DAMAGE: 傷害值為負值。\n");
	if( type!="jing" && type!="qi" )
		error("F_DAMAGE: 傷害種類錯誤( 只能是 jing, qi 其中之一 )。\n");

	if( objectp(reason) ) set_temp("last_damage_from", reason);
	if( stringp(reason) ) set_temp("die_reason",reason);
	imp=damage/5;
	if (query("max_nuqi") && this_object()->is_fighting())
  	{
	 	add( "nuqi" , imp );
	  if ( query("nuqi")>query("max_nuqi") )
	    set("nuqi",query("max_nuqi"));
	}
	val = (int)query(type) - damage;

	if( val >= 0 ) set(type, val);
	else set( type, -1 );

	set_heart_beat(1);

	return damage;
}

varargs int receive_wound(string type, int damage, mixed reason)
{
	int val;
	int imp;

	if( damage < 0 ) error("F_DAMAGE: 傷害值為負值。\n");
	if( type!="jing" && type!="qi" )
		error("F_DAMAGE: 傷害種類錯誤( 只能是 jing, qi 其中之一 )。\n");

	if( objectp(reason) ) set_temp("last_damage_from", reason);
	if( stringp(reason) ) set_temp("die_reason",reason);
	imp=damage/3;
	if (query("max_nuqi") && this_object()->is_fighting())
	  {
	  	add( "nuqi" , imp );
	    if ( query("nuqi")>query("max_nuqi") )
	    set("nuqi",query("max_nuqi"));
	  }	
	val = (int)query("eff_" + type) - damage;

	if( val >= 0 ) set("eff_" + type, val);
	else {
		set( "eff_" + type, -1 );
		val = -1;
	}

	if( (int)query(type) > val ) set(type, val);

	set_heart_beat(1);

	return damage;
}

int receive_heal(string type, int heal)
{
	int val;

	if( heal < 0 ) error("F_DAMAGE: 恢復值為負值。\n");
	if( type!="jing" && type!="qi" )
		error("F_DAMAGE: 恢復種類錯誤( 只能是 jing, qi 其中之一 )。\n");

	val = (int)query(type) + heal;

	if( val > (int)query("eff_"+type) ) set(type, (int)query("eff_"+type));
	else set( type, val );

	return heal;
}

int receive_curing(string type, int heal)
{
	int max, val;

	if( heal < 0 ) error("F_DAMAGE: 恢復值為負值。\n");
	if( type!="jing" && type!="qi" )
		error("F_DAMAGE: 恢復種類錯誤( 只能是 jing, qi 其中之一 )。\n");

	val = (int)query("eff_" + type);
	max = (int)query("max_" + type);

	if( val + heal > max ) {
		set("eff_" + type, max);
		return max - val;
	} else {
		set( "eff_" + type, val + heal);
		return heal;
	}
}

void unconcious()
{
	object defeater;
	object riding;

	// 所在房間定義了no_unconcious，不允許暈倒 
	if (environment()->no_unconcious(this_object())) return;
	if( !living(this_object()) || this_object()->query_temp("noliving") )
		return;
	if( wizardp(this_object()) && query("env/immortal") ) return;

	if( objectp(defeater = query_temp("last_damage_from")) )
		{
			COMBAT_D->winner_reward(defeater, this_object());
      if (environment(this_object())==environment(defeater))
        if (this_object()->query("max_nuqi"))
         this_object()->set("nuqi",query("max_nuqi"));
    }
	this_object()->remove_all_enemy();
	this_object()->set_temp("faint_by", query_temp("last_damage_from")); 
	       if (objectp(riding = query_temp("is_riding")))
        {
                message_vision("$N一頭從$n上面栽了下來！\n",
                               this_object(), riding);
                delete_temp("is_riding");
                riding->delete_temp("is_rided_by");
                riding->move(environment());
        }

	message("system", HIR "\n你的眼前一黑，接着什麼也不知道了....\n\n" NOR, this_object());
// 避免add_action的bug
	if(userp(this_object()))
		this_object()->set_temp("noliving/unconcious", 1);
	else this_object()->disable_player(" <昏迷不醒>");

	set("jing", 0);
	set("qi", 0);

	set_temp("block_msg/all", 1);
	COMBAT_D->announce(this_object(), "unconcious");

	call_out("revive", random(100 - query("con")) + 30);
}

varargs void revive(int quiet)
{
	remove_call_out("revive");
	while( environment()->is_character() )
		this_object()->move(environment(environment()));
// 避免add_action的bug
	if(userp(this_object())) this_object()->delete_temp("noliving");
	else this_object()->enable_player();

	if( !quiet )
	{
		COMBAT_D->announce(this_object(), "revive");
		set_temp("block_msg/all", 0);
		message("system", HIY "\n慢慢地你終於又有了知覺....\n\n" NOR, this_object());
	} else
		set_temp("block_msg/all", 0);
}

void die()
{
	object corpse, killer;
 
	string reason;
	object riding;

	
	if( !living(this_object()) || this_object()->query_temp("noliving") )
		revive(1);
	else delete_temp("faint_by");
	// 所在房間定義了no_die，不允許死亡 
	if (environment()->no_die(this_object())) return;
	if( wizardp(this_object()) && query("env/immortal") ) return;

	if(userp(this_object()) && this_object()->is_ghost())
	{
		this_object()->receive_curing("jing", 10);
		this_object()->receive_curing("qi", 10);
		message_vision(HIW "黑白索魂無常忽然出現，喝道：何方孤魂野鬼，快快隨我前去閻羅大殿！\n" NOR, this_object());
		this_object()->move("/d/death/dadian");
		return;
	}


// 擂臺比武不死
	if (file_name(environment(this_object())) == "/d/city/leitai")
	{
		message_vision(HIR "公平子道：“已分勝負，不決生死。”\n" NOR, this_object());
		this_object()->move("/d/city/wudao4");
		this_object()->receive_curing("jing", 10);
		this_object()->receive_curing("qi", 10);
		return;
	}
	if (userp(this_object())&& environment(this_object())->query("bwdhpk"))
        {
                message_vision(HIR "華山論劍，只分勝負，不決生死！。\n" NOR, this_object());
                message_vision(HIR "$N被抬了下去。\n" NOR, this_object());
                if( objectp(killer = query_temp("last_damage_from")) )
			{
			killer->add_temp("bwdh_pknum",1);
message("channel:chat", HIC"【華山論劍】公平子："+this_object()->query("name")+"不敵"+killer->query("name")+"，被迫退出華山論劍！\n"NOR,users() );
			}
	  this_object()->set("eff_jing", (int)this_object()->query("max_jing"));
	  this_object()->set("jing", (int)this_object()->query("max_jing"));
	  this_object()->set("eff_qi", (int)this_object()->query("max_qi"));
	  this_object()->set("qi", (int)this_object()->query("max_qi"));
	  this_object()->set("jingli", (int)this_object()->query("max_jingli"));
	  this_object()->set("neili", (int)this_object()->query("max_neili"));
	  this_object()->remove_all_killer();
	  this_object()->remove_all_enemy();
	  this_object()->delete_temp("bwdh_join");
	  this_object()->delete_temp("bwdh_pknum");
	  this_object()->delete_temp("bwdh_nknum");
          this_object()->move(ENTRY_ROOM);
          return;
	}
        if (objectp(riding = query_temp("is_riding")))
        {
                message_vision("$N一頭從$n上面栽了下來！\n",
                               this_object(), riding);
                delete_temp("is_riding");
                riding->delete_temp("is_rided_by");
                riding->move(environment());
        }


	if (this_object()->query_condition("huaiyun") > 0 &&
	    this_object()->query_condition("huaiyun") < 2560 )
	tell_object(this_object(),"你莫名地感到一陣心痛。。。\n");
	if( objectp(killer = query_temp("last_damage_from")) &&
		file_name(environment(killer)) == file_name(environment(this_object())))
	{
// Clear all the conditions by normal death.
		if ( userp(this_object()) && userp(killer) && (!environment(this_object())->query("bwdhpk")) &&
			(time()-this_object()->query("dietime")<13400 ||
			time()-killer->query("killertime")<13400))
 		{
			this_object()->set("eff_qi",10);
			this_object()->set("eff_jing",10);
			this_object()->set("qi",10);
			this_object()->set("jing",10);
			message_vision(HIY "\n天后仙子"HIC"自雲中飄然而下："HIR"一日不過四。不準頻繁屠殺！\n" NOR, this_object());
			message_vision(HIG "揮起長袖，擺起一陣香風把"+this_object()->name()+"刮回武廟。\n" NOR, this_object());
			this_object()->move("/d/city/wumiao");
			this_object()->start_busy(10);
			return;
		}
		this_object()->clear_condition();
		this_object()->set("dietime",time());
		this_object()->add("normal_die", 1);
/* 殺手本次殺人時間 */
		if (userp(this_object()))
			killer->set("killertime", time());
		set_temp("my_killer", killer->query("id"));
		COMBAT_D->killer_reward(killer, this_object());
	}
	else
		if(userp(this_object()))
		{
			this_object()->set("last_die_msg","死得很離奇");
			if (stringp(reason=this_object()->query_temp("die_reason")))
			    this_object()->set("last_die_msg",reason);
			else if (stringp(reason=this_object()->query_temp("last_damage_from")))
			    this_object()->set("last_die_msg",reason+"死了");
			message("channel:rumor", HIM"【謠言】"+"聽説"+this_object()->name()+ HIM"死了，而且死得很離奇。\n"NOR, users());

			this_object()->delete("last_die_by_name");
			this_object()->delete("last_die_by_id");
			this_object()->delete_temp("die_reason");
			this_object()->delete_temp("last_damage_from");
			this_object()->add("dietimes",1);
		}
	COMBAT_D->announce(this_object(), "dead");
	if (this_player()->query_condition("huaiyun"))
	this_object()->clear_condition("huaiyun");
	if( objectp(corpse = CHAR_D->make_corpse(this_object(), killer)) )
	{
		corpse->move(environment());
// 超度用的經驗值
		corpse->set("combat_exp", this_object()->query("combat_exp"));
// 死者是玩家
		if (userp(this_object()))
			corpse->set("userp", 1);
		else
		{
// 死者是任務對象
			if(this_object()->query("quest"))
				corpse->set("quest", this_object()->query("quest"));
			if(this_object()->query("owner"))
				corpse->set("owner", this_object()->query("owner"));
		}
	}

	this_object()->remove_all_killer();
	all_inventory(environment())->remove_killer(this_object());

	this_object()->dismiss_team();
	if( userp(this_object()) ) {
//		if (this_object()->is_busy())
//			this_object()->interrupt_me();
		this_object()->remove_busy();
		set("jing", 1);	set("eff_jing", 1);
		set("qi", 1);	set("eff_qi", 1);
		ghost = 1;
		this_object()->move(DEATH_ROOM);
		DEATH_ROOM->start_death(this_object());
	}
	else
	{
//浩劫系統的觸發條件
		LOGIN_D->add_dienpc();
                destruct(this_object());
         }
}

int max_food_capacity() { return query_weight() / 200; }

int max_water_capacity() { return query_weight() / 200; }

void reincarnate()
{
	ghost = 0;
	set("eff_jing", query("max_jing"));
	set("eff_qi", query("max_qi"));
	set("food",max_food_capacity());
	set("water",max_water_capacity());
}

int heal_up()
{
 int update_flag;
	mapping my;

//	if( this_object()->is_fighting() ) return -1;

	update_flag = 0;

	my = query_entire_dbase();



	//就是下面這兩句話！！！！！！！！！！！！！
	//就是下面這兩句話！！！！！！！！！！！！！
	//就是下面這兩句話！！！！！！！！！！！！！
	//就是下面這兩句話！！！！！！！！！！！！！
     

	  if (environment(this_object()) && environment(this_object())->is_chat_room()
 	      && this_object()->query("env/halt_age") )




  	      return 0;
  
	if( my["water"] > 0 ) { my["water"] -= 1; update_flag++; }
  	if( my["food"] > 0 ) { my["food"] -= 1; update_flag++; }
  
	if( my["water"] < 1 &&  //人和寵物如果沒飲水，不能恢復身體。
		(userp(this_object()) || this_object()->query("ownername")) )
		return update_flag;
	
	if( my["food"] < 1 &&  //人和寵物如果沒食物，不能恢復身體。
		(userp(this_object()) || this_object()->query("ownername")) )
		return update_flag;

	my["jing"] += my["con"] / 3 + my["max_jingli"] / 10;
	if( my["jing"] >= my["eff_jing"] )
	{
		my["jing"] = my["eff_jing"];
		if( my["eff_jing"] < my["max_jing"] )
		{
			my["eff_jing"] ++; update_flag++;
		}
	} else update_flag++;

	my["qi"] += my["con"] / 3 + my["max_neili"] / 10;
	if( my["qi"] >= my["eff_qi"] )
	{
		my["qi"] = my["eff_qi"];
		if( my["eff_qi"] < my["max_qi"] )
		{
			my["eff_qi"] ++; update_flag++;
		}
	} else update_flag++;

	if( my["max_jingli"] && my["jingli"] < my["max_jingli"] )
	{
		my["jingli"] += (int)this_object()->query_skill("taoism", 1)/20;
		if(my["jingli"]>my["max_jingli"]) my["jingli"]=my["max_jingli"];
		update_flag++;
	}

	if( my["max_neili"] && my["neili"] < my["max_neili"] )
	{
		my["neili"] += (int)this_object()->query_skill("force", 1)/2 + 
			(int)this_object()->query("sta")/3;
		if(my["neili"] > my["max_neili"]) my["neili"] = my["max_neili"];
		update_flag++;
	}

	if( my["max_tili"] && my["tili"] < my["max_tili"] )
	{
		my["tili"] += (int)this_object()->query_skill("parry", 1)/2 +
			(int)this_object()->query("sta")/3;
		if(my["tili"] > my["max_tili"]) my["tili"] = my["max_tili"];
		update_flag++;
	}

	return update_flag;
}