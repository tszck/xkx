// lu.c

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_job();

mapping *names=({
      (["name":                "宋遠橋",
       "where" :              "武當派",]),  
      (["name":                "俞蓮舟",
       "where" :              "武當派",]),  
      (["name":                "莫聲谷",
       "where" :              "武當派",]),
      (["name":                "俞岱巖",
       "where" :              "武當派",]),
      (["name":                "張松溪",
       "where" :              "武當派",]), 
      (["name":                "殷梨亭",
       "where" :              "武當派",]), 
      (["name":                "谷虛道長",
       "where" :              "武當派",]), 
      (["name":                "沙通天",
       "where" :              "黃河四鬼",]), 
      (["name":                "侯通海",
       "where" :              "黃河四鬼",]), 
      (["name":                "錢青健",
       "where" :              "黃河四鬼",]),
      (["name":                "彭連虎",
       "where" :              "黃河四鬼",]),
      (["name":                "空空兒",
       "where" :              "丐幫",]),
      (["name":                "林震南",
       "where" :              "福威鏢局",]),
      (["name":                "包不同",
       "where" :              "慕容世家",]),
      (["name":                "風波惡",
       "where" :              "慕容世家",]),
      (["name":                "鄧百川",
       "where" :              "慕容世家",]),
      (["name":                "殷野王",
       "where" :              "明教",]),
      (["name":                "蘇夢清",
       "where" :              "峨嵋派",]),
      (["name":                "李明霞",
       "where" :              "峨嵋派",]),
      (["name":                "貝錦儀",
       "where" :              "峨嵋派",]),
      (["name":                "方碧琳",
       "where" :              "峨嵋派",]),
      (["name":                "靜迦師太",
       "where" :              "峨嵋派",]),
      (["name":                "靜照師太",
       "where" :              "峨嵋派",]),
      (["name":                "靜虛師太",
       "where" :              "峨嵋派",]),
       (["name":                "靜空師太",
       "where" :              "峨嵋派",]),
       (["name":                "靜真師太",
       "where" :              "峨嵋派",]),
       (["name":                "靜閒師太",
       "where" :              "峨嵋派",]),
       (["name":                "靜玄師太",
       "where" :              "峨嵋派",]),
       (["name":                "靜慧師太",
       "where" :              "峨嵋派",]),
       (["name":                "阿紫",
       "where" :              "星宿派",]),
       (["name":                "天狼子",
       "where" :              "星宿派",]),
       (["name":                "慧名尊者",
       "where" :              "少林派",]),
       (["name":                "慧修尊者",
       "where" :              "少林派",]),
       (["name":                "慧虛尊者",
       "where" :              "少林派",]),
       (["name":                "慧空尊者",
       "where" :              "少林派",]),
       (["name":                "慧合尊者",
       "where" :              "少林派",]),
       (["name":                "慧潔尊者",
       "where" :              "少林派",]),
       (["name":                "慧色尊者",
       "where" :              "少林派",]),
       (["name":                "慧如尊者",
       "where" :              "少林派",]),
       (["name":                "慧真尊者",
       "where" :              "少林派",]),
       (["name":                "玄難大師",
       "where" :              "少林派",]),
       (["name":                "玄苦大師",
       "where" :              "少林派",]),
       (["name":                "玄悲大師",
       "where" :              "少林派",]),
       (["name":                "玄慈大師",
       "where" :              "少林派",]),
       (["name":                "玄痛大師",
       "where" :              "少林派",]),
       (["name":                "澄意",
       "where" :              "少林派",]),
       (["name":                "澄靈",
       "where" :              "少林派",]),
       (["name":                "澄和",
       "where" :              "少林派",]),
       (["name":                "澄尚",
       "where" :              "少林派",]),
       (["name":                "澄欲",
       "where" :              "少林派",]),
       (["name":                "澄觀",
       "where" :              "少林派",]),
       (["name":                "澄知",
       "where" :              "少林派",]),
       (["name":                "澄思",
       "where" :              "少林派",]),
       (["name":                "澄明",
       "where" :              "少林派",]),
       (["name":                "澄信",
       "where" :              "少林派",]),
       (["name":                "澄識",
       "where" :              "少林派",]),
       (["name":                "澄心",
       "where" :              "少林派",]),
       (["name":                "澄寂",
       "where" :              "少林派",]),
       (["name":                "澄堅",
       "where" :              "少林派",]),
       (["name":                "澄淨",
       "where" :              "少林派",]),
       (["name":                "澄行",
       "where" :              "少林派",]),
       (["name":                "澄滅",
       "where" :              "少林派",]),
      (["name":                "史青山",
       "where" :              "揚州守將",]),
      (["name":                "殷天正",
       "where" :              "明教",]),
      (["name":                "周顛",
       "where" :              "明教",]),
      (["name":                "説不得",
       "where" :              "明教",]),
      (["name":                "張中",
       "where" :              "明教",]),
      (["name":                "辛然",
       "where" :              "明教",]),
     (["name":                "範遙",
       "where" :              "明教",]),
     (["name":                "清法比丘",
       "where" :              "少林派",]),
     (["name":                "清無比丘",
       "where" :              "少林派",]),
     (["name":                "馬鈺",
       "where" :              "全真教",]),
     (["name":                "譚處端",
       "where" :              "全真教",]),
     (["name":                "劉處玄",
       "where" :              "全真教",]),
     (["name":                "丘處機",
       "where" :              "全真教",]),
     (["name":                "王處一",
       "where" :              "全真教",]),
     (["name":                "郝大通",
       "where" :              "全真教",]),
     (["name":                "孫不二",
       "where" :              "全真教",]),
     (["name":                "尹志平",
       "where" :              "全真教",]),
     (["name":                "趙志敬",
       "where" :              "全真教",]),
     (["name":                "崔志方",
       "where" :              "全真教",]),
     (["name":                "張志光",
       "where" :              "全真教",]),
     (["name":                "申志凡",
       "where" :              "全真教",]),
     (["name":                "祁志誠",
       "where" :              "全真教",]),
     (["name":                "李志常",
       "where" :              "全真教",]),
     (["name":                "王志坦",
       "where" :              "全真教",]),
     (["name":                "王志謹",
       "where" :              "全真教",]),
     (["name":                "陳志益",
       "where" :              "全真教",]),
     (["name":                "房志起",
       "where" :              "全真教",]),
     (["name":                "程瑤迦",
       "where" :              "全真教",]),
     (["name":                "宋德方",
       "where" :              "全真教",]),
     (["name":                "於道顯",
       "where" :              "全真教",]),
       });   
void create()
{
	set_name("魯有腳", ({"lu youjiao", "lu", "youjiao"}));
	set("gender", "男性");
	set("age", 45);
	set("long", 
		"魯有腳雖然武功算不得頂尖高手，可是在江湖上卻頗有聲望。\n"
		"因為他在丐幫中有仁有義，行事光明磊落，深得洪七公的器重。\n");
	set("attitude", "peaceful");
	set("class", "beggar");
 	set("beggarlvl", 9);
	set("str", 25);
	set("int", 12);
	set("con", 25);
	set("dex", 20);

	set("qi", 900);
	set("max_qi", 900);
	set("jing", 100);
	set("max_jing", 100);
	set("neili", 1200);
	set("max_neili", 1200);
	set("jiali", 100);
	set("no_get", 1);
	
	set("combat_exp", 100000);
	set("score", 20000);
	
	set_skill("force", 90); // 基本內功
	set_skill("huntian-qigong", 90); // 混天氣功
	set_skill("parry", 90); // 基本招架
	set_skill("hand", 95); // 基本手法
	set_skill("suohou-hand", 95); // 基本手法
	set_skill("strike", 95); // 基本掌法
	set_skill("xianglong-zhang", 90); // 降龍十八掌
	set_skill("dodge", 90); // 基本躲閃
	set_skill("xiaoyaoyou", 90); // 逍遙遊
	set_skill("staff", 85); // 基本杖法
	set_skill("fengmo-staff", 85); // 瘋魔杖法
	set_skill("stick", 85); // 基本棒法
	set_skill("dagou-bang", 45); // 打狗棒法
	set_skill("begging", 60);
	
	set_skill("lianhua-zhang",85); // 蓮花掌

	map_skill("force", "huntian-qigong");
	map_skill("parry", "xianglong-zhang");
	map_skill("strike", "xianglong-zhang");
	map_skill("hand", "suohou-hand");
	map_skill("staff", "fengmo-staff");
	map_skill("stick", "dagou-bang");
	map_skill("dodge", "xiaoyaoyou");
	prepare_skill("strike", "xianglong-zhang");
	set("inquiry", 
	([
		"送信" : (: ask_job :),
		"letter" : (: ask_job :),
	]));
	set("party/party_name", HIC"丐幫"NOR);
	set("party/rank", RED"九袋長老"NOR);
	set("party/level", 9);
	create_family("丐幫", 18, "掌棒龍頭");

	setup();

	carry_object(__DIR__"obj/jiaohuaji");
	carry_object(__DIR__"obj/cloth")->wear();
	carry_object(WEAPON_DIR"gangzhang")->wield();
}

void attempt_apprentice(object ob)
{
	if ( (int)ob->query("int") >= 25 )
	{
		command("say 我們丐幫的武藝一向以剛猛為主，" + 
		RANK_D->query_respect(ob) + "聰慧過人，似乎不宜學丐幫的功夫？");
		return;
	}
	command("say 好吧，希望" + RANK_D->query_respect(ob) +
		"能好好學習本門武功，將來在江湖中闖出一番作為。");
	command("recruit " + ob->query("id"));
}

string ask_job()
{
	object me;
	object ob;
	int time;
 mapping target;
  	ob=this_player();
	me=this_object();
/*
	if (!(fam = me->query("family")) || fam["family_name"] != "丐幫")
		return RANK_D->query_respect(me) + "與丐幫素無來往，此話從何説起？";
*/
	if (ob->query_temp("gb_songxin")&&present("secret letter", this_player()))
		return ("你不是已經領了送信的任務嗎？還不快去做。\n");
	if (ob->query_condition("gb_songxin") > 1) 
	    { time=1;
	      ob->apply_condition("gb_songxin",time);
	     } 
	if (ob->query_condition("gb_songxin") > 0)
	     {  
		return "現在暫時沒有給你的任務，再等"+chinese_number(ob->query_condition("gb_songxin"))+"柱香的時間吧。";
	      }
	if (ob->query("combat_exp")>=30000 && !wizardp(ob))
		return "我看你的武功已有相當的功底了，就不用在我這裏幹事了。\n";
	if (ob->query("combat_exp")<100 && !wizardp(ob))
		return "你的功夫還不夠啊，送信可是很危險的事，我可不敢交給你任務。\n";
 
	target = names[random(sizeof(names))];
	
	time = random(10)+(80-2*ob->query("int"));
	if (ob->query("combat_exp")>=10000 && !wizardp(ob))
	    time = time*4/5;
	if (ob->query("combat_exp")>=20000 && !wizardp(ob))
	    time = time*2/3;   
	    
	ob->delete_temp("songxin_ok");
	ob->delete_temp("gb_songxin_late");

	ob->set_temp("gb_songxin",1);
	ob->set_temp("songxin_time",time);
	ob->set_temp("songxin_target_name", target["name"]);
	ob->set_temp("songxin_where", target["where"]);
	ob->delete_temp("songxin_zuji");
	ob->apply_condition("gb_songxin",time);
	switch(random(3))
	{
		case 0:
			message_vision("$N悄悄把$n拉到一旁，低聲説道，你把這封密函火速送到「"+ob->query_temp("songxin_where")+"」"
"的「"+ob->query_temp("songxin_target_name")+"」手上。\n",me,ob);
			message_vision("$N交給$n一封密函。\n",me,ob);
			ob=new(__DIR__"obj/letter");
			ob->set_temp("no_get", 1);  
			break;
		case 1:
	        message_vision("$N點了點頭，説道，我這裏正好有封信，你去把它送到「"+ob->query_temp("songxin_where")+"」\n的「"+ob->query_temp("songxin_target_name")+"」手上。\n",me,ob);
			message_vision("$N交給$n一封信。\n",me,ob);
			ob=new(__DIR__"obj/letter");
			ob->set_temp("no_get", 1);
			break;
		case 2:
			message_vision("$N微微一笑，從懷中掏出一封信，説道，你趕緊把它送到「"+ob->query_temp("songxin_where")+"」\n的「"+ob->query_temp("songxin_target_name")+"」手上。\n",me,ob);
			message_vision("$N交給$n一封信。\n",me,ob);
			ob=new(__DIR__"obj/letter");
			ob->set_temp("no_get", 1);
			break;
	}
	
	ob->move(this_player());
	return "路上常有強人出沒，務必小心。。";
}
#include "/kungfu/class/gaibang/gaibang.h"