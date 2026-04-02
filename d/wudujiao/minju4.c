// Room: /d/wudujiao/minju4.c

inherit ROOM;

void create()
{
        set("short", "民居");
        set("long", @LONG
這是一戶普通的農家，屋裏沒有什麼象樣的擺設。牆邊擺放着一些
農具，屋正中擺着一張八仙桌，村長正拿着旱煙袋坐在桌邊抽着。
LONG
        );

        set("exits", ([
                "out" : __DIR__"cun5",
        ]));
        set("objects", ([
                __DIR__"npc/cunzhang": 1,
        ]));

	set("coor/x", -44950);
	set("coor/y", -80990);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}