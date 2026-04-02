// /d/taohuacun/shiji5.c
// Last Modifiedy by Zeratul June 2000

inherit ROOM;

void  create()
{
	set( "short", "市集" );
	set( "long", @LONG
你身處市集中，身邊人頭攢動，吆喝叫賣之聲不絕於耳。於是你就
想，如果手頭有點什麼貨水，不就可以和這個老大娘換(change)點東西
回去嘛？！
LONG
	);
	set( "exits", ([
		"west"	: __DIR__"shiji1",
		"north"	: __DIR__"shiji7",
	]));
	set("objects", ([
		__DIR__"npc/oldwoman" : 1,
	]));
        set("outdoors", "taohuacun");
	set("coor/x", -90);
	set("coor/y", 40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}