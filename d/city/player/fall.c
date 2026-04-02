// fall.c
#include <ansi.h>
inherit NPC;
int do_hp();
int do_score();
int do_skills();
void create()
{
	set_name("朱七七", ({ "fall"}));
	set("gender", "女性");
	set("long","本潭泥巴文學代表作《恐龍手記》的作者。該作品曾
被許多著名站點轉載，並連載於《電腦遊戲》等刊物。
在短暫的泥潭生涯裏，她經歷了死的寂滅與生的喜悅，
也體驗了練功的艱辛和愛情的甜美，至今她的身影仍
如一朵紫雲開放在崑崙的皚皚白雪中。\n");
	set("title", HIY"翰林碩士"HIG"明教天字門教衆"NOR"明教第三十五代弟子"NOR);
	set("nickname", HIM"天邊紫雲飛"NOR);
	set("age", 28);
	set("class", "eunach");
	set("attitude", "friendly");

	set("kar", 20);
	set("per", 30);
	set("int", 30);
	set("dex", 16);
	set("con", 17);
	set("str", 17);
	set("weiwang", 70);
	set("shen", 250000);
	set("combat_exp", 2717986);
	set("PKS", 0);
	set("MKS", 1011);

	set("max_jing", 540);
	set("jing", 540);
	set("max_qi", 1250);
	set("qi", 1250);
	set("max_jingli", 0);
	set("jingli", 0);
	set("max_neili", 3300);
	set("neili", 3300);
	set("meili", 60);
	set("env/no_teach", "1");

	set_skill("literate", 121);
	set_skill("force", 250);
	set_skill("unarmed",250);
	set_skill("parry", 250);
	set_skill("dodge", 250);
	set_skill("sword", 250);
	set_skill("cuff", 250);
	set_skill("qishang-quan", 200);
	set_skill("qiankun-danuoyi", 210);
	set_skill("jiuyang-shengong", 210);
	set_skill("shenghuo-ling", 200);
	set_skill("shenxing-baibian", 250);

	map_skill("force", "jiuyang-shengong");
	map_skill("dodge", "shenxing-baibian");
	map_skill("parry", "qiankun-danuoyi");
	map_skill("sword", "shenghuo-ling");
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
	carry_object(__DIR__"fall_sword")->wield();
	carry_object(CLOTH_DIR"female-cloth")->wear();
        carry_object(CLOTH_DIR"female-shoe")->wear();
}

int do_skills()
{
message_vision("$N說： 我所有的基本武功如下：\n"+
"  基本劍法 (sword)                         - 深不可測 250/    0\n"+
"□七傷拳 (qishang-quan)                    - 深不可測 200/    0\n"+
"  基本輕功 (dodge)                         - 深不可測 250/    0\n"+
"  基本內功 (force)                         - 深不可測 250/    0\n"+
"□聖火令 (shenghuo-ling)                   - 深不可測 200/    0\n"+
"□九陽神功 (jiuyang-shengong)              - 深不可測 210/    0\n"+
"  讀書寫字 (literate)                      - 瞭然於胸 121/    0\n"+
"  基本招架 (parry)                         - 深不可測 250/    0\n"+
"□神行百變 (shenxing-baibian)              - 深不可測 250/    0\n"+
"  基本拳法 (cuff)                          - 深不可測 250/    0\n"+
"  基本拳腳 (unarmed)                       - 深不可測 250/    0\n"+
"□乾坤大挪移 (qiankun-danuoyi)             - 深不可測 210/    0\n", this_object());

	return 1;
}
int do_hp()
{
message_vision("$N說： 我的基本狀態如下：\n\n"+
"≡------------------------------------------------------------≡\n"+
"【 精 氣 】  540/  540 (100%)    【 精 力 】    0 /    0 (+0)\n"+
"【 氣 血 】 1250/ 1250 (100%)    【 內 力 】 3300 / 3300 (+0)\n"+
"【 食 物 】    0/  270           【 潛 能 】  0\n"+
"【 飲 水 】    0/  270           【 經 驗 】  2717986\n"+
"≡------------------------------------------------------------≡\n", this_object());
	return 1;
}

int do_score()
{
message_vision("$N說： 我的基本狀況如下：\n\n"+
"【曠世女俠】翰林碩士明教天字門教衆明教第三十五代弟子朱七七(fall)n"+
"\n"+
" 你的師父是 張無忌。\n"+
" 你的伴侶是 白雲飛。\n"+
"\n"+
" 你是一位二十八歲的女性人類，甲寅年一月一日辰時三刻生。\n"+
" 膂力：[ 42]  悟性：[ 42]  根骨：[ 42]  身法：[ 41]\n"+
"\n"+
" <精>  ■■■■■■■■■■■■■■■■■■■■■■■■■\n"+
" <氣>  ■■■■■■■■■■■■■■■■■■■■■■■■■\n"+
"\n"+
" 戰鬥攻擊力   400000            戰鬥防禦力   500000\n"+
" 戰鬥傷害力       30            戰鬥保護力         1\n"+
"\n"+
" 食物：□□□□□□□□□□□□□□□□□□□□□□□□□\n"+
" 飲水：□□□□□□□□□□□□□□□□□□□□□□□□□\n"+
"\n"+
" 你到目前爲止總共殺了 1011 個人，其中有 0 個是其他玩家。\n"+
"\n"+
" 正    氣：   250000     潛    能：   0 (100%)   實戰經驗：  2717986\n"+
" 魅    力：       60     江湖閱歷：    12517     江湖威望：       70\n"+
"\n", this_object());
	return 1;
}
