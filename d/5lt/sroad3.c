// Room: /d/5lt/sroad3.c

inherit ROOM;

void create()
{
        set("short", "碎石路");
        set("long", @LONG
這是一個繁華的村子，一派欣欣向榮的景象。你走在一條南北向的
碎石路上，西邊是一家打鐵鋪，叮叮噹噹的聲音老遠就能聽到。東面是
村裏的體彩中心。
LONG);
        set("exits", ([ /* sizeof() == 3 */
            "north" : __DIR__"sroad2",
            "west"  : __DIR__"datiepu",
            "east"  : __DIR__"tczhongxin",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "5lt");

	set("coor/x", -150);
	set("coor/y", -40);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}