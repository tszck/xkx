// yang.c 楊老闆 

inherit NPC;
inherit F_DEALER;
string ask_mask();

void create()
{
	set_name("楊永福", ({ "Yang yongfu", "yang" }));
	set("title", "雜貨鋪老闆");
	set("shen_type", 1);

	set("gender", "男性");
	set("age", 45);
	set("long",
		"楊老闆是土生土長的揚州人，做了幾十年的小買賣。
聽說他最近得了一樣寶物，卻不知是什麼好東西。\n");
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_temp("apply/damage", 15);

	set("combat_exp", 40000);
	set("attitude", "friendly");
	set("inquiry", ([
		"寶物" : (: ask_mask :),
		"寶貝" : (: ask_mask :),
		"mask" : (: ask_mask :),
		"面具" : (: ask_mask :),
	]));
	set("vendor_goods", ({
		"/clone/misc/chutou",
		"/clone/misc/fire",
		"/clone/misc/shihui",
		"/clone/misc/yanwu",
		WEAPON_DIR"muchui",
		WEAPON_DIR"club",
		FOOD_DIR+"sugar/xitang",
		__DIR__"obj/mabudai",
		__DIR__"obj/beixin",
		__DIR__"obj/toukui",
		__DIR__"obj/cycle",
		__DIR__"obj/surcoat",
		__DIR__"obj/shield",
		__DIR__"obj/huwan",
		__DIR__"obj/zhitao",
		__DIR__"obj/huyao",
		__DIR__"obj/caoxie",
		__DIR__"obj/pixue",
		__DIR__"obj/shoutao",
		__DIR__"obj/tieshou",
		__DIR__"obj/jinsijia",
		__DIR__"obj/hongbao", 
		__DIR__"obj/lan",
		__DIR__"obj/marrybox",
		__DIR__"obj/map",
	}));
	
	setup();
	set("count",1);
	carry_object(CLOTH_DIR"cloth")->wear();
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}
string ask_mask()
{
	object me, ob;
	
	me = this_player();
	ob = this_object();
	if (query("count")>0)
	{
		message("vision",ob->name()+"在"+me->name()+"耳邊嘀咕了幾句什麼。\n",me,({me}));
		tell_object(me,ob->name()+"悄悄告訴你：我是有樣上古寶貝，給我五百兩黃金就轉讓給你。\n");
	}
	return "沒有沒有，我什麼都不知道啊。";
}
int accept_object(object who,object ob)
{
	object obj;
	
	if (!query("count") || !ob->query("money_id") || ob->value()<5000000)
	{
		message_vision("$N說道：你給我這個做什麼？\n",this_object());
		return 0;
	}
	if (query("count")>0)
	{
		obj = new("/clone/misc/mask1");
		obj->move(this_player());
		add("count",-1);
		message_vision("$N取出一個包裹，交給$n。\n",this_object(),who);
		tell_object(who,"你急忙打開包裹，竟然是一個精緻的人皮面具。\n");
		return 1;
	}
}