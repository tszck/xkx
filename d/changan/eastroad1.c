// /d/changan/eastroad1.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "東大街");
	set  ("long",  @LONG
你走在東大街上，踩着堅實的青石板地面。東邊是東城門，可以聽
到守城官兵的吆喝聲，與西邊朗朗的讀書聲混雜在一起。南邊是個小鋪
子，專門賣一些紀念品。北邊是塊空地，種着一些花卉。
LONG);
	set("exits",  ([  //sizeof()  ==  4
		"west"  :  __DIR__"eastroad2",
		"east"  :  __DIR__"eastgate",
		"north" :  __DIR__"huachang",
		"south" :  __DIR__"xiaopu",
	]));
	set("outdoors",  "changan");
	set("no_clean_up",  0);
	set("coor/x", -5020);
	set("coor/y", 1000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
