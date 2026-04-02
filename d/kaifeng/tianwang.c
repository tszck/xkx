// /kaifeng/tianwang.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "天王殿");
	set("long", @LONG
這是天王殿，四大天王手握法器，高據於法壇之上，兩邊有紅色柵
欄與中間的通道隔開。每個法像的身前各有一個蒲團供善男信女們膜拜，
以求風調雨順。
LONG);
	set("objects", ([
		__DIR__"npc/hufa" : 1,
	]));
	set("exits", ([
		"south" : __DIR__"qianyuan",
		"north" : __DIR__"zhongyuan",
	]));

	setup();
	replace_program(ROOM);
}
