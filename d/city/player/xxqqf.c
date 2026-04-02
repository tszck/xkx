// xxqqf.c
#include <ansi.h>
inherit NPC;
int do_hp();
int do_score();
int do_skills();
void create()
{
	set_name("標準情人", ({ "xxqqf"}));
	set("gender", "男性");
	set("long","桃花島弟子，師從黃老邪經年苦練終成本潭武林至尊。開
創天龍門提攜新手聲名遠揚。年輕氣盛時曾獨步中原，憑
借本門絕技“蘭花拂穴”和“天外清音”狂傲不可一世，
後經歷一番情感波折，悄然歸隱桃花島，潛心武學，不問
江湖。他的鬚髮皆白，神色有些蒼涼，然眼中不時掠過一
絲青芒，似七月的流星墜落天際。\n");
	set("title", HIW"聖人"NOR"天龍門門主"NOR);
	set("nickname", HIR"愛"HIG"你一萬"HIB"年"NOR);
	set("age", 79);
	set("attitude", "friendly");

	set("kar", 30);
	set("per", 27);
	set("int", 30);
	set("dex", 18);
	set("con", 21);
	set("str", 20);
	set("weiwang", 30);
	set("shen", 10819664);
	set("combat_exp", 12129747);
	set("PKS", 28);
	set("MKS", 29859);

	set("max_jing", 485);
	set("jing", 485);
	set("max_qi", 1353);
	set("qi", 1353);
	set("max_jingli", 0);
	set("jingli", 0);
	set("max_neili", 4050);
	set("neili", 4050);
	set("meili", 60);
	set("env/no_teach", "1");

	set_skill("literate", 201);
	set_skill("force", 290);
	set_skill("unarmed",250);
	set_skill("parry", 300);
	set_skill("dodge", 251);
	set_skill("sword", 270);
	set_skill("cuff", 250);
        set_skill("array",233);
        set_skill("bibo-shengong",260);
        set_skill("blade",250);
        set_skill("claw",250);
        set_skill("count",103);
        set_skill("finger",250);
        set_skill("hand",250);
        set_skill("jiuyin-baiguzhao",270);
        set_skill("kuangfeng-blade",182);
        set_skill("lanhua-shou",444);
        set_skill("lingboweibu",50);
        set_skill("luoying-zhang",443);
        set_skill("qimen-wuxing",51);
        set_skill("shenxing-baibian",375);
        set_skill("strike",250);
        set_skill("taixuan-gong",248);
        set_skill("tanzhi-shentong",369);
        set_skill("xuanfeng-leg",427);
        set_skill("yuxiao-jian",444);

	map_skill("force", "bibo-shengong");
	map_skill("dodge", "shenxing-baibian");
	map_skill("parry", "lanhua-shou");
	map_skill("sword", "yuxiao-jian");
	map_skill("unarmed","xuanfeng-leg");
	map_skill("hand","lanhua-shou");
	set("inquiry", ([
		"hp"    : (: do_hp :),
		"score" : (: do_score :),
		"skill" : (: do_skills :),
		"武功"  : (: do_skills :),
	]));

	create_family("桃花島",3, "弟子");
	setup();
	carry_object(__DIR__"xxqqf_sword")->wield();
	carry_object(CLOTH_DIR"male-cloth")->wear();
        carry_object(CLOTH_DIR"male-shoe")->wear();
}

int do_skills()
{
message_vision("$N説： 我所有的基本武功如下：\n"+
"  暗影浮香 (anying-fuxiang)                - 深不可測 340/  303\n"+
"  基本陣法 (array)                         - 深不可測 233/12605\n"+
"□碧波神功 (bibo-shengong)                 - 深不可測 260/13541\n"+
"  基本刀法 (blade)                         - 深不可測 250/    0\n"+
"  基本爪法 (claw)                          - 深不可測 250/    0\n"+
"  陰陽八卦 (count)                         - 心領神會 103/  283\n"+
"  基本拳法 (cuff)                          - 深不可測 250/    0\n"+
"  基本輕功 (dodge)                         - 深不可測 251/ 3268\n"+
"  基本指法 (finger)                        - 深不可測 250/    0\n"+
"  基本內功 (force)                         - 深不可測 290/29861\n"+
"  基本手法 (hand)                          - 深不可測 250/    5\n"+
"□九陰白骨抓 (jiuyin-baiguzhao)            - 深不可測 270/   59\n"+
"□狂風刀法 (kuangfeng-blade)               - 一代宗師 182/27564\n"+
"□蘭花拂穴手 (lanhua-shou)                 - 超凡入聖 444/78267\n"+
"  凌波微步 (lingboweibu)                   - 半生不熟  50/  380\n"+
"  讀書寫字 (literate)                      - 深不可測 201/    0\n"+
"□落英神劍掌 (luoying-zhang)               - 超凡入聖 443/117000\n"+
"  基本招架 (parry)                         - 深不可測 300/76467\n"+
"  奇門五行 (qimen-wuxing)                  - 略知一二  51/  861\n"+
"□神行百變 (shenxing-baibian)              - 深不可測 375/10342\n"+
"  基本掌法 (strike)                        - 深不可測 250/    0\n"+
"  基本劍法 (sword)                         - 深不可測 270/    1\n"+
"  太玄功 (taixuan-gong)                    - 深不可測 248/    0\n"+
"□彈指神通 (tanzhi-shentong)               - 深不可測 369/93330\n"+
"  基本拳腳 (unarmed)                       - 深不可測 250/    0\n"+
"□旋風掃葉腿 (xuanfeng-leg)                - 超凡入聖 427/   14\n"+
"□玉簫劍法 (yuxiao-jian)                   - 超凡入聖 444/37462\n", this_object());
	return 1;
}
int do_hp()
{
message_vision("$N説： 我的基本狀態如下：\n\n"+
"≡------------------------------------------------------------≡\n"+
"【 精 氣 】  485/  485 (100%)   【 精 力 】    0 /    0 (+0)\n"+
"【 氣 血 】 1353/ 1353 (100%)   【 內 力 】 4050 / 4050 (+0)\n"+
"【 食 物 】  222/  280          【 潛 能 】  49584\n"+
"【 飲 水 】  225/  280          【 經 驗 】  12129747\n"+
"≡------------------------------------------------------------≡\n", this_object());
}

int do_score()
{
message_vision("$N説： 我的基本狀況如下：\n\n"+
"【曠世大俠】聖人天龍門門主桃花島第三代弟子「愛你一萬年」標準情人(Xxqqf)\n"+
"\n"+
" 你是一位七十九歲十二個月的男性人類，戊午年二月二十七日醜時一刻生。\n"+
" 膂力：[ 18]  悟性：[ 30]  根骨：[ 21]  身法：[ 24]\n"+
"\n"+
" 你的師父是陸乘風。             存款：十八萬三千五百五十兩黃金。\n"+
" 你還是個光棍。\n"+
"\n"+
" <精>  ■■■■■■■■■■■■■■■■■■■■■■■■■\n"+
" <氣>  ■■■■■■■■■■■■■■■■■■■■■■■■■\n"+
"\n"+
" 戰鬥攻擊力   317578            戰鬥防禦力   860038\n"+
" 戰鬥傷害力      260            戰鬥保護力        1\n"+
"\n"+
" 食物：■■■■■■■■■■■■■■■■■■■■■■■■■\n"+
" 飲水：■■■■■■■■■■■■■■■■■■■■■■□□□\n"+
"\n"+
" 你到目前為止總共殺了 29860 個人，其中有 28 個是其他玩家。\n"+
" 你到目前為止總共死了 5 次了，其中有 -1 次是非正常死亡。\n"+
"\n"+
" 正    氣： 10820830     潛    能： 49612 ( 95%)         實戰經驗： 12130073\n"+
" 魅    力：       60     江湖閲歷：    43898     江湖威望：       30\n"+
"\n", this_object());
	return 1;
}
