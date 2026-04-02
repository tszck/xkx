// guozhuang.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
int do_knock(string arg);

void create()
{
        set("short", "郭莊");
        set("long", @LONG
莊園的大匾上是“郭莊”兩個大字。大門(gate)緊閉，裏面靜悄
悄的一點聲音都沒有。
LONG);
        set("exits", ([
            "east"      : __DIR__"dadao1",
        ]));
        set("item_desc", ([
           "gate" : "硃紅的大門緊閉着，敲敲(knock)看吧。\n"
        ]));
        set("objects", ([
                __DIR__"npc/wolfdog" : 2,
        ]));
//        set("no_clean_up", 0);
	set("coor/x", 4060);
	set("coor/y", -1450);
	set("coor/z", 0);
	setup();
}
void init()
{
        add_action("do_knock", "knock");
}

int do_knock(string arg)
{
        object me;

        me = this_player();
message_vision("$N“咚，咚，咚，。。。”地敲着門，可裏面卻一點動靜都沒有。\n", me);
        return 1;
}