// Room: /d/wudujiao/road2.c

inherit ROOM;

void create()
{
        set("short", "黃土大道");
        set("long", @LONG
這是一條向南的黃土大道，兩旁是一片片綠油油的水田
和悠閒的牧童。大道上人流熙熙攘攘，過往的行人頂着炎炎烈
日滿頭大汗的匆匆趕路，似乎並無心欣賞這優美的田園風光。
LONG
        );
        set("outdoors", "wudujiao");

        set("exits", ([
                "south" : __DIR__"road3",
                "north" : __DIR__"road1",
        ]));
        set("objects", ([
                "/d/taishan/npc/tiao-fu": 2,
        ]));

	set("coor/x", -45000);
	set("coor/y", -77000);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}