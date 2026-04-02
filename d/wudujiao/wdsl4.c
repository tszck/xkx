// Room: /d/wudujiao/wdsl4.c

inherit ROOM;

void create()
{
        set("short", "五毒山路");
        set("long", @LONG
這裏是五毒山中的山間小路，蜿蜒曲折盤旋而上。山路上寂靜
無聲，看不到一絲鳥獸的痕跡。你順手撥開伸向路中的枝條，樹枝
忽然一動，縮了回去，“哇...”竟然是一條形似枯枝的毒蛇。
LONG
        );
        set("outdoors", "wudujiao");
	set("no_clean_up", 0);
        set("exits", ([
                "eastup" : __DIR__"wdsl5",
                "south" : __DIR__"baidu1",
                "westdown" : __DIR__"wdsl3",
                "north" : __DIR__"qiandu1",
        ]));

	set("coor/x", -44960);
	set("coor/y", -81060);
	set("coor/z", 20);
	setup();
        replace_program(ROOM);
}