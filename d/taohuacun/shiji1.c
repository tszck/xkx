// /d/taohuacun/shiji1.c
// Last Modifiedy by Zeratul June 2000

inherit ROOM;

void  create()
{
	set( "short", "市集" );
	set( "long", @LONG
你身處市集中，身邊人頭攢動，吆喝叫賣之聲不絕於耳。你只想看
看(list)有什麼可買的，如果能買點(buy) 菜種回去，料理那一畝三分
地也就不愁了。
LONG
	);
	set( "exits", ([
		"north" : __DIR__"shiji2",
		"west" 	: __DIR__"shiji4",
		"east" 	: __DIR__"shiji5",
		"south"	: __DIR__"shijigate",
	]));
	set("objects", ([
		__DIR__"npc/cainong" : 1,
	]));
        set("outdoors", "taohuacun");
	set("coor/x", -100);
	set("coor/y", 40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}