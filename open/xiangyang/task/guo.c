// Last Modified by winder on Apr. 25 2001
// guojing.c 郭靖

inherit NPC;
#include <ansi.h>
#include "zzzjob.c"
#include "teamjob.c"
string ask_newjob();
string ask_newover();
int job_over(string arg);

void create()
{
	set_name("郭靖", ({"guo jing", "guo", "jing"}));
	set("nickname", HIY"北俠"NOR);
	set("gender", "男性");
	set("age", 41);
	set("long", 
		"他就是人稱北俠的郭靖，既是蒙古成吉思汗的金刀駙馬，又是\n"
		"江南七怪、全真派馬鈺、「北丐」洪七公和「老頑童」周伯通\n"
		"等人的徒弟，身兼數門武功。他身着一件灰色長袍，體態魁梧，\n"
		"敦厚的面目中透出一股威嚴。令人不由得產生一股欽佩之情。\n");
	set("attitude", "friendly");
	set_max_encumbrance(100000000);
	set("per", 20);
	set("str", 40);
	set("int", 20);
	set("con", 30);
	set("dex", 25);
	set_temp("no_kill",1);
	set("chat_chance", 1);
	set("chat_msg", ({
		"郭靖嘆了口氣道： 蒙古兵久攻襄陽不下，一定會再出詭計，蓉兒又不在身邊，這....\n",
		"郭靖說道：華箏公主近來不知可好，抽空一定要回大漠去看看她。\n",
//		(: random_move :),
	}));
	set("inquiry", ([
		"周伯通" : "你見到我周大哥了？他現在可好？\n",
		"老頑童" : "周大哥一貫這樣，沒點正經！\n",
		"洪七公" : "師父除了喫，就是喜歡玩。到處玩，還是爲了找喫的。\n",
		"黃藥師" : "那是我泰山大人。他雲遊四海，神龍見首不見尾的。\n",
		"一燈大師" : "在下對大師好生感激。\n",
		"歐陽鋒" : "這個老毒物，害死我六位師父，一待襄陽事了，決不與他干休。\n",
		"黃蓉"   : "蓉兒是我的愛妻，你問她做甚？\n",
		"蓉兒"   : "蓉兒就是蓉兒了。你問這麼多幹嘛？\n",
		"郭芙"   : "這個女兒，又笨又不聽話。\n",
		"郭襄"   : "襄兒生於亂世，這輩子又多艱厄。但願她能快樂一世。\n",
		"郭破虜" : "那是我的小兒子。\n",
		"楊過"   : "過兒確實有出息。\n",
		"馬鈺"   : "馬道長於我有半師之誼。\n",
		"丘處機" : "邱道長義薄雲天，是真豪傑。\n",
		"柯鎮惡" : "那是我大師父。\n",
		"朱聰"   : "那是我二師父。\n",
		"韓寶駒" : "那是我三師父。\n",
		"南希仁" : "那是我四師父。\n",
		"張阿生" : "那是我五師父。\n",
		"全金髮" : "那是我六師父。\n",
		"韓小瑩" : "那是我七師父。\n",
		"丐幫"   : "丐幫英雄幾百年了，守衛襄陽多虧了他們。\n",
		"拜師"   : "現在蒙古人圍攻襄陽，我哪有心情收徒啊！\n",
		"job"    : (: ask_job :),
		"義士"   : (: ask_job :),
		"功勞"   : (: ask_gonglao :),
		"fangqi" : (: ask_fangqi :),
		"放棄"   : (: ask_fangqi :),
		"奸細"   : (: ask_jianxi :),
		"守城"   : (: ask_newjob :),
		"job2"   : (: ask_newjob :),
		"撤退"   : (: ask_newover :),
	]));
	set("qi", 8000);
	set("max_qi", 8000);
	set("jing", 8000);
	set("max_jing", 8000);
	set("neili", 24000);
	set("max_neili", 24000);
	set("jiali", 500);
	set("combat_exp", 25000000);
	set("score", 200000);
	set_skill("force", 400);		// 基本內功
	set_skill("huntian-qigong", 400);	// 混天氣功
	set_skill("unarmed", 400);		// 基本拳腳
	set_skill("xianglong-zhang", 400);	// 降龍十八掌
	set_skill("dodge", 400);		// 基本躲閃
	set_skill("xiaoyaoyou", 400);		// 逍遙遊
	set_skill("parry", 400);		// 基本招架
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "xianglong-zhang");
	prepare_skill("unarmed","xianglong-zhang");
	setup();
	carry_object("/clone/misc/cloth")->wear();
}
void init()
{
	add_action("job_over","shoucheng");
}
string ask_newjob()
{
	object *ene;
	object me = this_player();

	if(is_fighting()) 
	{
		ene=query_enemy();
		if(sizeof(ene)>1)
			return "“請"+RANK_D->query_respect(me)+ "稍等片刻，我先和這"+sizeof(ene)+"位高手切磋幾下！”\n";
		if(sizeof(ene)==1)
			return "“請"+RANK_D->query_respect(me)+ "稍等片刻，我先和"+ene[0]->name()+"切磋幾下！”\n";
	}
	if(this_object()->query("shadi"))
		return "“剛纔救援的英雄已去城門，你看去幫幫忙如何？”\n";
	if(!me->query("family/family_name"))
		return "“"+RANK_D->query_respect(me)+"無門無派，不知尊師是誰？”\n";
	if(me->query_temp("mark/job_shadi")>0 )
		return "“"+RANK_D->query_respect(me)+"不是已有任務了嗎！”\n";
//        if((int)me->query("shen") < 0)
//		return "“你心術不正，快快請回！”\n";
	if ((int)me->query("combat_exp")<100000)
		return "“"+RANK_D->query_respect(me)+ "手無縛雞之力，還是別領任務的爲好！”\n";
	if ( (int)me->query_skill("force") < 20 )
		return "守城是件危險工作，我看"+RANK_D->query_respect(me)+ "的基本內功修爲不足，不宜冒險！\n";
	if ((int)me->query_condition("jobshadi_failed"))
	{
		message_vision("$N對着$n搖了搖頭說：逃跑失敗了還來見我？\n", this_object(), me);
		return "“"+RANK_D->query_respect(me)+"還是別領任務爲好！”\n";
	}
	if ((int)me->query_condition("jobshadi_limit")>1)
	{
		message_vision("$N對着$n搖了搖頭說：你不是正做着嗎？\n", this_object(), me);
		return "“"+RANK_D->query_respect(me)+"快點回你的崗位去！”\n";
	}
	if ((int)me->query_condition("guojob2_busy"))
	{
		message_vision("$N對着$n搖了搖頭說：現在蒙古人正在攻城！！\n", this_object(), me);
		return "“"+RANK_D->query_respect(me)+"你等會再來！”\n";
	}
	if (me->query("shen")>0)
	{
		switch( random(2) )
		{
			case 0:
				this_object()->set("shadi", 1);
              			call_out("new_give_job",360,this_object());
                                me->set_temp("mark/job_shadi",1);
				me->set_temp("carry_location","northgate1");
				me->apply_condition("jobshadi_limit",6);
				return "“現在蒙古靼子侵犯中原，這位"+RANK_D->query_respect(me)+"去玄武內門幫助宋軍守城吧。”";
				break;
			case 1:
				this_object()->set("shadi", 1);
                                call_out("new_give_job",360,this_object());
				me->set_temp("mark/job_shadi",2);
				me->set_temp("carry_location","northgate1");
				me->apply_condition("jobshadi_limit",6);
				return "“現在蒙古靼子侵犯中原，這位"+RANK_D->query_respect(me)+"去青龍內門幫助宋軍守城吧。”";
				break;
		}	
	}
	else
	{
		switch( random(2) )
		{
			case 0:
				this_object()->set("shadi", 1);
                                call_out("new_give_job",360,this_object());
				me->set_temp("mark/job_shadi",3);
				me->set_temp("carry_location","southgate1");
				me->apply_condition("jobshadi_limit",6);
				return "“現在蒙古靼子侵犯中原，這位"+RANK_D->query_respect(me)+"去朱雀內門幫助宋軍守城吧。”";
				break;
			case 1:
				this_object()->set("shadi", 1);
			        call_out("new_give_job",360,this_object());
                         	me->set_temp("mark/job_shadi",4);
				me->set_temp("carry_location","southgate1");
				me->apply_condition("jobshadi_limit",6);
				return "“現在蒙古靼子侵犯中原，這位"+RANK_D->query_respect(me)+"去白虎內門幫助宋軍守城吧。”";
				break;
		}
	}
}

int new_give_job()
{ 
   this_object()->delete("shadi", 1);
} 

int job_over(string arg)
{
	int job_pot,job_exp;
	object me = this_player();

	if(!arg) return 1;

	if(arg!="over") return 1;
	if(me->query_temp("help_killed")>0)
	{
		message_vision(CYN "$N拍了拍$n的肩膀說道：“"+RANK_D->query_respect(me)+"，爲國殺敵，不錯不錯！”\n" NOR, this_object(), me);
		job_exp=((int)me->query_temp("killed_mgb"))*80;
		job_pot=job_exp*1/3;
		job_exp=job_exp;
		me->add("combat_exp", job_exp);
		me->add("potential",job_pot);
tell_object(me, "你被獎勵了"+chinese_number(job_exp)+"點經驗值，"+chinese_number(job_pot)+"點潛能。\n");
		me->delete_temp("killed_mgb");	
		me->delete_temp("job_over");
		me->delete_temp("mark/job_shadi");
		me->delete_temp("help_killed");
		me->apply_condition("guojob2_busy",4);
		return 1;
	}
	if(me->query_temp("mark/job_shadi")==0)
	{
		message_vision(CYN"$N瞧了$n一眼：“沒任務還什麼完成不完成。”\n",this_object(),me);
		return 1;
	}
	if(me->query_temp("job_over")==0)
	{
		message_vision(CYN"$N瞧了$n一眼：“任務還沒完成。”\n"NOR,this_object(),me);
		return 1;
	}
	if(me->query_temp("killed_mgb")<2)
	{
		message_vision(CYN"$N瞧了$n一眼：“你殺了幾個敵人，你還來領賞？”\n"NOR,this_object(),me);
		me->delete_temp("job_over");
		me->delete_temp("mark/job_shadi");
		return 1;
	}
	message_vision(CYN"$N對$n說道：“"+RANK_D->query_respect(me)+"辛苦了，去休息一下吧！”\n" NOR, this_object(), me);
	me->delete_temp("job_over");
	me->delete_temp("mark/job_shadi");
	job_exp=((int)me->query_temp("killed_mgb"))*80;
	job_pot=job_exp*1/3;
	job_exp=job_exp;
	tell_object(me, "你被獎勵了"+chinese_number(job_exp)+"點經驗值，"+chinese_number(job_pot)+"點潛能。\n");
	me->apply_condition("guojob2_busy",4);
	me->add("combat_exp", job_exp);
	me->add("potential",job_pot);
	me->delete_temp("killed_mgb");	
	this_object()->delete("shadi", 1);
	return 1;
}
string ask_newover()
{
	object me;
	me = this_player();
	if(me->query_condition("jobshadi_limit") <= 1)
		return "你沒有領任務，跑這裏瞎嚷嚷什麼？";
	me->apply_condition("jobshadi_limit", 1);
	me->apply_condition("jobshadi_failed", 6);
	me->delete_temp("mark/job_shadi");
	me->delete_temp("carry_location");
	me->delete_temp("job_over");
	me->delete_temp("start_job");
	this_object()->delete("shadi", 1);
	return "沒關係，下次繼續努力。";
}
