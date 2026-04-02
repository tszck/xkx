// lianwu.c 練武房

inherit ROOM;

void create()
{
        set("short", "練武房");
        set("long", @LONG
這裏是天地會的練武房，壁上掛着一些熊皮、虎皮、花葉豹皮，地
下青磚地已經破損得很零碎了。牆角倚着一些兵器。幾個天地會會眾正
盤膝打坐。
LONG );
        set("exits", ([
                "east" : __DIR__"dating",
        ]));
        set("objects", ([
                "/d/shaolin/npc/mu-ren" : 6
        ]));
	set("coor/x", -213);
	set("coor/y", 4015);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}