// Room: /d/wudujiao/milin1.c

inherit ROOM;

void create()
{
        set("short", "黑森林");
        set("long", @LONG
這裏就是有名的黑森林，四周均是茂密的叢林，巨大的古木遮
天蔽日，頭頂看不到一片天空。腳下不時傳來輕微的聲響，似乎有
什麼東西從草叢中游過，遠處偶爾傳來一陣野獸的嚎叫聲。
LONG
        );
        set("outdoors", "wudujiao");

        set("exits", ([
                "east" : __DIR__"milin2",
                "south" : __DIR__"milin2",
                "west" : __DIR__"milin2",
                "north" : __DIR__"shanlu1",
        ]));
        set("objects", ([
                __DIR__"npc/cunmin": 1,
                __DIR__"npc/cunfu": 1,
        ]));

	set("coor/x", -45000);
	set("coor/y", -80000);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}