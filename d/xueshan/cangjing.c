//      cangjingge.c 藏經閣

inherit ROOM;

void create()
{
        set("short","藏經閣");
        set("long",@LONG
這裏是雪山寺的藏經之處。書架上林林總總都是梵文典籍。你一個
字也看不懂。
LONG );
        set("exits",([
                "northwest" : __DIR__"dating",
        ]));
        set("objects", ([
                CLASS_D("xueshan")+"/lingzhi" : 1,
        ]));

        set("coor/x", -69990);
	set("coor/y", -19900);
	set("coor/z", 130);
	setup();
        replace_program(ROOM);
}

