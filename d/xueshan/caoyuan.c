//      caoyuan.c 草原

inherit ROOM;

void create()
{
        set("short","草原");
        set("long",@LONG
這裏是雪山腳下的一片草原。北面是起伏的羣山，山頂上積着終年
不化的雪。西邊有一條土路。
LONG );
        set("outdoors","xueshan");
        set("exits",([
                "west"      : __DIR__"tulu1",
                "northeast" : "/d/xingxiu/silk5" ,
        ]));
        set("objects",([
                __DIR__"npc/yetu" : 4 ,
        ]));
//        set("no_clean_up", 0);
	set("coor/x", -25000);
	set("coor/y", -5000);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
