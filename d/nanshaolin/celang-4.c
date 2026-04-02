// Room: /d/nanshaolin/celang-4.c
// Last Modified by Winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "東側廊");
	set("long", @LONG
這裏是天王殿旁的側廊。彩梁畫棟，連頂棚也用彩漆繪滿了各種飛
天的圖形，每幅畫似乎都在訴説一個娓娓動人的佛經故事。東面飄來陣
陣米飯的清香，乃是僧人們用膳的齋堂。
LONG );
	set("outdoors", "nanshaolin");
	set("exits", ([
		"east"      : __DIR__"zhaitang",
		"south"     : __DIR__"celang-3",
                "northwest" : __DIR__"sblu-1",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1830);
	set("coor/y", -6270);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

