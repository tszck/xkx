// Room: /d/nanshaolin/celang-1.c
// Last Modified by Winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "西側廊");
	set("long", @LONG
這裏是天王殿旁的側廊。彩梁畫棟，連頂棚也用彩漆繪滿了各種飛
天的圖形，每幅畫似乎都在訴説一個娓娓動人的佛經故事。由此向西通
向鼓樓。南面是一片廣場。
LONG
	);
	set("exits", ([
		"west"  : __DIR__"gulou",
		"south" : __DIR__"gchang-2",
                "north" : __DIR__"celang-2",
	]));
	set("outdoors", "nanshaolin");
	set("no_clean_up", 0);
	set("coor/x", 1810);
	set("coor/y", -6280);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

