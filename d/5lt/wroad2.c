// Room: /d/5lt/wroad2.c

inherit ROOM;

void create()
{
        set("short", "碎石路");
        set("long", @LONG
這是一個繁華的村子，一派欣欣向榮的景象。你正走在一條東西向的
碎石路上。
LONG );
        set("exits", ([ /* sizeof() == 2 */
            "west"  : __DIR__"wroad3",
            "east"  : __DIR__"wroad1",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "5lt");
	set("coor/x", -170);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}