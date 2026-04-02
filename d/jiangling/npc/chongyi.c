//Edited by fandog, 02/15/2000
#include <ansi.h>
inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("蟲一居士"NOR, ({ "chongyi jushi", "chongyi" }));
	set("title", "茶館老闆");
	set("nickname", HIW"風月"HIY"無邊"HIB"不見天"NOR);
	set("shen_type", 1);

	set("str", 30);
	set("gender", "男性");
	set("age", 25);
	set("long","
這位蟲一先生可是個風雅之人，他不喜出門，成天在茶館裏
和來往的客人談詩論畫。\n");
	set("combat_exp", 500);
	set("attitude", "friendly");
	
	set("vendor_goods", ({
		"/d/jiangling/obj/jiuhuangb",
		"/d/jiangling/obj/babao",
	}));

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}

