//  Room:  /d/luoyang/northgate.c

inherit  ROOM;

void  create  ()
{
	set("short",  "北門");
	set("long",  @LONG
出了此門，就不在洛陽城的管轄範圍了，門口站着的是守城官兵。
站在城樓望出去，外面是一片茅草路，據說可以通往各地，官兵守備也
不甚嚴。不少商販正是利用這條小路將洛陽的唐三彩販賣到京城各地。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"north"  :  __DIR__"road5",
		"south"  :  __DIR__"northroad",
	]));
	set("objects",  ([
		"/d/city/npc/bing" : 1,
	]));
	set("outdoors", "luoyang");
	set("no_clean_up", 0);
	set("coor/x", -500);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
