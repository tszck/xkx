//      tulu3.c 土路

inherit ROOM;

void create()
{
        set("short","土路");
        set("long",@LONG
這是一條不起眼的土路。塵埃泛起的遠方，北邊波光瀲灩的一大片
幽藍水光處，就是著名的聖湖。
LONG );
        set("outdoors","xueshan");
        set("exits",([
                "south" : __DIR__"tulu2",
                "north" : __DIR__"shenghu",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -30020);
	set("coor/y", -8020);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}
