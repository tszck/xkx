// /d/changan/center.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "中央廣場");
	set  ("long",  @LONG
這裏便是長安城的中心，東南西北四條大街交匯於此。廣場中央一
座巍峨高大的鐘樓聳立於前，和市北的鼓樓遙相呼應，很是有些氣勢。
每到清晨，響亮的鐘聲便會伴着淡淡霧氣傳向長安城的大街小巷。路口
車水馬龍，來往人潮不斷。
LONG);
	//set("item_desc",  (["  ***  "  :  "  ***  ",  ]));

	set("exits",  ([  //sizeof()  ==  4
		"north" :  __DIR__"northroad2",
		"south" :  __DIR__"southroad2",
		"west"  :  __DIR__"westroad2",
		"east"  :  __DIR__"eastroad2",
		"up"    :  __DIR__"zhonglou",
	]));
	set("objects",  ([  //sizeof()  ==  1
//		__DIR__"npc/libai"  :  1,
	]));
	set("outdoors",  "changan");
	set("coor/x", -5040);
	set("coor/y", 1000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
