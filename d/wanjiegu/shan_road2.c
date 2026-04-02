// Room: /t/wanjiegu/shan_road2.c

inherit ROOM;

void create()
{
        set("short", "山路");
        set("long", @LONG
這是一條山間小路，兩邊山坡上張了許多樹木，北風吹過，發
出沙沙的響聲。路上張着許多雜草，看起來這裏很少有人走動。
LONG
        );
        set("outdoors", "wanjiegu");
        set("exits", ([ /* sizeof() == 2 */
            "westdown" : __DIR__"shan_road3",
            "eastdown" : __DIR__"shan_road1",
        ]));
        set("objects", ([
            __DIR__"npc/bee" : 2,
        ]));
//        set("no_clean_up", 0);

	set("coor/x", -50090);
	set("coor/y", -19010);
	set("coor/z", 20);
	setup();
        replace_program(ROOM);
}