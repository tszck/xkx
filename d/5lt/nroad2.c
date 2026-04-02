// Room: /d/5lt/nroad2.c

inherit ROOM;

void create()
{
        set("short", "碎石路");
        set("long", @LONG
這是一個繁華的村子，一派欣欣向榮的景象。你走在一條南北向的
碎石路上，西邊是村支部，門上掛一匾額「無釐頭村」。東邊是村裏花
大力氣辦的廣播站，站裏的喇叭正咿咿呀呀播着你不熟悉的音樂。
LONG );
        set("exits", ([ /* sizeof() == 3 */
            "north" : __DIR__"nroad3",
            "south" : __DIR__"shiqiao",
            "west"  : __DIR__"chuandashi",
            "east"  : __DIR__"guangbozhan",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "5lt");

	set("coor/x", -150);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}