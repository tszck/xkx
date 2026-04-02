// Room: /d/nanshaolin/huilang1.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "迴廊");
	set("long", @LONG
這裏是法堂西側的迴廊。彩梁畫棟，連頂棚也用彩漆繪滿了各種飛
天的圖形，每幅畫似乎都在訴説一個娓娓動人的佛經故事。廊外兩側是
翠綠的青竹，在微風中沙沙做響。四周靜悄悄的，只有你自己的腳步聲
在耳邊迴盪。
LONG );
	set("exits", ([
		"east"  : __DIR__"fatang",
                "west"  : __FILE__,
		"south" : __FILE__,
                "north" : __DIR__"huilang2",
	]));
	set("no_clean_up", 0);
	set("outdoors","nanshaolin");
	set("coor/x", 1810);
	set("coor/y", -6110);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}

