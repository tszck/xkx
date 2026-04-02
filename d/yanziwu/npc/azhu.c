// azhu.c

inherit NPC;
//inherit F_SKILL;
int inquiry_tanqin();

void create()
{
	set_name("阿朱", ({ "azhu", "zhu" }));
	set("long",
		"這是個身穿紅衣的女郎，大約十七八歲，一臉精靈頑皮的神氣。\n"
		"一張鵝蛋臉，眼珠靈動，別有一番動人風韻。\n");

	set("gender", "女性");
	set("age", 17);
	set("per", 29);
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
		"阿碧" : "那小丫頭也不只跑哪兒去了。\n",
		"彈琴" : ( : inquiry_tanqin : ),
	]) );
	create_family("姑蘇慕容", 33, "弟子");
	setup();
	carry_object(__DIR__"obj/goldring")->wear();
	carry_object(__DIR__"obj/necklace")->wear();
	carry_object("clone/weapon/changjian")->wield();
	carry_object(__DIR__"obj/pink_cloth")->wear();
	carry_object(__DIR__"obj/flower_shoe")->wear();
	carry_object("clone/misc/mask");
}

int inquiry_tanqin()
{
	object me=this_player();
message_vision("阿朱説道：這位"+ RANK_D->query_respect(me)+"這麼有雅興，那我就為你彈奏一曲?\n只聽琴聲繁複清亮，你不由的癡了。\n", me );
//	細細品來，竟是張信哲的<<愛如潮水>>!!!\n 
	message_vision("阿朱一曲終了，道個萬福，説道：現醜了。\n", me );
	return 1;
}
