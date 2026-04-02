// /d/taohuacun/shiji2.c
// Last Modifiedy by Zeratul June 2000

inherit ROOM;

void  create()
{
	set( "short", "市集" );
	set( "long", @LONG
你身處市集中，身邊人頭攢動，吆喝叫賣之聲不絕於耳。於是你就
想，如果手頭有點什麼貨水，不就可以和這個瓜農換(change)點東西回
去嘛？！
LONG
	);
	set( "exits", ([
		"south"	: __DIR__"shiji1",
		"north" : __DIR__"shiji3",
		"west" 	: __DIR__"shiji6",
		"east" 	: __DIR__"shiji7",
	]));
	set("objects", ([
		__DIR__"npc/guanong" : 1,
	]));
        set("outdoors", "taohuacun");
	set("coor/x", -100);
	set("coor/y", 50);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}