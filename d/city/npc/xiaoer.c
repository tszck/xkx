// xiaoer.c

// inherit NPC;
inherit F_VENDOR_SALE;
#include <ansi.h>

void create()
{
//	reload("xiaoer");
	set_name("店小二", ({ "xiao er", "xiao", "waiter" }) );
	set("gender", "男性" );
	set("age", 22);
	set("long",
		"這位店小二正笑咪咪地忙著，還不時拿起掛在脖子上的抹布擦臉。\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("rank_info/respect", "小二哥");
	setup();
}
void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if (wizardp(ob)) return;
	if (!ob->query_temp("welcome100") || ob->query("mud_age")<1000)
	{
		ob->set_temp("welcome100","1");
tell_object(ob,"\n\n店小二笑咪咪地説道：這位"+RANK_D->query_respect(ob)+"，歡迎來到"GRN"俠客行一百。"NOR"

    如果您有什麼不明白的，可以問"RED"tell"NOR"老玩家。缺錢花，也可以請老
玩家幫您暫渡難關。大俠們都會樂於助人的。當然您也可以用"RED"help"NOR"來獲
得我們給您的幫助。
    您在"HIR"help"NOR"中能看到很多幫助項目。
    這裏的故事和情節，謎語的基本依據是金庸的十五本小説。如果您
對故事不太記得了或想了解多些可以用"RED"help intro"NOR"這個幫助項。如果您
從沒玩過 MUD遊戲，那就先看看"RED"help newbie"NOR"來新手上路吧。"RED"help cmds"NOR"
是這裏所有玩家都能用的命令。想認識一下這裏的地圖就"RED"map map"NOR"，裏
面有很多項目的，您可以選擇地圖項目"RED"map all"NOR"看到整個遊戲的地圖。
而在露天直接"RED"map "NOR"就是您現在呆的地方的地圖。當然最重要的是向老玩
家請教，這就一定要會使用"RED"chat"NOR"這個命令啦。這裏的幫助文件也因為我
們的工作而更新，多多留意哦。客店往西，南，南，東就到武館了，叛
師在這裏會喫虧的，所以沒想好拜哪個門派就先去武館學。揚州的武廟
是信息中心，常去看看那裏的公告，最新的消息一定最早出現在那裏。
    如果您對這個遊戲的設計和管理有什麼建議或意見，請不妨直接在
這"RED"mailto winder"NOR" 或者其他巫師，我們一定會認真考慮的。\n\n");
	}
	switch( random(2) ) {
		case 0:
			say( "店小二笑咪咪地説道：這位" + RANK_D->query_respect(ob)
				+ "，進來喝杯茶，歇歇腿吧。\n");
			break;
		case 1:
			say( "店小二用脖子上的毛巾抹了抹手，説道：這位" + RANK_D->query_respect(ob)
				+ "，請進請進。\n");
			break;
	}
}
int accept_object(object who, object ob)
{
	
	if (ob->query("money_id") && ob->value() >= 5000) 
	{
		tell_object(who, "小二一哈腰，説道：多謝您老，客官請上樓歇息。\n");

		who->set_temp("rent_paid",1);

		return 1;
	}

	return 0;
}
