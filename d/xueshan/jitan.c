//  jitan.c 祭壇

inherit ROOM;

void create()
{
        set("short","雪山祭壇");
        set("long",@LONG
這裏是雪山寺雪山祭壇，中間一個高臺，青石砌就。周圍擺滿了木
柴和酥油，旁邊一個盛水的顱鉢擱着一隻法鈴。一些痛苦和可憐的亡靈
可以在這裏獲得超度。
LONG );
        set("outdoors","xueshansi");
        set("no_fight","1");
        set("exits",([
                "north" : __DIR__"chang",
        ]));
        set("objects",([
                __DIR__"npc/x_lama": 2,
        ]));
        set("no_clean_up", 0);
	set("coor/x", -70050);
	set("coor/y", -19910);
	set("coor/z", 120);
	setup();
        replace_program(ROOM);
}
