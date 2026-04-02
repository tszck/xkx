// /kaifeng/yanqing.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "延慶觀");
	set("long", @LONG
延慶觀飛檐挑拱，氣勢磅礴。始建於元太宗五年，原名為重陽觀，
為紀念道教中全真教創始人王吉在此傳教並逝世於此而修建。明洪武六
年，改名延慶觀。
LONG);
	set("exits", ([
		"east"  : __DIR__"wroad2",
		"north" : __DIR__"sanqing",
	]));
	set("objects", ([
		__DIR__"npc/walker" : 1,
	]));
	set("outdoors", "kaifeng");

	setup();
	replace_program(ROOM);
}
