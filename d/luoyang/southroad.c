//  Room:  /d/luoyang/southroad.c

inherit  ROOM;

void  create  ()
{
	set("short",  "洛川街");
	set("long",  @LONG
濕潤的青石路顯然是剛剛下過雨，因為來往行人過多，路面多少有
些坑坑凹凹，一不留神很容易被絆到。這條街便是因為南面的洛水而得
名。
　　南面是洛陽城的南門，北面是洛陽城中心鼓樓，而西面則是一家專
門賣唐三彩的店鋪，東面是一家賣牡丹花的店鋪。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"east"      :  __DIR__"huadian",
		"west"      :  __DIR__"dianpu",
		"south"     :  __DIR__"southgate",
		"north"     :  __DIR__"center",
		"southwest" :  __DIR__"luoshenmiao",
	]));
	set("objects",  ([  /*  sizeof()  ==  2  */
		"/d/village/npc/girl" : 1,
	]));
	set("outdoors", "luoyang");
	set("no_clean_up", 0);
	set("coor/x", -500);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
