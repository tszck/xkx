
inherit __DIR__"changer.c";

int ask_for_s();

int sunjian = 1;

void  create()
{
	set_name("老農", ({ "old man" }));
	set("gender", "男性");
	set("age", 50);
	set("per", 15);
	set("long", "一位山裏來的老大爺。\n");
	set("combat_exp", 100);
        set("attitude", "friendly");
        set("exchangeable_goods", ({
        	__DIR__"obj/xianggu",
        	__DIR__"obj/lizi",
        }));	
        set("inquiry", ([
        	"筍尖"	:  (: ask_for_s :),
        ]));
        set("want_goods", ({
        	__DIR__"obj/cuke",
        	__DIR__"obj/meat",
        }));	
        setup();
        carry_object("/clone/misc/cloth")->wear();	
}

void  init()
{
	add_action("do_change", "change");
	add_action("do_list", "list");
}

int  ask_for_s()
{
	object me = this_player(), ob;
	
	if ( sunjian == 0 || random(me->query("kar")) < 10 ) 
                  command( "say 您來得太遲，筍尖我已經送人了。" );
 	else
 	   {
	          command( "say 我摘香菇的時候順便摘了些筍尖，這位" + RANK_D->query_respect(me) + "要的話就送給你好了。" );
		  message_vision( "老農送給$N一袋筍尖。\n", me );
		  ob = new( __DIR__"obj/sunjian" );
		  ob->move( me );
		  sunjian = 0;
	   }
	return 1;	
}