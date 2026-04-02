// chang.c 練武場

inherit ROOM;

void create()
{
        set("short","練武場");
        set("long",@LONG
這裏是雪山寺練武場，樹着好多木樁和沙袋，僧人們日常均在此習
武。東邊是廣場，西邊有個小庫房，南邊一大片開闊地，就是雪山聞名
海內的祭壇了。
LONG );
        set("outdoors","xueshansi");
        set("exits",([
                "east" : __DIR__"guangchang",
                "west" : __DIR__"kufang",
                "north" : __DIR__"houyuan",
                "south" : __DIR__"jitan",
        ]));
        set("objects", ([
//                CLASS_D("xueshan")+"/gelunbu" :1,
		__DIR__"npc/x_lama" : 1 ,
        ]));
//        set("no_clean_up", 0);
        set("coor/x", -70050);
	set("coor/y", -19900);
	set("coor/z", 120);
	setup();
        replace_program(ROOM);
}

