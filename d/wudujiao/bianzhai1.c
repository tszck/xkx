// Room: /d/wudujiao/bianzhai1.c

inherit ROOM;

void create()
{
        set("short", "邊寨風情");
        set("long", @LONG
這裏已是苗疆地界，只覺得山清水秀，風景與中原大不相同。
走在路上，不時會碰到少男少女在路邊田野裏載歌載舞，頓覺心
情舒暢，但願終老此鄉。南面就是有名的黑森林了。
LONG
        );
        set("outdoors", "wudujiao");
	set("no_clean_up", 0);

        set("exits", ([
                "south" : __DIR__"milin8",
                "west" : __DIR__"bianzhai2",
                "southwest" : __DIR__"bianzhai3",
        ]));

	set("coor/x", -46000);
	set("coor/y", -81000);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}