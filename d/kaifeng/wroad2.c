// /kaifeng/wroad2.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "西大街");
	set("long", @LONG
開封府內西面的主要交通要道，街道兩邊店鋪林立，行人車馬如梭。
商販的吆喝，市民與小販的討價還價喧鬧無比。西面就是延慶觀，東面
可以上到角樓。
LONG);
	set("objects", ([
		__DIR__"npc/qigai" : 1,
	]));
	set("outdoors", "kaifeng");
	set("exits", ([
		"west"   : __DIR__"yanqing",
		"eastup" : __DIR__"jiaolou1",
		"north"  : __DIR__"wroad3",
		"south"  : __DIR__"wroad1",
	]));

	setup();
	replace_program(ROOM);
}
