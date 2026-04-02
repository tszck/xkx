// /kaifeng/wroad1.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "西大街");
	set("long", @LONG
開封府內西面的主要交通要道，街道兩邊店鋪林立，行人車馬如梭。
商販的吆喝，市民與小販的討價還價喧鬧無比。此地向北不遠就到了延
慶觀的大門。
LONG
        );
        set("objects", ([
  		__DIR__"npc/lisi" : 1,
	]));
        set("outdoors", "kaifeng");
        set("exits", ([
  		"north" : __DIR__"wroad2",
  		"south" : __DIR__"wroad0",
	]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
