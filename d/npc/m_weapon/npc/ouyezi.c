// npc: /d/npc/m_weapon/npc/tianjianshi.c
// Last Modified by winder on Feb. 28 2001
// Modified by sir 4/13/2001

#include <ansi.h>
inherit NPC;

int do_weapon();
int do_give_weapon(object me);
object creat_weapon();

void create()
{
	set_name("歐冶子", ({ "ouye zi", "zi" }) );
	set("nickname", RED "赤心劍膽" NOR );
	set("gender", "男性" );
	set("age", 60);
	set("no_get", 1);
	set("long", "他頭上包着頭巾，三縷長髯飄灑胸前，面目清瘦但紅暈有光，\n"
		"二目炯炯有神，爍爍閃着竟似是凜凜的劍光，渾身似乎都包圍\n"
		"在一股劍氣之中。\n");
	set("str", 25);
	set("dex", 20);
	set("con", 17);
	set("int", 30);
	set("shen_type", 0);
	set("max_neli",5000);
	set("jiali",50);

	set_skill("unarmed", 100);
	set_skill("dodge", 100);
	set_skill("claw",200);
	set_skill("jiuyin-baiguzhao",200);
	set_skill("force",150);
	set_skill("sword",150);
	set_skill("bibo-shengong",100);
	set_skill("luoying-shenjian",100);
	set_skill("parry",90);
	set_skill("anying-fuxiang",100);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/damage",50);

	set("combat_exp", 250000);
	set("score",0);
	
	map_skill("force","bibo-shengong");
	map_skill("parry","luoying-shenjian");
	map_skill("sword","luoying-shenjian");
	map_skill("claw","jiuyin-baiguzhao");
	map_skill("dodge","anying-fuxiang");
	
	set("attitude", "peaceful");
	
	set("inquiry", ([
		"鑄劍" : "鑄劍可是件十分艱苦的事，要消耗人的精氣和內力，你有決心和毅力嗎？\n",
		"原料" : "鑄劍可用千年玄鐵。。。你找到了我才能幫你鑄劍。\n",
		"兵器" : (: do_weapon() :),
	]) );

	setup();
	set("chat_chance", 3);
	set("chat_msg", ({
		"歐冶子撫劍而歌：巨闕神兵兮，人鑄就。蓋世寶劍兮，配英雄！\n",
		"歐冶子低頭沉吟，似乎在思考什麼。\n"
		"歐冶子嘆了一口氣：神兵配英雄，可英雄。。。。。。\n"
	}) );
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}

void init()
{
	::init();
	add_action("do_answer","answer");
}

int accept_object(object who, object ob)
{	
	switch ((string)ob->query("name") ) 
	{
		case "倭刀" :
		case "叫化雞" :
		case "羊皮書":
		case "軟劍":
		case "辟邪劍譜":
			if( (who->query_temp("condition")) != (string)ob->query("name") )
			{
				message_vision(HIC "歐冶子一愣：我對你説過我要這樣東西麼？\n" NOR, who);
				return 0;
			}
			else
			{
				who->delete_temp("condition");
				message_vision(HIG "歐冶子微笑着：很好很好！那我就幫你這一次吧！\n" NOR, who);
				who->set_temp("condition_ok",1);
				destruct(ob);
				do_give_weapon(who);
				return 1;
			}
	}
	if((int)(who->query("weapon/make")) )
	{
		say("歐冶子一臉茫然：您已經有一把自造的武器了，還來幹什麼？難到不合手麼？\n");
		return 0;
	}
	switch ((string)ob->query("id") ) 
	{
		case "shen mu": 
			who->set_temp("or",1);
			who->set_temp("get_orc",1);
			break;
		case "jin mu":
			who->set_temp("or",2);
			who->set_temp("get_orc",1);
			break;
		case "han zhu": 
			who->set_temp("or",3);
			who->set_temp("get_orc",1);
			break;
		case "iron stone": 
			who->set_temp("or",4);
			who->set_temp("get_orc",1);
			break;
		default :
			message("vision","這是什麼！這不能用來打造兵器！",who);
			return 0;
	}
	message("vision", "歐冶子低頭檢視了一下手中的"+(string)ob->query("name")+"點了點頭説：\n",who);
	write("我這兒可以打造以下兵器：\n"+
		"     劍(sword)\n"+
		"     刀(blade)\n"+
		"     槍(spear)\n"+
		"     棍(club)\n"+
		"     棒(stick)\n"+
		"     杖(staff)\n"+
		"     錘(hammer)\n"+
		"     鈎(hook)\n"+
		"     斧(axe)\n"+
		"     鞭(whip)\n");	  	
	say("這位"+RANK_D->query_respect(who)+"要造什麼兵器？決定了告訴我(answer)。\n");
	return 2;

}

int do_answer(string arg)
{
 object me;
	me = this_player();
	if(!(me->query_temp("get_orc") ) )
	{
//		write("你找到原料了嗎？\n");
		return 0;
	}
	
	if(!arg)
	{
		write("你要造什麼兵器？\n");
		return 0;
	}

	message("vision",me->name()+"對歐冶子輕聲説了幾句。\n",environment(me), ({me}) );
	switch (arg)
	{
		case "sword" :
			me->add_temp("sword",1);
			write("帶着原料去找侍劍吧！\n");
			message("vision","去吧！"+me->name()+"！\n",me);
			break;
		case "blade" :
			me->add_temp("blade",1);
			write("帶着原料去找侍刀吧！\n");
			message("vision","去吧！"+me->name()+"！\n",me);
			break;
		case "spear" :
			me->add_temp("spear",1);
			write("帶着原料去找侍槍吧！\n");
			message("vision","去吧！"+me->name()+"！\n",me);
			break;
		case "club" :
			me->add_temp("club",1);
			write("帶着原料去找侍棍吧！\n");
			message("vision","去吧！"+me->name()+"！\n",me);
			break;
		case "stick" :
			me->add_temp("stick",1);
			write("帶着原料去找侍棒吧！\n");
			message("vision","去吧！"+me->name()+"！\n",me);
			break;
		case "staff" :
			me->add_temp("staff",1);
			write("帶着原料去找侍杖吧！\n");
			message("vision","去吧！"+me->name()+"！\n",me);
			break;
		case "axe" :
			me->add_temp("axe",1);
			write("帶着原料去找侍斧吧！\n");
			message("vision","去吧！"+me->name()+"！\n",me);
			break;
		case "hammer" :
			me->add_temp("hammer",1);
			write("帶着原料去找侍錘吧！\n");
			message("vision","去吧！"+me->name()+"！\n",me);
			break;
		case "hook" :
			me->add_temp("hook",1);
			write("帶着原料去找侍鈎吧！\n");
			message("vision","去吧！"+me->name()+"！\n",me);
			break;
		case "whip" :
			me->add_temp("whip",1);
			write("帶着原料去找侍鞭吧！\n");
			message("vision","去吧！"+me->name()+"！\n",me);
			break;
		default :
			message_vision(HIC"歐冶子一臉狐疑：什麼兵器？\n"NOR,me);
			return notify_fail("歐冶子仔細的説：此事不可兒戲，請慎重！！\n");
	}
	switch ( me->query_temp("or") )
	{
		case 1:
//			w_or = new("/d/npc/m_weapon/tan/item/shenmu",1);
//			w_or->move(me);			
//			message_vision(HIC"歐冶子給了$N一塊千年神木。\n"NOR,me);
		command("give shen mu to "+me->query("id"));
			break;
		case 2:
//			w_or = new("/d/npc/m_weapon/tan/item/jinmu",1);
//			w_or->move(me);
//			message_vision(HIC"歐冶子給了$N一塊海底金母。\n"NOR,me);
		command("give jin mu to "+me->query("id"));
			break;
		case 3:
//			w_or = new("/d/npc/m_weapon/tan/item/hanzhu",1);
//			w_or->move(me);
//			message_vision(HIC"歐冶子給了$N一塊寒絲羽竹。\n"NOR,me);
		command("give han zhu to "+me->query("id"));
			break;
		case 4:
//			w_or = new("/d/qilian/obj/ironstone",1);
//			w_or->move(me);
//			message_vision(HIC"歐冶子給了$N一塊隕星鐵石。\n"NOR,me);
		command("give iron stone to "+me->query("id"));
			break;
	}

	me->delete_temp("get_orc");
	return 1;
}

int do_weapon()
{
	object me,obj;
//object weapon;	
	string w_id;
	me = this_player();
	w_id = me->query("weapon/id");
	if( !(me->query("weapon/make")) )
		return notify_fail("你造過兵器嗎？\n");

	if( objectp(obj = present(w_id, me)) )
	{
		say("歐冶子臉色一沉：您的武器不就在你手邊麼？還來幹什麼！\n");
		return 1;
	}
	if (me->query_temp("condition") )
	{
		say("歐冶子臉色一沉：不是讓你去拿"+(me->query_temp("condition") )+
"了麼？還沒拿到回來幹嘛！\n");
		return 1;
	}

	if( !(me->query_temp("condition_ok")) )
	{
		message_vision(HIY"這位"+RANK_D->query_respect(me)+"想要重新得到兵器？這不難。不過......\n" NOR, me);
		message_vision(HIY"歐冶子沉吟了一下説：你得找到我要的東西。\n" NOR, me);
		switch( random(5) )
		{
			case 0:
				message_vision("拿到倭刀，再來吧！\n",me);
				me->set_temp("condition","倭刀");
				break;
			case 1:
				message_vision("給我叫化雞，我就幫你！！\n",me);
				me->set_temp("condition","叫化雞");
				break;
			case 2:
				message_vision("嗯..你就拿羊皮書來換吧！\n",me);
				me->set_temp("condition","羊皮書");
				break;
			case 3:
				message_vision("..我想看看軟劍！\n",me);
				me->set_temp("condition","軟劍");
				break;
			case 4:
				message_vision("如果你能替我找到辟邪劍譜的話......\n",me);
				me->set_temp("condition","辟邪劍譜");
				break;
		}
	}
	return 1;
}
int do_give_weapon(object me)
{
		object weapon;
		object *obs;
		int i;
		object env;
		string env_name;
    string area;
    

		
		me->delete_temp("condition_ok");
		obs = children("/d/npc/m_weapon/weapon/m_weapon");
		for (i=0;i<sizeof(obs);i++)
		{
			if (obs[i]->query("owner")==me->query("id"))
			{
				if (!environment(obs[i])) continue;
				env = environment(obs[i]);
        sscanf(base_name(env),"/%*s/%s/%*s",area);
        area=to_chinese(area);
				if (env->is_character())
				  env_name = env->query("name")+"手中";
				else
				  env_name = env->query("short");				
			  if (!userp(env))
			    env_name = area +"的" + env_name;
			  message_vision("$N説道：你的"+obs[i]->query("name")+
			  "在"+ env_name+"，快去找吧。\n",this_object());
			  return 1;
			}
		}
		
		weapon = creat_weapon();
		weapon->move(me);
		return 1;
}

object creat_weapon()
{
	object me,weapon;
	string mask;	//the verible that record the type of weapon
	me = this_player();
	mask = me->query("weapon/type");
	weapon = new("/d/npc/m_weapon/weapon/m_weapon",1);
	return weapon;
/*
	switch(mask)
	{
		case "劍":
			weapon = new("/d/npc/m_weapon/weapon/m_sword",1);
			return weapon;
		case "刀":
			weapon = new("/d/npc/m_weapon/weapon/m_blade",1);
			return weapon;
		case "槍":
			weapon = new("/d/npc/m_weapon/weapon/m_spear",1);
			return weapon;
		case "棍":
			weapon = new("/d/npc/m_weapon/weapon/m_club",1);
			return weapon;
		case "棒":
			weapon = new("/d/npc/m_weapon/weapon/m_stick",1);
			return weapon;
		case "杖":
			weapon = new("/d/npc/m_weapon/weapon/m_staff",1);
			return weapon;
		case "錘":
			weapon = new("/d/npc/m_weapon/weapon/m_hammer",1);
			return weapon;
		case "鈎":
			weapon = new("/d/npc/m_weapon/weapon/m_hook",1);
			return weapon;
		case "鞭":
			weapon = new("/d/npc/m_weapon/weapon/m_whip",1);
			return weapon;
		case "斧":
			weapon = new("/d/npc/m_weapon/weapon/m_axe",1);
			return weapon;
	}
*/
}