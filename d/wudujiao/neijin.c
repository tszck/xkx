// Room: /d/wudujiao/neijin.c

inherit ROOM;

void create()
{
        set("short", "客房");
        set("long", @LONG
這裏是一間客房，靠牆布着一溜通鋪，行人累可以在這裏隨
意休息。窗邊擺着一個破破爛爛的木桌，一個遊方道人正坐在桌
邊喝茶。
LONG
        );

        set("exits", ([
                "east" : __DIR__"xiaodian",
        ]));
        set("objects", ([
                CLASS_D("wudujiao")+"/daoshi": 1,
        ]));

	set("coor/x", -45020);
	set("coor/y", -79000);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}