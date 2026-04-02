//RJQTING.C

inherit ROOM;

void create()
{
	set("short", "巨木旗大廳");
	set("long", @LONG
這是巨木旗的大廳，雖然都是練武之人，這裏卻佈置得古色古香。
整個大廳就建在神木之中，樹木掩映，極為嚴密。雖然未免擠迫，卻絕
無外敵能輕易攻得上來。廳中充滿茶香和古木幽香，十分動人。掌旗使
聞松神色自若地端坐喝茶，全不理會客人的到來。巨木旗下在廳口準備
了極多的巨木樁，專候來敵。
LONG);
	set("exits", ([
//		"down" : __DIR__"jmqshenmu",
	  "down": __DIR__"jmqmen",
	]));
	set("objects",([
		__DIR__"npc/wensong":1,
	]));
	set("coor/x", -52200);
	set("coor/y", 860);
	set("coor/z", 60);
	setup();
	replace_program(ROOM);
}