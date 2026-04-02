// Room: /d/5lt/qsroad.c

inherit ROOM;

void create()
{
        set("short", "青石大道");
        set("long", @LONG
你走在一條青石大道上,人來人往非常繁忙,不時有人騎着馬匆匆而
過。北面是一片平緩的草地，一些叫不出名目的大鳥小獸在草叢中出沒
十分自在地遊嘻。南邊是塊菜地，剛剛下了場小雨，滿眼的青翠讓你心
情格外舒暢。東邊通向村口。
LONG );
        set("exits", ([ /* sizeof() == 4 */
            "north" : __DIR__"caodi",
            "south" : __DIR__"caidi",
            "west"  : __DIR__"eroad2",
            "east"  : __DIR__"exit",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "5lt");

	set("coor/x", -120);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}