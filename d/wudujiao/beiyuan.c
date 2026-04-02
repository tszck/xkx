// Room: /d/wudujiao/beiyuan.c

inherit ROOM;

void create()
{
        set("short", "北院");
        set("long", @LONG
這裏是北院，院子裏靜悄悄的。北面有一個廚房，遠遠飄來一
股飯香，想是該開飯了。
LONG
        );
        set("outdoors", "wudujiao");
        set("no_clean_up", 0);
        set("exits", ([
                "west" : __DIR__"bingqi",
                "south" : __DIR__"lianwu",
                "north" : __DIR__"chufang",
        ]));

	set("coor/x", -44920);
	set("coor/y", -81040);
	set("coor/z", 30);
	setup();
        replace_program(ROOM);
}