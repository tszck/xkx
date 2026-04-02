// Room: /d/5lt/nroad3.c

inherit ROOM;

void create()
{
        set("short", "碎石路");
        set("long", @LONG
這是一個繁華的村子，一派欣欣向榮的景象。你走在一條南北向的
碎石路上，西邊是羽毛球館，據説裏面臥虎藏龍，高手如雲。東邊是放
映場，有了空暇村民們喜歡聚在一起邊看電影邊叨家常。
LONG);
        set("exits", ([ /* sizeof() == 3 */
            "south" : __DIR__"nroad2",
            "west"  : __DIR__"qiuguan",
            "east"  : __DIR__"fychang",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "5lt");

	set("coor/x", -150);
	set("coor/y", 40);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}