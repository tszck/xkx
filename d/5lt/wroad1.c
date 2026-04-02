// Room: /d/5lt/wroad1.c

inherit ROOM;

void create()
{
        set("short", "碎石路");
        set("long", @LONG
這是一個繁華的村子，一派欣欣向榮的景象。你走在一條東西向的
碎石路上，南邊新開了間鋪子，據説出售的都是稀罕的物件，北邊有間
風格獨特的民間工藝店，貨架上擺放的都是一等一的工藝品。
LONG);
        set("exits", ([ /* sizeof() == 4 */
            "north" : __DIR__"gongyidian",
            "south" : __DIR__"xiaopuzi",
            "west"  : __DIR__"wroad2",
            "east"  : __DIR__"center",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "5lt");
	set("coor/x", -160);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}