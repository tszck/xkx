// Room: /d/wudujiao/minju10.c

inherit ROOM;

void create()
{
        set("short", "後院");
        set("long", @LONG
這是一個用籬笆圍成的簡易院落，遠處種着幾畦蔬菜。院子
中間一棵高大的柿樹上結滿了鮮紅的果實，旁邊的地上蓋着一張
厚厚的草蓆。
LONG
        );
        set("outdoors", "wudujiao");

        set("exits", ([
                "north" : __DIR__"minju6",
        ]));
        set("objects", ([
                  __DIR__"npc/xuetong": 3,
        ]));
        set("item_desc", ([
                "草蓆" : "\n一張厚厚的草蓆蓋在洞口，下面似乎是一個地窖。\n" ,
        ]));
	set("coor/x", -44940);
	set("coor/y", -81040);
	set("coor/z", 0);
	setup();
}
void init()
{
        add_action("do_move", "pull");
}
int do_move(string arg)
{
        object me/*,hole*/;
//      string dir;
        me = this_player();
        if (!arg||arg=="") return 0;
        if( arg=="草蓆" ) {
            message_vision("\n$N掀開蓋在洞口的草蓆走了下去。\n", this_player());
            me->move(__DIR__"dijiao");
            message_vision("\n蓋在洞口的草蓆一掀，$N從上面走了下來。\n",me);
        }
        else {
            message_vision("\n$N雙手在空中比劃了幾下，但似乎什麼也沒抓住。\n", this_player());
        }
        return 1;
}