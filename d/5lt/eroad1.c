// Room: /d/5lt/eroad1.c

inherit ROOM;

void create()
{
        set("short", "碎石路");
        set("long", @LONG
這是一個繁華的村子，一派欣欣向榮的景象。你走在一條東西向的
碎石路上，南面是一間甜品店，微風習習，空氣中夾雜着的餅的香味讓
你不禁食指大動。北面是牌局室，隱約可以聽到傳出來吆五喝六的聲音。
LONG );
        set("exits", ([ /* sizeof() == 4 */
            "north" : __DIR__"zoulang1",
            "south" : __DIR__"tianpindian",
	    "west"  : __DIR__"center",
            "east"  : __DIR__"eroad2",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "5lt");

	set("coor/x", -140);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}