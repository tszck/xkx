// Room: /d/5lt/center.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "村廣場");
	set  ("long",  @LONG
這裏便是無釐頭村的正中心，一個很寬闊的廣場，東南西北四條碎
石路交匯於此。一些遊手好閒的人在這裏溜溜達達，經常有藝人在這裏
表演。
LONG);
	//set("item_desc",  (["  ***  "  :  "  ***  ",  ]));

	set("exits",  ([  //sizeof()  ==  4
		"north" :  __DIR__"nroad1",
		"south" :  __DIR__"sroad1",
		"west"  :  __DIR__"wroad1",
		"east"  :  __DIR__"eroad1",
	]));
        set("objects", ([
		__DIR__"npc/hehehehe": 1,
	]));
	set("outdoors",  "5lt");
	set("coor/x", -150);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
