//  Room:  /d/luoyang/road3.c

inherit  ROOM;

void  create  ()
{
	set("short",  "城郊小路");
	set("long",  @LONG
這是洛陽城郊的一條小路，向南望去已可以看見襄陽城的輪廓，北
面就是通往洛陽城的龍門關口。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"south" :  "/d/xiangyang/caodi3",
		"north" :  __DIR__"longmen1",
	]));
	set("outdoors", "luoyang");
	set("no_clean_up", 0);
	set("coor/x", -500);
	set("coor/y", -50);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
