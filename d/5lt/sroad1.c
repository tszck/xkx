// Room: /d/5lt/sroad1.c

inherit ROOM;

void create()
{
        set("short", "碎石路");
        set("long", @LONG
這是一個繁華的村子，一派欣欣向榮的景象。你走在一條南北向的
碎石路上，西面有個大酒樓，金色的錦旗迎風飄揚，只見上書四個大字
格外醒目“悅華酒樓”。東面看起來是個茶館，一個個衣着光鮮的人從那
裏進進出出。
LONG);
        set("exits", ([ /* sizeof() == 4 */
            "north" : __DIR__"center",
            "south" : __DIR__"yanwuqiao",
            "west"  : __DIR__"jiulou1",
            "east"  : __DIR__"chaguan",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "5lt");

	set("coor/x", -150);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
