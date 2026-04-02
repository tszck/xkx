// Room: /d/wudujiao/wdsl7.c

inherit ROOM;

void create()
{
        set("short", "五毒山路");
        set("long", @LONG
這裏是五毒山中的山間小路，蜿蜒曲折盤旋而上。山路上寂靜
無聲，看不到一絲鳥獸的痕跡。你順手撥開伸向路中的枝條，樹枝
忽然一動，縮了回去，“哇...”竟然是一條形似枯枝的毒蛇。前面
現出一段綠瓦紅牆，好象是所大宅院。
LONG
        );
        set("outdoors", "wudujiao");
	set("no_clean_up", 0);
        set("exits", ([
                "east" : __DIR__"damen",
                "west" : __DIR__"wdsl6",
        ]));

	set("coor/x", -44940);
	set("coor/y", -81050);
	set("coor/z", 30);
	setup();
        replace_program(ROOM);
}