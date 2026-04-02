// fall.c
#include <ansi.h>
inherit NPC;
int do_hp();
int do_score();
int do_skills();
void create()
{
	set_name("步驚雲", ({ "news"}));
	set("gender", "男性");
	set("long","早年遊俠江湖，酷愛交友和解謎，曾創下三天兩夜不眠挖泥
的超級記錄，為人偶爾亦會整人，雖有點放蕩不羈，但常
真誠幫人。雖其貌不驚人，但其發展新手的速度可謂是
前無古人後無來者。早年出身丐幫當小乞丐，而後出家全真，
轉而陪伴東方不敗繡花，最後於凌霄之顛，一覽天下小。\n");
	set("title", HIW"聖人"HIG"明教天字門教眾"NOR"凌霄城掌門大師兄"NOR);
	set("nickname", HIR"不哭死神"NOR);
	set("age", 18);
	set("class", "sword");
	set("attitude", "friendly");

	set("kar", 30);
	set("per", 30);
	set("int", 42);
	set("dex", 41);
	set("con", 42);
	set("str", 42);
	set("weiwang", 10);
	set("shen", 8623);
	set("combat_exp", 2995735);
	set("PKS", 1);
	set("MKS", 1968);

	set("max_jing", 250);
	set("jing", 250);
	set("max_qi", 1092);
	set("qi", 1092);
	set("max_jingli", 0);
	set("jingli", 0);
	set("max_neili", 3650);
	set("neili", 3650);
	set("meili", 0);
	set("env/no_teach", "1");

	set_skill("literate", 200);
	set_skill("taoism", 99);
	set_skill("dodge", 199);
	set_skill("force", 219);
	set_skill("parry", 174);
	set_skill("unarmed",20);
	set_skill("sword", 298);
	set_skill("strike", 100);
	set_skill("bingxue-xinfa", 990);
	set_skill("snow-strike", 12);
	set_skill("snowstep", 226);
	set_skill("taixuan-gong", 251);
	set_skill("xueshan-sword", 304);

	map_skill("force", "bingxue-xinfa");
	map_skill("dodge", "snowstep");
	map_skill("parry", "xueshan-sword");
	map_skill("sword", "xueshan-sword");
	map_skill("unarmed","taixuan-gong");
	map_skill("strike","snow-strike");
	set("inquiry", ([
		"hp"    : (: do_hp :),
		"score" : (: do_score :),
		"skill" : (: do_skills :),
		"武功"  : (: do_skills :),
	]));

	create_family("明教",35, "弟子");
	setup();
	carry_object(CLOTH_DIR"male-cloth")->wear();
        carry_object(CLOTH_DIR"male-shoe")->wear();
}

int do_skills()
{
message_vision("$N説： 我所有的基本武功如下：\n"+

"≡------------------------------------------------------------------≡\n"+
"□冰雪心法 (bingxue-xinfa)                 - 神乎其技 299/ 1464\n"+
"  基本輕功 (dodge)                         - 融會貫通 199/   73\n"+
"  基本內功 (force)                         - 爐火純青 219/ 9497\n"+
"  讀書寫字 (literate)                      - 融會貫通 200/  882\n"+
"  基本招架 (parry)                         - 駕輕就熟 174/   19\n"+
"□飛雪映梅掌 (snow-strike)                 - 毫不足慮  12/   34\n"+
"□梅雪飄香 (snowstep)                      - 瞭然於胸 226/10062\n"+
"  基本掌法 (strike)                        - 平淡無奇 100/    0\n"+
"  基本劍法 (sword)                         - 神乎其技 298/53415\n"+
"□太玄功 (taixuan-gong)                    - 豁然貫通 251/    0\n"+
"  道學心法 (taoism)                        - 半生不熟  99/    0\n"+
"  基本拳腳 (unarmed)                       - 不足掛齒  20/    2\n"+
"□雪山劍法 (xueshan-sword)                 - 出神入化 304/40829\n"+
"≡------------------------------------------------------------------≡\n", this_object());
	return 1;
}
int do_hp()
{
message_vision("$N説： 我的基本狀態如下：\n\n"+
"≡------------------------------------------------------------≡\n"+
"【 精 氣 】  250/  250 (100％)   【 精 力 】    0 /    0 (+0)\n"+
"【 氣 血 】 1092/ 1092 (100％)   【 內 力 】 3650 / 3650 (+0)\n"+
"【 正 氣 】    8623              【 體 力 】   50 /   50\n"+
"【 食 物 】  256/  300           【 潛 能 】  0\n"+
"【 飲 水 】  179/  300           【 經 驗 】  2995735\n"+
"≡------------------------------------------------------------≡\n", this_object());
	return 1;
}

int do_score()
{
message_vision("$N説： 我的基本狀況如下：\n\n"+
"【 劍  士 】明教天字門教眾凌霄城掌門大師兄「不哭死神」步驚雲(News)\n\n"+
" 你是一位十九歲五個月性格普通的男性人類，甲寅年一月一日辰時三刻生。\n"+
" 膂力[20/ 30]  悟性[30/ 50]  根骨[16/ 37]  身法[14/ 33]  耐力[24/ 41]\n"+
" 靈性[25/ 34]  福緣[30/ 30]  膽識[22/ 22]  定力[15/ 15]  容貌[20/320]\n\n"+
" 你的師父是 白自在。        你還是個光棍。\n"+
" 存款：二百三十三兩黃金七十七兩白銀二十九文銅錢。\n\n"+
" <精>  ■■■■■■■■■■■■■■■■■■■■■■■■■\n"+
" <氣>  ■■■■■■■■■■■■■■■■■■■■■■■■■\n\n"+
" 食物：■■■■■■■■■■■■■■■■■■■■■□□□□\n"+
" 飲水：■■■■■■■■■■■■■■■□□□□□□□□□□\n\n"+
" 你到目前為止總共殺了 2115 個人，其中有 1 個是其他玩家。\n"+
" 你到目前為止總共死了 25 次了，其中有 19 次是非正常死亡。\n\n"+
" 正    氣：     8623     潛    能：  20 ( 99%)   實戰經驗：  2959269\n"+
" 魅    力：       60     江湖閲歷：    22994     江湖威望：       30\n"+
"\n", this_object());
	return 1;
}
