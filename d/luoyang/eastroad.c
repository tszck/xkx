//  Room:  /d/luoyang/eastroad.c

inherit  ROOM;

void  create  ()
{
	set("short",  "金谷街");
	set("long",  @LONG
由於連年的戰亂，整條金谷街的不少鋪子已經荒廢掉了只剩下南面
的一家賣牡丹花的店鋪。北面石街通往銅駝陌，西面是鼓樓，東面則是
洛陽城的東門。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"east"  :  __DIR__"eastgate",
		"west"  :  __DIR__"center",
		"south" :  __DIR__"huadian",
		"north" :  __DIR__"xiaojie1",
	]));
	set("objects",  ([
		__DIR__"npc/wangjiaju" : 1,
	]));
	set("outdoors", "luoyang");
	set("coor/x", -400);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
