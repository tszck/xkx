// Room: /d/wudujiao/minju9.c

inherit ROOM;

void create()
{
        set("short", "供桌下");
        set("long", @LONG
你現在蜷縮在低矮的供桌下面，四周到處都是灰塵和蜘蛛網，
稍一抬頭就會碰到桌面。桌子四周被骯髒的布簾擋住了，你看不
到外面的情況，別人也發現不了你。
LONG
        );

        set("exits", ([
                "out" : __DIR__"minju7",
        ]));
        set("objects", ([
                  __DIR__"npc/zhanglang": 1,
        ]));
        set("coor/x", -44929);
	set("coor/y", -81010);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}

