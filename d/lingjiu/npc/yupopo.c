// NPC yupopo.c
// modified by rocwood

#include <ansi.h>
inherit NPC;
string ask_me();
void create()
{
	set_name("餘婆婆", ({ "yu popo", "yu", "popo" }));
	set("long",
		"她是「靈鷲宮」九天九部中昊天部的首領。
她跟隨童姥多年，出生入死，飽經風霜。\n");
	set("title", "靈鷲宮昊天部首領");
	set("gender", "女性");
	set("class", "dancer");
	set("age", 60);
	set("shen_type",1);
	set("attitude", "peaceful");

	set("str", 20);
	set("int", 25);
	set("con", 30);
	set("dex", 30);

	set("qi", 2000);
	set("max_qi", 2000);
	set("jing", 1500);
	set("max_jing", 1500);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 50);

	set("combat_exp", 100000);
	set("score", 10000);
	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("hand",100);
	set_skill("strike", 100);
	set_skill("sword",100);
	set_skill("tianyu-qijian",100);
	set_skill("zhemei-shou",100);
	set_skill("liuyang-zhang",100);
	set_skill("yueying-wubu",100);
	set_skill("bahuang-gong", 100);
	map_skill("force", "bahuang-gong");
	map_skill("dodge", "yueying-wubu");
	map_skill("strike","liuyang-zhang");
	map_skill("hand", "zhemei-shou");
	map_skill("parry", "liuyang-zhang");
	map_skill("sword", "tianyu-qijian");
	prepare_skill("strike","liuyang-zhang");
	prepare_skill("hand", "zhemei-shou");
	create_family("靈鷲宮",2,"弟子");
	set("inquiry", ([
		"靈鷲宮" : (: ask_me :),
		"拜師"   : (: ask_me :),
	]));
	setup();
	carry_object("/d/lingjiu/obj/qingyi")->wear();
	carry_object("/d/lingjiu/obj/doupeng")->wear();
	carry_object("/clone/weapon/changjian")->wield();
	add_money("silver",40);
}

void die()
{
	message("vision", HIW"\n餘婆婆嘆道：“唉，主人，沒想到老身不能守住百丈澗！哼，讓你們也過不去！”\n"NOR,"/d/lingjiu/jian");
	message("vision", HIW"餘婆婆揮動長劍，只聽見“乒”的一聲，碗口粗的鐵索斷斷成了兩截。\n"NOR,"/d/lingjiu/jian");
//	message_vision("$N慘叫一聲，死了！\n", this_object());
	::die();
}
string ask_me()
{
	object ob=this_player(),room;
	if(!( room = find_object("/d/lingjiu/xianchou")) )
		room = load_object("/d/lingjiu/xianchou");
	if (!(string)ob->query("family/family_name"))
	{
		if ((string)ob->query("gender")=="女性")
		{
			message_vision("餘婆婆衝着$N微笑説：你是來拜師的吧，我送你進去。\n",ob);
			message_vision("餘婆婆長袖一拂，$N只覺得一陣狂風吹來，慢慢被吹到山澗對面去。\n",ob);
			ob->move(room);
			return "靈鷲宮的將來有希望了。\n";
		} else return "無恥奸徒打聽我靈鷲宮有何居心！\n";
	}
	if ((string)ob->query("family/family_name")=="靈鷲宮")
	{
		message_vision("餘婆婆衝着$N點點頭，微微笑了笑。\n",ob);
		return "諸位靈鷲宮弟子辛苦了。\n";
	}
	return  "老身奉主人之命守衞百丈澗，非靈鷲宮弟子請回！";
}

