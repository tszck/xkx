// top.c
#include <ansi.h>
inherit NPC;
int do_hp();
int do_score();
int do_skills();
void create()
{
	set_name("冷楓", ({ "top"}));
	set("gender", "男性");
	set("long","雪山派弟子，天賦異稟，年少時隻身一人遠遊西域，投師雪山。
短短數年即已名揚天下。成名後浪跡天涯，武學境界一日千里。
某年春暖花開之際，牽馬漫步江南雨巷，邂逅一位冰雪佳人，兩
情相悅，遂結為夫妻，從此淡出江湖，晚年開創逍遙門，屬下門
徒甚眾，乃武林第一幫派也。他年近花甲，兩鬢斑白，額上幾道
深深的皺紋，略顯孤單的目光，恰似秋涼時片片楓葉飄落的滄桑。\n");
	set("title", HIW"聖人"NOR"逍遙門門主"NOR);
	set("nickname", HIY"福"HIR" 星"HIG" 高"HIB" 照"NOR);
	set("age", 56);
	set("attitude", "friendly");

	set("kar", 30);
	set("per", 26);
	set("int", 24);
	set("dex", 11);
	set("con", 24);
	set("str", 26);
	set("weiwang", 80);
	set("shen", 1744183791);
	set("combat_exp", 9138500);
	set("PKS", 19);
	set("MKS", 11831);

	set("max_jing", 522);
	set("jing", 522);
	set("max_qi", 3011);
	set("qi", 3011);
	set("max_jingli", 154);
	set("jingli", 154);
	set("max_neili", 5002);
	set("neili", 5002);
	set("meili", 60);
	set("env/no_teach", "1");

	set_skill("literate", 272);
	set_skill("force", 290);
	set_skill("parry", 382);
	set_skill("dodge", 320);
	set_skill("sword", 303);
	set_skill("cuff", 298);
        set_skill("houquan",440);
        set_skill("dashou-yin",400);
        set_skill("blade",339);
        set_skill("claw",298);
        set_skill("hubo",138);
        set_skill("huoyan-dao",435);
        set_skill("hand",298);
        set_skill("hammer",298);
        set_skill("liangyi-jian",428);
        set_skill("mingwang-jian",419);
        set_skill("necromancy",198);
        set_skill("qiankun-danuoyi",248);
        set_skill("qiufeng-chenfa",424);
        set_skill("riyue-lun",423);
        set_skill("shenxing-baibian",429);
        set_skill("strike",298);
        set_skill("taiji-jian",415);
        set_skill("taiji-quan",330);
        set_skill("taiji-shengong",332);
        set_skill("taoism",150);
        set_skill("unarmed",311);
        set_skill("wuhu-duanmendao",201);
        set_skill("xue-dao",438);
        set_skill("yujiamu-quan",400);
        set_skill("taixuan-gong",278);

	map_skill("unarmed", "houquan");
	map_skill("hand", "dashou-yin");
	map_skill("sword", "liangyi-jian");
	map_skill("blade", "wuhu-duanmendao");
	map_skill("force", "taiji-shengong");
	map_skill("cuff", "yujiamu-quan");
	map_skill("parry", "taiji-jian");
	map_skill("whip", "qiufeng-chenfa");
	map_skill("claw", "jiuyin-baiguzhao");
	map_skill("strike", "huoyan-dao");
	map_skill("dodge", "shenxingbaibian");
	map_skill("hammer", "riyue-lun");
	set("inquiry", ([
		"hp"    : (: do_hp :),
		"score" : (: do_score :),
		"skill" : (: do_skills :),
		"武功"  : (: do_skills :),
	]));

	create_family("雪山寺",6, "弟子");
	setup();
	carry_object(__DIR__"top_sword")->wield();
	carry_object(CLOTH_DIR"male-cloth")->wear();
        carry_object(CLOTH_DIR"male-shoe")->wear();
}

int do_skills()
{
message_vision("$N説： 我所有的基本武功如下：\n"+
"  基本刀法 (blade)                         - 深不可測 339/   44\n"+
"  基本爪法 (claw)                          - 深不可測 298/   12\n"+
"  基本拳法 (cuff)                          - 深不可測 298/    1\n"+
"□密宗大手印 (dashou-yin)                  - 超凡入聖 400/18380\n"+
"  基本輕功 (dodge)                         - 深不可測 320/51443\n"+
"  基本內功 (force)                         - 深不可測 352/13145\n"+
"  基本錘法 (hammer)                        - 深不可測 298/   21\n"+
"  基本手法 (hand)                          - 深不可測 298/    2\n"+
"□猴拳 (houquan)                           - 超凡入聖 440/71026\n"+
"  左右互搏 (hubo)                          - 瞭然於胸 138/    0\n"+
"□火焰刀 (huoyan-dao)                      - 超凡入聖 435/  195\n"+
"□九陰白骨抓 (jiuyin-baiguzhao)            - 深不可測 211/    0\n"+
"□兩儀劍法 (liangyi-jian)                  - 超凡入聖 428/    1\n"+
"  讀書寫字 (literate)                      - 深不可測 272/ 1583\n"+
"  不動明王劍 (mingwang-jian)               - 超凡入聖 419/    0\n"+
"  降伏法 (necromancy)                      - 一代宗師 198/  106\n"+
"  基本招架 (parry)                         - 深不可測 382/40526\n"+
"  乾坤大挪移 (qiankun-danuoyi)             - 深不可測 248/    0\n"+
"□秋風拂塵 (qiufeng-chenfa)                - 超凡入聖 424/32382\n"+
"□日月輪法 (riyue-lun)                     - 超凡入聖 423/84670\n"+
"□神行百變 (shenxing-baibian)              - 超凡入聖 429/ 6500\n"+
"  基本掌法 (strike)                        - 深不可測 298/    0\n"+
"  基本劍法 (sword)                         - 深不可測 303/   69\n"+
"□太極劍法 (taiji-jian)                    - 超凡入聖 415/134233\n"+
"  太極拳 (taiji-quan)                      - 深不可測 330/  193\n"+
"□太極神功 (taiji-shengong)                - 深不可測 332/18089\n"+
"  太玄功 (taixuan-gong)                    - 深不可測 278/37811\n"+
"  道學心法 (taoism)                        - 豁然貫通 150/    0\n"+
"  基本拳腳 (unarmed)                       - 深不可測 311/26426\n"+
"□五虎斷門刀 (wuhu-duanmendao)             - 深不可測 201/ 2312\n"+
"  血刀刀法 (xue-dao)                       - 超凡入聖 438/48464\n"+
"□金剛瑜迦母拳 (yujiamu-quan)              - 超凡入聖 400/62140\n", this_object());
	return 1;
}
int do_hp()
{
message_vision("$N説： 我的基本狀態如下：\n\n"+
"≡------------------------------------------------------------≡\n"+
"【 精 氣 】  522/  522 (100%)   【 精 力 】  154 /  154 (+0)\n"+
"【 氣 血 】 3011/ 3011 (100%)   【 內 力 】 5002 / 5002 (+0)\n"+
"【 食 物 】  191/  360          【 潛 能 】  19\n"+
"【 飲 水 】  150/  360          【 經 驗 】  9138500\n"+
"≡------------------------------------------------------------≡\n", this_object());
}

int do_score()
{
message_vision("$N説： 我的基本狀況如下：\n\n"+
"【曠世大俠】聖人逍遙門門主雪山派俗家弟子「福 星 高 照」冷楓(Top)\n"+
"\n"+
" 你是一位五十六歲九個月的男性人類，甲寅年一月一日辰時三刻生。\n"+
" 膂力：[ 57]  悟性：[ 51]  根骨：[ 46]  身法：[ 56]\n"+
"\n"+
" 你的師父是 葛倫布。             存款：二千零十四兩黃金。\n"+
" 你還是個光棍。\n"+
"\n"+
" <精>  ■■■■■■■■■■■■■■■■■■■■■■■■■\n"+
" <氣>  ■■■■■■■■■■■■■■■■■■■■■■■■■\n"+
"\n"+
" 食物：■■■■■■■■■■■■■□□□□□□□□□□□□\n"+
" 飲水：■■■■■■■■■■□□□□□□□□□□□□□□□\n"+
"\n"+
" 你到目前為止總共殺了 11831 個人，其中有 19 個是其他玩家。\n"+
"\n"+
" 你到目前為止總共死了 41 次了，其中有 29 次是非正常死亡。\n"+
"\n"+
" 正    氣： 1744183791   潛    能：  19 ( 99%)   實戰經驗：  9138500\n"+
" 魅    力：       60     江湖閲歷：   345593     江湖威望：       80\n"+
"\n", this_object());
	return 1;
}
