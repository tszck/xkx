//  Room:  /d/luoyang/southgate.c

inherit  ROOM;

void  create  ()
{
	set("short",  "南門");
	set("long",  @LONG
由此洛陽城南門出去，就可以通往洛陽著名的名勝古蹟：關林和龍
門石窟，再往南一些就可以到達郭靖率領各路英雄捍衛的襄陽城。北面
是通往洛陽城中心的主要幹道，南面是出城的小路。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"east"  :  __DIR__"luopu",
		"north" :  __DIR__"southroad",
		"south" :  __DIR__"tianjinqiao",
	]));
	set("objects",  ([  /*  sizeof()  ==  2  */
		"/d/city/npc/bing" : 2,
	]));
	set("outdoors", "luoyang");
	set("coor/x", -500);
	set("coor/y", -30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
