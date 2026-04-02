// Room: /d/village/nwhouse.c

inherit ROOM;

void create()
{
        set("short", "民房");
	set("long", @LONG
這是一個小房間，屋子裏飄着一股大蔥加香粉的味道。靠牆擺着張大
牀，牀頭有個小梳妝檯。
LONG );
        set("exits", ([ /* sizeof() == 1 */
            "northeast" : __DIR__"nwroad2",
        ]));
        set("objects", ([
                __DIR__"npc/cuihua": 1
        ]) );
//        set("no_clean_up", 0);

	set("coor/x", -990);
	set("coor/y", 270);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
 