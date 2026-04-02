// /d/changan/eastroad2.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "東大街");
	set  ("long",  @LONG
你正走在長安東大街上，一條寬闊的青石板街道，向東西兩頭延伸。
南邊是一座簡樸的院子，半月形的大門上方寫着“關中書院”四個燙金
大字，蒼勁有力。裏面不時地傳來學生們抑揚頓挫的讀書聲，和北邊嘈
雜之聲混雜在一起。北面就是長安樂坊了。
LONG);
	set("exits",  ([  //sizeof()  ==  4
		"west"  :  __DIR__"center",
		"east"  :  __DIR__"eastroad1",
		"north" :  __DIR__"club",
		"south" :  __DIR__"shuyuan",
	]));
	set("outdoors",  "changan");
	set("no_clean_up",  0);
	set("coor/x", -5030);
	set("coor/y", 1000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
