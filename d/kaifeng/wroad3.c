// /kaifeng/wroad3.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "西大街");
	set("long", @LONG
開封府內西面的主要交通要道，街道兩邊店鋪林立，行人車馬如梭
商販的吆喝，市民與小販的討價還價，喧鬧無比。南邊不遠就是延慶觀。
東面是龍亭園。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"tingyuan",
		"south" : __DIR__"wroad2",
	]));
	set("outdoors", "kaifeng");

	setup();
	replace_program(ROOM);
}
