//      shanjiao.c 山腳

inherit ROOM;

void create()
{
        set("short","山腳");
        set("long",@LONG
這裏是山腳下的一片平地，山上不遠處，皚皚白雪映照下的一大片
紅牆金瓦處，就是遠近聞名的雪山寺。
LONG );
        set("outdoors","xueshan");
        set("exits",([
                "westup" : "/d/xuedao/nroad7",
                "south"  : __DIR__"hubian4",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -29990);
	set("coor/y", -7980);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}
