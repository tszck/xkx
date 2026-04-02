// /d/changan/northgate.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "安遠門");
	set  ("long",  @LONG
這裏便是長安北門----安遠門。長安為多朝古都，果然不同凡響，
城牆以石灰、糯米和土夯成，固若金湯。一條官道自北門向北延伸，官
兵們警惕地注視着過往行人。
LONG);
	//set("item_desc",  (["  ***  "  :  "  ***  ",  ]));
	set("exits",  ([  //sizeof()  ==  4
		"north"  :  __DIR__"road6",
		"south"  :  __DIR__"northroad1",
	]));
	set("objects",  ([  //sizeof()  ==  1
		"/d/city/npc/wujiang"  :  1,
		"/d/city/npc/bing"  :  3,
	]));
	set("outdoors",  "changan");
	set("no_clean_up",  0);
	set("coor/x", -5040);
	set("coor/y", 1030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
