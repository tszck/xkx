// Room: /d/wudujiao/minju3.c

inherit ROOM;

void create()
{
        set("short", "民居");
        set("long", @LONG
這是一戶普通的農家，屋裏沒有什麼象樣的擺設。牆邊擺放着一些
農具，除此只外四壁皆空，看來並不富裕。
LONG
        );

        set("exits", ([
                "out" : __DIR__"cun4",
                "west" : __DIR__"minju8",
        ]));
        set("objects", ([
                __DIR__"npc/cuilan": 1,
        ]));

	set("coor/x", -44960);
	set("coor/y", -81000);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}