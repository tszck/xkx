//      tulu2.c 土路

inherit ROOM;

void create()
{
        set("short","土路");
        set("long",@LONG
這是一條不起眼的土路，卻是連接雪山寺與中原的必經之路。西邊
點點的炊煙依稀可見。往北可以通往聲震西域的雪山寺。
LONG );
        set("outdoors","xueshan");
        set("exits",([
                "east" : __DIR__"tulu1",
                "north" : __DIR__"tulu3",
                "west" : __DIR__"kedian",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -30020);
	set("coor/y", -8030);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}
