// /d/changan/northroad1.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "北大街");
	set  ("long",  @LONG
你正走在長安北大街上。東邊是個酒樓，往北就是城門了。西面一
羣喇嘛進進出出，原來是個喇嘛廟。裏面不知道供的是什麼佛爺。
LONG);
	set("exits",  ([  //sizeof()  ==  4
		"west"  :  __DIR__"lamamiao",
		"east"  :  __DIR__"jiulou",
		"north" :  __DIR__"northgate",
		"south" :  __DIR__"northroad2",
	]));
	set("outdoors",  "changan");
	set("no_clean_up",  0);
	set("coor/x", -5040);
	set("coor/y", 1020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
