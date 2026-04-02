// Room: /d/wudujiao/wandu1.c

inherit ROOM;

void create()
{
        set("short", "萬毒窟外");
        set("long", @LONG
這裏是五毒教飼養毒物的地方，山壁旁有一個天然的石洞，裏
面黑漆漆的看不清楚。一陣山風吹來，你聞到一股腥味。有一個衣
衫襤褸的枯瘦老婦正靠在洞邊打盹。
LONG
        );
        set("outdoors", "wudujiao");

        set("exits", ([
                "south" : __DIR__"wandu2",
                "north" : __DIR__"wdsl3",
        ]));
        set("objects", ([
                  CLASS_D("wudujiao")+"/hehongyao": 1,
        ]));

        set("coor/x", -44970);
	set("coor/y", -81090);
	set("coor/z", 10);
	setup();
}
int valid_leave(object me, string dir)
{
        int i;
        object ob;
        me=this_player();
        if(dir=="south")
        {
            if( !present("tie shao", me)
                & objectp(present("he hongyao", environment(me))))
                return notify_fail("何紅藥身形一晃，忽然擋住你，厲聲説道：這位" + RANK_D->query_respect(me) + "沒有教主準許，不得進入本教聖地。\n");
        }
        return ::valid_leave(me, dir);
}
