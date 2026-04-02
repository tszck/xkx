//Edited by fandog, 02/13/2000

inherit NPC;

void create ()
{
	set_name("教書先生", ({"jiao shu", "teacher"}));
	set("long", "他搖頭晃腦的，拿了一張紙，一隻墨盒，一枝筆，正抄寫着什麼。\n");
	set("gender", "男性");
	set("age", 24);
	set("combat_exp", 1000);
	set("str", 24);
	set("int", 15);
	set("dex", 18);
	set("con", 22);
	set("per", 20);
	set("chat_msg", ({
	"教書先生眯縫着眼，仔細端詳着城牆上用石灰泥寫的數目字。\n",
	"教書先生拿了一張紙，一隻墨盒，一枝筆，搖頭晃腦的，將城牆上那幾行字抄了下來。。\n",
	"教書先生神祕兮兮道：“老夫這麼做自有用處，旁人不得問之也。”\n",
	(: random_move :)
	}) );

  
	setup();
	carry_object("/clone/cloth/cloth")->wear();
}


