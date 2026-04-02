// Room: /d/wudujiao/wandu3.c

inherit ROOM;
#include <ansi.h>
string* npcs = ({
        __DIR__"npc/wandu1",
        __DIR__"npc/wandu2",
        __DIR__"npc/wandu3",
        __DIR__"npc/wandu4",
        __DIR__"npc/wandu5",
});

void create()
{
        set("short", "萬毒窟");
        set("long", @LONG
這裏是山洞內部的支洞，這裏已經沒有一絲光線了，黑洞洞的
什麼也看不見。洞內巖壁上好象生着幾株不知名的小草。身旁傳來
一陣“噝噝”的聲音。
LONG
        );

        set("exits", ([
                "north" : __DIR__"wandu2",
        ]));
        set("objects", ([
                npcs[random(sizeof(npcs))] : 1,
                npcs[random(sizeof(npcs))] : 1,
        ]));

	set("coor/x", -44970);
	set("coor/y", -81110);
	set("coor/z", 0);
	setup();
//      replace_program(ROOM);
}

void init()
{
        add_action("do_climb","climb");
}
int do_climb(string arg)
{

        object me=this_player();
        object ob;
        if( (!arg) ||!((arg == "巖壁") || (arg == "洞壁")))
                return notify_fail("你要爬什麼？\n");
                message_vision(HIC"$N攀着巖壁上突出的石筍艱難的爬了上去。\n\n"NOR,me);
        ob = load_object(__DIR__"dongxue");
        ob = find_object(__DIR__"dongxue");
        message("vision", me->query("name")+"從下面爬了上來。\n", ob);
        me->move(__DIR__"dongxue");
        return 1;
}