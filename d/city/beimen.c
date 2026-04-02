// Room: /city/beimen.c
// Last Modified by winder on Apr. 10 2000

#include <room.h>

inherit ROOM;
string look_gaoshi();

void create()
{
	set("short", "鎮淮門");
	set("long", @LONG
這是揚州的北門「鎮淮門」，城門兩邊站着幾個士兵，盤查着過往
行人車輛。門前有一道深深的護城河，左右各開一水門，連接護城河和
官河及小秦淮河。城門建有高高的門樓，上有幾個士兵持槍在警戒。門
樓上懸着金字匾額「鎮淮門」。因爲曾經失火，到現在城牆還是黑乎乎
的，因此白紙黑字的官府告示(gaoshi)就顯得特別顯眼。
LONG );
	set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	]));
	set("exits", ([
		"south" : __DIR__"beimendajie",
		"north" : "/d/nanyang/yidao",
		"west"  : "/d/huanghe/caodi1",
		"up"    : __DIR__"chenglou",
		"northeast" : __DIR__"hangou2",
	]));
	set("objects", ([
		__DIR__"npc/wujiang" : 1,
		__DIR__"npc/bing" : 2,
	]));
	set("outdoors", "yangzhouw");
	set("coor/x", 10);
	set("coor/y", 100);
	set("coor/z", 0);
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n揚州知府\n程藥發\n";
}
