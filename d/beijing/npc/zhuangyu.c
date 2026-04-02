// zhuangyu.c
inherit NPC;
#include <ansi.h>
int ask_weiwang();

void create()
{
	set_name("莊允城", ({ "zhuang yuncheng", "zhuang","yuncheng" }) );
	set("gender", "男性" );
	set("age", 40);
	set("int", 28);
	set("long","這是個飽讀詩書，卻手無縛雞之力的書生。\n因編輯‘明史輯略’，被吳之榮告發，全家逮入京中。\n" );
	set("attitude", "peaceful");
	set_skill("literate", 100);
	set("noget", "莊允城嘆道：我不行了，你走吧。唉，我擔心我家裏人啊。\n");
	set("chat_chance", 5);
	set("chat_msg", ({
	"\n莊允城說道：只怪我當初好心，在書中夾了金葉送與他，\n"
	"誰想這狼心狗肺的傢伙竟然就去告發了我。唉...\n",
	"\n莊允城說道：誰要把吳之榮抓到莊府就好了。\n",
	"莊允城突然說道: 江湖威望很重要，威望高大有好處啊。\n",
	"\n莊允城嘆了口氣，說道：我知道鰲拜書房的祕密，只可惜我出不去啊。\n",
	"莊允城說道：誰要救了我，我一定把我知道的都告訴他。\n",
	}));
	set("inquiry", ([
		"鰲拜" : "鰲拜的書房裏有寶貝。",
		"書房" : "書房裏那幅畫兒有學問。",
		"畫"   : "移動那幅畫時可是有方向的。",
		"畫卷" : "移動那幅畫時可是有方向的。",
		"方向" : "先左移一下，後右移一下就行了。",
		"暗門" : "那可不能隨便進，畫裏可是有學問的。",
		"吳之榮" : "把他送到莊府去有好處。",
		"威望" : (: ask_weiwang :),
		"江湖威望" : (: ask_weiwang :),
	]) );
	setup();
	carry_object(CLOTH_DIR"cloth")->wear();
}

int ask_weiwang()
{
	command("tell "+this_player()->query("id")+" 你現在的江湖威望是 " +(string)(this_player()->query("weiwang")));
	say( "莊允城說：如果你威望值很高，有些人見了你不但不會殺你，還會教你武功，送你寶貝。\n而且你還可以加入幫會，率領會衆去攻打目標，就連去錢莊取錢也會有利息 。。。。。\n");
	say("莊允城又說：殺某些壞人或救某些好人可以提高江湖威望。\n");
	return 1;
}

void init()
{
	object ob = this_player();
	int i;

	if(!userp(ob)) return;
	if(interactive(ob) && !is_fighting() ) 
	say("莊允城哈哈笑道：終於有人來救我了！\n這位" + RANK_D->query_respect(ob)+"，鰲府的寶貝可不少啊，你要有什麼不明白的，儘管問我吧。\n");
	i=(int)this_player()->query("weiwang");
	if(i<20) 
	{
		i=i+10;
		this_player()->set("weiwang",i);
		message_vision(HIC"\n$N的江湖威望提高了！\n"NOR,this_player());
	}
	command("tell "+this_player()->query("id")+" 你現在的江湖威望是 " +(string)(i));
}

int accept_object(object me, object ob)
{
	if( !me || environment(me) != environment() ) return 0;
	if ( !objectp(ob) ) return 0; 
	if ( !present(ob, me) ) return notify_fail("你沒有這件東西。");
	if ( (string)ob->query("name") == "明史輯略") 
	{
		write(HIC "\n莊允城笑到：書裏有金葉子，難道你不知道嗎？\n" NOR);
		write(HIC "莊允城說：替我把吳之榮這廝抓到莊府去吧，我不行了。\n" NOR);		
		write("莊允城喘了口氣，又說：莊府在京城東北邊。\n");
	}		
	return 1;
}

