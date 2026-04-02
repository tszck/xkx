// Room: /d/wudujiao/tree.c

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "榕樹上");
        set("long", @LONG
這裏是大樹的頂端，四周是濃密的枝葉和濕漉漉的苔蘚。一陣
微風吹來，樹葉發出唰啦啦的聲音。從上面望下去，你只覺得一陣
眼暈，心想還是趕快下去吧。
LONG
        );
        set("outdoors", "wudujiao");

        set("exits", ([
        ]));
        set("objects", ([
                  __DIR__"obj/xiang": 1,
        ]));

        set("coor/x", -44920);
	set("coor/y", -81060);
	set("coor/z", 50);
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
        if( (!arg) ||!((arg == "tree") || (arg == "down")))
                return notify_fail("你要爬什麼？\n");
                message_vision("$N攀着榕樹的枝杈慢慢的爬了下去。\n\n",me);
        ob = load_object(__DIR__"nanyuan");
        ob = find_object(__DIR__"nanyuan");
        message("vision", me->query("name")+"從榕樹上面爬了下來。\n", ob);
        me->move(__DIR__"nanyuan");
        return 1;
}

