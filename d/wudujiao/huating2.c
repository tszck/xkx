// Room: /d/wudujiao/huating2.c

inherit ROOM;

void create()
{
        set("short", "棲鳳亭");
        set("long", @LONG
這裏是一個花園中的小亭子，雕樑畫棟，古色古香。亭子當中立着幾個木人。
LONG
        );
        set("outdoors", "wudujiao");

        set("exits", ([
                "west" : __DIR__"huayuan2",
                "north" : __DIR__"huating1",
        ]));
        set("objects", ([
                 "/d/shaolin/obj/mu-ren": 4,
        ]));

	set("coor/x", -44890);
	set("coor/y", -81060);
	set("coor/z", 30);
	setup();
        replace_program(ROOM);
}