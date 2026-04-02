// Npc: /d/lingxiao/npc/shi.c
// Last Modified by winder on Jul. 15 2001

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("時萬年",({"shi wannian","shi",}));
	set("gender", "男性");
	set("age", 20);
	set("long", "他是凌霄城第六代弟子時萬年，在此守衞監獄。\n");
	set("attitude", "peaceful");

	set("no_get", 1);
	set("str", 30);
	set("con", 30);
	set("int", 24);
	set("dex", 30);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jing", 800);
	set("max_jing", 800);
	set("qi", 1500);
	set("max_qi", 1500);

	set("combat_exp", 250000); 
	set("shen_type", 0);
	set("score", 20000);

	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :)
	}) );
	set("chat_chance", 5);
	set("chat_msg", ({
	"時萬年恨恨説道：老瘋子不知道又怎麼了，把自己關在裏面弄死不肯出來。\n", 
	"時萬年把劍一彈，傲然道：有我守在這，誰都別想把老瘋子放出來。\n", 
	}) );
	set_skill("strike", 120);
	set_skill("sword", 150);
	set_skill("force", 120);
	set_skill("parry", 120);
	set_skill("dodge", 150);
	set_skill("literate", 80);

	set_skill("xueshan-sword", 150);
	set_skill("bingxue-xinfa", 120);
	set_skill("snow-strike", 120);
	set_skill("snowstep", 120);

	map_skill("sword", "xueshan-sword");
	map_skill("parry", "xueshan-sword");
	map_skill("force", "bingxue-xinfa");
	map_skill("strike", "snow-strike");
	map_skill("dodge", "snowstep");
	prepare_skill("strike", "snow-strike");

	create_family("凌霄城", 6, "弟子");
	setup();
	
	carry_object("/clone/weapon/changjian")->wield();
	carry_object(CLOTH_DIR+"bai")->wear();
} 
void init()
{ 
	object ob;
	::init();

	ob = this_player();
	if(ob->query("family/family_name") !="凌霄城")
	{
		command("heng");
		command("say 你居然敢闖入本派禁地，受死吧！\n");
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob); 
	}
	else
		if(ob->query("family/master_id")=="bai zizai")
		{
			command( "say 師兄回來了，快去見掌門人吧，不過小心點……沒準他又犯病了。");
		} 
		else
			if(ob->query("family/master_id")=="bai wanjian")
			{
				command( "say 你是白師哥的弟子吧，快進去見見老爺子吧，他的病越來越不得了啦。");
			}
}

