//Edited by fandog, 02/13/2000

inherit NPC;
string ask_me();

void create ()
{
	object weapon;
	set_name("狄雲", ({"di yun","di"}));
	set("long", "他長臉黝黑，顴骨微高，粗手大腳，象是湘西鄉下常見的莊稼漢子。\n");
	set("gender", "男性");
	set("age", 24);
	set("combat_exp", 1500000);
	set("str", 24);
	set("int", 15);
	set("dex", 18);
	set("con", 22);
	set("per", 28);
  
	set_skill("force", 200);
	set_skill("unarmed", 200);
	set_skill("dodge", 200);
	set_skill("blade", 200);
	set_skill("yanfly", 200);
	set_skill("shenzhao-jing", 300);
	set_skill("xue-dao", 200);
	map_skill("force", "shenzhao-jing");
	map_skill("blade", "xue-dao");
	map_skill("parry", "xue-dao");
	map_skill("unarmed", "shenzhao-jing");
	map_skill("dodge", "yanfly");
	set("inquiry", ([
		"水笙" : (: ask_me :),
	]));
	set("wucan_count", 1);
	setup();
	carry_object("/clone/cloth/cloth")->wear();
	if (clonep())
	{
		weapon = new( WEAPON_DIR"treasure/xblade" );	
		if ( weapon->violate_unique() )
		{
			destruct( weapon );
			weapon = new( "/clone/weapon/gangdao" );
		}
		weapon->move(this_object());
		weapon->wield();
	}
} 

string ask_me()
{
  
 
	
	if (query("wucan_count") < 1)
		return "水笙姑娘？她在雪域等着我？";

	add("wucan_count", -1);
	this_player()->set_temp("marks/wucan", 1);
	return "水笙姑娘？她在雪域等着我？她有什麼東西捎給我麼？";
}
int accept_object(object who, object ob)
{
	object obj;
	if (ob->query("id") != "da chang")
		return notify_fail("給我這東西有什麼用？");
	message_vision("狄雲笑着説道：“謝謝你！這位" + RANK_D->query_respect(ob) +"，辛苦你了。”\n", who);
	if (!who->query_temp("marks/wucan"))
	{
		return 1;
	}
	obj = new(ARMOR_DIR"treasure/wucanyi");
	this_player()->delete_temp("marks/wucan");
	if ( obj->violate_unique() || uptime() < 300)
	{
		destruct( obj );
		return 1;
	}
	message_vision("狄雲對$N説道：“這件烏蠶衣也不算是什麼寶貝，聊表心意吧！”狄雲從懷裏掏出一團不起眼的東西，遞到$N的手上。\n", who);
	obj->move(this_player());
	return 1;
}