 // Last Modified by Winder on Apr. 25 2001

#include <ansi.h>
inherit ITEM;
inherit F_QUEST;
#include "stuffs.h";

void create()
{
	set_name(WHT"白玉短笛"NOR, ({ "duandi", "di",}));
	set("weight", 100);
	seteuid(getuid());
	if(clonep()) set_default_object(__FILE__);
	else{
		set("unit", "只");
		set("long", WHT"這玉笛短得出奇，只不來七寸來長、通體潔白，晶瑩可愛。\n" NOR);
		set("value", 50); 
		set("no_get", 1);
		set("di_number", 0);
		set("no_drop", 1);
	}
	setup();
}

void init()
{
	add_action("mark_success", "sign");
	add_action("set_task", "blow");
	add_action("set_task", "chui");
	add_action("report_task", "report");
}

mapping get_stuffs()
{
	mapping quest = stuffs[random(sizeof(stuffs))];
	quest += (["time" : time()+quest["exp_reward"]*30,
		"last_id" : quest["id"],
		"type" : "找" ]);
        return quest;
}
int set_task(string arg)
{
	object where, me = this_player();  
	mapping quest;
	where = environment(me);

	if( !arg ) return 0;
	if( !this_object()->id(arg)) return 0;

	if( me->is_busy() || me->is_fighting()) 
		return notify_fail("你正忙着呢。\n");    
	if(this_object()->query("xx_user") != getuid(me)) 
		return notify_fail("拿着只別人的笛子吹？\n");    
	if(!(where)->query("outdoors")) 
		return notify_fail("你在屋裏吹笛子，笛聲怎麼可能傳得遠呢？\n");
	if(me->query_condition("gb_songxin") )
		return notify_fail("老仙最討厭臭叫化子，先扔掉你的丐幫幫務再說！\n");
	if(me->query_temp("xx/id")) 
		return notify_fail("你現在正在執行任務中。\n");  
	if(me->query_condition("job_busy")) 
		return notify_fail("你剛要完任務，先等等吧。\n");           
	if(me->query_condition("wait_xx_task")) 
		return notify_fail("上次搞砸了，這次你就等等吧。\n");      
	tell_room(environment(me), HIY+me->name()+"拿起一隻"+this_object()->query("name")+HIY"放到口邊，輕輕一吹，發出一股塵銳的哨聲。本來笛聲清揚激越，\n但這根玉笛中發出來的聲音卻十分淒厲，全非樂調。\n"NOR, ({ me }));
	tell_object(me,HIY"你拿起"+this_object()->query("name")+HIY"放到口邊，輕輕吹了起來。\n"NOR);
	if((where)->query("outdoors") != "xingxiu" &&
		(where)->query("outdoors") != "xiyu")
		return notify_fail("此地和星宿海相離太遠，信鴿恐怕聽不到笛聲。\n"); 
	if(random(2)==1)
	{
		if(!mapp(quest = get_quest(me, 0, "殺"))) 
		quest = get_stuffs();
	}
	else quest = get_stuffs();
	me->set_temp("quest", quest);
	me->start_busy(1);          
	me->apply_condition("job_busy", 30);   
	remove_call_out("report");
	call_out("report", 1, me);
	return 1;
}
int report(object me)
{        
	if(!me) return 0;
  
	if( me->is_busy() || me->is_fighting()) 
		return notify_fail("你正忙着呢。\n");   
	if (!me->query_temp("quest/id")) 
		return notify_fail("你現在還沒有接收到任何任務。\n");
   
	message_vision(HIW"\n只見天空中飛下一隻白色信鴿，降在$N的肩頭。\n\n"NOR,me);
	message_vision("$N將書信從白鴿身上解下，瞟了一眼。\n",me);
	tell_object(me,"信中寫道： \n老仙最近的意思可能是想要");
	if(me->query_temp("quest/type") == "殺")
		tell_object(me, "殺掉「 "+me->query_temp("quest/name")+"("+me->query_temp("quest/id")+") 」。\n\n");
	else
		tell_object(me, "得到「 "+me->query_temp("quest/name")+"("+me->query_temp("quest/id")+") 」。\n\n");
	tell_object(me, "目前情況可以通過查看任務(report)來了解。\n");
	return 1;       
}
int report_task()
{
	int time;
	object me = this_player();
	time = me->query_temp("quest/time");
  
	if (!time) return notify_fail("你現在還沒有接收到任何任務。\n");
	write("你目前的任務目標是：\n\n");
   
	if(me->query_temp("quest/type") == "殺")
		write("       殺掉「 "+me->query_temp("quest/name")+"("+me->query_temp("quest/id")+") 」。\n\n並在屍體上留下(sign corpse)我們星宿派的標誌。\n");
	else
		write("       找到「 "+me->query_temp("quest/name")+"("+me->query_temp("quest/id")+") 」，獻(xian)給老仙。\n\n");
   
	tell_object(me, "你必須在"+get_time(time)+"之前完成任務！\n\n");
	return 1;
}
int mark_success(string arg)
{
	object target, me = this_player();
	string last;
  
	if(!arg) return notify_fail("你要幹什麼？\n");
	if(!objectp(target = present(arg, environment(me))))
		return notify_fail("找不到這個東西。\n");
	if( me->is_busy() || me->is_fighting()) 
		return notify_fail("你正忙着呢。\n");    
	switch (is_target(target, me))
	{
		case 0:  return 0;
		case -1: tell_object(me, "耶？有讓你去殺人了嗎？\n");
			return 0;
		case -2: tell_object(me,"笨蛋，你殺錯人了！\n");
			return 0;
		case -3: tell_object(me,"糟了，時間已經過了！\n");
			last = me->query_temp("quest/last_id");
			me->delete_temp("quest");
			me->set_temp("quest/last_id", last);
			me->apply_condition("wait_xx_task", 40); 
			return 0;
		case -4: tell_object(me,"哦，這人和NPC同名？算他倒黴！\n");
			return 0;
		default: break;
	}
	if(me->query("family/family_name") == "星宿派")
	{
		message_vision(HIR"\n$N左手一揚，衣袖中飛出一點"BLU"藍印印"HIR"的火花，嗤嗤做響，射向$n，着體便燃！\n\n"NOR, me, target);
		target->set("name", HIB"燒焦的屍體"NOR);
		target->set("long", HIB"一具被煉心彈燒焦的屍體，焦臭四溢，情狀可怖。\n"NOR);
		me->add("xx_points", 1);
	}
	else
	{
		message_vision("$N哼了一聲，用墨筆在$n的衣袖上寫下了“星宿”二字。\n", me, target);
		target->set("long", target->query("long")+"\n上面有人寫了大大的 "HIB"星宿"NOR" 二字。\n");
	}
	call_out("done", 1, me);   
	me->start_busy(1);    
	return 1;
}      
void done(object me)
{
	int num,times,score;
	mapping quest,fam;
	if(!me) return;
	quest = me->query_temp("quest");
        
        num=(int)me->query("perform/number")+1;
        if (num<4) times=num;
         else times=4;
        
        if (!(fam = me->query("family")) || fam["family_name"] != "星宿派")  score = 0;
         else score=random(10)+ 10 * times;        
	
	me->add("combat_exp", quest["exp_reward"]);
	me->add("potential", quest["pot_reward"]);
	me->add("family/fealty",score);
	
	tell_object(me, "好！任務完成，你馬上做了一封飛鴿傳書送回星宿海。\n");
	tell_object(me, GRN"你獲得"+chinese_number(quest["exp_reward"])+"點經驗和"+chinese_number(quest["pot_reward"])+"點潛能和"+chinese_number(score)+"點忠誠度的獎勵！\n"NOR);

	
	me->add("shen", -(quest["exp_reward"]*15));
	me->delete_temp("quest");
	me->set_temp("last_id", quest["last_id"]);
//	me->apply_condition("job_busy", 3);  
	me->clear_condition("job_busy");
	return;
}

