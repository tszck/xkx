// laughing.c
#include <ansi.h>
inherit NPC;
int do_hp();
int do_score();
int do_skills();
void create()
{
	set_name("笑笑生", ({ "laughing"}));
	set("gender", "男性");
	set("long","這是一位江湖著名遊俠，早些年曾在丐幫呆過，降龍掌
的雷霆一擊無人能敵，但後來卻淡出江湖，如閒雲野鶴
般浪跡天涯。人們忘記了他的威儀和強悍，卻時常能在
街市裏見到他懶散儒雅的微笑。\n");
	set("title", HIW"聖人"NOR"普通百姓"NOR);
	set("nickname", HIB"獨立小橋"HIG"風滿袖"NOR);
	set("age", 45);
	set("class", "eunach");
	set("attitude", "friendly");

	set("kar", 10);
	set("per", 27);
	set("int", 30);
	set("dex", 16);
	set("con", 14);
	set("str", 20);
	set("weiwang", 70);
	set("shen", 0);
	set("combat_exp", 6238756);
	set("PKS", 0);
	set("MKS", 3107);

	set("max_jing", 700);
	set("jing", 700);
	set("max_qi", 1500);
	set("qi", 1500);
	set("max_jingli", 500);
	set("jingli", 500);
	set("max_neili", 3900);
	set("neili", 3900);
	set("meili", 60);
	set("env/no_teach", "1");

	set_skill("literate", 210);
	set_skill("taoism", 100);
	set_skill("force", 260);
	set_skill("unarmed",265);
	set_skill("parry", 260);
	set_skill("dodge", 260);
	set_skill("blade", 250);
	set_skill("staff", 250);
	set_skill("xianglong-zhang", 380);
	set_skill("lingboweibu", 380);
	set_skill("huntian-qigong", 260);
	set_skill("kuangfeng-blade", 380);
	set_skill("dagou-bang", 380);

	map_skill("force", "huntian-qigong");
	map_skill("dodge", "lingboweibu");
	map_skill("parry", "xianglong-zhang");
	map_skill("blade", "kuangfeng-blade");
	map_skill("unarmed","xianglong-zhang");
	map_skill("staff","dagou-bang");
	set("inquiry", ([
		"hp"    : (: do_hp :),
		"score" : (: do_score :),
		"skill" : (: do_skills :),
		"武功"  : (: do_skills :),
	]));

	create_family("丐幫",18, "弟子");
	setup();
	carry_object(__DIR__"laughing_sword")->wield();
	carry_object(CLOTH_DIR"male-cloth")->wear();
        carry_object(CLOTH_DIR"male-shoe")->wear();
}

int do_skills()
{
message_vision("$N說： 我所有的基本武功如下：\n"+
"  基本刀法 (blade)                         - 深不可測 250/    0\n"+
"□打狗棒法 (dagou-bang)                    - 深不可測 380/    0\n"+
"  基本輕功 (dodge)                         - 深不可測 260/    0\n"+
"  基本內功 (force)                         - 深不可測 260/    0\n"+
"□狂風刀   (kuangfeng-blade)               - 深不可測 380/    0\n"+
"□混天氣功 (huntian-qigong)                - 深不可測 260/    0\n"+
"  讀書寫字 (literate)                      - 深不可測 210/    0\n"+
"  基本招架 (parry)                         - 深不可測 260/    0\n"+
"□凌波微步 (lingboweibu)                   - 深不可測 380/    0\n"+
"  基本杖法 (staff)                         - 深不可測 250/    0\n"+
"  道學心法 (taoism)                        - 心領神會 100/    0\n"+
"  基本拳腳 (unarmed)                       - 深不可測 265/    0\n"+
"□降龍十八掌 (xianglong-zhang)             - 深不可測 380/    0\n", this_object());

	return 1;
}
int do_hp()
{
message_vision("$N說： 我的基本狀態如下：\n\n"+
"≡------------------------------------------------------------≡\n"+
"【 精 氣 】  700/  700 (100%)    【 精 力 】  500 /  500 (+0)\n"+
"【 氣 血 】 1500/ 1500 (100%)    【 內 力 】 3900 / 3900 (+0)\n"+
"【 食 物 】    0/  300           【 潛 能 】  0\n"+
"【 飲 水 】    0/  300           【 經 驗 】  6238756\n"+
"≡------------------------------------------------------------≡\n", this_object());
	return 1;
}

int do_score()
{
message_vision("$N說： 我的基本狀況如下：\n\n"+
"【曠世大俠】聖人普通百姓「獨立小橋風滿袖」笑笑生(Laughing)\n"+
"\n"+
" 你是一位四十五歲的男性人類，甲寅年一月一日辰時三刻生。\n"+
" 膂力：[ 46]  悟性：[ 51]  根骨：[ 40]  身法：[ 42]\n"+
"\n"+
" <精>  ■■■■■■■■■■■■■■■■■■■■■■■■■\n"+
" <氣>  ■■■■■■■■■■■■■■■■■■■■■■■■■\n"+
"\n"+
" 戰鬥攻擊力   800000            戰鬥防禦力   1000000\n"+
" 戰鬥傷害力       30            戰鬥保護力         1\n"+
"\n"+
" 食物：□□□□□□□□□□□□□□□□□□□□□□□□□\n"+
" 飲水：□□□□□□□□□□□□□□□□□□□□□□□□□\n"+
"\n"+
" 你到目前爲止總共殺了 3107 個人，其中有 0 個是其他玩家。\n"+
"\n"+
" 正    氣：        0     潛    能：   0 (100%)   實戰經驗：  6238756\n"+
" 魅    力：       60     綜合評價：        0     江湖威望：       70\n"+
"\n", this_object());
	return 1;
}
