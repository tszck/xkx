// cunzhang.c

inherit NPC;
//inherit F_SKILL;
int zao(string msg);
int xiu(string msg);
int change();
int chai();

void create()
{
	set_name("桃花村長", ({ "cun zhang", "zhang" }));
	set("gender", "男性");
	set("age", random(10) + 40);
	set("str", 25);
	set("dex", 16);
	set("per", 20);
	set("long", "他是桃花村長，誰想在桃花村造屋安家，都要經過他老人家的
同意。他是個面目慈善的老漢。很得全村人的尊重。\n");
	set("combat_exp", 75000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("unarmed", 60);
	set_skill("force", 60);
	set_skill("sword", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 30);

	set("neili", 400); 
	set("max_neili", 400);
	set("jiali", 10);
	set("inquiry", ([
		"造屋" : "造屋就是 (zao 屋名 屋子説明) 就可以了。\n",
		"修屋" : "如果對屋子陳設不滿意了，(xiu 新屋名 屋子新描述) 就會重新裝修了。\n",
		"拆屋" : "不想要房子了或鑰匙丟了就(chai)吧。\n",
	]));

	setup();
	carry_object("/clone/cloth/cloth")->wear();
}

void init()
{
	object ob;

	::init();
	if( interactive(ob=this_player()) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("zao","zao");
	add_action("xiu","xiu");
	add_action("chai","chai");
	add_action("change","change");
}
int change()
{
	object key;
	object me=this_player();
	object *inv;
	int i;
	int flag=0;
	if (!me->query("home") )
	{
		write("\n村長説道：你在本村根本沒有房屋了，換什麼換？\n");
		return 1;
	}	
	inv=all_inventory(me);
	for (i=0;i<sizeof(inv);i++)
	{
		if (inv[i]->is_key())
		 {flag=1;break;}
	}
	if (flag==1)
	 write("村長笑咪咪地説：這位"+RANK_D->query_respect(me) + "，鑰匙不是還在你身上嗎。\n");
  else 
   {
   	seteuid(getuid(me));
   	key=new("/clone/misc/key");
   	seteuid(getuid());
   	key->move(me);
   	write("村長説道：好，我馬上派人幫你換鎖，這是鑰匙，你
退出遊戲後再連進來就可以去看看了。\n");
   	}
   	return 1;
}
void greeting(object ob)
{
	if (environment(ob)==environment())
	if (ob->query("age")>17)
say ("村長笑咪咪地説：這位"+RANK_D->query_respect(ob) + "，歡迎到桃花村來。
你可以造屋(zao)，也可以修改屋裏的裝修(xiu)，如果丟了鑰匙
就得換鎖(change)了。拆(chai)了房子也行，屋內裝修該換行的
地方請用 $ 代替。\n");
        else
say ("村長笑咪咪地説：這位"+RANK_D->query_respect(ob) + "，還不夠年齡修造自己的房子呢。\n");
        return;
}

int zao(string msg)
{
	object obj, ob = this_player();
	string homename, homedesc, tmpdesc;
	int i,have;
	object *inv;

	if (ob->query("age")<=17)
	{
		write("\n村長説道：你還沒成人呢，不能造私宅的。\n");
		return 1;
	}
	if (ob->query("home") )
	{
		write("\n村長説道：你在已經本村有房屋了，不能再造了。\n");
		return 1;
	}
	if( !msg ) return notify_fail("你要造什麼東西？\n");
	if( sscanf(msg ,"%s %s" ,homename, tmpdesc) != 2)
		 return notify_fail("zao 屋名 屋中陳設説明\n");
	homedesc = replace_string(tmpdesc, "$", "\n");
	ob -> set("home/home_name", homename);
	ob -> set("home/home_desc", homedesc);
	ob -> save();
	inv = all_inventory(ob);
	have=0;
	for (i=0;i<sizeof(inv);i++)
		if (inv[i]->is_key()) 
		  {
		  	have=1;
		  	break;
		  }
	if (have == 0)
	{
		seteuid(getuid(ob));
		obj = new("/clone/misc/key");
		obj -> move(ob);
	}
  seteuid(getuid());
	write("\n村長説道：我馬上派人去桃花坪幫你造屋，這是鑰匙，你
退出遊戲後再連進來就可以去看看了。\n");
	return 1;
}

int xiu(string msg)
{
 object  ob = this_player();
	string homename, homedesc, tmpdesc;

	if (!ob->query("home") )
	{
		write("\n村長説道：你在本村根本沒有房屋了，修什麼修？\n");
		return 1;
	}
	if( !msg ) return notify_fail("你要修什麼東西？\n");
	if( sscanf(msg ,"%s %s" ,homename, tmpdesc) != 2)
		 return notify_fail("xiu 新屋名 屋中陳設的新説明\n");
	homedesc = replace_string(tmpdesc, "$", "\n");
	ob -> set("home/home_name", homename);
	ob -> set("home/home_desc", homedesc);
	ob -> save();
	write("\n村長説道：我馬上派人去桃花坪幫你改裝房屋，你馬上就可以去看看了。\n");
	return 1;
}

int chai()
{
	object ob = this_player();
	object key;
	int i;
	object *inv;
	
	if (!ob->query("home")) 
	 {
	 	write("村長説道：你沒有建房屋啊，有什麼好拆的。\n");
	 	return 1;
	}
	if (!ob->query_temp("pending/chai"))
	{
		if (!key = present("yaoshi",ob))
		  write("村長説道：如果只是丟了鑰匙，換把鎖(change)就好了，你真的打算拆(chai)掉嗎？\n");
	  else
	    write("村長説道：你真的打算拆(chai)掉房子嗎，要不要再考慮一下？\n");
	  ob->set_temp("pending/chai",1);
	  return 1;
	}
	ob->delete_temp("pending/chai");
	ob->delete("home");
	inv=all_inventory(ob);
	for (i=0;i<sizeof(inv);i++)
		if (inv[i]->is_key()) destruct(inv[i]);
	write("\n村長説道：好吧，你這裏的房屋我已經派人去拆了。\n");
	return 1;
}