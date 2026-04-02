// /d/taohuacun/shijigate.c
// Last Modifiedy by Zeratul June 2000

inherit ROOM;

void  create()
{
	set( "short", "桃花集門" );
	set( "long", @LONG
北邊新開了一個市集，四面八方的商販都聚集到此處，好不熱鬧。
市集裏熙熙攘攘的人聲不時傳入你的耳中，惹的你心癢癢的，忍不住
想進去瞧瞧。
LONG
	);
	set( "exits", ([
		"north" : __DIR__"shiji1",	
		"south" : __DIR__"taohua6",	
	]));
        set("outdoors", "taohuacun");		
	set("coor/x", -100);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}