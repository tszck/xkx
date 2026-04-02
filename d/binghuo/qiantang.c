// Room: /binghuo/qiantang.c
// Date: Oct.28 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "錢塘江畔");
	set("long", @LONG
錢塘江到了六和塔下轉一個大彎，然後直向東流。該處和府城相
距不近，塔東三株大柳樹下繫着一艘扁舟(zhou)。江船張有風帆，船
頭掛着兩盞碧紗燈籠。碧紗燈下，一個少女獨坐船頭，身穿淡綠衫子。
LONG );
	set("outdoors", "wangpan");
	set("no_clean_up", 0);
	set("item_desc", ([
		"zhou" : "一艘小舟，不妨進去(enter)看看。\n",
	]));
	set("exits", ([
		"westup" : "/d/hangzhou/qiantang",
	]));
	set("coor/x", 4080);
	set("coor/y", -1800);
	set("coor/z", -10);
	setup();
}

void init()
{
        add_action("do_enter", "enter");
}

int do_enter(string arg)
{
        object me;
        

        me = this_player();
        if( !arg || arg=="" ) return 0;
        if( arg=="zhou" )
        {
               message("vision",
                        me->name() + "運起輕功，一縱身上了小舟。",
                        environment(me), ({me}) );
               me->move(__DIR__"zhou");
               message("vision",
                        me->name() + "從岸上躍上舟來。\n",
                        environment(me), ({me}) );
                        return 1;
        }
        else  return notify_fail("你想到哪去？\n");
}