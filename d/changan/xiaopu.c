// /d/changan/xiaopu.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "小鋪子");
	set  ("long",  @LONG
這是一家專賣旅遊紀念品的小鋪子。到了長安不買點紀念品，說不
過去吧......一個大嫂正站在鋪前向遊客招攬生意。
LONG);
	set("exits",  ([  //sizeof()  ==  4
		"north"  :  __DIR__"eastroad1",
	]));
	set("objects",  ([  //sizeof()  ==  4
		__DIR__"npc/dasao": 1,
	]));
	set("coor/x", -5020);
	set("coor/y", 990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
