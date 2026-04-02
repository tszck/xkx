// Room: /t/wanjiegu/xiaoting.c

inherit ROOM;

void create()
{
        set("short", "小廳");
        set("long", @LONG
這是一間小廳，桌上點着一對巨燭。東壁四幅屏條，繪的是梅
蘭竹菊，西壁上的四幅是春夏秋冬。可是全掛錯了方位，看來這裏
的主人並不懂得書畫。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
            "south" : __DIR__"grassland",
            "north" : __DIR__"hall",
        ]));
        set("objects", ([
            __DIR__"npc/gan" : 1,
        ]));
//        set("no_clean_up", 0);

	set("coor/x", -51100);
	set("coor/y", -18890);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}