
inherit __DIR__"changer.c";

int ask_for_y();

int yingtao = 1;

void  create()
{
	set_name("瓜農", ({ "gua nong" }));
	set("gender", "男性");
	set("age", 25);
	set("per", 15);
	set("combat_exp", 100);
        set("attitude", "friendly");
        set("exchangeable_goods", ({
        	__DIR__"obj/cuke",
        	__DIR__"obj/carrot",
        	__DIR__"obj/donggua",
        	__DIR__"obj/bean",
        }));	
        set("want_goods", ({
        	__DIR__"obj/chop",
        	__DIR__"obj/hen",
        }));	
        set("inquiry", ([
        	"櫻桃"	: (: ask_for_y :),
        ]));
        setup();
        carry_object("/clone/misc/cloth")->wear();	
}

void  init()
{
	add_action("do_change", "change");
	add_action("do_list", "list");
}

int  ask_for_y()
{
	object me = this_player(), ob;
	
	if ( yingtao == 0 || random(me->query("kar")) < 10 ) 
                command( "say 您來得太遲，櫻桃我已經送人了。" );
	else {
		command( "say 我自己栽的櫻桃樹今年結果了，摘了滿滿一籃那。" );
		command( "say 既然這位" + RANK_D->query_respect(me) + "開口了，就送你一些吧。" );
		message_vision( "瓜農從籃裏倒了一些櫻桃出來送給$N。\n", me );
		ob = new( __DIR__"obj/yingtao" );
		ob->move( me );
		yingtao = 0;
	}
	return 1;
}
