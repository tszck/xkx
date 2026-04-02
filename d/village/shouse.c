// Room: /d/village/shouse.c

inherit ROOM;

void create()
{
        set("short", "小土房");
	set("long", @LONG
這是一間用土坯搭成的房屋，屋裏只有幾件殘破的傢俱。在靠門口的
牆角有一隻空空的籠子，大概曾經用來養過雞、鴨之類的家禽。
LONG );
        set("exits", ([ /* sizeof() == 1 */
            "west" : __DIR__"sroad2",
        ]));
//        set("no_clean_up", 0);
        set("objects", ([
            __DIR__"npc/oldwoman": 1
        ]) );

	set("coor/x", -960);
	set("coor/y", 240);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
 