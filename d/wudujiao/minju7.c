// Room: /d/wudujiao/minju7.c

inherit ROOM;

void create()
{
        set("short", "學堂");
        set("long", @LONG
這裏是一座簡陋的學堂，似乎是用祠堂改成的,正中供桌上還供着一
些牌位，上面落滿了灰塵。幾個八.九歲的農家小孩正跟着先生在唸書。
LONG
        );

        set("exits", ([
                "out" : __DIR__"cun7",
        ]));
        set("objects", ([
                __DIR__"npc/xuetong": 3,
                __DIR__"npc/xiansheng": 1,
        ]));
        set("item_desc", ([
                "供桌": "一個陳舊的供桌，上面搭着黑糊糊的檯布一直垂到地面。\n"
        ]) );

	set("coor/x", -44930);
	set("coor/y", -81010);
	set("coor/z", 0);
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
        if( arg=="供桌" ) {
                message("vision",me->name() + "一彎腰往供桌下面鑽了進去。\n",environment(me), ({me}) );
                me->move(__DIR__"minju9.c");
                message("vision",me->name() + "從外面鑽了進來。\n",environment(me), ({me}) );
                return 1;
        }
}