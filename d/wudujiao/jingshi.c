// Room: /d/wudujiao/jingshi.c

inherit ROOM;

void create()
{
        set("short", "靜室");
        set("long", @LONG
這是一個昏暗的房間，除了幾張牀之外什麼都沒有。室內光線昏暗，你
不由的打了一個哈欠。
LONG
        );
        set("sleep_room", 1);
        set("no_fight", 1);
	set("no_clean_up", 0);
        set("exits", ([
                "north" : __DIR__"dating",
        ]));

	set("coor/x", -44910);
	set("coor/y", -81060);
	set("coor/z", 30);
	setup();
        replace_program(ROOM);
}