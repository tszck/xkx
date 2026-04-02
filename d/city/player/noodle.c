//noodle.c
# include <ansi.h>
inherit NPC;
int do_hp();
int do_score();
int do_skills();
int do_saite();
void create()
{
	set_name("蕭邪", ({ "noodle"}));
	set("gender", "男性");
	set("long","   生性愚鈍。無憂無慮過了少年，混混噩噩度了青年。
   人到中年，卻對培養新手起了極大興趣。主id淪為大米,培養新角色無數。
所練之新角色曾經在一次比武中，勇奪300萬與500萬兩個桂冠，成為雙料冠軍。
在此期間，偶遇摯友賽特，從此兩人聯手，笑傲江湖（哈哈，現在還在我身邊呢）。
   漸入晚年，與周伯通習得不老之術後，整日與郭靖為伍，為國為民，
武功也突飛猛進，擂臺上鮮有敵手。某日在擂臺上碰一知己，結為連理。
唯憾老婆生性懶惰，使我身負相妻教子之重任。
   終其一生，發現bug無數，最擅長從日常之小事物中發現大bug。\n");
	set("title", HIW"聖人"NOR"吸星小教教主"NOR"逍遙派掌門大師兄"NOR);
	set("nickname", HIW"我喜歡bug"NOR);
	set("age", 46);
	set("class", "swordman");
	set("attitude", "friendly");

	set("kar", 30);
	set("per", 30);
	set("int", 33);
	set("dex", 69);
	set("con", 41);
	set("str", 70);
	set("weiwang", 70);
	set("shen", 3);
	set("combat_exp", 16055317);
	set("PKS", 6);
	set("MKS", 30171);
	set("env/no_teach", "1");

	set("max_jing", 765);
	set("jing", 765);
	set("max_qi", 2436);
	set("qi", 2436);
	set("max_jingli", 740);
	set("jingli", 740);
	set("max_neili", 8130);
	set("neili", 8130);
	set("meili", 60);

	set_skill("literate", 542);
	set_skill("taoism", 200);
	set_skill("force", 542);
	set_skill("unarmed",542);
	set_skill("parry", 542);
	set_skill("dodge", 542);
	set_skill("staff", 542);
	set_skill("cuff", 542);
	set_skill("hand", 542);
	set_skill("claw", 542);
	set_skill("strike", 542);

	set_skill("hamagong", 542);
	set_skill("hamaquan", 542);
	set_skill("jiuyin-baiguzhao", 542);
	set_skill("kongming-quan", 542);
	set_skill("lingboweibu", 542);
	set_skill("lingshe-zhangfa", 542);
	set_skill("shexing-diaoshou", 542);

	map_skill("force", "hamagong");
	map_skill("dodge", "lingboweibu");
	map_skill("parry", "lingshe-zhangfa");
	map_skill("staff", "lingshe-zhangfa");
	map_skill("unarmed","kongming-quan");
	map_skill("cuff","hamaquan");
	map_skill("strike","hamagong");
	map_skill("hand","shexing-diaoshou");
	map_skill("claw","jiuyin-baiguzhao");
	prepare_skill("claw","jiuyin-baiguzhao");

	set("inquiry", ([
		"hp"    : (: do_hp :),
		"score" : (: do_score :),
		"skill" : (: do_skills :),
		"武功"  : (: do_skills :),
		"賽特"  : (: do_saite :),
	]));

	create_family("逍遙派",2, "弟子");

	setup();
	carry_object(CLOTH_DIR"male-cloth")->wear();
        carry_object(CLOTH_DIR"male-shoe")->wear();
}

int do_hp()
{
message_vision("$N説： 我的基本狀態如下：\n\n"+
"≡------------------------------------------------------------≡\n"+
"【 精 氣 】  765/  765 (100％)   【 精 力 】  740 /  740 (+0)\n"+
"【 氣 血 】 2436/ 2436 (100％)   【 內 力 】 8130 / 8130 (+0)\n"+
"【 正 氣 】       3              【 體 力 】  340 /  340\n"+
"【 食 物 】  262/  260           【 潛 能 】  4409\n"+
"【 飲 水 】  260/  260           【 經 驗 】  16055317\n"+
"≡------------------------------------------------------------≡\n", this_object());
	return 1;
}

int do_score()
{
message_vision("$N説： 我的基本狀況如下：\n\n"+
"【 老秀才 】聖人吸星小教教主逍遙派掌門大師兄「我喜歡bug」蕭邪(Noodle)\n"+
"\n"+
"  你是一位四十六歲十二個月性格普通的男性人類，甲寅年一月一日辰時三刻生。\n"+
"  膂力[16/ 70]  悟性[30/ 84]  根骨[19/ 73]  身法[15/ 69]  耐力[15/ 69]\n"+
"  靈性[10/ 30]  福緣[16/ 16]  膽識[15/ 15]  定力[21/ 21]  容貌[38/ 41]\n"+
"\n"+
" 你的師父是 蘇星河。 你的伴侶是 藍點。\n"+
" 存款：五萬一千六百零五兩黃金五十三兩白銀十五文銅錢。\n"+
"\n"+
" <精>  ■■■■■■■■■■■■■■■■■■■■■■■■■\n"+
" <氣>  ■■■■■■■■■■■■■■■■■■■■■■■■■\n"+
"\n"+
" 食物：■■■■■■■■■■■■■■■■■■■■■■■■■\n"+
" 飲水：■■■■■■■■■■■■■■■■■■■■■■■■■\n"+
"\n"+
" 到目前為止你總共殺了 30171 個人，其中有 6 個是其他玩家。\n"+
" 到目前為止你總共殺了 1 個同門，其中有 1 個是你的師長。\n"+
" 到目前為止你總共殺了 0 個幫中弟兄，其中有 0 個是你的上司。\n"+
" 到目前為止你總共殺了 7882 個無辜百姓，其中有 204 個是兒童。\n"+
" 到目前為止你總共死了 130 次了，其中有 11 次是非正常死亡。\n"+
" 到目前為止你總共叛師了 0 次了，被開除了 0 次。\n"+
"\n"+
" 正    氣：        3     潛    能： 4409 ( 99%)  實戰經驗： 16055317\n"+
" 魅    力：       60     江湖閲歷：     8432     江湖威望：       70\n"+
"\n", this_object());
	return 1;
}
int do_skills()
{
command("secret noodle");
return 1;
}
int do_saite()
{
message_vision("$N説：他呀，是我的鐵哥們，我們一起挖泥大半生了。喏，就在我身邊呢
。\n",this_object());
	return 1;
}
