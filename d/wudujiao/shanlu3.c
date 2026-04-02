// Room: /d/wudujiao/shanlu3.c

inherit ROOM;

void create()
{
        set("short", "上山小路");
        set("long", @LONG
這是一條上山的小路，腳下是青石砌成的臺階，溼漉漉的長
滿了青苔，四周全是茂密的竹林。前面似乎就快到小山頂上了。
LONG
        );
        set("outdoors", "wudujiao");

        set("exits", ([
                "southup" : __DIR__"caoping",
                "northdown" : __DIR__"shanlu2",
        ]));
        set("objects", ([
                __DIR__"npc/qiaofu": 2,
        ]));

	set("coor/x", -44000);
	set("coor/y", -78120);
	set("coor/z", 20);
	setup();
        replace_program(ROOM);
}