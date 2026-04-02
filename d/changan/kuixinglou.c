// /d/changan/kuixinglou.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "奎星樓");
	set  ("long",  @LONG
這是永寧門上的一個城樓，極目四望，可以看到南邊青青的終南山。
旁邊幾個官兵正在休息。不過這裏是軍事重地，你最好還是趕快離開。
LONG);
	set("exits",  ([  //sizeof()  ==  4
		"down"  :  __DIR__"southgate",
	]));
	set("objects",  ([  //sizeof()  ==  4
		"/d/city/npc/wujiang" : random(3),
		"/d/city/npc/bing" : random(3),
	]));
	set("outdoors",  "changan");
	set("coor/x", -5040);
	set("coor/y", 970);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
