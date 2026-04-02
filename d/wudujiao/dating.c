// Room: /d/wudujiao/dating.c

inherit ROOM;

void create()
{
        set("short", "大廳");
        set("long", @LONG
這裏是個寬廣的大廳，高大的盤龍柱一人都合抱不過來。這裏是平日教
主召集教眾們議事的地方，大廳正中供奉着五聖--毒蛇，蜘蛛，蜈蚣，蠍子
蟾蜍的畫像。幾位長老正坐在廳中議事 。
LONG
        );
        set("valid_startroom", 1);

        set("exits", ([
                "east" : __DIR__"huayuan1",
                "south" : __DIR__"jingshi",
                "west" : __DIR__"lianwu",
                "north" : __DIR__"shufang",
        ]));
        set("objects", ([
               CLASS_D("wudujiao")+"/first": 1,
               CLASS_D("wudujiao")+"/qiyunao": 1,
               CLASS_D("wudujiao")+"/panxiuda": 1,
               CLASS_D("wudujiao")+"/cenqisi": 1,
        ]));


	set("coor/x", -44910);
	set("coor/y", -81050);
	set("coor/z", 30);
	setup();
        "/clone/board/wudu_b"->foo();
}
int valid_leave(object me, string dir)
{
//      int i;
//      object ob;
        me=this_player();
        if(dir=="east"||dir=="north"||dir=="south")
        {
              if ((string)me->query("family/family_name")!="五毒教"
                 & objectp(present("qi yunao", environment(me))))
              return notify_fail("齊雲敖身形一晃，忽然擋住你，厲聲説道：這位" +
              RANK_D->query_respect(me) + "不是本教弟子，不得進入本教禁地。\n");
        }
        return ::valid_leave(me, dir);
}