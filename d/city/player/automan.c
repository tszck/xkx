// automan.c
#include <ansi.h>
inherit NPC;
int do_hp();
int do_score();
int do_skills();
void create()
{
	set_name("笑三少", ({ "automan"}));
	set("gender", "男性");
	set("title", HIW"聖人"NOR"武當派第三代弟子「"HIC"天網恢恢 "HIR"疏而不漏"NOR"」");
	set("nickname", HIY"俠客行初中分舵舵主"NOR);
	set("long", "本潭初中分舵舵主。姑蘇慕容門下第一大俠，鬥轉星移絕技
唯一傳人，以“以彼之道，還施彼身”聞名天下。後來加入武當派，
成為一個不為人知的小道士。所發現的蟲蟲之多令人震驚。\n");
	set("age", 25);
	set("class", "swordman");
	set("attitude", "friendly");

	set("kar", 30);
	set("per", 30);
	set("int", 30);
	set("dex", 20);
	set("con", 25);
	set("str", 21);
	set("weiwang", 90);
	set("shen", 270000);
	set("combat_exp", 4953266);
	set("PKS", 23);
	set("MKS", 16424);
	set("max_jing", 485);
	set("jing", 485);
	set("max_qi", 2553);
	set("qi", 2553);
	set("max_jingli", 180);
	set("jingli", 180);
	set("max_neili", 3050);
	set("neili", 3050);
	set("meili", 60);
	set("score", 36534);
	set("env/no_teach", "1");

	set_skill("claw", 250);
	set_skill("cuff", 250);
	set_skill("dodge", 301);
	set_skill("douzhuan-xingyi", 150);
	set_skill("finger", 250);
	set_skill("force", 319);
	set_skill("hand", 250);
	set_skill("jiuyin-baiguzhao", 230);
	set_skill("literate", 296);
	set_skill("murong-sword", 201);
	set_skill("parry", 250);
	set_skill("strike", 250);
	set_skill("sword", 330);
	set_skill("liangyi-jian", 345);
	set_skill("taiji-jian", 360);
	set_skill("taiji-quan", 200);
	set_skill("taiji-shengong", 299);
	set_skill("tiyunzong", 259);
	set_skill("taoism", 150);
	set_skill("unarmed", 250);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "liangyi-jian");
	map_skill("unarmed", "taiji-quan");
	map_skill("claw", "jiuyin-baiguzhao");

	set("inquiry", ([
		"hp"    : (: do_hp :),
		"skill" : (: do_skills :),
		"score" : (: do_score :),
		"武功"  : (: do_skills :),
	]));

	create_family("武當派", 3, "弟子");
	setup();
	carry_object(__DIR__"automan_sword")->wield();
	carry_object(CLOTH_DIR"male-cloth")->wear();
        carry_object(CLOTH_DIR"male-shoe")->wear();
}

int do_skills()
{
message_vision("$N説： 我所有的基本武功如下：\n"+
"≡------------------------------------------------------------≡\n"+
"  基本爪法 (claw)                          - 深不可測 250/    0\n"+
"  基本拳法 (cuff)                          - 深不可測 250/    0\n"+
"  基本輕功 (dodge)                         - 深不可測 301/56468\n"+
"  鬥轉星移 (douzhuan-xingyi)               - 瞭然於胸 150/    0\n"+
"  基本指法 (finger)                        - 深不可測 250/    0\n"+
"  基本內功 (force)                         - 深不可測 319/31356\n"+
"  基本手法 (hand)                          - 深不可測 250/    0\n"+
"□九陰白骨抓 (jiuyin-baiguzhao)            - 深不可測 230/   59\n"+
"□兩儀劍法 (liangyi-jian)                  - 深不可測 345/55463\n"+
"  讀書寫字 (literate)                      - 深不可測 296/    0\n"+
"  慕容劍法 (murong-sword)                  - 深不可測 201/    3\n"+
"  基本招架 (parry)                         - 深不可測 250/    0\n"+
"  基本掌法 (strike)                        - 深不可測 250/    0\n"+
"  基本劍法 (sword)                         - 深不可測 330/    1\n"+
"□太極劍法 (taiji-jian)                    - 深不可測 360/ 1415\n"+
"□太極拳 (taiji-quan)                      - 深不可測 200/    2\n"+
"□太極神功 (taiji-shengong)                - 深不可測 299/   37\n"+
"  道學心法 (taoism)                        - 瞭然於胸 150/    0\n"+
"□梯雲縱 (tiyunzong)                       - 深不可測 259/ 3287\n"+
"  基本拳腳 (unamred)                       - 深不可測 250/    0\n"+
"≡------------------------------------------------------------≡\n", this_object());

	return 1;
}

int do_hp()
{
message_vision("$N説： 我的基本狀態如下：\n\n"+
"≡------------------------------------------------------------≡\n"+
"【 精 氣 】  485/  850 (100%)    【 精 力 】  180 /  180 (+0)\n"+
"【 氣 血 】 2553/ 2553 (100%)    【 內 力 】 3050 / 3050 (+0)\n"+
"【 食 物 】    0/  300           【 潛 能 】  0\n"+
"【 飲 水 】    0/  300           【 經 驗 】  4953266\n"+
"≡------------------------------------------------------------≡\n", this_object());
	return 1;
}

int do_score()
{
message_vision("$N説： 我的基本狀況如下：\n\n"+
"【 曠世大俠 】聖人武當派第三代弟子「天網恢恢 疏而不漏」笑三少(Automan)\n"+
" 你是一位二十八歲二個月的男性人類，甲寅年五月十九日辰時三刻生。\n"+
" 膂力：[21/46 ]  悟性：[30/ 59 ]   根骨：[25/ 56]  身法：[20/ 50]\n"+
" 你的師父是 宋遠橋。             存款：四十六兩黃金十兩白銀三十六文銅錢。\n"+
" 你還是個光棍。\n"+
" <精>  ■■■■■■■■■■■■■■■■■■■■■■■■■\n"+
" <氣>  ■■■■■■■■■■■■■■■■■■■■■■■■■\n"+
"\n"+
"戰鬥攻擊力   302190         戰鬥防禦力   502991\n"+
"戰鬥傷害力   200            戰鬥保護力   2 \n"+
"\n"+
" 食物：□□□□□□□□□□□□□□□□□□□□□□□□□\n"+
" 飲水：□□□□□□□□□□□□□□□□□□□□□□□□□\n"+
"\n"+
" 你到目前為止總共殺了 16424 個人，其中有 23 個是其他玩家。\n"+
" 你到目前為止總共死了 7 次了，其中有 3 次是非正常死亡。\n"+
"\n"+
" 正    氣：   270000     潛    能： 0  ( 100%)    實戰經驗：   4953266\n"+
" 魅    力：       60     江湖閲歷：     36534     江湖威望：        90\n"+
"\n", this_object());
	return 1;
}
