// luoyz.c
#include <ansi.h>
inherit NPC;
int do_hp();
int do_score();
int do_skills();
void create()
{
	set_name("渡天", ({ "luoyz"}));
	set("gender", "男性");
        set("long","本潭最早的玩家之一。雖人在少林，但性情灑脫無拘。
沉迷佛家武學數十年後浪跡江湖，與好友無情紅塵作
伴，瀟瀟灑灑；策馬奔騰，共享人世繁華。\n");
	set("nickname", HIR"老不死, 死賴皮"NOR);
	set("title", HIR"學士"NOR"少林派第三十五代弟子");
	set("age", 66);
	set("class", "bonze");
	set("attitude", "friendly");

	set("kar", 28);
	set("per", 28);
	set("int", 24);
	set("dex", 22);
	set("con", 23);
	set("str", 17);
	set("score", 144);
	set("weiwang", 70);
	set("shen", -17879);
	set("combat_exp", 2692981);
	set("PKS", 2);
	set("MKS", 1894);

	set("max_jing", 1054);
	set("jing", 1054);
	set("max_qi", 1301);
	set("qi", 1301);
	set("max_jingli", 0);
	set("jingli", 0);
	set("max_neili", 3143);
	set("neili", 3143);
	set("meili", 60);
	set("env/no_teach", "1");

	set_skill("buddhism", 180);
	set_skill("claw", 242);
	set_skill("club", 250);
	set_skill("cuff", 180);
	set_skill("damo-jian", 223);
	set_skill("dodge", 250);
	set_skill("finger", 250);
	set_skill("force", 250);
	set_skill("hand", 180);
	set_skill("hunyuan-yiqi", 101);
	set_skill("jingang-quan", 156);
	set_skill("jiuyin-baiguzhao", 214);
	set_skill("kongming-quan", 250);
	set_skill("literate", 160);
	set_skill("nianhua-zhi", 155);
	set_skill("parry", 250);
	set_skill("qianye-shou", 174);
	set_skill("riyue-bian", 232);
	set_skill("shaolin-shenfa", 257);
	set_skill("sword", 191);
	set_skill("unarmed", 250);
	set_skill("whip", 180);
	set_skill("xuantian-zhi", 242);
	set_skill("yijinjing", 201);
	set_skill("yizhi-chan", 250);
	set_skill("zui-gun", 279);

	map_skill("unarmed", "kongming-quan");
	map_skill("sword", "damo-jian");
	map_skill("force", "yijinjing");
	map_skill("cuff", "jingang-quan");
	map_skill("parry", "zui-gun");
	map_skill("whip", "riyue-bian");
	map_skill("claw","jiuyin-baiguzhao");
	map_skill("club", "zui-gun");
	map_skill("finger", "yizhi-chan");
	map_skill("dodge", "shaolin-shenfa");
	prepare_skill("claw", "jiuyin-baiguzhao");

	set("inquiry", ([
		"hp"    : (: do_hp :),
		"score" : (: do_score :),
		"skill" : (: do_skills :),
		"武功"  : (: do_skills :),
	]));

	create_family("峨嵋派",4, "弟子");
	setup();
	carry_object(__DIR__"luoyz_club")->wield();
	carry_object(CLOTH_DIR"seng-cloth")->wear();
        carry_object(CLOTH_DIR"seng-shoe")->wear();
}

int do_skills()
{
message_vision("$N說： 我所有的基本武功如下：\n"+
"≡------------------------------------------------------------≡\n"+
"  禪宗心法 (buddhism)                      - 震古鑠今 180/    0\n"+
"  基本爪法 (claw)                          - 深不可測 242/    0\n"+
"  基本棍法 (club)                          - 深不可測 250/    0\n"+
"  基本拳法 (cuff)                          - 一代宗師 180/    0\n"+
"□達摩劍 (damo-jian)                       - 深不可測 223/    0\n"+
"  基本輕功 (dodge)                         - 深不可測 250/    0\n"+
"  基本指法 (finger)                        - 深不可測 250/    0\n"+
"  基本內功 (force)                         - 深不可測 250/    0\n"+
"  基本手法 (hand)                          - 一代宗師 180/    0\n"+
"  混元一氣功 (hunyuan-yiqi)                - 出類拔萃 101/    0\n"+
"□大金剛拳 (jingang-quan)                  - 出神入化 156/    0\n"+
"□九陰白骨抓 (jiuyin-baiguzhao)            - 深不可測 214/    0\n"+
"□空明拳 (kongming-quan)                   - 深不可測 250/    0\n"+
"  讀書寫字 (literate)                      - 舉世無雙 160/    0\n"+
"  拈花指 (nianhua-zhi)                     - 出神入化 155/    0\n"+
"  基本招架 (parry)                         - 深不可測 250/    0\n"+
"  如來千葉手 (qianye-shou)                 - 登峯造極 174/    0\n"+
"□日月鞭法 (riyue-bian)                    - 深不可測 232/    0\n"+
"□少林身法 (shaolin-shenfa)                - 深不可測 257/    0\n"+
"  基本劍法 (sword)                         - 一代宗師 191/    0\n"+
"  基本拳腳 (unarmed)                       - 深不可測 250/    0\n"+
"  基本鞭法 (whip)                          - 一代宗師 180/    0\n"+
"  玄天無情指 (xuantian-zhi)                - 深不可測 242/    0\n"+
"□易筋經神功 (yijinjing)                   - 深不可測 201/    0\n"+
"□一指禪 (yizhi-chan)                      - 深不可測 250/    0\n"+
"□少林醉棍 (zui-gun)                       - 深不可測 279/    0\n"+
"≡------------------------------------------------------------≡\n", this_object());
	return 1;
}

int do_hp()
{
message_vision("$N說： 我的基本狀態如下：\n\n"+
"≡------------------------------------------------------------≡\n"+
"【 精 氣 】 1054/ 1054 (100%)    【 精 力 】    0 /    0 (+0)\n"+
"【 氣 血 】 1301/ 1301 (100%)    【 內 力 】 3143 / 3143 (+0)\n"+
"【 食 物 】    0/  270           【 潛 能 】  0\n"+
"【 飲 水 】    0/  270           【 經 驗 】  2692981\n"+
"≡------------------------------------------------------------≡\n", this_object());
	return 1;
}

int do_score()
{
message_vision("$N說： 我的基本狀況如下：\n\n"+
"【 長  老 】學士少林派第三十五代弟子「老不死,死賴皮」渡天(Luoyz)\n"+
"\n"+
" 你是一位六十六歲的男性人類，甲寅年一月一日辰時三刻生。\n"+
" 膂力：[ 42]  悟性：[ 40]  根骨：[ 48]  身法：[ 47]\n"+
"\n"+
" <精>  ■■■■■■■■■■■■■■■■■■■■■■■■■\n"+
" <氣>  ■■■■■■■■■■■■■■■■■■■■■■■■■\n"+
"\n"+
" 戰鬥攻擊力   343895            戰鬥防禦力   705361\n"+
" 戰鬥傷害力       30            戰鬥保護力        1\n"+
"\n"+
" 食物：□□□□□□□□□□□□□□□□□□□□□□□□□\n"+
" 飲水：□□□□□□□□□□□□□□□□□□□□□□□□□\n"+
"\n"+
" 你到目前爲止總共殺了 1896 個人，其中有 2 個是其他玩家。\n"+
"\n"+
" 你到目前爲止總共死了 0 次了，其中有 0 次是非正常死亡。\n"+
"\n"+
" 戾    氣：   -17879     潛    能：   0 (100%)   實戰經驗：  2692981\n"+
" 魅    力：       60     江湖閱歷：      144     江湖威望：       70\n"+
"\n", this_object());
	return 1;
}
