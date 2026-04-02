// Room: /d/nanshaolin/celang-2.c
// Last Modified by Winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "西側廊");
	set("long", @LONG
這裏是天王殿旁的側廊。彩梁畫棟，連頂棚也用彩漆繪滿了各種飛
天的圖形，每幅畫似乎都在訴説一個娓娓動人的佛經故事。左面傳來陣
陣木魚的敲擊聲和輕輕的梵唱。
LONG
	);
	set("outdoors", "nanshaolin");
	set("exits", ([
		"northeast" : __DIR__"sblu-1",
		"south"     : __DIR__"celang-1",
                "west"      : __DIR__"zdyuan",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1810);
	set("coor/y", -6270);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

