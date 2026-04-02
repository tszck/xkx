// /d/changan/chaguan.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "清馨茶館");
	set  ("long",  @LONG
你一走進來，就聞到一股茶香沁入心脾，精神為之一爽。幾張八仙
桌一字排開，坐滿了客人。一位老者正在堂前彈奏，幾個儒生擊幾而歌。
的確是個悠然去處。
LONG);
	set("exits",  ([  //sizeof()  ==  4
		"northeast" :  __DIR__"zaoxiang",
	]));
	set("no_clean_up",  0);
	set("coor/x", -5060);
	set("coor/y", 980);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
