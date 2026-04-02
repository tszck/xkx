
inherit __DIR__"changer.c";

int  ask_for_y();
int  ask_for_z();
int  ask_for_n();

int  zuotun = 1;
int  yaozi = 1;
int  erduo = 1;

void  create()
{
	set_name("肉販", ({ "rou fan" }));
	set("gender", "男性");
	set("age", 25);
	set("per", 15);
	set("combat_exp", 100);
        set("attitude", "friendly");
        set("exchangeable_goods", ({
        	__DIR__"obj/chop",
        	__DIR__"obj/hen",
        	__DIR__"obj/cock",
        	__DIR__"obj/meat",
        	__DIR__"obj/beef",
        }));	
        set("want_goods", ({
        	__DIR__"obj/baicai",
        	__DIR__"obj/qingcai",
        }));	
        set("inquiry", ([
        	"羊羔坐臀"  :  (: ask_for_y :),
        	"小牛腰子"  :  (: ask_for_n :),
        	"小豬耳朵"  :  (: ask_for_z :),
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
	
	if ( zuotun == 1 && random(me->query("kar")) > 10 ) {
		command( "say 算你走運，我這兒還剩下一塊，送給你吧。" );
		message_vision( this_object()->query("name") + "拿出一塊羊羔坐臀遞給$N。\n", me );
		ob = new( __DIR__"obj/zuotun" );
		ob->move( me );
		zuotun = 0;
	}	
	else 
		command( "say 您來得太遲，羊羔坐臀俺給送人了。" );
	return 1;
}

int  ask_for_n()
{
	object me = this_player(), ob;
	
	if ( yaozi == 1 && random(me->query("kar")) > 10 ) {
		command( "say 這東西可不好弄到，看在老主顧的份上就給你一個吧。" );
		message_vision( this_object()->query("name") + "拿出一個小牛腰子遞給$N。\n", me );
		ob = new( __DIR__"obj/yaozi" );
		ob->move( me );
		yaozi = 0;
	}	
	else 
		command( "say 您來得太遲，小牛腰子俺給送人了。" );
	return 1;
}

int  ask_for_z()
{
	object me = this_player(), ob;
	
	if ( erduo == 1 && random(me->query("kar")) > 10 ) {
		command( "say 我留着這玩意兒也沒用，你要就拿去。" );
		message_vision( this_object()->query("name") + "拿出一塊小豬耳朵遞給$N。\n", me );
		ob = new( __DIR__"obj/erduo" );
		ob->move( me );
		erduo = 0;
	}	
	else 
		command( "say 您來得太遲，小豬耳朵俺給送人了。" );
	return 1;
}