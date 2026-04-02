//      bieyuan.c 雪山別院

inherit ROOM;

void create()
{
        set("short","雪山別院");
        set("long",@LONG
這裏是雪山寺的分部，當年貢唐倉大喇嘛不遠萬裏進京面聖，被封
爲國師，就在此處宣揚佛法。
LONG );
        set("exits",([
                "east" : "/d/beijing/road5",
        ]));
        set("objects" , ([
                __DIR__"npc/seng-bing1"  : 2 ,
                CLASS_D("xueshan") + "/guoshi" : 1 ,
        ]));
//        set("no_clean_up", 0);
	set("coor/x", -210);
	set("coor/y", 4000);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if ( me->query("id") == "seng bing" &&  dir == "east" ) return 0;

	return ::valid_leave(me, dir);
}
