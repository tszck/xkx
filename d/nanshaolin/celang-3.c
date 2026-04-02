// Room: /d/nanshaolin/celang-3.c
// Last Modified by Winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "東側廊");
	set("long", @LONG
這裏是天王殿旁的側廊。彩梁畫棟，連頂棚也用彩漆繪滿了各種飛
天的圖形，每幅畫似乎都在訴說一個娓娓動人的佛經故事。由此向東通
向鐘樓。南面是一片廣場。
LONG );
	set("outdoors", "nanshaolin");
	set("exits", ([
		"east"  : __DIR__"zhonglou",
		"south" : __DIR__"gchang-3",
                "north" : __DIR__"celang-4",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1830);
	set("coor/y", -6280);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

