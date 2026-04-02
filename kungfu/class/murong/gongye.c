// gongye.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("公冶乾", ({ "gongye qian", "gongye","qian" }));
	set("title", "姑蘇慕容 "HIR"赤霞莊主"NOR );
	set("long", "這是一個文士打扮的中年書生，豪邁過人。\n");
	set("gender", "男性");
	set("class", "scholar");
	set("age", 40);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 2000);
	set("max_jing", 1100);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 100);
	set("combat_exp", 400000);
	set("score", 50000);

	set_skill("force", 110);
	set_skill("dodge", 110);
	set_skill("parry", 110);
	set_skill("sword", 110);
	set_skill("blade", 110);
	set_skill("strike", 110);
	set_skill("finger", 110);
	set_skill("literate", 110);
	set_skill("murong-sword", 160);
	set_skill("murong-blade", 160);
	set_skill("canhe-finger", 160);
	set_skill("xingyi-strike", 160);
	set_skill("shenyuan-gong", 110);
	set_skill("yanling-shenfa", 160);
	map_skill("parry", "murong-sword");
	map_skill("sword", "murong-sword");
	map_skill("blade", "murong-blade");
	map_skill("force", "shenyuan-gong");
	map_skill("dodge", "yanling-shenfa");
	map_skill("finger", "canhe-finger");
	map_skill("strike", "xingyi-strike");
	prepare_skill("finger", "canhe-finger");
	prepare_skill("strike", "xingyi-strike");
	set("env/wimpy", 60);
	set("chat_chance_combat", 60);  
	set("chat_msg_combat", ({		
		(: perform_action, "sword.lianhuan" :),
		(: perform_action, "finger.dian" :),
		(: exert_function, "powerup" :),
		(: exert_function, "reserve" :),
		(: exert_function, "recover" :),
	}) );
	set("inquiry",([
		"王語嫣"   : "只有她才配得上我們公子，也不知她現在怎樣了！\n",
		"南慕容" : "我家公子和丐幫喬幫主齊名，合稱“南慕容北喬峯”！\n",
		"慕容復"   : "哎，這你也不懂，他就是我家公子！\n",
		"王夫人"   : "就是公子爺的舅媽，曼陀山莊的莊主！\n",
		"阿朱"     : "那小妮子只大我一歲，整天就喜歡扮別人玩。\n",
		"鄧百川"   : "你問鄧大哥啊？他在他青風莊上呢。\n",
		"公冶乾"   : "別問我，煩着呢。\n",
		"包不同"   : "包三弟最愛擡槓了，你見了他還是閉嘴的好。\n",
		"風波惡"   : "風四弟最是豪爽了，他從不與人計較什麼。\n",
	]) );

	create_family("姑蘇慕容", 33, "弟子");
 	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query("betrayer") > 0)
	{
		command("say 這位" + RANK_D->query_respect(ob) +
			"，我慕容家復國乃至爲要事，你心志不堅，無緣我門。");
		return;
	}
	if ((int)ob->query_skill("shenyuan-gong", 1) < 50)
	{
		command("say 姑蘇慕容家武功，以內功爲根基。");
		command("say "+RANK_D->query_respect(ob)+"還應該多加努力！");
		return;
	}
	command("say 好吧我就收你爲徒吧。");
	command("recruit " + ob->query("id"));
}
