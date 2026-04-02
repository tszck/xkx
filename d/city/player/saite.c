// saite.c
#include <ansi.h>
inherit NPC;
int do_hp();
int do_score();
int do_skills();
int do_noodle();
int do_linqiyan();
int do_baoer();
int do_yuki();
int do_ftlsk();
void create()
{
	set_name("賽特", ({ "saite"}));
	set("gender", "男性");
	set("long","自2001年接觸xkx100以來，一直是這裏的忠實擁護者。從此在
這裏常常能看到他的身影。其間幫助新手老手無數，受到衆玩
家的喜愛。可惜終生未得一紅顏知己，僅有一至交蕭邪相伴，
共同享受泥潭樂趣。其培養的很多id號如kofc ssread等都曾
經奪取過比武大會名次。泥潭晚期對編寫機器人及解迷產生濃
厚興趣，並由此發現不少大小bug，雖對泥潭日益熟悉，但人非
聖賢，許多迷題終不得解，引爲憾事，逍遙而去。\n");
	set("title", NOR"逍遙派第三代弟子"NOR);
	set("nickname", HIC"我就只能當她哥們吧.."NOR);
	set("age", 34);
	set("class", "swordman");
	set("attitude", "friendly");

	set("kar", 20);
	set("per", 30);
	set("int", 37);
	set("dex", 40);
	set("con", 35);
	set("str", 40);
	set("weiwang", 50);
	set("shen", -802282);
	set("combat_exp", 1691661);
	set("PKS", 2);
	set("MKS", 7449);

	set("max_jing", 570);
	set("jing", 570);
	set("max_qi", 982);
	set("qi", 982);
	set("max_jingli", 600);
	set("jingli", 600);
	set("max_neili", 8130);
	set("neili", 8130);
	set("meili", 60);

	set_skill("literate", 175);
	set_skill("taoism", 120);
	set_skill("force", 200);
	set_skill("unarmed",100);
	set_skill("parry", 200);
	set_skill("dodge", 200);
	set_skill("construction", 10);
	set_skill("hubo", 200);
	set_skill("qimen-wuxing", 101);
	set_skill("claw", 151);
	set_skill("sword", 601);
	set_skill("training", 39);
	set("env/no_teach", "1");

	set_skill("shenzhao-jing", 157);
	set_skill("jinshe-jian", 200);
	set_skill("jinshe-zhui", 200);
	set_skill("jiuyin-baiguzhao", 171);
	set_skill("beiming-shengong", 200);
	set_skill("kongming-quan", 1);
	set_skill("lingboweibu", 204);
	set_skill("tianyu-qijian", 202);
	map_skill("dodge", "lingboweibu");
	map_skill("parry", "tianyu-qijian");
	map_skill("throwing", "jinshe-zhui");
	map_skill("claw","jiuyin-baiguzhao");
	map_skill("sword","tianyu-qijian");
	prepare_skill("claw","jiuyin-baiguzhao");

	set("inquiry", ([
		"hp"    : (: do_hp :),
		"score" : (: do_score :),
		"skill" : (: do_skills :),
		"noodle"  : (: do_noodle :),
		"linqiyan": (: do_linqiyan :),
		"yuki"	: (: do_yuki :),
		"baoer" : (: do_baoer :),
		"ftlsk" : (: do_ftlsk :),
	]));

	create_family("逍遙派",2, "弟子");
	setup();
//	carry_object(__DIR__"saite_sword")->wield();
	carry_object(CLOTH_DIR"male-cloth")->wear();
    carry_object(CLOTH_DIR"male-shoe")->wear();
}

int do_skills()
{
message_vision("$N說： 我所有的基本武功如下：\n"+

"≡------------------------------------------------------------------≡\n"+
"  北冥神功 (beiming-shengong)              - 心領神會 200/  173\n"+
"  基本爪法 (claw)                          - 已有小成 151/  163\n"+
"  土木機關 (construction)                  - 新學乍用  10/   48\n"+
"  基本輕功 (dodge)                         - 心領神會 200/  198\n"+
"  基本內功 (force)                         - 心領神會 200/   31\n"+
"  左右互搏 (hubo)                          - 半生不熟 100/    0\n"+
"  金蛇劍法 (jinshe-jian)                   - 心領神會 200/  527\n"+
"□金蛇錐法 (jinshe-zhui)                   - 心領神會 200/    8\n"+
"□九陰白骨抓 (jiuyin-baiguzhao)            - 駕輕就熟 171/14648\n"+
"  空明拳 (kongming-quan)                   - 不堪一擊   1/    0\n"+
"□凌波微步 (lingboweibu)                   - 心領神會 204/41847\n"+
"  讀書寫字 (literate)                      - 已有小成 175/ 3851\n"+
"  基本招架 (parry)                         - 心領神會 200/ 1119\n"+
"  奇門五行 (qimen-wuxing)                  - 半生不熟 101/    0\n"+
"□神照經 (shenzhao-jing)                   - 已有小成 157/17362\n"+
"  基本劍法 (sword)                         - 心領神會 201/ 1413\n"+
"  道學心法 (taoism)                        - 馬馬虎虎 120/  314\n"+
"□天羽奇劍 (tianyu-qijian)                 - 心領神會 202/ 6566\n"+
"  馭獸術 (training)                        - 初窺門徑  39/  828\n"+
"  基本拳腳 (unarmed)                       - 平淡無奇 100/   22\n"+
"≡------------------------------------------------------------------≡\n", this_object());
	return 1;
}

int do_hp()
{
message_vision("$N說： 我的基本狀態如下：\n\n"+
"≡------------------------------------------------------------≡\n"+
"【 精 氣 】  570/  570 (100％)   【 精 力 】  600 /  600 (+0)\n"+
"【 氣 血 】  982/  982 (100％)   【 內 力 】 2570 / 2570 (+0)\n"+
"【 戾 氣 】 -802282              【 體 力 】  276 /  276\n"+
"【 食 物 】  350/  350           【 潛 能 】  307\n"+
"【 飲 水 】  350/  350           【 經 驗 】  1691661\n"+
"≡------------------------------------------------------------≡\n", this_object());
	return 1;
}

int do_score()
{
message_vision("$N說： 我的基本狀況如下：\n\n"+
"【 魔  王 】逍遙派第三代弟子「我就只能當她哥們吧...」賽特(Saite)\n"+
"\n"+
" 你是一位三十四歲四個月性格普通的男性人類，己卯年三月七日辰時四刻生。\n"+
" 膂力[25/ 40]  悟性[20/ 37]  根骨[15/ 35]  身法[20/ 40]  耐力[11/ 31]\n"+
" 靈性[18/ 30]  福緣[20/ 20]  膽識[30/ 30]  定力[21/ 21]  容貌[18/ 18]\n"+
"\n"+
" 你的師父是 心傷。        你還是個光棍。\n"+
" 存款：一千九百三十三兩黃金二十七兩白銀。\n"+
"\n"+
" <精>  ■■■■■■■■■■■■■■■■■■■■■■■■■\n"+
" <氣>  ■■■■■■■■■■■■■■■■■■■■■■■■■\n"+
"\n"+
" 食物：■■■■■■■■■■■■■■■■■■■■■■■■■\n"+
" 飲水：■■■■■■■■■■■■■■■■■■■■■■■■■\n"+
"\n"+
" 到目前爲止你總共殺了 7449 個人，其中有 2 個是其他玩家。\n"+
" 到目前爲止你總共殺了 3 個同門，其中有 0 個是你的師長。\n"+
" 到目前爲止你總共殺了 3 個幫中弟兄，其中有 0 個是你的上司。\n"+
" 到目前爲止你總共殺了 3564 個無辜百姓，其中有 28 個是兒童。\n"+
" 到目前爲止你總共死了 5 次了，其中有 3 次是非正常死亡。\n"+
" 到目前爲止你總共叛師了 0 次了，被開除了 0 次。\n"+
"\n"+
" 戾    氣：  -802282     潛    能： 307 ( 99%)   實戰經驗：  1691661\n"+
" 魅    力：       60     江湖閱歷：    25236     江湖威望：       50\n"+
"\n", this_object());
	return 1;
}

int do_noodle()
{message_vision("$N說：他呀，是我的鐵哥們，我們一起挖泥大半生了。喏，就在我身邊呢
。\n",this_object());
	return 1;
}

int do_linqiyan()
{message_vision("$N說：小燕子阿，他是我在學校一起玩飛雪的兄弟了。他比他師兄影
楓可安靜多了，最不喜歡出風頭\n",this_object());
	return 1;
}

int do_baoer()
{message_vision("$N說：鈴の寶ル呀，她是我在泥潭中唯一心怡的人了，可惜初次認識時，
她已經有心上人了。唉，什麼時候才能再見到她啊....\n",this_object());
	return 1;
}

int do_yuki()
{message_vision("$N說：你說徐懷鈺啊，他可是我的老前輩。這傢伙的籃球技術可了不得，
籃板\n"+
"三分樣樣拿手。高是夠高了，就是瘦了點，做校籃球隊主力還差那麼一些體力。\n",this_object());
	return 1;
}

int do_ftlsk()
{message_vision("$N說：凱子這傢伙，有事沒事就給我找麻煩。不過也沒辦法，誰叫我\n"+
"比他玩得早呢。想想蝦米時候要再敲他幾頓飯爽爽。heihei  \n",this_object());
	return 1;
}
