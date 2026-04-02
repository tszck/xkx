// Room: /d/wudujiao/damen.c

inherit ROOM;

void create()
{
        set("short", "五毒教大門");
        set("long", @LONG
這裏是一座隱沒于山林中的大宅院，高高的圍牆，硃紅的大門，
好象是一座有錢人家的避暑別院。
LONG
        );
        set("outdoors", "wudujiao");

        set("exits", ([
                "east" : __DIR__"lianwu",
                "west" : __DIR__"wdsl7",
        ]));
        set("objects", ([
                __DIR__"npc/jiaotu": 4,
        ]));

	set("coor/x", -44930);
	set("coor/y", -81050);
	set("coor/z", 30);
	setup();
        replace_program(ROOM);
}