// /d/changan/westroad2.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "西大街");
	set  ("long",  @LONG
你正走在長安西大街上，畢竟曾為多朝古都，氣派非比尋常。北邊
是鼓樓，相傳當年天子曾在此鳴鼓點將，往南可以到長安城內有名的“
清馨”茶館。
LONG);
	set("exits",  ([  //sizeof()  ==  4
		"west"  :  __DIR__"westroad1",
		"east"  :  __DIR__"center",
		"north" :  __DIR__"gulou",
		"south" :  __DIR__"zaoxiang",
	]));
	set("outdoors",  "changan");
	set("no_clean_up",  0);
	set("coor/x", -5050);
	set("coor/y", 1000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
