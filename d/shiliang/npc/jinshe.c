// Feb. 6, 1999 by Winder
// jinshe.c 金蛇郎君
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void dest(object ob);
string ask_skill1(object me,string arg);
string ask_skill2(object me,string arg);
string ask_skill3(object me,string arg);
void create()
{
	set_name("夏雪宜", ({"xia xueyi", "xia", "xueyi"}));
	set("nickname", HIY"金蛇郎君"NOR);
	set("gender", "男性");
	set("age", 25);
	set("long", 
		"他就是人稱“金蛇郎君”的一代怪傑——夏雪宜。\n"
		"他做事全憑好惡，時正時邪，端地是獨來獨往，好不瀟灑！\n"
		"聽説他的身世很慘，人也變得偏激起來。\n"
		"看起來他好象受了點傷，臉色很難看。\n");
 	set("attitude", "peaceful");
	
	set("str", 100);
	set("int", 20);
	set("con", 30);
	set("dex", 25);
	set("chat_chance", 15);
	set("chat_msg", ({
		"夏雪宜突然惡狠狠地説道：儀兒，你到底為什麼要害我！？\n",
		"夏雪宜眼中彷彿要噴出火來。\n",
                "突然，夏雪宜“哇”地一聲，吐出一大口帶黑的血。\n",
	}));
	set("inquiry", ([
		"溫儀": "她....她..... \n",
		"鎖劍訣" 	:	(: ask_skill1 :),
		"附骨纏身":	(: ask_skill2 :),
		"金蛇吐霧":	(: ask_skill3 :),
	]));
	set("qi", 10000);
	set("max_qi", 10000);
	set("jing", 5000);
	set("max_jing", 5000);
	set("neili", 9000);
	set("max_neili", 9000);
	set("jiali", 100);
	set("no_get",1);
	
	set("combat_exp", 10000000);
	 
	set_skill("force", 200);		// 基本內功
	set_skill("huntian-qigong", 200);	// 混天氣功
	set_skill("unarmed", 220);		// 基本拳腳
	set_skill("dodge", 200);		// 基本躲閃
	set_skill("parry", 200);		// 基本招架
        set_skill("sword", 200);                // 基本劍法
        set_skill("jinshe-jian",200);           // 金蛇劍法
	
	map_skill("force", "huntian-qigong");
	map_skill("sword", "jinshe-jian");
	map_skill("parry", "jinshe-jian");
	
	setup();
	
	carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}
int accept_object(object who, object ob)
{
	object obn;
	if( !who || environment(who) != environment() ) return 0;
	if ( !objectp(ob) ) return 0;
	if ( !present(ob, who) ) return notify_fail("你沒有這件東西。\n");
	if (  (string)ob->query("id") != "wen shoupa")
		    return notify_fail("夏雪宜不需要這件東西。\n");
         write(HIY "夏雪宜接過手帕，呆呆地出神，突然間潸然淚下。 \n" NOR);
         write(HIR "夏雪宜喃喃道：儀兒啊，我知道你的心意，其實就算是真的，我也不在乎的。\n" NOR);         
         write(HIY "夏雪宜轉過頭來對你説：我該怎樣感謝你呢？\n" NOR);
         write(HIY "他背轉身去，沉默不語，好象在思考着什麼。\n" NOR);
         write(HIY "夏雪宜突然象下了很大決心似地對你説：我看\n" NOR);
         write(HIY "你也是武林中人，這裏有兩本我畢身心血的《金蛇祕芨》，\n" NOR);
         write(HIY "現在它對我來説已經沒有什麼用了，你就拿去吧。\n" NOR);
         write(HIY "夏雪宜嘆了口氣道：你是鋤惡揚善也好，我行我素也好，胡作非為也好，通通與我無關。\n" NOR);
         write(HIY "夏雪宜揮了揮手：好了，你可以走了。\n" NOR);
         obn = new("/clone/book/jinshe2");
         obn->move(who);
         obn = new("/clone/book/jinshe3");
         obn->move(who);
         write(HIR "夏雪宜回首按了牆上的一個機關，只聽得隆隆幾聲巨響，石壁之上露出一個四方的洞口來。\n"NOR);
         "/d/shiliang/jinshedong"->set("exits/east","/d/shiliang/jinshedong1");
         destruct(ob);
         return 1;
}
void dest(object ob)
{
    destruct(ob);
}
string ask_skill1(object me,string arg)
{
	return teach_perform(this_player(),this_object(),([
		"perform"	: "suo",	//pfm的代碼
		"name"		: "鎖劍訣",	//pfm的名稱
		"sk1"		: "jinshe-jian",//主要的武功的id
		"lv1"		: 100,		//主要的武功的等級
		"sk2"		: "sword",	//需要武功sk2的id
		"lv2"		: 100,		//需要武功sk2 的等級
		"neili"		: 300,		//需要基本內功等級
		"free"		: 1, 		//free=1不需要同一門派
		"msg1"		: "$N哈哈一笑：要學其實這招並不難，天下人都以常理出招。\n"+
				"而我金蛇劍法反其道而行，劍訣要旨在於意境，不在招式。\n"+
				"$n聽了$N的指導，恍然大悟。",
		"msg2"		: "好了，你自己繼續練習吧。",
		]));
}
string ask_skill2(object me,string arg)
{
	return teach_perform(this_player(),this_object(),([
		"perform"	: "fugu",	//pfm的代碼
		"name"		: "附骨纏身",	//pfm的名稱
		"sk1"		: "jinshe-zhang",//主要的武功的id
		"lv1"		: 100,		//主要的武功的等級
		"sk2"		: "strike",	//需要武功sk2的id
		"lv2"		: 100,		//需要武功sk2 的等級
		"neili"		: 300,		//需要基本內功等級
		"free"		: 1, 		//free=1不需要同一門派
		]));
}
string ask_skill3(object me,string arg)
{
return teach_perform(this_player(),this_object(),([
		"perform" 	: "tuwu",	//pfm的代碼
		"name"		: "金蛇吐霧",	//pfm的名稱
		"sk1"		: "jinshe-zhui",//主要的武功的id
		"lv1"		: 100,		//主要的武功的等級
		"sk2"		: "throwing",	//需要武功sk2的id
		"lv2"		: 100,		//需要武功sk2 的等級
		"force"		: 100,		//需要基本內功等級
		"neili"		: 300,		//需要最大內力多少
		"free"		: 1, 		//free=1不需要同一門派
		]));
}
