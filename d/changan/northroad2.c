// /d/changan/northroad2.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "北大街");
	set  ("long",  @LONG
你正走在長安北大街上。西邊是一家錢莊，可以聽到叮叮噹噹的金
銀聲音。東邊個兵營，長安守軍駐紮在內，不時傳來操練之聲。
LONG);
	set("exits",  ([  //sizeof()  ==  4
		"west"  :  __DIR__"qianzhuang",
		"east"  :  __DIR__"bingying",
		"north" :  __DIR__"northroad1",
		"south" :  __DIR__"center",
	]));
	set("outdoors",  "changan");
	set("no_clean_up",  0);
	set("coor/x", -5040);
	set("coor/y", 1010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
