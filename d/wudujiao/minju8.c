// Room: /d/wudujiao/minju8.c

inherit ROOM;

void create()
{
        set("short", "竈房");
        set("long", @LONG
這是一個簡陋的竈房，四壁都被煙火燻的黑糊糊的，竈臺旁的牆上
貼着一張發黃的黃裱紙，旁邊掛着一些風乾的獸肉。竈臺鐵鍋旁的水缸
上擺着幾隻粗瓷大碗，屋的一角堆着一大堆麥秸。
LONG
        );

        set("exits", ([
                "east" : __DIR__"minju3",
        ]));
        set("objects", ([
                __DIR__"obj/qhcwan": 2,
                __DIR__"obj/shourou2": 1,
                __DIR__"obj/shourou1": 1,
        ]));
        set("resource", ([ /* sizeof() == 1 */
                "water" : 1,
        ]));
        set("item_desc",([
                "黃裱紙":"         木人到此一遊。。。\n",
        ]));
	set("coor/x", -44970);
	set("coor/y", -81000);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}