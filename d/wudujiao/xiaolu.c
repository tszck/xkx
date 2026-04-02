// Room: /d/wudujiao/xiaolu.c

inherit ROOM;

void create()
{
        set("short", "小路");
        set("long", @LONG
一條小路向東南延伸，四周盡是花香鳥語，空氣頓時清新了許
多。前面有一座小小的山岡。
LONG
        );
        set("outdoors", "wudujiao");

        set("exits", ([
                "northwest" : __DIR__"road3",
                "southup" : __DIR__"shanlu2",
        ]));
        set("objects", ([
                "/d/wudang/npc/yetu": 3,
        ]));

	set("coor/x", -44000);
	set("coor/y", -78100);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}