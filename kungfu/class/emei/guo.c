// guo.c 郭襄
// Modified by Winder Jul.2000
#include <command.h>
#include <ansi.h>

inherit NPC;
inherit F_MASTER;
string ask_for_quit();
mixed out_master(mixed arg);

void create()
{
	set_name("郭襄", ({ "guo xiang","guo","xiang"}));
	set("long",
"她十八九歲年紀，身穿淡黃衣衫，騎着一頭青驢，正緩緩而行。
她腰懸短劍，臉上頗有風塵之色，顯是遠遊已久；韶華如花，正
當喜樂無憂之年，可是容色間卻隱隱有懊悶意，似是愁思襲人，
眉間心上，無計迴避。她姓郭，單名一個襄字，乃大俠郭靖和女
俠黃蓉的次女，現下她一驢一劍，隻身漫遊，排遣心中愁悶。\n");
	set("gender", "女性");
	set("nickname", "小東邪");
	set("age", 18);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("shen", 100000);
	set("class", "bonze");
	set("env/wimpy", 60);

	set("str", 35);
	set("int", 35);
	set("con", 35);
	set("dex", 35);
	set("per", 20);

	set("max_qi", 4000);
	set("max_jing", 2000);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jingli", 1500);
	set("max_jingli", 1500);
	set_temp("is_riding", HIC"青驢"NOR);
	set("combat_exp", 3000000);
	set("score", 1000);
	set("chat_chance", 10);
	set("chat_msg", ({
		"郭襄低聲吟道：「問世間，情是何物，直教生死相許？」\n",
		"郭襄低聲吟道：「天南地北雙飛客，老翅幾回寒暑？」\n",
		"郭襄低聲吟道：「歡樂趣，離別苦，就中更有癡兒女。」\n",
		"郭襄低聲吟道：「君應有語，渺萬裏層雲，千山暮雪，隻影向誰去？」\n",
		"郭襄低聲吟道：「橫汾路，寂寞當年簫鼓。荒煙依舊平楚。」\n",
		"郭襄低聲吟道：「招魂些何嗟及，山鬼自啼風雨。」\n",
		"郭襄低聲吟道：「天也妒，未信與，鶯兒燕子俱黃土。」\n",
		"郭襄低聲吟道：「千秋萬古，爲留待騷人，狂歌痛飲，來訪雁丘處。」\n",
		(: random_move :)
	}) );

	set_skill("persuading", 150);
	set_skill("throwing", 200);
	set_skill("force", 200);
	set_skill("dodge", 200);
	set_skill("finger", 200);
	set_skill("parry", 200);
	set_skill("strike", 200);
	set_skill("sword", 200);
	set_skill("blade", 200);
	set_skill("literate", 100);
	set_skill("mahayana", 200);
	set_skill("buddhism", 200);
	set_skill("jinding-zhang", 300);
	set_skill("tiangang-zhi", 300);
	set_skill("huifeng-jian", 300);
	set_skill("yanxing-dao", 300);
	set_skill("zhutian-bu", 300);
	set_skill("linji-zhuang", 200);
	map_skill("force","linji-zhuang");
	map_skill("finger","tiangang-zhi");
	map_skill("dodge","zhutian-bu");
	map_skill("strike","jinding-zhang");
	map_skill("sword","huifeng-jian");
	map_skill("blade","yanxing-dao");
	map_skill("parry","huifeng-jian");
	prepare_skill("strike", "jinding-zhang");
	prepare_skill("finger", "tiangang-zhi");
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "sword.mie" :),
//		(: perform_action, "blade.wuxing" :),
		(: perform_action, "strike.bashi" :),
		(: perform_action, "finger.lingkong" :),
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :),
		(: exert_function, "regenerate" :),
	}) );
	create_family("峨嵋派", 1, "掌門人");

	setup();
	carry_object(WEAPON_DIR"changjian")->wield();
	carry_object(CLOTH_DIR"female-cloth")->wear();
	carry_object(CLOTH_DIR"female-shoe")->wear();
	carry_object(__DIR__"obj/donkey");
}

void attempt_apprentice(object ob)
{
	mapping ob_fam;
	mapping my_fam = ob->query("family");
	string name, new_name;
	name = ob->query("name");

	if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "峨嵋派")
	{
		command("say "+RANK_D->query_respect(ob)+"與本派素無來往，不知此話從何談起？");
		return;
	}
	if ((string)ob->query("class")!="bonze" )
	{
		command ("say 我不收俗家弟子。");
		return;
	}
	if ((int)ob->query_skill("mahayana",1)<150||
		(int)ob->query_skill("linji-zhuang",1)<150)
	{
		command("say 你本門的功夫修爲還太低。");
		return;
	}
	if ((int)ob->query("shen") < 500000)
	{
		command("say "+RANK_D->query_respect(ob)+"你行俠仗義之事還做的不夠。");
		return;
	}
	if ((string)ob->query("class")=="bonze" )
	{
		name = ob->query("name");
		new_name = "風" + name[1..1];
		ob->set("name", new_name);
		command("say 從今以後你的法名叫做" + new_name + "，恭喜你成爲峨嵋第三代弟子!");
	}
	command("recruit " + ob->query("id"));
}
