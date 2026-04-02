inherit NPC;
#include <ansi.h>


int ask_me();

void create()
{
	set_name("公平子", ({ "gongping zi", "zi", "referee" }) );
	set("gender", "男性");
	set("age", 35);
	set("long",
		"這是一位仙風道骨的中年道人，早年雲遊四方，性好任俠，公正無私。\n");

	set("combat_exp",60000);
                set("shen_type", 1);
	set("attitude", "friendly");

	set("max_qi", 800);
	set("max_jing", 800);
	set("max_neili", 800);
	set("owner","mud os");

	set("win_times", 0);

	set_skill("force", 80);
	set_skill("unarmed", 80);
	set_skill("sword",80);
	set_skill("parry",80);
	set_skill("dodge", 80);
	set("inquiry", ([
		"華山論劍"       : (: ask_me :),
	]));
  
	setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/d/city/obj/changjian")->wield();
}

void init()
{
        add_action("do_sign", "sign");
        add_action("do_join", "join");
}

//mixed ask_me()
int ask_me()
{
        object me;

        me = this_player();
        if (PK_D->is_pking())
        {
        	tell_object(me,"公平子對你說道：“現在華山論劍正在舉行呢，你想幹什麼？”\n");
		return 1;
	}
        else if (PK_D->is_ready())
        {
        	tell_object(me,"公平子對你說道：“很好，現在華山論劍正要開始，你要報名(sign)麼？”\n");
		return 1;
	}
	else
	{
        	tell_object(me,"公平子對你說道：“華山論劍？你慢慢等着吧。要是無聊，現在要是想進去玩玩(join)也行。”\n");
		return 1;
	}
}

int do_sign()
{
        object me;
        string msg;
        

        me = this_player();
        message_vision(CYN "\n$N" CYN "陪着笑臉對$n" CYN "道：您好，您好，我也來籤個到。\n" NOR, me, this_object());
        
        if (stringp(msg = PK_D->reject_join(me)))
        {
		tell_object(me,"公平子對你說道：“"+msg+"”\n");
                return 1;
        }
        
	me->set_temp("bwdh_join",1);
       	tell_object(me,"公平子對你說道：“華山論劍馬上就要開始了，閣下做好準備就趕快加入吧（join）！”\n");
        return 1;
}

int do_join()
{
        object me;
        object *obs;
        int i;
        
        me=this_player();
        if (PK_D->is_pking())
        {
        	tell_object(me,"公平子對你說道：“現在華山論劍正在進行中，你還是等等吧。”\n");
		return 1;
	}
	
	if (PK_D->is_ready() && !me->query_temp("bwdh_join") )
        {
        	tell_object(me,"公平子對你說道：“想要參加論劍的趕緊先報名（sign）吧，其他人還是等等吧。”\n");
		return 1;
	}
	
	obs = all_inventory(me);
	for ( i = 0 ; i < sizeof(obs); i++)
        {
                if (obs[i]->is_character())
                {
                        tell_object(me,"公平子對你說道：“閣下身上揹着誰呢？還是先放下再來吧！”\n");
                        return 1;
                }
        }
        
        message_vision(CYN "$N" CYN "賠笑對$n" CYN "道：我想要參加華山論劍，放行可好？\n" NOR, this_player(), this_object());

        if (!PK_D->join_competition(this_player()))
        {
                message("vision", HIW + this_player()->name() + HIW "一閃身進了紫竹林。\n" NOR, environment());
                return 1;
        }
        else
        {
        	tell_object(me,"公平子對你說道：“閣下還是改日再來參加華山論劍吧！”\n");
                return 1;
        }
        	      
}

void unconcious()
{
        die();
}

