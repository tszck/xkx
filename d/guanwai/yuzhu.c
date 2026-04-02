// /guanwai/yuzhu.c

inherit ROOM;

void create()
{
	set("short", "玉柱峯");
	set("long", @LONG
白雲峯西南，有峯高聳挺秀，多峯突起，形如玉柱。東麓瀉出一水，
懸流如線，注入天池，就是古籍所載的“金線泉”了。
LONG );
	set("exits", ([
		"north"      : __DIR__"tiyun",
		"northeast"  : __DIR__"baiyun",
	]));
        set("objects", ([
                __DIR__"npc/she" : 1,
        ]));
	set("outdoors", "changbai");
	set("coor/x", 6170);
	set("coor/y", 5160);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}