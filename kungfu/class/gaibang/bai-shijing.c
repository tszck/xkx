// bai-shijing.c

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

string ask_quit();
void create()
{
	set_name("白世鏡", ({"bai shijing", "bai", "shijing"}));
	set("nickname", "丐幫六老");
	set("gender", "男性");
	set("age", 50);
	set("long", 
"執法長老白世鏡，面色蠟黃，向來鐵面無私，幫中大小人等，縱然並不違
犯幫規刑條，見到他也是懼怕三分。\n");
	set("attitude", "peaceful");
	set("class", "beggar");
 	set("beggarlvl", 9);
	set("no_get", "1");
	
	set("str", 24);
	set("int", 20);
	set("con", 24);
	set("dex", 20);

	set("qi", 900);
	set("max_qi", 900);
	set("jing", 100);
	set("max_jing", 100);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 100);
	set("inquiry", ([
		"法刀"    :   (: ask_quit :),
		"執法"    :   (: ask_quit :),
		"退幫"    :   (: ask_quit :),
		"tuibang" :   (: ask_quit :),
	]));
	
	set("combat_exp", 100000);
	set("score", 20000);
	
	set_skill("force", 95);            // 基本內功
	set_skill("huntian-qigong", 90);   // 混天氣功
	set_skill("hand", 90);             // 基本手法
	set_skill("suohou-hand", 85);      // 鎖喉擒拿手
	set_skill("staff", 90);            // 基本杖法
	set_skill("fengmo-staff", 85);     // 瘋魔杖法
	set_skill("dodge", 90);            // 基本躲閃
	set_skill("xiaoyaoyou", 95);       // 逍遙遊
	set_skill("parry", 85);            // 基本招架
	set_skill("staff", 90);            // 基本棍杖
	set_skill("strike",85);  // 基本掌法
	set_skill("lianhua-zhang",85); // 蓮花掌
	set_skill("xianglong-zhang",85);

	map_skill("strike","lianhua-zhang");
	prepare_skill("strike","lianhua-zhang");
	map_skill("force", "huntian-qigong");
	map_skill("staff", "fengmo-staff");
	map_skill("parry", "fengmo-staff");
	map_skill("hand", "suohou-hand");
	map_skill("dodge", "xiaoyaoyou");
	prepare_skill("hand", "suohou-hand");

	set("party/party_name", HIC"丐幫"NOR);
	set("party/rank", RED"九袋長老"NOR);
	set("party/level", 9);
	create_family("丐幫", 10, "執法長老");
	setup();

	carry_object(__DIR__"obj/cloth")->wear();
	carry_object(WEAPON_DIR"gangzhang")->wield();
}

init()
{
	object ob;
	mapping myfam;
	
	::init();
	if (interactive(ob = this_player()) && !is_fighting())
	{
		myfam = (mapping)ob->query("family");
		if((!myfam || myfam["family_name"] != "丐幫") && (!wizardp(ob)))
		{
			remove_call_out("saying");
			call_out("saying", 1, ob);
		}
	}
	add_action("do_decide", "decide");
}
void attempt_apprentice(object ob)
{
	command("say 老夫不收徒弟，"+RANK_D->query_respect(ob)+"還是請回吧。");
}
void destroying(object me, object obj)
{
	destruct(obj);
	return;
}
string ask_quit()
{
	mapping fam;
 object me=this_player();
 
 

	if (!(fam = me->query("family")) || fam["family_name"] != "丐幫")
		return RANK_D->query_respect(me) +
		"與本派素無來往，不知此話從何談起？";
	if(!me->query("party") || me->query("party/party_name") != HIC"丐幫"NOR)
	{
		return "你不是丐幫中人，想走就給我滾。";
	}
	if(me->query("combat_exp") < 100000)
	{
		return "你混進丐幫也沒多少日子啊，哪裏想走就能走？。";
	}
	me->set_temp("pending/quit_gaibang", 1);
	return "好吧，叛出丐幫須領受本幫法刀，廢去你本門武功。\n想好就決定(decide)吧。";
}
int do_decide()
{
	if( !this_player()->query_temp("pending/quit_gaibang") )
		return 0;

	message_vision(
"$n臉如寒霜，沉聲道：“執法弟子，請本幫法刀。”\n
他身後屬下九名弟子齊聲應道：“是！”每人從背後布袋中取出一個黃布包
袱，打開包袱，取出一柄短刀。九柄精光燦然的短刀並列在一起，一樣的長
短大小，火光照耀之下，刀刃上閃出藍森森的光采。一名執法弟子捧過一段
樹木，九人同時將九柄短刀插入了木中，隨手而入，足見九刀鋒銳異常。九
人齊聲叫道：“法刀齊集，驗明無誤。”\n
$n押低嗓子，啞聲道：“行刑！”
"HIR"九名執法弟子法刀如疾電般閃過，$N只覺得劇痛如九線大潮，沛然而至，眼
前一陣眩暈。微一定神，執法弟子已經收刀退走了。\n"NOR"
$n冷笑着道：“你去吧，解下背上布袋，自今而後，丐幫中沒了你這號人物。”\n
", this_player(), this_object() );
	this_player()->delete_temp("pending/quit_gaibang");
	this_player()->skill_death_penalty();
	this_player()->skill_death_penalty();
	this_player()->skill_death_penalty();
	this_player()->skill_death_penalty();
	this_player()->skill_death_penalty();
	this_player()->skill_death_penalty();
	this_player()->skill_death_penalty();
	this_player()->skill_death_penalty();
	this_player()->skill_death_penalty();
	this_player()->skill_death_penalty();
	this_player()->add("combat_exp", -23250);
	this_player()->set("combat_exp",this_player()->query("combat_exp")*8/9);
	this_player()->delete("party");
	return 1;
}
