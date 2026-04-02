// Last Modified by winder on Apr. 25 2001
#include <ansi.h>

mixed names = ({
	({
	"朱雀外門","青龍外門","白虎外門","玄武外門","天安門","玄妙觀","靈隱寺",
	"泉州南門","靈州南門","諸葛亮殿","煙雨樓","南陽城","佛山南門",
	"衡陽西街","喜州城","葛魯城","伊犁城","山海關","老龍頭","長白天池",
	"天山腳下","麗春院","湧泉寺","五老峯","紫金城","松風觀","終南山腳",
	"抱子巖","昇仙坊","嘉應門","玄妙觀","峻極禪院","俠義廳","蕭家橋", 
	}),
	({
	"郭芙","武三通","朱子柳","靜玄師太","靜照師太","宋遠橋","莫聲谷",
	"陸乘風","韓寶駒","黃藥師","餘滄海","殷野王","胡青牛","尹志平","小龍女",
	"劉乘風","歐陽鋒","九翼道人","阿紫","玉磬子","玉音子","嶽夫人","嶽不羣",
	"令狐沖","玄苦大師","清善比丘","獨臂神尼","莊夫人","雙兒","吳六奇",
	"木婉清","蕭遠山","李沅芷","向問天","曲洋","黑白子","程瑤迦","沐劍屏",
	"天柏道人","本塵","本觀","天山童姥","韋一笑","謝遜","澄堅","陸乘風",
	"張翠山","宋青書","玄貞道長","石破天","蘇星河","逍遙子","朱丹臣",
	"簡長老","封不平",
	}),
});
// names need modify
string ask_job()
{ 
	object ob, me,gift,*team;
	int exp,position;
	string target,myfam,obfam,job_type;
	ob=this_player();
	me=this_object();
	exp=ob->query("combat_exp");
/*
	myfam = me->query("family/family_name");//同一門派的才給他job,把這四
	obfam = ob->query("family/family_name");//行去掉後就沒有門派限制
	if(!myfam ||!obfam||myfam != obfam) 
	return "你不是本門弟子，我不能給你工作！";
*/
	if (interactive(ob) && ob->query_temp("zzz_job_target") &&
		(int)ob->query_condition("zzz_mission"))  
		return "你上一次的任務還沒完成！";
	if (interactive(ob) && !ob->query_temp("zzz_job_target") &&
		(int)ob->query_condition("zzz_mission"))  
		return "你辦事不力，先等會吧。";
	if (interactive(ob) && (int)ob->query_condition("zzz_busy"))  
		return "現在我可沒有給你的任務，等會再來吧。\n";
	if(exp<=100000)	return "你的武功太差了，等練強了再來吧。\n";
	job_type="保護";
   	ob->set_temp("zzz_job_type",job_type);
	if(job_type=="保護")
	{
		target = names[1][random(sizeof(names[1]))];
		ob->apply_condition("zzz_mission",30);    
		ob->set_temp("zzz_job_target", target);
		message_vision(CYN "$N點了點頭，對$n説道：蒙古人收買了一批武林敗類，好象要暗殺"+target+"，你去保護他一下。\n"NOR , me,ob);
		call_out("begin_kill",30,ob,target);
		return "多加小心。";
	}
}
int accept_object(object who, object ob,object me)
{
	if ( ob->query("id") != "corpse")
	{
		command("say 你給我這個幹嗎？");
		return 0;
	}
	if ( !who->query_temp("zzz_job_target") )
	{
		command("say 好啊！不過你得先申請任務。");
		return 0;
	}
/*
	if( who->query_temp("zzz_job_type")=="殺")
		if(ob->query("victim_name")!=who->query_temp("zzz_job_target")||
			ob->query("victim_user")||who->query_temp("zzz_given") )
		{
			command("shake");
			command("say 你殺錯人了。");
			return 0;
		}
*/
	if( who->query_temp("zzz_job_type")=="保護")
		if (ob->query_temp("must_killby")!= who->query("id") ||
			ob->query("victim_user")||who->query_temp("zzz_given") )
		{
			command("shake");
			command("say 你殺錯人了。");
			return 0;
		} 
/*
	if ( ob->query("kill_by") != who)
	{
		command("say 這個任務似乎不是你自己完成的吧？");
		return 0;
	}
*/
	who->set_temp("zzz_given",1);
	call_out("destroying", 1, ob);
	call_out("ok", 1, who);
	return 1;
}
void ok(object who)
{
	int exp,pot,i;
	if (!who) return;
	command("pat" + who->query("id"));
	command("say 乾的好，你辦事幹淨利落，將來必成大器！");
	if(!who->query("zzz_job_count")) who->set("zzz_job_count",1);
	else who->add("zzz_job_count",1);	
	i=who->query("zzz_job_count");
	i/=30;
	exp=200+random(20)+i;
	if(who->query_temp("zzz_job_super"))
	{
		exp+=100;
		who->delete_temp("zzz_job_super");
	}
	pot=exp/3+random(10);
//i=3+random(3)+exp/200;
	who->add("potential",pot);
	who->add("combat_exp",exp);
	who->delete_temp("zzz_job_target");
	who->delete_temp("zzz_given");
	who->delete_temp("zzz_job_type");
	who->clear_condition("zzz_mission");
	who->apply_condition("zzz_busy",3+random(6)+exp/50);	
	tell_object(who,HIW"你被獎勵了：" + 
		chinese_number(exp) + "點實戰經驗，" +
		chinese_number(pot) + "點潛能。\n"+ NOR);
	return;
}


void destroying(object obj)
{
	destruct(obj);
	return;
}
string ask_fangqi()
{
	object me;
	me = this_player();
	if(me->query_condition("zzz_mission")<=1)
		return "你沒有領任務，跑這裏瞎嚷嚷什麼？";
	me->clear_condition("zzz_mission");
//	me->apply_condition("zzz_busy",4+random(10));
	me->delete_temp("zzz_job_target");
	me->delete_temp("zzz_job_type");
	return "沒關係，下次繼續努力。";
}
void begin_kill(object me,string target)
{
	object obj,*ob;
	int i,flag=0;
	if( !me->query_condition("zzz_mission")) return;
	if( me->query_temp("zzz_job_type")!="保護" ||
		me->query_temp("zzz_job_target")!=target)
		return;
	ob = all_inventory(environment(me));
	for(i=0; i<sizeof(ob); i++)
	{
		if( !living(ob[i])||userp(ob[i])||ob[i]==me ) continue;
		if(ob[i]->query("name")==target)
		{
			flag=1;
			break;
		}
	}
	if (flag==0)
	{
		call_out("begin_kill",30,me,target);
		return;
	} 
	obj=new(__DIR__"killer");
	obj->move(environment(me));
	if(random(10)>7||me->query("id")=="zzz")
	{
		obj->do_copy(me,1);
		obj->set("title",HIR"武林敗類"NOR);
		me->set_temp("zzz_job_super",1);
	}
	else obj->do_copy(me,0);
	obj->set_temp("must_killby",me->query("id"));
	message_vision( GRN"\n$N對着"+target+"發出一陣陰笑聲，令"+target+"全身上下的寒毛根根豎起，不寒而慄。\n"NOR,obj); 
	message_vision(HIY"$N對$n喝道：大膽狂徒，竟敢在這撒野！！\n"NOR,me,obj);
	message_vision(HIY"$N陰陰一笑：要你多管閒事，去死吧！！\n"NOR,obj);
	obj->kill_ob(me);
}

string ask_gonglao(object who)
{
	object me;
	int i;
  
	me = this_player();
	if(!me->query("zzz_job_count")) i=0;
	else i =(int)me->query("zzz_job_count"); 
	message_vision( CYN"$N對$n説道：你已經完成了" + chinese_number(i) + "次任務。\n"NOR,who,me);
	return "繼續努力吧！";
}
