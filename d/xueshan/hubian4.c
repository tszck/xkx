//      hubian4.c 湖邊小路

inherit ROOM;

void create()
{
        set("short","湖邊小路");
        set("long",@LONG
這是聖湖邊的小路。路側長草沒足, 青綠可喜。
LONG );
        set("outdoors","xueshan");
        set("exits",([
                "north" : __DIR__"shanjiao",
                "south" : __DIR__"hubian3",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -29990);
	set("coor/y", -7990);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}