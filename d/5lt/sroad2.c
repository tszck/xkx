// Room: /d/5lt/sroad2.c

inherit ROOM;

void create()
{
        set("short", "碎石路");
        set("long", @LONG
這是一個繁華的村子，一派欣欣向榮的景象。你走在一條南北向的
碎石路上，西面有個郵局，不時有送信的郵差騎着腳踏車吆喝着從你身
邊掠過。東邊就是“青蛙診所”了。
LONG);
        set("exits", ([ /* sizeof() == 4 */
            "north" : __DIR__"yanwuqiao",
            "south" : __DIR__"sroad3",
            "west"  : __DIR__"youju",
            "east"  : __DIR__"zhensuo",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "5lt");

	set("coor/x", -150);
	set("coor/y", -30);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
