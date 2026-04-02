//      hubian3.c 湖邊小路

inherit ROOM;

void create()
{
        set("short","湖邊小路");
        set("long",@LONG
這是聖湖邊的小路。天藍藍的，白白的雲朵在湖裏漂移，波光瀲灩。
湖邊生長着一些綠綠青青的不知名的矮樹。
LONG );
        set("outdoors","xueshan");
        set("exits",([
                "north" : __DIR__"hubian4",
                "southwest" : __DIR__"hubian2",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -29990);
	set("coor/y", -8000);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}
