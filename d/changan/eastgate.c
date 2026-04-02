// /d/changan/eastgate.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "長樂門");
	set  ("long",  @LONG
這裏便是長安東門----長樂門。長安為多朝古都，果然不同凡響，
城牆以石灰、糯米和土夯成，固若金湯。出了城門是條護城河，幾名官
兵正在守門。
LONG);
	//set("item_desc",  (["  ***  "  :  "  ***  ",  ]));
	set("exits",  ([  //sizeof()  ==  4
		"west"  :  __DIR__"eastroad1",
		"east"  :  __DIR__"baqiao",
	]));
	set("objects",  ([  //sizeof()  ==  1
		"/d/city/npc/wujiang"  :  1,
		"/d/city/npc/bing"  :  3,
	]));
	set("outdoors",  "changan");
	set("no_clean_up",  0);
	set("coor/x", -5010);
	set("coor/y", 1000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
