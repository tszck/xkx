// /d/changan/southroad2.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "南大街");
	set  ("long",  @LONG
你正走在長安南大街上，北邊是一個熱鬧的廣場，人聲鼎沸，東邊
不時地傳來金屬撞擊聲，和西邊安靜的小巷形成鮮明的對比。
LONG);
	set("exits",  ([  //sizeof()  ==  4
		"north" :  __DIR__"center",
		"south" :  __DIR__"southroad1",
		"west"  :  __DIR__"zaoxiang",
		"east"  :  __DIR__"datiepu",
	]));
	set("outdoors",  "changan");
	set("no_clean_up",  0);
	set("coor/x", -5040);
	set("coor/y", 990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
