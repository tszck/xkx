// Room: /d/wudujiao/nanyuan.c

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "南院");
        set("long", @LONG
這裏是南跨院，院子裏有棵很大的榕樹，將天空大部遮住，院子裏靜
悄悄的，只有幾隻高大的藏獒在樹下來回踱步。
LONG
        );
        set("outdoors", "wudujiao");

        set("exits", ([
                "east" : __DIR__"yaoshi",
                "south" : __DIR__"liandu",
                "west" : __DIR__"xiangfang",
                "north" : __DIR__"lianwu",
        ]));
        set("objects", ([
                  __DIR__"npc/zangao": 2,
        ]));

	set("coor/x", -44920);
	set("coor/y", -81060);
	set("coor/z", 30);
	setup();
}

void init()
{
       add_action("do_climb","climb");
}
int do_climb(string arg)
{

        object me=this_player();
        object ob;
        if( (!arg) ||!((arg == "tree") || (arg == "up")))
                return notify_fail("你要爬什麼？\n");
                message_vision("$P撮了撮手，攀着榕樹的枝杈三下兩下就爬了上去。\n
\n",me);
        ob = load_object(__DIR__"tree");
        ob = find_object(__DIR__"tree");
        message("vision", me->query("name")+"從下面爬了上來。\n", ob);
        me->move(__DIR__"tree");
        return 1;
}