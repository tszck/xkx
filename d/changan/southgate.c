// /d/changan/southgate.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "永寧門");
	set  ("long",  @LONG
這裏便是長安南門----永寧門。長安爲多朝古都，果然不同凡響，
城牆以石灰、糯米和土夯成，固若金湯。出了城門便是官道，幾名官兵
正在守門。還有幾名不當值的官兵正在門樓上休息。
LONG);
	//set("item_desc",  (["  ***  "  :  "  ***  ",  ]));
	set("exits",  ([  //sizeof()  ==  4
		"north"  :  __DIR__"southroad1",
		"south"  :  __DIR__"road5",
		"up"     :  __DIR__"kuixinglou",
	]));
	set("objects",  ([  //sizeof()  ==  1
		"/d/city/npc/wujiang"  :  1,
		"/d/city/npc/bing"  :  3,
	]));
	set("outdoors",  "changan");
	set("no_clean_up",  0);
	set("coor/x", -5040);
	set("coor/y", 970);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
