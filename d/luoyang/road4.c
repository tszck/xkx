//  Room:  /d/luoyang/road4.c

inherit  ROOM;

void  create  ()
{
	set("short",  "南郊小路");
	set("long",  @LONG
這是洛陽城郊的一條小路，向南望去便是雄偉的龍門，北面是洛陽
城，東面是洛陽一風景點：關林和龍門石窟。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"east"  :  __DIR__"guanlin",
		"south" :  __DIR__"longmen1",
		"north" :  __DIR__"tianjinqiao",
	]));
	set("objects",  ([  /*  sizeof()  ==  2  */
		"/d/wudang/npc/tufei1" : 1,
	]));
	set("outdoors", "luoyang");
	set("coor/x", -500);
	set("coor/y", -40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
