// Room: /d/wudujiao/shufang.c

inherit ROOM;

void create()
{
        set("short", "書房");
        set("long", @LONG
這裏是教主平時看書的地方，房間不大，只靠窗擺着一張書案，案邊
放了幾本書，看來是教主經常翻看的。
LONG
        );
        set("exits", ([
                "south" : __DIR__"dating",
        ]));
        set("objects", ([
                 "/clone/book/five_force": 1,
                 "/clone/book/parry_shu": 1,
        ]));

	set("coor/x", -44910);
	set("coor/y", -81040);
	set("coor/z", 30);
	setup();
        replace_program(ROOM);
}