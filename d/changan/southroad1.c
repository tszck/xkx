// /d/changan/southroad1.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "南大街");
	set  ("long",  @LONG
你正走在長安南大街上，南大街乃是城裏的繁華地段，幾個客商正
將貨物販往雜貨鋪。往南可以看到南門，東邊則是個熱鬧的雜貨鋪。
LONG);
	set("exits",  ([  //sizeof()  ==  4
		"north" :  __DIR__"southroad2",
		"south" :  __DIR__"southgate",
		"west"  :  __DIR__"yizhan",
		"east"  :  __DIR__"zahuopu",
	]));
	set("outdoors",  "changan");
	set("no_clean_up",  0);
	set("coor/x", -5040);
	set("coor/y", 980);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
