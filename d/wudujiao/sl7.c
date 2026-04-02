// Room: /d/wudujiao/sl7.c

inherit ROOM;

void create()
{
        set("short", "松樹林");
        set("long", @LONG
這裏是一片松樹林，連綿的看不到盡頭，四周都是參天的古松，但
許多都莫名其妙的枯死了，只剩下一些慘白的樹幹矗立在那裏。陽光透
過枯死的樹枝間隙照射到林中，暖洋洋的。四周死一般寂靜，你不由一
陣緊張。
LONG
        );
        set("outdoors", "wudujiao");
	set("no_clean_up", 0);
        set("exits", ([
                "east" : __DIR__"sl8",
                "northwest" : __DIR__"sl4",
                "west" : __DIR__"sl6",
                "northeast" : __DIR__"sl5",
                "north" : __DIR__"caodi",
        ]));

	set("coor/x", -44930);
	set("coor/y", -81090);
	set("coor/z", 40);
	setup();
        replace_program(ROOM);
}