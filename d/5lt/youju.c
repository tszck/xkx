// Room: /d/5lt/youju.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "郵局");
	set  ("long",  @LONG
這裏是一家郵局。時近黃昏，工作人員正忙着完成手上的事情準備下班。
LONG);
	set("exits",  ([  //sizeof()  ==  1
		"east"  :  __DIR__"sroad2",
	]));
	set("objects",  ([
	]));
	set("coor/x", -160);
	set("coor/y", -30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
