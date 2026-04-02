//      chanshi.c 禪室

inherit ROOM;

void create()
{
        set("short","禪室");
        set("long",@LONG
這裏是僧人門參禪打坐的地方。側壁一列禪牀讓人看了就想到該想
的事。
LONG );
        set("no_fight",1);
        set("sleep_room",1);
        set("no_steal",1);
        set("exits",([
                "southwest" : __DIR__"dating",
        ]));
//        set("no_clean_up", 0);
        set("coor/x", -69990);
	set("coor/y", -19880);
	set("coor/z", 130);
	setup();
        replace_program(ROOM);
}
