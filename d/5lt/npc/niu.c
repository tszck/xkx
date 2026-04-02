// niu.c

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("牛", ({ "niu" }));
	set("title", "隱士");
	set("shen_type", 1);

	set("gender", "男性" );
	set("long", @LONG
他就是電視臺的農業副業主編，年少時投身明教，追隨張教主行走
江湖多年，立下了赫赫戰功，急流勇退後隱於無釐頭村。
LONG);
	set("nickname", HIG"農業頻道主任·林業副業頻道主編"NOR);
	set("age", 30);
	set("per", 30);
	set("attitude", "friendly");		
        set("no_get", "1");
	set("env/no_teach", "1");

	set("inquiry", ([
                 "yoyo": "你問臺長啊，他在電視臺，你是要做廣告嗎？\n",
           "singleblue": "細胳膊啊，她是我的無敵搭檔啊。\n",
                  "lip": "那個可憐的豬頭，正在大連泡mm呢。",
               "fandog": "恩，大狗狗是我們最敬仰的村長。",
                  "niu": "問什麼問，沒見過長得帥的牛嗎？",
	]));   
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("max_qi", 1400);
	set("max_jing", 700);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jiali", 150);

	set("combat_exp", 3000000);
	set_skill("force", 250);
	set_skill("jiuyang-shengong", 250);
	set_skill("dodge", 250);
	set_skill("qiankun-danuoyi", 250);
	set_skill("cuff", 250);
	set_skill("qishang-quan", 250);
	set_skill("parry", 250);
	set_skill("sword", 250);
	set_skill("shenghuo-ling", 250);
	set_skill("taoism", 150);
	set_skill("literate", 300);

	map_skill("force", "jiuyang-shengong");
	map_skill("dodge", "qiankun-danuoyi");
	map_skill("cuff", "qishang-quan");
	map_skill("parry", "qishang-quan");
	map_skill("sword", "shenghuo-ling");
	setup();

	carry_object(CLOTH_DIR"niupi-dayi")->wear();
        carry_object(CLOTH_DIR"niupi-xue")->wear();
}