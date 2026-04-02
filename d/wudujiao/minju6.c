// Room: /d/wudujiao/minju6.c

inherit ROOM;

void create()
{
        set("short", "民居");
        set("long", @LONG
這是一戶普通的農家，屋裏沒有什麼象樣的擺設。牆邊擺放着一些
農具，除此只外四壁皆空，看來並不富裕。後面似乎有一個小院。
LONG
        );

        set("exits", ([
                "out" : __DIR__"cun6",
                "south" : __DIR__"minju10",
        ]));
        set("objects", ([
                __DIR__"npc/girl": 1,
        ]));

	set("coor/x", -44940);
	set("coor/y", -81030);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}