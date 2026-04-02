// Room: /d/wudujiao/yaoshi.c

inherit ROOM;
string* objs = ({
        __DIR__"obj/fugu",
        __DIR__"obj/hedinghong",
        __DIR__"obj/chuanxin",
        __DIR__"obj/qianrizui",
        __DIR__"obj/shexinzi",
//      __DIR__"obj/xiang",
        __DIR__"obj/fugu",
        __DIR__"obj/chuanxin",
        __DIR__"obj/shexinzi",
        __DIR__"obj/hedinghong",

});

void create()
{
        set("short", "藥室");
        set("long", @LONG
這裏是五毒教存放藥品的地方，只見十多個黑漆木櫃一字排開，上面
開着數百個的小抽屜，每個抽屜上面都整整齊齊的貼着一行標籤。這裏存
放着各種珍貴藥材，其中大多數是有毒的。旁邊一個案上放着幾束剛採來
的草藥。
LONG
        );

        set("exits", ([
                "west" : __DIR__"nanyuan",
        ]));
        set("objects", ([
                objs[random(sizeof(objs))] : 1,
                objs[random(sizeof(objs))] : 1,
                __DIR__"obj/zhulou"        : 2,
        ]));

	set("coor/x", -44910);
	set("coor/y", -81060);
	set("coor/z", 30);
	setup();
        replace_program(ROOM);
}