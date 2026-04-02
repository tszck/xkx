//      houmen.c 後門

inherit ROOM;

void create()
{
        set("short","後門");
        set("long",@LONG
這是雪山寺的後門。一片破落而蕭索模樣。喇嘛們香火也足，花用
也大。這是後門，雖然未免寒酸，可也總可以掖着。
LONG );
	set("outdoors", "xueshansi");
        set("exits",([
            "south" : __DIR__"houyuan",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -70050);
	set("coor/y", -19880);
	set("coor/z", 120);
	setup();
        replace_program(ROOM);
}
