// eagleg.c
#include <ansi.h>
inherit NPC;
int do_hp();
int do_score();
int do_skills();
void create()
{
	set_name("孤鷹", ({ "eagleg"}));
	set("gender", "男性");
	set("long","本潭最早的玩家之一。桃花島第一大俠。他石雕似的方臉配着
鷹隼般銳利的雙眼，不時閃射出寒冰似的殺機；渾身上下每寸
肌肉都顯示出無窮的力量，象尊掌管生死的地獄之魔。\n");
	set("title", HIW"聖人"NOR"桃花島第二代弟子");
	set("nickname", HIB"黑羽掠空"HIW"了無痕"NOR);
	set("age", 47);
	set("class", "eunach");
	set("attitude", "friendly");

	set("kar", 29);
	set("per", 26);
	set("int", 28);
	set("dex", 32);
	set("con", 36);
	set("str", 26);
	set("weiwang", 70);
	set("shen", 6217202);
	set("combat_exp", 5455577);
	set("PKS", 4);
	set("MKS", 6628);

	set("max_jing", 548);
	set("jing", 548);
	set("max_qi", 1501);
	set("qi", 1501);
	set("max_jingli", 0);
	set("jingli", 0);
	set("max_neili", 3300);
	set("neili", 3300);
	set("meili", 60);
	set("env/no_teach", "1");

	set_skill("literate", 206);
	set_skill("array", 250);
	set_skill("count", 250);
	set_skill("force", 253);
	set_skill("unarmed",250);
	set_skill("parry", 278);
	set_skill("dodge", 268);
	set_skill("sword", 250);
	set_skill("lanhua-shou", 375);
	set_skill("hand", 250);
	set_skill("hanbing-mianzhang", 372);
	set_skill("luoying-shenjian", 375);
	set_skill("qimen-wuxing", 102);
	set_skill("shenxing-baibian", 375);
	set_skill("tanzhi-shentong", 370);
	set_skill("yuxiao-jian", 376);
	set_skill("bibo-shengong", 204);
	set_skill("strike", 250);
	set_skill("luoying-zhang", 259);
        set_skill("xuanfeng-leg", 273);
        set_skill("finger", 250);

	map_skill("force", "bibo-shengong");
	map_skill("dodge", "shenxing-baibian");
	map_skill("parry", "yuxiao-jian");
	map_skill("finger", "tanzhi-shentong");
	map_skill("hand", "lanhua-shou");
	map_skill("sword", "yuxiao-jian");
	map_skill("unarmed","xuanfeng-leg");
	map_skill("strike","luoying-zhang");
	set("inquiry", ([
		"hp"    : (: do_hp :),
		"score" : (: do_score :),
		"skill" : (: do_skills :),
		"武功"  : (: do_skills :),
	]));

	create_family("桃花島",2, "弟子");
	setup();
	carry_object(__DIR__"eagleg_sword")->wield();
	carry_object(CLOTH_DIR"male-cloth")->wear();
        carry_object(CLOTH_DIR"male-shoe")->wear();
}

int do_skills()
{
message_vision("$N說： 我所有的基本武功如下：\n"+
"  基本陣法 (array)                         - 深不可測 250/    0\n"+
"□碧波神功 (bibo-shengong)                 - 深不可測 204/    0\n"+
"  基本輕功 (dodge)                         - 深不可測 268/    0\n"+
"  基本內功 (force)                         - 深不可測 253/    0\n"+
"  陰陽八卦 (count)                         - 深不可測 250/    0\n"+
"  基本指法 (finger)                        - 深不可測 250/    0\n"+
"  寒冰綿掌 (hanbing-mianzhang)             - 深不可測 372/    0\n"+
"  基本手法 (hand)                          - 深不可測 250/    0\n"+
"  讀書寫字 (literate)                      - 瞭然於胸 206/    0\n"+
"  基本招架 (parry)                         - 深不可測 278/    0\n"+
"□蘭花拂穴手 (lanhua-shou)                 - 深不可測 375/    0\n"+
"  神行百變 (shenxing-baibian)              - 粗通皮毛 375/    0\n"+
"  落英神劍 (luoying-shenjian)              - 深不可測 375/    0\n"+
"  基本劍法 (sword)                         - 深不可測 250/    0\n"+
"  落英神劍掌 (luoying-zhang)               - 深不可測 259/    0\n"+
"  基本拳腳 (unarmed)                       - 出神入化 250/    0\n"+
"  奇門五行 (qimen-wuxing)                  - 心領神會 102/    0\n"+
"  基本掌法 (strike)                        - 深不可測 250/    0\n"+
"□旋風掃葉腿 (xuanfeng-leg)                - 深不可測 273/    0\n"+
"□玉簫劍法 (yuxiao-jian)                   - 深不可測 376/    0\n"+
"□彈指神通 (tanzhi-shentong)               - 深不可測 370/    0\n", this_object());

	return 1;
}
int do_hp()
{
message_vision("$N說： 我的基本狀態如下：\n\n"+
"≡------------------------------------------------------------≡\n"+
"【 精 氣 】  548/  548 (100%)    【 精 力 】    0 /    0 (+0)\n"+
"【 氣 血 】 1501/ 1501 (100%)    【 內 力 】 3300 / 3300 (+0)\n"+
"【 食 物 】    0/  360           【 潛 能 】  0\n"+
"【 飲 水 】    0/  360           【 經 驗 】  5455577\n"+
"≡------------------------------------------------------------≡\n", this_object());
	return 1;
}

int do_score()
{
message_vision("$N說： 我的基本狀況如下：\n\n"+
"【曠世大俠】聖人 桃花島第二代弟子 孤鷹(Eagleg)\n"+
"\n"+
" 你是一位四十七歲五個月的男性人類，戊子年七月十日巳時四刻生。\n"+
" 膂力：[ 51]  悟性：[ 48]  根骨：[ 61]  身法：[ 58]\n"+
"\n"+
" 你的師父是 黃藥師。             你沒有存款。\n"+
" 你的伴侶是 走走。\n"+
"\n"+
" <精>  ■■■■■■■■■■■■■■■■■■■■■■■■■\n"+
" <氣>  ■■■■■■■■■■■■■■■■■■■■■■■■■\n"+
"\n"+
" 戰鬥攻擊力   448204            戰鬥防禦力  1045272\n"+
" 戰鬥傷害力       30            戰鬥保護力        1\n"+
"\n"+
" 食物：□□□□□□□□□□□□□□□□□□□□□□□□□\n"+
" 飲水：□□□□□□□□□□□□□□□□□□□□□□□□□\n"+
"\n"+
" 你到目前爲止總共殺了 6628 個人，其中有 4 個是其他玩家。\n"+
"\n"+
" 正    氣：  6217202     潛    能：   0 (100%)   實戰經驗：  5455577\n"+
" 魅    力：       60     江湖閱歷：      172     江湖威望：       70\n"+
"\n", this_object());
	return 1;
}
