inherit NPC;
void create()
{
	set_name("範先生", ({"fan xiansheng", "fan", "xiansheng"}));
	set("title", "帳房先生");
	set("gender", "男性");
	set("age", 34);
	set("str", 22);
	set("int", 24);
	set("dex", 18);
	set("con", 18);       
	set("combat_exp",300000);
	set("attitude", "friendly");
	setup();
	carry_object("/clone/misc/cloth")->wear();
}
