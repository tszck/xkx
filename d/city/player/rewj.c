// rewj.c
#include <ansi.h>
inherit NPC;
int do_hp();
int do_score();
int do_skills();
void create()
{
	set_name("阿卡", ({ "rewj"}));
	set("gender", "男性");
        set("long",
"本潭知名的一位老玩家。早期師出峨嵋，憑藉一身絕技
 橫行武林，成名後修道於崑崙之顛。快意江湖爲人豪爽，
 詼諧幽默，插科打諢，活躍氣氛，廣交朋友，是一個人
 緣極好的老混混。\n");
        set("title", "崑崙派第二代弟子");
        set("nickname", HIR"一生一火花"NOR);
	set("age", 27);
	set("class", "taoist");
	set("attitude", "friendly");

	set("kar", 20);
	set("per", 29);
	set("int", 31);
	set("dex", 14);
	set("con", 21);
	set("str", 16);
	set("weiwang", 30);
	set("shen", 47384);
	set("combat_exp", 1016246);
	set("PKS", 2);
	set("MKS", 73);

	set("max_jing", 596);
	set("jing", 596);
	set("max_qi", 1210);
	set("qi", 1210);
	set("max_jingli", 0);
	set("jingli", 0);
	set("max_neili", 3096);
	set("neili", 3096);
	set("meili", 60);
	set("env/no_teach", "1");

	set_skill("literate", 180);
	set_skill("force", 212);
	set_skill("unarmed",200);
	set_skill("parry", 200);
	set_skill("dodge", 200);
	set_skill("sword", 216);
	set_skill("cuff", 100);
	set_skill("leg", 101);
	set_skill("goplaying", 159);
	set_skill("luteplaying",159);
	set_skill("gambling",4);
	set_skill("strike", 100);

	set_skill("chuanyun-leg", 200);
	set_skill("kunlun-strike", 200);
	set_skill("liangyi-sword", 216);
	set_skill("taxue-wuhen",210);
	set_skill("xuantian-wuji",209);
	set_skill("zhentian-cuff",201);
	set_skill("xunlei-sword",216);

	map_skill("force", "xuantian-wuji");
	map_skill("dodge", "taxue-wuhen");
	map_skill("parry", "liangyi-sword");
	map_skill("sword", "liangyi-sword");
	map_skill("leg","chuanyun-leg");
	map_skill("strike","kunlun-strike");

	set("inquiry", ([
		"hp"    : (: do_hp :),
		"skill" : (: do_skills :),
		"score" : (: do_score :),
		"武功"  : (: do_skills :),
	]));
	create_family("崑崙派",2, "弟子");
	setup();
        carry_object(__DIR__"rewj_sword")->wield();
	carry_object(CLOTH_DIR"dao-cloth")->wear();
        carry_object(CLOTH_DIR"dao-shoe")->wear();
}

int do_skills()
{
message_vision("$N說： 我所有的基本武功如下：\n"+
"≡------------------------------------------------------------≡\n"+
"□穿雲腿 (chuanyun-leg)                    - 心領神會 200/    0\n"+
"  基本拳法 (cuff)                          - 平淡無奇 100/    0\n"+
"  基本輕功 (dodge)                         - 心領神會 200/    0\n"+
"  基本內功 (force)                         - 爐火純青 212/    0\n"+
"  紋枰手談 (goplaying)                     - 已有小成 159/    0\n"+
"□崑崙掌 (kunlun-strike)                   - 心領神會 200/    0\n"+
"  基本腿法 (leg)                           - 平淡無奇 100/    0\n"+
"□正兩儀劍法 (liangyi-sword)               - 爐火純青 216/    0\n"+
"□踏雪無痕 (taxue-wuhen)                   - 爐火純青 210/    0\n"+
"  讀書寫字 (literate)                      - 融會貫通 180/    0\n"+
"  繞樑琴藝 (luteplaying)                   - 已有小成 159/    0\n"+
"  基本招架 (parry)                         - 心領神會 200/    0\n"+
"  基本掌法 (strike)                        - 平淡無奇 100/    0\n"+
"  基本劍法 (sword)                         - 爐火純青 216/    0\n"+
"  基本拳腳 (unarmed)                       - 心領神會 200/    0\n"+
"□玄天無極功 (xuantian-wuji)               - 心領神會 209/    0\n"+
"  迅雷十六劍 (xunlei-sword)                - 爐火純青 216/    0\n"+
"□震天拳法 (zhentian-cuff)                 - 心領神會 201/    0\n"+
"≡------------------------------------------------------------≡\n", this_object());

	return 1;
}

int do_hp()
{
message_vision("$N說： 我的基本狀態如下：\n\n"+
"≡------------------------------------------------------------≡\n"+
"【 精 氣 】  596/  596 (100%)    【 精 力 】    0 /    0 (+0)\n"+
"【 氣 血 】  1210/  1210 (100%)    【 內 力 】 3096 / 3096 (+0)\n"+
"【 食 物 】    0/  300           【 潛 能 】  0\n"+
"【 飲 水 】    0/  300           【 經 驗 】  1016246\n"+
"≡------------------------------------------------------------≡\n", this_object());
	return 1;
}

int do_score()
{
message_vision("$N說： 我的基本狀況如下：\n\n"+
"【實習捕快】崑崙派第二代弟子「獵戶座照耀的傷心人」阿卡(Rewj)\n"+
"\n"+
" 你是一位二十七歲八個月的男性人類，甲寅年一月一日辰時三刻生。\n"+
" 膂力：[16/ 36]  悟性：[31/ 49]   根骨：[21/ 42]  身法：[14/ 34]\n"+
" 耐力：[ 14]  福緣：[ 20]  膽識：[ 29]  定力：[ 11]  容貌：[ 15]\n"+
"\n"+
" <精>  ■■■■■■■■■■■■■■■■■■■■■■■■■\n"+
" <氣>  ■■■■■■■■■■■■■■■■■■■■■■■■■\n"+
"\n"+
" 戰鬥攻擊力    57936            戰鬥防禦力   100818\n"+
" 戰鬥傷害力      230            戰鬥保護力        2\n"+
"\n"+
" 食物：□□□□□□□□□□□□□□□□□□□□□□□□□\n"+
" 飲水：□□□□□□□□□□□□□□□□□□□□□□□□□\n"+
"\n"+
" 你到目前爲止總共殺了 3795 個人，其中有 2 個是其他玩家。\n"+
" 你到目前爲止總共死了 73 次了，其中有 68 次是非正常死亡。\n"+
"\n"+
" 正    氣：    47384     潛    能： 5241 ( 98%)  實戰經驗：  1016246\n"+
" 魅    力：       60     江湖閱歷：    32366     江湖威望：       30\n"+
"\n", this_object());
	return 1;
}
