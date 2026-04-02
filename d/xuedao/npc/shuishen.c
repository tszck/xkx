// shuisheng.c

inherit NPC;
#include <ansi.h>
string ask_me();
void create()
{
	set_name("水笙", ({ "shui sheng", "shui" }));
	set("long", 
	"她是個生得十分秀美清麗動人的江南佳麗。\n"
	"她和她的表哥汪嘯風號稱“鈴劍雙俠”，名動東南。\n");
	set("gender", "女性");
	set("nickname", HIM"鈴劍女俠"NOR);
	set("age", 16);
	set("attitude", "peaceful");
	set("shen_type", 0);
	set("per", 28);
	set("str", 25);
	set("int", 28);
	set("con", 25);
	set("dex", 25);

	set("max_qi", 1000);
	set("max_jing", 400);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 10);
	set("combat_exp", 200000);
	set("shen_type", 1);

	set_skill("force", 80);
	set_skill("huashan-neigong", 80);
	set_skill("dodge", 80);
	set_skill("huashan-shenfa", 80);
	set_skill("strike", 80);
	set_skill("huashan-zhangfa", 80);
	set_skill("parry", 80);
	set_skill("sword", 80);
	set_skill("huashan-jianfa", 80);
	set_skill("literate", 80);

	map_skill("force", "huashan-neigong");
	map_skill("dodge", "huashan-shenfa");
	map_skill("strike", "huashan-zhangfa");
	map_skill("parry", "huashan-jianfa");
	map_skill("sword", "huashan-jianfa");
	set("inquiry", ([
		"狄雲" : (: ask_me :),
	]));
	set("chang_count", 1);

	setup();
	carry_object("/clone/weapon/changjian")->wield();
}

string ask_me()
{
	mapping fam; 
	object ob;
	
	if (query("chang_count") < 1)
		return "狄大哥還好嗎？我在這裏等了他這麼久！我知道他終於會回來的。";
	add("chang_count", -1);
	ob = new("/d/xuedao/obj/dachang");
	ob->move(this_object());
	command("give da chang to "+this_player()->query("id"));
	return "狄大哥還好嗎？我在這一直等着他。麻煩你，把這領大氅交給他吧。";
}
