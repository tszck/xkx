// shh.c
#include <ansi.h>
inherit NPC;
int do_hp();
int do_score();
int do_skills();
void create()
{
	set_name("沈浪", ({ "shh"}));
	set("gender", "男性");
	set("long","明教第一大俠，數十年潛心武學，淡泊名利。他喜歡
在黃昏時牽一匹白馬，披一件大氅，獨自佇立於崑崙
山巔的雪原裏，凝望天邊的落日。誰能瞭解他內心的
孤寂呢？也許武學的最高境界就是將刀光劍影斂藏於
心。人生的榮耀已隨着歲月流逝，他的額頭隱現皺紋，
面容清癯，眼裏有一絲淡淡的憂傷。\n");
	set("title", HIW"聖人"HIG"明教天字門教眾"NOR"明教第三十五代弟子"NOR);
	set("nickname", HIR"落日"HIY"一笑"NOR);
	set("age", 68);
	set("class", "eunach");
	set("attitude", "friendly");

	set("kar", 20);
	set("per", 20);
	set("int", 24);
	set("dex", 16);
	set("con", 22);
	set("str", 20);
	set("weiwang", 20);
	set("shen", 205010);
	set("combat_exp", 11313839);
	set("PKS", 1);
	set("MKS", 13844);

	set("max_jing", 616);
	set("jing", 616);
	set("max_qi", 1459);
	set("qi", 1459);
	set("max_jingli", 531);
	set("jingli", 531);
	set("max_neili", 4190);
	set("neili", 4190);
	set("meili", 60);
	set("env/no_teach", "1");

	set_skill("literate", 300);
	set_skill("force", 300);
	set_skill("unarmed",260);
	set_skill("parry", 295);
	set_skill("dodge", 298);
	set_skill("sword", 260);
	set_skill("cuff", 260);
	set_skill("qishang-quan", 423);
	set_skill("qiankun-danuoyi", 260);
	set_skill("jiuyang-shengong", 282);
	set_skill("tianyu-qijian", 292);
	set_skill("shenxing-baibian", 435);
        set_skill("strike", 250);
        set_skill("hanbing-mianzhang", 283);
        set_skill("taoism", 120);
        set_skill("hand", 250);
        set_skill("hubo", 110);

	map_skill("force", "jiuyang-shengong");
	map_skill("dodge", "shenxing-baibian");
	map_skill("parry", "qiankun-danuoyi");
	map_skill("sword", "tianyu-qijian");
	map_skill("unarmed","qiankun-danuoyi");
	map_skill("cuff","qishang-quan");
	set("inquiry", ([
		"hp"    : (: do_hp :),
		"score" : (: do_score :),
		"skill" : (: do_skills :),
		"武功"  : (: do_skills :),
	]));

	create_family("明教",35, "弟子");
	setup();
	carry_object(__DIR__"shh_sword")->wield();
	carry_object(CLOTH_DIR"male-cloth")->wear();
        carry_object(CLOTH_DIR"male-shoe")->wear();
}

int do_skills()
{
message_vision("$N説： 我所有的基本武功如下：\n"+
"  基本劍法 (sword)                         - 深不可測 260/    0\n"+
"□七傷拳 (qishang-quan)                    - 深不可測 423/    0\n"+
"  基本輕功 (dodge)                         - 深不可測 298/    0\n"+
"  基本內功 (force)                         - 深不可測 300/    0\n"+
"□天羽奇劍 (tianyu-qijian)                 - 深不可測 292/    0\n"+
"□九陽神功 (jiuyang-shengong)              - 深不可測 282/    0\n"+
"  讀書寫字 (literate)                      - 深不可測 300/    0\n"+
"  基本招架 (parry)                         - 深不可測 295/    0\n"+
"□神行百變 (shenxing-baibian)              - 深不可測 435/    0\n"+
"  基本拳法 (cuff)                          - 深不可測 260/    0\n"+
"  基本拳腳 (unarmed)                       - 深不可測 260/    0\n"+
"  基本掌法 (strike)                        - 深不可測 250/    0\n"+
"  寒冰綿掌 (hanbing-mianzhang)             - 深不可測 283/    0\n"+
"  基本手法 (hand)                          - 深不可測 250/    0\n"+
"  道學心法 (taoism)                        - 瞭然於胸 120/    0\n"+
"  左右互搏 (hubo)                          - 出類拔萃 110/    0\n"+
"□乾坤大挪移 (qiankun-danuoyi)             - 深不可測 260/    0\n", this_object());

	return 1;
}
int do_hp()
{
message_vision("$N説： 我的基本狀態如下：\n\n"+
"≡------------------------------------------------------------≡\n"+
"【 精 氣 】  616/  616 (100%)    【 精 力 】  531 /  531 (+0)\n"+
"【 氣 血 】 1459/ 1459 (100%)    【 內 力 】 4190 / 4190 (+0)\n"+
"【 食 物 】    0/  300           【 潛 能 】  0\n"+
"【 飲 水 】    0/  300           【 經 驗 】  11313839\n"+
"≡------------------------------------------------------------≡\n", this_object());
	return 1;
}

int do_score()
{
message_vision("$N説： 我的基本狀況如下：\n\n"+
"【曠世大俠】聖人明教天字門教眾天下第二大俠明教第三十五代弟子「落日一笑」沈浪(Shh)\n"+
"\n"+
" 你是一位六十八歲十個月的男性人類，甲寅年一月一日辰時三刻生。\n"+
" 膂力：[ 46]  悟性：[ 54]  根骨：[ 52]  身法：[ 45]"+
"\n"+
" <精>  ■■■■■■■■■■■■■■■■■■■■■■■■■\n"+
" <氣>  ■■■■■■■■■■■■■■■■■■■■■■■■■\n"+
"\n"+
" 戰鬥攻擊力  2100000            戰鬥防禦力   2300000\n"+
" 戰鬥傷害力       30            戰鬥保護力         1\n"+
"\n"+
" 食物：□□□□□□□□□□□□□□□□□□□□□□□□□\n"+
" 飲水：□□□□□□□□□□□□□□□□□□□□□□□□□\n"+
"\n"+
" 你到目前為止總共殺了 13844 個人，其中有 1 個是其他玩家。\n"+
"\n"+
" 正    氣：   205010     潛    能：   0 (100%)   實戰經驗： 11313839\n"+
" 魅    力：       60     江湖閲歷：   0          江湖威望：       20\n"+
"\n", this_object());
	return 1;
}
