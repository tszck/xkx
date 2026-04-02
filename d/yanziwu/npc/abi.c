// abi.c

inherit NPC;
//inherit F_SKILL;

void create()
{
	set_name("阿碧", ({ "abi", "bi" }));
	set("long",
		"這是個身穿綠衣的女郎，約十六七歲年紀，滿臉都是溫柔，\n"
		"滿身都是秀氣。一張可愛的瓜子臉，膚白如新剝鮮藕，説話\n"
		"聲音極甜極清，令人一聽之下説不出的舒適。嘴角邊一粒細\n"
		"細的黑痣，更增俏媚。\n");
	set("gender", "女性");
	set("age", 16);
	set("per", 28);
	set("shen_type", 1);

	set("neili", 200);
	set("max_neili", 200);
	set("max_qi", 160);
	set("max_jing", 160);
	set_skill("force", 40);
	set_skill("dodge", 30);
	set_skill("parry", 30);
	set_skill("sword", 30);
	set_skill("blade", 30);
	set_skill("strike", 40);
	set_skill("finger", 40);
	set_skill("murong-sword", 30);
	set_skill("murong-blade", 30);
	set_skill("canhe-finger", 30);
	set_skill("xingyi-strike", 30);
	set_skill("shenyuan-gong", 30);
	set_skill("yanling-shenfa", 30);
	map_skill("parry", "murong-sword");
	map_skill("sword", "murong-sword");
	map_skill("blade", "murong-blade");
	map_skill("force", "shenyuan-gong");
	map_skill("dodge", "yanling-shenfa");
	map_skill("finger", "canhe-finger");
	map_skill("strike", "xingyi-strike");
	prepare_skill("finger", "canhe-finger");
	prepare_skill("strike", "xingyi-strike");

	set("combat_exp", 10000);
	set("inquiry",([
		"曼陀山莊" : "我才不敢去曼陀山莊，王夫人太霸道了！\n",
		"王語嫣" : "哎，只有她才配得上我們公子，也不知她現在怎樣了！\n",
		"阿朱"     : "那小妮子只大我一歲，整天就喜歡扮別人玩。\n",
	]) );
	create_family("姑蘇慕容", 33, "弟子");
	setup();
	carry_object(__DIR__"obj/goldring")->wear();
	carry_object(__DIR__"obj/necklace")->wear();
	carry_object("clone/weapon/changjian")->wield();
	carry_object(__DIR__"obj/green_cloth")->wear();
	carry_object(__DIR__"obj/flower_shoe")->wear();
}
