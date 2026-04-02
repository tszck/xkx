// Room: /d/wudujiao/road3.c

inherit ROOM;

void create()
{
        set("short", "黃土大道");
        set("long", @LONG
這是一條向南的黃土大道，遠處隱約看見一片翠綠的山巒。
路上行人逐漸稀少起來，大路越走越窄，有些地方竟長出了一
片片的雜草。東邊似乎有一條岔路。
LONG
        );
        set("outdoors", "wudujiao");
	set("no_clean_up", 0);
        set("exits", ([
                "southeast" : __DIR__"xiaolu",
                "south"     : __DIR__"shanlu1",
                "north"     : __DIR__"road2",
        ]));

	set("coor/x", -45000);
	set("coor/y", -78000);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}