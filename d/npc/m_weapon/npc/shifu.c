// npc: shifu.c
// Last Modified by Winder on Oct. 24 2000

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("侍斧", ({ "shifu"}) );
	set("nickname", RED "斧" NOR );
	set("gender", "男性" );
	set("type","斧");
	set("age", 20);
	set("no_get", 1);
	set("long", 	
		"他頭上包着白布頭巾，上身精赤，一身虯肌。\n");
	set("str", 25);
	set("dex", 20);
	set("con", 17);
	set("int", 30);
	set("shen_type", 0);
	set("max_neli",500);
	set("jiali",50);
	set_skill("unarmed", 100);
	set_skill("dodge", 100);
	set_skill("force",150);
	set_skill("sword",150);
	set_skill("parry",90);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/damage",50);
	set("combat_exp", 250000);
	set("score",0);
	set("attitude", "peaceful");
	set("inquiry", ([
		"鑄斧" : "師傅命我幫助別人鑄斧，但到現在也不見一個人影。誰要鑄斧呢？\n",
		"原料" : "鑄斧可用海底金母，隕星鐵石。但效果各不一樣。\n",
	]) );
	setup();
	carry_object("/clone/misc/cloth")->wear();
}


int accept_object(object who, object ob)
{	
	if(!(who->query_temp("axe") ) )
	{
		message_vision(HIC"師傅沒有同意爲你鑄斧，您請回吧！\n"NOR, who);
		return 0;
	}
	who->delete_temp("axe");
	who->set_temp("m_make","斧");
	switch ((string)ob->query("id") ) 
	{
		case "jin mu":
			who->add_temp("jinmu",1);
			break;
		case "iron stone":
			who->add_temp("ironstone",1);
			break;
		default :
			message("vision","這是什麼！師傅說這不能用來打造兵器！\n",who);
			return 0;
	}
	message("vision", "侍斧低頭檢視了一下手中的"+(string)ob->query("name")+"點了點頭說：\n", who);
	message("vision","。。。好我們現在就開始鑄斧。\n", who);
	write("請這位"+RANK_D->query_respect(who)+"給斧起名字吧！(zhu 斧的名字 英文代號)\n");
	destruct(ob);
	return 2;
}
#include "shi.c"