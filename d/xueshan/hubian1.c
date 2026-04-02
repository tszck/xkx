//      hubian1.c 湖邊小路

inherit ROOM;

void create()
{
        set("short","湖邊小路");
        set("long",@LONG
這是聖湖邊的小路。路側的湖水極爲清澈。陽光下映着白頂雪山顯
出一片藍幽幽的寧靜。
LONG );
        set("outdoors","xueshan");
        set("exits",([
                "east" : __DIR__"hubian2",
                "west" : __DIR__"shenghu",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -30010);
	set("coor/y", -8010);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}
