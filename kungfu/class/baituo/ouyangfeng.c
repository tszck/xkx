// /kungfu/class/baituo/ouyangfeng.c
// Last Modified by Winder on May. 15 2001

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
inherit F_MANAGER;

int ask_help();
int do_accept();

void create()
{
	object ob;
	set_name("歐陽鋒", ({ "ouyang feng", "ouyang", "feng" }));
	set("long", "他是白駝山莊主，號稱“西毒”的歐陽鋒。\n"
		+"由於習練「九陰真經」走火入魔，已變得精\n"
		+"神錯亂，整日披頭散髮。\n");
	set("title", "白駝山莊主");
	set("gender", "男性");
	set("age", 53);
	set("nickname", HIY "西毒" NOR);
	set("shen_type",-1);
	set("shen", -150000);
	set("attitude", "peaceful");
	set("no_get",1);

	set("str", 30);
	set("int", 29);
	set("con", 30);
	set("dex", 28);

	set("qi", 2500);
	set("max_qi", 2500);
	set("jing", 900);
	set("max_jing", 900);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 50);

	set("combat_exp", 3000000);
	set("score", 200000);

	set_skill("force", 200);
	set_skill("cuff", 200);
	set_skill("dodge", 200);
	set_skill("parry", 200);
	set_skill("hand",200);
	set_skill("strike",200);
	set_skill("staff", 200);
	set_skill("training",200);
	set_skill("literate", 100);
	set_skill("xidu-poison", 150);
	set_skill("hamagong", 200);
	set_skill("hamaquan", 300);
	set_skill("chanchu-bufa", 300);
	set_skill("shexing-diaoshou", 300);
	set_skill("lingshe-zhangfa", 300);
	map_skill("force", "hamagong");
	map_skill("dodge", "chanchu-bufa");
	map_skill("cuff", "hamaquan");
	map_skill("strike", "hamagong");
	map_skill("hand", "shexing-diaoshou");
	map_skill("parry", "lingshe-zhangfa");
	map_skill("staff", "lingshe-zhangfa");
	prepare_skill("strike", "hamagong");
	prepare_skill("hand", "shexing-diaoshou");

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "staff.shoot" :),
		(: perform_action, "staff.saoye" :),
		(: perform_action, "strike.hama" :),
		(: exert_function, "powerup" :),
		(: exert_function, "reserve" :),
		(: exert_function, "recover" :),
	}) );

	create_family("白駝山派",1, "開山祖師");
	set("chat_chance",2);
	set("chat_msg",({
		"歐陽鋒自言自語道：何日白駝山派才能重霸江湖呢…\n",
		"歐陽鋒道：我兒歐陽克必能夠重振白駝山派雄風！\n",
		"歐陽鋒道：江湖險惡，困難重重哪！\n",
	}));
	
	set("inquiry", ([
		"name":   "名字，我...我沒有名字，我...我是誰?",
		"名字":   "名字，我...我沒有名字，我...我是誰?",
	]));
	setup();
	if (clonep())
	 {
	 	ob = new(WEAPON_DIR"treasure/lingshezhang");
	 	if ( ob -> violate_unique() )
	 	{
	 		destruct(ob);
	 		ob=new("/d/baituo/obj/shezhang");
 		}
 		ob->move(this_object());
 		ob->wield();
	 }
	carry_object(__DIR__"obj/baipao")->wear();
	add_money("silver",50);
}

void init()
{
	add_action("do_accept", "accept");
        add_action("do_qiecuo","qiecuo");
}

int ask_help()
{
	object me = this_player();
	
	if (me->query("family/family_name") == "白駝山派" &&
		me->query("family/master_id") != "ouyang feng" &&
		me->query_condition("ice_sting") &&
		me->query_condition("ice_sting") < 10)
	{
		message_vision(HIG"歐陽鋒說道：“好，救你不難，但是你須答應(accept)叫我一聲爸爸。”\n"NOR, me);
		me->set_temp("helpme", 1);
		return 1;
	}
	return 0;
}

int do_accept()
{
	if (this_player()->query_temp("helpme"))
	{
		this_player()->set("oyf_son", 1);
		this_player()->apply_condition("ice_sting", 0);
		message_vision( HIY"歐陽鋒哈哈大笑，聲震林梢：“好，好，乖兒子，我就傳你蛤蟆功作見面禮吧！只要你勤加修習，”\n", this_player());
		message_vision( HIY"不但除去身上劇毒輕而易舉，他日稱霸武林，光我白駝亦非難事！“ \n", this_player());
		tell_object(this_player(),HIG"你按照歐陽鋒所傳依法行功，胸口痛楚立減，不由得喜上眉梢。\n"NOR);
		this_player()->set_temp("baifeng", 1);
		return 1;
	} else return notify_fail("歐陽鋒瞥了你一眼：“你沒事瞎答應甚麼！”\n");
}

void attempt_apprentice(object ob)
{
//	if (ob->query_temp("baifeng") && ob->query("combat_exp") > 50000 && ob->query("age") <= 18 && ob->query("age") >= 16)
	if (ob->query_temp("baifeng") && ob->query("combat_exp") > 50000 )
		command("recruit " + ob->query("id"));
	else message_vision("歐陽鋒瞪了$N一眼道：“我白駝山不世藝業豈可輕傳。”\n", ob); 	
}
