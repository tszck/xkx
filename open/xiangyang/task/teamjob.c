// Last Modified by winder on Apr. 25 2001
// teamjob.c
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

string ask_jianxi()
{
	object guo,ob;
	object *team;
	int i=0,count=0,minexp,maxexp;
	string where;
	guo =this_object();
	ob=this_player();

	if (guo->query_condition("zzz_busy")) return "我沒有收到任何消息。";
	if(ob->query("combat_exp")<500000) return "你的功夫太差了。";
	team=ob->query_team();
	count=sizeof(team);
//	write("\n"+sprintf("%d",count));
	if(count<=1) return "就你一個人？";    // 不能單獨做
	if(count>=5) return "此事不宜張揚。";  // 不能超過五人一起做
	minexp=team[0]->query("combat_exp");
	maxexp=minexp;
      
	for(i=1;i<count;i++)
	{
		if(team[i]!=0)
		{
			if(team[i]->query("combat_exp")<minexp)
				minexp=team[i]->query("combat_exp");
			if(team[i]->query("combat_exp")>maxexp)
				maxexp=team[i]->query("combat_exp");
		}
	}
	if ((maxexp-minexp)>800000)
		return "你們的武功相差太懸殊。";// 同夥武功差距不能太大
	// 成功檢測
	where=names[0][random(40)];
	guo->apply_condition("zzz_busy",30);
	ob->set_temp("team_count",count);
	ob->apply_condition("zzz_busy",60);
	for(i=0;i<count;i++)
//		team[i]->set_temp("zzz_job_zhuji",1);
		team[i]->apply_condition("zzz_busy",60);
	for(i=100;i*i*i/10<=maxexp;i++);
	call_out("job",60,ob,where,i,count+2);
//	message_vision(HIY"$N狂笑不已：就憑你們幾個也想擋住我的去路？\n"NOR,obj);
	return "我剛得到消息，有一名蒙古奸細偷盜了襄陽城防的機密文件。
          你們趕快去"+where+"設防阻截，搶到文件後就地銷燬(xiaohui)。
          蒙古人肯定會派兵接應他，多加小心。"; 
}

void job(object ob,string where,int maxpot,int ckiller)
{
	object *team,obj,obj1,gift;
	int i=0;
//	team=ob->query_team();
//	for(i=0;i<sizeof(team);i++)
	if(environment(ob)->query("short")==where &&
		ob->query_condition("zzz_busy"))
	{
		if (ckiller>0)
		{
			if (random(20)>16)
			{
				obj=new(__DIR__"mengbing");   
				obj->do_copy(ob,maxpot,3);
				obj->set("title",HIY"蒙古千夫長"NOR);     
				obj->move(environment(ob));
				obj->kill_ob(ob);
			}
			else 
			{
				obj=new(__DIR__"mengbing"); 
				obj->do_copy(ob,maxpot,1);
				obj->set("title",HIY"蒙古百夫長"NOR);
				obj->move(environment(ob));
				obj->kill_ob(ob);
				obj1=new(__DIR__"mengbing");
				if (random(20)>10)
				{
					obj1->do_copy(ob,maxpot,2);
					obj1->set("title",HIY"蒙古百夫長"NOR);
				}
				else obj1->do_copy(ob,maxpot,1);
				obj1->move(environment(ob));
				obj1->kill_ob(ob);
			}  
			call_out("job",120,ob,where,maxpot,ckiller-1);
		}
		else 
		{
			if (present("menggu dahan",environment(ob)))
			{
// present menggu dahan, then mission failed
				tell_room(environment(ob),HIC"蒙古兵揮揮手，示意奸細先走。\n奸細匆匆忙忙的離開了。\n"NOR);
				tell_object(ob, HIY"\n奸細離開中原了，你任務失敗！\n"NOR);
			}
			else
			{
				obj=new(__DIR__"jianxi"); 
				obj->do_copy(ob,maxpot);
				obj->set("title",HIR"奸細"NOR);
				obj->move(environment(ob));
				message_vision(HIY "$N狂笑不已：就憑你們幾個也想擋住我的去路？\n"NOR, obj);
				obj->kill_ob(ob);
				gift=new(__DIR__"mijian");
				gift->set_temp("host",ob->query("id"));
				gift->move(obj);
			}
		}
	}
	else
	tell_object(ob, HIY "\n奸細偷偷溜出了中原，你任務失敗！\n" NOR); 
	return;
}
//make killer
