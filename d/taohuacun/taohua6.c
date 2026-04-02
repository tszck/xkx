// Room: /d/taohuacun/taohua6.c

inherit ROOM;

void create()
{
	set("short", "桃花汀");
	set("long", @LONG
桃花汀在桃花溪邊。一桃一柳，夾溪成趣。翠柳長條，依風憐
惜，似有無盡風情。碧水徜佯，落紅時節，滿目飄零，另有一般情
趣。汀西一望處，有點點精巧漂亮的小別墅，真是住家好去處。
LONG );
	set("outdoors", "taohuacun");
	set("no_clean_up", 0);
	set("exits", ([
		"north"     : __DIR__"shijigate",
		"south"     : __DIR__"taohua2",
		"west"      : __DIR__"taohua7",
		"east"      : __DIR__"road3",
	]));
	set("objects", ([
		__DIR__"npc/taohuatong" : 1,
	]));
	set("coor/x", -100);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}