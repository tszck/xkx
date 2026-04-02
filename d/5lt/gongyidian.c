// Room: /d/5lt/gongyidian.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "民間工藝品店");
	set  ("long",  @LONG
這是一個古色古香的民間工藝品商店。房內擺設着上好的香檀木家
具，櫃子裏陳列着店主收藏的各種名貴工藝品，牆上則掛滿了店主自己
繪製的Ascii名畫。
LONG);
	set("exits",  ([  //sizeof()  ==  1
		"south"  :  __DIR__"wroad1",
	]));
	set("objects",  ([
		__DIR__"npc/xiyi": 1,
	]));
	set("no_fight", "1");
	set("coor/x", -160);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
