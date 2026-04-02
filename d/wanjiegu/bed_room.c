// Room: /t/wanjiegu/bed_room.c

inherit ROOM;

void create()
{
        set("short", "臥室");
        set("long", @LONG
這是鍾谷主的臥室，室內大紅的幃帳掛在大紅的木牀之上。牆
上貼滿了各種花花綠綠的東西。牀邊有個小櫃，櫃上放着一盞豆油
燈。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
            "south" : __DIR__"left_room",
        ]));
        set("objects", ([
            __DIR__"npc/zhongling" : 1,
        ]));
//        set("no_clean_up", 0);

	set("coor/x", -51110);
	set("coor/y", -18870);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}