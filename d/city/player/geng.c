// geng.c
#include <ansi.h>
inherit NPC;
int do_hp();
int do_score();
int do_skills();
void create()
{
	set_name("滑滑小籠包", ({ "geng"}));
	set("gender", "男性");
	set("long","本潭早期玩家，終老於少林。苦心鑽研武學，亦不避塵世
煙雲。青燈古佛，佳人紅袖添香；木魚銅鐸，癡心一段梵
唱。此生有一紅顏知己，遠在白駝大漠，從少林出山後曾
偕愛侶行走江湖，豪俠多情壯士也。\n");
	set("title", HIY"翰林碩士"HIG"明教風字門教眾"NOR"少林派第三十五代弟子");
	set("nickname", HIC"花心大蘿蔔"NOR);
	set("age", 42);
	set("class", "eunach");
	set("attitude", "friendly");

	set("kar", 22);
	set("per", 26);
	set("int", 19);
	set("dex", 20);
	set("con", 20);
	set("str", 24);
	set("weiwang", 70);
	set("shen", 0);
	set("combat_exp", 2404210);
	set("PKS", 3);
	set("MKS", 1437);

	set("max_jing", 1004);
	set("jing", 1004);
	set("max_qi", 1251);
	set("qi", 1251);
	set("max_jingli", 0);
	set("jingli", 0);
	set("max_neili", 3260);
	set("neili", 3260);
	set("meili", 60);
	set("env/no_teach", "1");

	set_skill("literate", 121);
	set_skill("buddhism", 120);
	set_skill("club", 250);
	set_skill("claw",250);
	set_skill("force", 251);
	set_skill("unarmed",250);
	set_skill("parry", 255);
	set_skill("dodge", 250);
	set_skill("sword", 250);
	set_skill("blade", 250);
	set_skill("damo-jian", 219);
	set_skill("finger", 250);
	set_skill("fumo-jian", 260);
	set_skill("hunyuan-yiqi", 250);
	set_skill("jingang-quan", 203);
	set_skill("kongming-quan", 244);
	set_skill("lingboweibu", 268);
	set_skill("nianhua-zhi", 100);
	set_skill("qianye-shou", 110);
	set_skill("sanhua-zhang", 101);
	set_skill("sougu", 271);
	set_skill("strike", 250);
	set_skill("wuyun-jian", 265);
	set_skill("xiuluo-dao", 140);
	set_skill("yijinjing", 201);
	set_skill("zui-gun", 282);
	set_skill("qianye-shou", 110);
	set_skill("hand", 250);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "lingboweibu");
	map_skill("parry", "zui-gun");
	map_skill("sword", "damo-jian");
	map_skill("unarmed","kongming-quan");
	map_skill("club","zui-gun");
	map_skill("finger","nianhua-zhi");
	map_skill("strike","sanhua-zhang");
	map_skill("claw","sougu");
	map_skill("blade","xiuluo-dao");
        map_skill("hand","hand");
	set("inquiry", ([
		"hp"    : (: do_hp :),
		"score" : (: do_score :),
		"skill" : (: do_skills :),
		"武功"  : (: do_skills :),
	]));

	create_family("少林派",35, "弟子");
	setup();
	carry_object(__DIR__"geng_sword")->wield();
	carry_object(CLOTH_DIR"seng-cloth")->wear();
        carry_object(CLOTH_DIR"seng-shoe")->wear();
}

int do_skills()
{
message_vision("$N説： 我所有的基本武功如下：\n"+
"  基本刀法 (blade)                         - 深不可測 250/    0\n"+
"  禪宗心法 (buddhism)                      - 瞭然於胸 120/    0\n"+
"  基本輕功 (dodge)                         - 深不可測 250/    0\n"+
"  基本內功 (force)                         - 深不可測 251/    0\n"+
"  基本棍法 (club)                          - 深不可測 250/    0\n"+
"□達摩劍 (damo-jian)                       - 深不可測 219/    0\n"+
"  基本指法 (finger)                        - 深不可測 250/    0\n"+
"□空明拳 (kongming-quan)                   - 深不可測 244/    0\n"+
"  讀書寫字 (literate)                      - 瞭然於胸 121/    0\n"+
"  基本招架 (parry)                         - 深不可測 255/    0\n"+
"  伏摩劍 (fumo-jian)                       - 深不可測 260/    0\n"+
"  混元一氣功 (hunyuan-yiqi)                - 深不可測 200/    0\n"+
"□大金剛拳 (jingang-quan)                  - 深不可測 203/    0\n"+
"  基本劍法 (sword)                         - 深不可測 250/    0\n"+
"□拈花指 (nianhua-zhi)                     - 出類拔萃 100/    0\n"+
"  基本拳腳 (unarmed)                       - 出神入化 250/    0\n"+
"□如來千葉手 (qianye-shou)                 - 出類拔萃 110/    0\n"+
"□散花掌 (sanhua-zhang)                    - 出類拔萃 101/    0\n"+
"  基本掌法 (strike)                        - 深不可測 250/    0\n"+
"  基本手法 (hand)                          - 深不可測 250/    0\n"+
"  基本爪法 (claw)                          - 深不可測 250/    0\n"+
"□易筋經神功 (yijinjing)                   - 深不可測 201/    0\n"+
"□少林醉棍 (zui-gun)                       - 深不可測 282/    0\n"+
"  五韻七絃劍 (wuyun-jian)                  - 深不可測 265/    0\n"+
"□修羅刀 (xiuluo-dao)                      - 出神入化 140/    0\n"+
"□搜骨鷹爪功 (sougu)                       - 深不可測 271/    0\n", this_object());

	return 1;
}
int do_hp()
{
message_vision("$N説： 我的基本狀態如下：\n\n"+
"≡------------------------------------------------------------≡\n"+
"【 精 氣 】 1004/ 1004 (100%)    【 精 力 】    0 /   0 (+0)\n"+
"【 氣 血 】 1251/ 1251 (100%)    【 內 力 】 3260 / 3260 (+0)\n"+
"【 食 物 】    0/  340           【 潛 能 】  0\n"+
"【 飲 水 】    0/  340           【 經 驗 】  2404210\n"+
"≡------------------------------------------------------------≡\n", this_object());
	return 1;
}

int do_score()
{
message_vision("$N説： 我的基本狀況如下：\n\n"+
"【 聖  僧 】翰林碩士明教風字門教眾少林派第三十五代弟子「花心大蘿蔔」滑滑小籠包(Geng)\n"+
"\n"+
" 你是一位四十二歲三個月的男性人類，甲午年十二月七日亥時二刻生。\n"+
" 膂力：[ 49]  悟性：[ 31]  根骨：[ 46]  身法：[ 42]\n"+
"\n"+
" 你的師父是達摩老祖。             你沒有存款。\n"+
" 你還是個光棍。\n"+
"\n"+
" <精>  ■■■■■■■■■■■■■■■■■■■■■■■■■\n"+
" <氣>  ■■■■■■■■■■■■■■■■■■■■■■■■■\n"+
"\n"+
" 戰鬥攻擊力   450000            戰鬥防禦力   880000\n"+
" 戰鬥傷害力       30            戰鬥保護力        1\n"+
"\n"+
" 食物：□□□□□□□□□□□□□□□□□□□□□□□□□\n"+
" 飲水：□□□□□□□□□□□□□□□□□□□□□□□□□\n"+
"\n"+
" 你到目前為止總共殺了 1437 個人，其中有 3 個是其他玩家。\n"+
"\n"+
" 正    氣：        0     潛    能： 112 ( 99%)   實戰經驗：  2404210\n"+
" 魅    力：       60     江湖閲歷：       54     江湖威望：       70\n"+
"\n", this_object());
	return 1;
}
