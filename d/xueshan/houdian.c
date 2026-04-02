//      houdian.c 後殿

inherit ROOM;

void create()
{
        set("short","後殿");
        set("long",@LONG
這裏是雪山寺的後殿，也是雪山弟子閉門練功的地方。殿內是一些
練功的蒲團和木人，還有一些吊掛着的沙袋和直豎的木樁。
LONG );
        set("exits",([
                "south" : __DIR__"neidian",
        ]));
        set("objects",([
                "/d/shaolin/npc/mu-ren" : 5,
        ]));
//        set("no_clean_up", 0);
	set("coor/x", -70000);
	set("coor/y", -19870);
	set("coor/z", 140);
	setup();
        replace_program(ROOM);
}
