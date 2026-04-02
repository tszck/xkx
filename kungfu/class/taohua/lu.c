// lu.c
#include <command.h>
#include <ansi.h>
inherit NPC;                                                                    
inherit F_MASTER;                                                               
string ask_yao();
void create()
{
        set_name( "陸乘風" ,({ "lu chengfeng", "lu" }));
        set("gender", "男性");
        set("age", 52);
        set("long",
            "陸乘風是黃藥師的第四個徒弟。\n"
            "他的鬢角已微見白髮，但身材魁梧，雙眼有神。\n");
        set("attitude", "friendly");
        set("class", "scholar");
        set("str", 30);
        set("int", 28);
        set("con", 30);
        set("dex", 30);
        set("chat_chance", 1);
        set("max_qi",1500);
        set("max_jing",500);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 100);
        set("shen_type",1);
        set("env/wimpy", 60);

        set("combat_exp", 300000);
        set_skill("force", 90);             // 基本內功
        set_skill("bibo-shengong", 80);     // 碧波神功
        set_skill("unarmed", 90);           // 基本拳腳
        set_skill("xuanfeng-leg", 130);      // 旋風掃葉腿
        set_skill("strike", 90);            // 基本掌法
        set_skill("luoying-zhang", 130);     // 落英神劍掌
        set_skill("dodge", 70);             // 基本躲閃
        set_skill("anying-fuxiang", 100);    // 暗影浮香
        set_skill("parry", 90);             // 基本招架
        set_skill("sword", 90);             // 基本劍法
        set_skill("luoying-shenjian", 130);  // 落英神劍
        set_skill("literate",90);           // 讀書識字
        set_skill("qimen-wuxing",60);       // 奇門五行

        map_skill("force"  , "bibo-shengong");
        map_skill("unarmed", "xuanfeng-leg");
        map_skill("strike" , "luoying-zhang");
        map_skill("dodge"  , "anying-fuxiang");
        map_skill("parry"  , "luoying-shenjian");
        map_skill("sword"  , "luoying-shenjian");
	prepare_skill("unarmed", "xuanfeng-leg");
	prepare_skill("strike", "luoying-zhang");

        set("inquiry", ([
           "桃花陣":   "你若不是本派弟子，上桃花島就要過桃花陣。",
           "東邪":     "家師人稱東邪！呵呵。",
           "西毒":     "歐陽鋒是與家師並世齊名的高手，人稱老毒物。",
           "南帝":     "聽家師說段王爺現在出家當了和尚，法名一燈。",
           "北丐":     "北丐洪七公是丐幫幫主，現在揚州城外。",
           "黃蓉":     "她是師父的愛女。",
           "黃藥師":   "你要拜訪家師？",
           "無常丹":   "那是家師密配丹藥，我這哪裏會有？",
           "九花玉露丸":  (: ask_yao :)
        ]) );
        set("jinbing", 10);
        set("yao_count", 1);

        create_family("桃花島", 2, "弟子 歸雲莊莊主");
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}

void attempt_apprentice(object ob)
{
        if (ob->query_dex() < 20)
        {
           command("say 我派武功講究輕靈巧捷。");
           command("say 這位"+RANK_D->query_respect(ob)+"可能是白來歸雲莊一趟了。");
           return;
        }
        if ((int)ob->query("shen") < 0)
        {
           command("say 我派在江湖中立身尚正，"+ RANK_D->query_respect(ob)+"請回吧。");
           return;
        }
        if (ob->query("gender") == "無性")
        {
           command("say 師父最討厭不男不女的東西了，這位"+RANK_D->query_respect(ob)+"趕快請吧。");
           return;
        }
        if (ob->query("class") == "bonze")
        {
           command("say 師父最愛非僧抑道了，這位"+RANK_D->query_respect(ob)+"還是請回吧。");
           return;
        }
        if (ob->query_skill("literate",1) <= 10)
        {
           command("say 桃花島只收讀書人作弟子，這位"+RANK_D->query_respect(ob)+"是否去讀點書再來。");
           return;
        }
        command("smile");
        command("say " + RANK_D->query_respect(ob) + "入我門下，需努力不墮。");
        command("recruit " + ob->query("id"));
}
int accept_fight(object ob)
{
        command("wield jian");
}
int accept_object(object who, object ob)
{
	int exp,pot,score;
	if (query("jinbing") < 0)
	{
                command("say " + RANK_D->query_respect(who) + "我很累，你回頭再來領賞吧。");
		return 0;
	}
	if (ob->query("userp") == 1)
	{
		message_vision("$N對着$n說：我叫你殺金狗，你卻去殺玩家！去死吧你！\n", this_object() , who);
		this_object()->kill_ob(who);
		return 1;
	}
	if (strsrch(ob->query("name"), "完顏康的頭顱") < 0 &&
	    strsrch(ob->query("name"), "完顏洪烈的頭顱") < 0 &&
	    strsrch(ob->query("name"), "歐陽鋒的頭顱") < 0 &&
	    strsrch(ob->query("name"), "歐陽克的頭顱") < 0 &&
	    strsrch(ob->query("name"), "彭連虎的頭顱") < 0 &&
	    strsrch(ob->query("name"), "樑子翁的頭顱") < 0 &&
	    strsrch(ob->query("name"), "靈智上人的頭顱") < 0 &&
	    strsrch(ob->query("name"), "沙通天的頭顱") < 0 &&
	    strsrch(ob->query("name"), "侯通海的頭顱") < 0 &&
	    strsrch(ob->query("name"), "沈青剛的頭顱") < 0 &&
	    strsrch(ob->query("name"), "吳青烈的頭顱") < 0 &&
	    strsrch(ob->query("name"), "馬青雄的頭顱") < 0 &&
	    strsrch(ob->query("name"), "錢青健的頭顱") < 0 &&
	    strsrch(ob->query("name"), "大金兵的頭顱") < 0 &&
	    strsrch(ob->query("name"), "段天德的頭顱") < 0) 
	{
                command("say 給我這些東西有什麼用？\n");
		return 0;
	}
	else
	{
                command("say 不錯不錯，我一直想殺這些金狗，謝你代勞了。");
	}
	exp = 20 + random(30);
        pot = 20 + random(10);
	score = 30 + random(20); 
	who->add("combat_exp", exp);
	who->add("potential",pot);
	who->add("score", score);		
	add("jinbing", -1);
	tell_object(who,HIW"你獲得了"+chinese_number(exp)+"點實戰經驗和"+chinese_number(pot)+"點潛能和"+chinese_number(score)+"點江湖閱歷。\n"NOR);
	return 1;
}
string ask_yao()
{
	object ob, me = this_player();
	
	if (me->query("family/family_name")!="桃花島")
		return RANK_D->query_respect(me) + "非我派弟子，不知此話從何談起？";
	if (query("yao_count") < 1 || random(3) > 0)
		return "你來晚了，九花玉露丸給小師妹了。";
	add("yao_count", -1);
	ob = new("/clone/medicine/nostrum/jiuhuawan");
	ob->move(me);
	return "好吧，這丸九花玉露丸就先給你吧。";
}
