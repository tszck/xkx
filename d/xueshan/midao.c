//      midao.c 密道

inherit ROOM;

void create()
{
        set("short","密道");
        set("long",@LONG
這是一條狹窄的暗道。陰森可怕，到處積滿了灰塵，結滿了蛛網，
也不知道通往何處。
LONG );
        set("exits",([
                "north" : __DIR__"mishi",
                "east" : __DIR__"neidian",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -70010);
	set("coor/y", -19880);
	set("coor/z", 140);
	setup();
        replace_program(ROOM);
}
