//      houyuan.c 後院

inherit ROOM;

void create()
{
        set("short","後院");
        set("long",@LONG
這裏是雪山寺的後院，後院不大，栽了幾株參天雪松，在白晃晃的
雪山背景下，竟是飄然出世的心動。南邊是練武場，北邊是後門。
LONG );
        set("outdoors","xueshansi");
        set("exits",([
                "eastdown" : __DIR__"dilao",
                "north" : __DIR__"houmen",
                "south" : __DIR__"chang",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -70050);
	set("coor/y", -19890);
	set("coor/z", 120);
	setup();
        replace_program(ROOM);
}
