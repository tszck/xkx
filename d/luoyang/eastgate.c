//  Room:  /d/luoyang/eastgate.c

inherit  ROOM;

void  create  ()
{
	set("short",  "東門");
	set("long",  @LONG
由此洛陽城東門出去，就可以通往洛陽另一個著名的名勝古蹟：白
馬寺。再往東一些就可以到達煙花三月的揚州了。西面是通往洛陽城中
心的主要幹道，東面是出城的大道。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"east"  :  __DIR__"road2",
		"west"  :  __DIR__"eastroad",
	]));
	set("objects",  ([  /*  sizeof()  ==  2  */
		"/d/city/npc/bing" : 2,
	]));
	set("outdoors", "luoyang");
	set("coor/x", -300);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
