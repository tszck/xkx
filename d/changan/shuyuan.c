// /d/changan/shuyuan.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "關中書院");
	set  ("long",  @LONG
關中書院是甘陝地區最高學府，建於明萬曆年間。一位莊重嚴肅的
老者坐在太師椅上講學，那就是當今大儒馮先生了。在他的兩側坐滿了
求學的學生。
LONG);
	set("exits",  ([  //sizeof()  ==  4
		"north"  :  __DIR__"eastroad2",
	]));
	set("objects",  ([  //sizeof()  ==  4
		__DIR__"npc/feng" : 1,
	]));
	set("coor/x", -5030);
	set("coor/y", 990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
