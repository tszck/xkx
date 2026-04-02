// /d/changan/westroad1.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "西大街");
	set  ("long",  @LONG
你正走在長安西大街上，畢竟曾為多朝古都，氣派非比尋常。南邊
是碑林，北邊是個熱鬧的客棧，來自各地的人們進進出出，據説也是情
人們的幽會地點。
LONG);
	set("exits",  ([  //sizeof()  ==  4
		"west"  :  __DIR__"westgate",
		"east"  :  __DIR__"westroad2",
		"north" :  __DIR__"kedian",
		"south" :  __DIR__"beilin",
	]));
	set("outdoors",  "changan");
	set("no_clean_up",  0);
	set("coor/x", -5060);
	set("coor/y", 1000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
