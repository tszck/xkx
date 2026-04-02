// Room: /d/wudujiao/bingqi.c

inherit ROOM;

void create()
{
        set("short", "兵器房");
        set("long", @LONG
這裏是五毒教存放武器的地方，四面靠牆全是兵器架，上面插滿了
各種兵器。
LONG
        );

        set("exits", ([
                "east" : __DIR__"beiyuan",
        ]));
        set("objects", ([
                  __DIR__"obj/ganggou": 2,
                  __DIR__"obj/woodjian": 2,
                  __DIR__"obj/tiechui": 2,
        ]));

	set("coor/x", -44930);
	set("coor/y", -81040);
	set("coor/z", 30);
	setup();
        replace_program(ROOM);
}