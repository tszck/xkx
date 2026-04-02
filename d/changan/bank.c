// /d/changan/bank.c

#include  <ansi.h>
inherit  ROOM;

void  reset_balance(object  me);

void  create  ()
{
	set  ("short",  "相記錢莊");
	set  ("long",  @LONG
這是一家老字號的錢莊，相老闆是山西人，這家錢莊從他的爺爺的
爺爺的爺爺的爺爺那輩開始辦起，一直傳到他手裏，聲譽非常好，在全
國各地都有分店。它發行的銀票通行全國。錢莊的門口，掛有一塊牌子
(paizi)。
LONG);
	set("item_desc",  ([
		"paizi":  @TEXT
這裏是錢莊，目前我們提供的服務有：

check		    查帳。
deposit		  存款。
withdraw		取款。
convert		  兌換錢幣。

TEXT
	])  );
	set("no_fight", 1);
	set("exits",  ([  //sizeof()  ==  4
	    "north"  :  __DIR__"center",
	]));

	set("objects",  ([  //sizeof()  ==  1
		__DIR__"npc/tiesuanpan"  :  1,
	]));
//		set("outdoors",  "changan");
	set("no_clean_up",  0);
	setup();
}
/*
void  init()
{
	reset_balance(this_player());
	::init();
}
*/
void  reset_balance(object  me)
{
	int  myexp=me->query("combat_exp")/1000;
	int  allowed,  removed_gold;
 
	string  NPCNAME="鐵算盤";

	if(myexp<1)  myexp=1;
	if(myexp>100)  myexp=100;
	allowed=myexp*1000000;//each  year  can  have  100  gold,  range  100-10000.  
	if  (me->query("balance")  >  allowed)
	{
	me->set("balance_old",  me->query("balance"));
	me->set("balance",  allowed);
	removed_gold  =  (me->query("balance_old")  -  me->query("balance"))/10000;
	log_file("MONEY_RESET",  ctime(  time()  )+"：魏大人收繳了"+me->query("name")+"("+me->query("id")+")"+removed_gold+"兩黃金。\n");
	tell_object(me,  GRN+NPCNAME+"在你的耳邊悄聲說道："+RANK_D->query_respect(me)+
		"，這、這真不知怎麼說是好．．．\n"NOR);
	tell_object(me,  GRN+NPCNAME+"在你的耳邊悄聲說道："+
		"昨日魏大人派人前來察案，發覺你老的黃金來路．．．\n"NOR);
	tell_object(me,  GRN+NPCNAME+"在你的耳邊悄聲說道："+
		"若不是在下幫你老辯解，你老的錢就全都充公了．．．\n"NOR);
	}
	return;
}
