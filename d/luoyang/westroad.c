//  Room:  /d/luoyang/westroad.c

inherit  ROOM;

void  create  ()
{
	set("short",  "問鼎街");
	set("long",  @LONG
相傳春秋時代，楚王在此仰望周王城，問鼎重幾何。周室闇弱，居
然隱忍不發。這便是街名的由來。溼潤的青石路顯然是剛剛下過雨，因
爲來往行人過多，路面多少有些坑坑凹凹，一不留神很容易被絆到。這
裏是洛陽繁華之處，北面就是號稱中州第一的金刀王家了，南面是一家
專門賣唐三彩的店鋪。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"west"  :  __DIR__"westgate",
		"east"  :  __DIR__"center",
		"south" :  __DIR__"dianpu",
		"north" :  __DIR__"wanggate",
	]));
	set("objects",  ([  /*  sizeof()  ==  2  */
		__DIR__"npc/wangbofen" : 1,
	]));
	set("outdoors", "luoyang");
	set("coor/x", -600);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
