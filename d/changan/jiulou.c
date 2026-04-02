// /d/changan/jiulou.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "謫仙樓");
	set  ("long",  @LONG
這裏就是天下聞名的謫仙樓，就是李太白醉中做神仙的地方。可是
你剛走進去，就看見一塊牌子：暫不營業。世人皆知，天下美酒，北有
汾酒，南有紹酒。最好的汾酒不在山西，而就在這裏。你聞着滿樓酒香，
原來都是從地窖中飄出來的。
LONG);
	set("exits",  ([  //sizeof()  ==  4
		"down"  :  __DIR__"dijiao",
		"west"  :  __DIR__"northroad1",
	]));
	set("no_clean_up", 0);
	set("coor/x", -5030);
	set("coor/y", 1020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
