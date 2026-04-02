// Last Modified by winder on Sep. 12 2001
// chen-jialuo.c 陳家洛

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
inherit F_MANAGER;

string ask_me();
string ask_ling();
int count=1;

void create()
{
	set_name("陳家洛", ({ "chen jialuo", "chen" }));
	set("title", HIR"紅花會"HIG"總舵主"NOR);
	set("nickname", HIY"玉面神龍"NOR);
	set("long","他就是天下聞名的紅花會的總舵主陳家洛。\n身穿一件乾乾淨淨的青色長袍。\n他一副模樣直是個富貴人家的紈褲子弟，丰姿如玉，目朗似星，神采飛揚，氣度閒雅，吐屬斯文。服飾儼然是個貴介公子。\n");
	set("gender", "男性");
	set("age", 22);
	set("shen_type", 1);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	
	set("max_qi", 5000);
	set("max_jing", 5000);
	set("neili", 5000);
	set("max_neili", 5000);
	set("jiali",100);
	set("combat_exp", 3000000);
	set("score", 700000);

	set_skill("force", 200);
	set_skill("honghua-shengong", 200);
	set_skill("dodge", 200);
	set_skill("youlong-shenfa", 300);
	set_skill("hand", 200);
	set_skill("benlei-shou", 300);
	set_skill("cuff", 200);
	set_skill("baihua-cuoquan", 300);
	set_skill("strike", 200);
	set_skill("heisha-zhang", 300);
	set_skill("throwing", 200);
	set_skill("wuying-feidao", 300);
	set_skill("blade", 200);
	set_skill("qiuge-dao", 300);
	set_skill("sword", 200);
	set_skill("luohua-jian", 300);
	set_skill("zhuihun-jian", 300);
	set_skill("parry", 200);
	set_skill("literate", 100);

	map_skill("force", "honghua-shengong");
	map_skill("dodge", "youlong-shenfa");
	map_skill("cuff", "baihua-cuoquan");
	map_skill("hand", "benlei-shou");
	map_skill("strike", "heisha-zhang");
	map_skill("throwing", "wuying-feidao");
	map_skill("sword", "luohua-jian");
	map_skill("blade", "qiuge-dao");
	map_skill("parry", "luohua-jian");
	prepare_skill("cuff", "baihua-cuoquan");
	prepare_skill("hand", "benlei-shou");

	set("inquiry", ([
		"紅花會" : (: ask_me :),
	]));
	set("chat_chance", 5);	 // 隨機動作概率 25%
	set("chat_msg", ({
		"陳家洛嘆了一口氣道：唉....想不到乾隆竟是我兄弟，這可如何是好？\n",
		"陳家洛恨聲說道：我們漢人的江山，一定要從滿清手中奪回來。\n",
		"陳家洛說道：這位兄弟，可要加入我們紅花會嗎？\n",
	}) );
	set("no_get",1);
	set("chat_chance_combat", 50); // 戰鬥中隨機動作概率
	set("chat_msg_combat", ({
		"陳家洛說道：你敢惹我，追到天涯海角我都要殺了你！\n",
		(: perform_action, "sword.beng" :),
		(: perform_action, "sword.lian" :),
		(: perform_action, "cuff.cuo" :),
		(: perform_action, "hand.yunkai" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
	}) );
	create_family("紅花會", 2, "總舵主");

	setup();
	carry_object(WEAPON_DIR"changjian")->wield();
	carry_object(__DIR__"obj/yaodai")->wear();
	carry_object(__DIR__"obj/bluecloth")->wear();
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query("shen") < 50000)
	{
		command( "say 紅花會中皆是敢作敢當的好漢子，你這小賊也想混進來麼？");
		command("say 想要加入紅花會"+RANK_D->query_respect(ob) + "你先去殺幾個清狗再說！");
		return;
	}
	command("say 在下對"+RANK_D->query_respect(ob)+"已是神交已久，從今而後咱們就是一家人了！");
	command("recruit " + ob->query("id"));
}

void init()
{
	object ob = this_player();

	::init();
	if( interactive(ob) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}

	if((int)ob->query("shen") < -1000 &&
		ob->query("family/master_id")=="chen jialuo")
	{
		command( "chat "+ob->query("name")+"！你這等邪惡奸詐之徒，紅花會豈能再容你！\n");
		command("expell "+ ob->query("id"));
		this_player()->set("title","紅花會" + RED + "棄徒" NOR);
	}
	add_action("do_say", "say");
        add_action("do_qiecuo","qiecuo");
}

void greeting(object me)
{
       
       	mapping myfam;
	myfam = (mapping)me->query("family");
	if((myfam["family_name"] == "紅花會")&&(!me->query_skill("honghua-shengong",1))&&(me->query("combat_exp")>500000))
        {
                command("say 你竟敢放棄本門心法！從我這裏滾出去吧！");
                command("expell " + me->query("id"));
        }
        
}

int do_say(string arg)
{
	if( !arg || arg=="" ) return 0;
 
	if( arg=="青葉紅花白蓮藕") 
	{
		write("陳家洛說道：天下英雄是一家。\n");
		message("vision", "陳家洛低聲道：原來是自家弟兄，不知有何見教？\n", this_player());
		set("inquiry", ([
			"紅花令" : (: ask_ling :),
		]));
	}
}
string ask_me()
{
	return RANK_D->query_respect(this_player())+ "，我紅花會乃天下第一大幫，專與清狗作對，哈...哈...";
}
string ask_ling()
{
	object ob,me;

	if (count == 0) return "紅花令已經傳出去了！\n";
	message_vision(HIR"陳家洛說道：“想要紅花令嗎？，先接我三招！\n"NOR,this_player());
	ob = this_object();
	me = this_player();
	COMBAT_D->do_attack(ob, me, query_temp("weapon") );
	COMBAT_D->do_attack(ob, me, query_temp("weapon") );
	COMBAT_D->do_attack(ob, me, query_temp("weapon") );

	me->set_temp("fighter", 1);
	ob->fight_ob(me);
	me->fight_ob(ob);
	command("halt");

	if (( (int)me->query("qi")*100 / (int)me->query("max_qi") ) >= 30 )
	{
		ob = new(__DIR__"obj/honghua-ling");
		ob->move(this_player());
		count=0;
		message_vision(HIY"陳家洛交給$N一支紅花令！\n"NOR, me);
		return "好，這是紅花令，兄弟你要好好保管！\n";
	}
	else return "你這樣武功怎能掌管紅花令？";	
}

