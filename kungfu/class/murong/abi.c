// abi.c

inherit NPC;
//inherit F_SKILL;

void create()
{
	set_name("阿碧", ({ "a bi", "bi" }));
	set("long",
		"這是個身穿綠衣的女郎，約十六七歲年紀，滿臉都是溫柔，\n"
		"滿身都是秀氣。一張可愛的瓜子臉，膚白如新剝鮮藕，説話\n"
		"聲音極甜極清，令人一聽之下説不出的舒適。嘴角邊一粒細\n"
		"細的黑痣，更增俏媚。\n");
	set("gender", "女性");
	set("class", "scholar");
	set("age", 16);
	set("per", 28);
	set("shen_type", 1);

	set("neili", 200);
	set("max_neili", 200);
	set("max_qi", 160);
	set("max_jing", 160);
	set_skill("force", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	set_skill("sword", 50);
	set_skill("blade", 50);
	set_skill("strike", 50);
	set_skill("finger", 50);
	set_skill("murong-sword", 50);
	set_skill("murong-blade", 50);
	set_skill("canhe-finger", 30);
	set_skill("xingyi-strike", 30);
	set_skill("shenyuan-gong", 50);
	set_skill("yanling-shenfa", 50);
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

	set("combat_exp", 10000);
	set("inquiry",([
		"曼陀山莊" : "我才不敢去曼陀山莊，王夫人太霸道了！\n",
		"王語嫣" : "哎，只有她才配得上我們公子，也不知她現在怎樣了！\n",
		"南慕容" : "我家公子和丐幫喬幫主齊名，合稱“南慕容北喬峯”！\n",
		"慕容復"   : "哎，這你也不懂，他就是我家公子！\n",
		"王夫人"   : "就是公子爺的舅媽，曼陀山莊的莊主！\n",
		"阿朱"     : "那小妮子只大我一歲，整天就喜歡扮別人玩。\n",
		"鄧百川"   : "你問鄧大哥啊？他在他青風莊上呢。\n",
		"公冶乾"   : "公冶二哥把信鴿傳書一編碼，就沒幾個人讀得懂了。\n",
		"包不同"   : "包三哥最愛抬槓了，你見了他還是閉嘴的好。\n",
		"風波惡"   : "風四哥最是豪爽了，他從不與人計較什麼。\n",
	]) );
	create_family("姑蘇慕容", 33, "弟子");
	setup();
	carry_object("/d/yanziwu/npc/obj/goldring")->wear();
	carry_object("/d/yanziwu/npc/obj/necklace")->wear();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/yanziwu/npc/obj/green_cloth")->wear();
	carry_object("/d/yanziwu/npc/obj/flower_shoe")->wear();
}
void attempt_apprentice(object ob)
{
	if ((int)ob->query("betrayer") > 0)
	{
		command("say 這位" + RANK_D->query_respect(ob) +
			"，我慕容家復國乃至為要事，你心志不堅，無緣我門。");
		return;
	}
	command("say 好吧我就收你為徒吧。");
	command("recruit " + ob->query("id"));
}
