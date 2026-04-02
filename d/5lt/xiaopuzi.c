// Room: /d/changan/xiaopuzi.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "小鋪子");
	set  ("long",  @LONG
這是一家小鋪子。
LONG);
	set("exits",  ([  //sizeof()  ==  1
		"north"  :  __DIR__"wroad1",
	]));
	set("objects",  ([
	]));
	set("coor/x", -160);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
