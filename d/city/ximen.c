// Room: /city/ximen.c
// Last Modified by winder on Apr. 10 2000

#include <room.h>

inherit ROOM;
string look_gaoshi();

void create()
{
	set("short", "通泗門");
	set("long", @LONG
通泗門是揚州的西門，青磚砌成。城門前沿着城牆，在護城河邊種
着揚柳，因而揚州被稱爲「綠柳城郭」。幾個士兵站在城門口，檢查着
過往行人車輛。這裏是罪犯逃往西域的必經之地，官兵們戒備森嚴，動
不動就截住行人盤問。城牆上貼着幾張通緝告示(gaoshi)。 
    一條筆直的青石板大道向東西兩邊延伸。西邊是郊外，騎馬的、座
轎的、走路的，行人匆匆。東邊是城裏。往北是一片桃林。
LONG );
	set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	]));
	set("exits", ([
		"east"  : __DIR__"tongsijie",
		"west"  : "/d/luoyang/road1",
		"north" : "/d/taohuacun/taohua1",
	]));
	set("objects", ([
		__DIR__"npc/wujiang" : 1,
		__DIR__"npc/bing" : 2,
		__DIR__"npc/runyu" : 1,
	]));
	set("outdoors", "yangzhouw");
	set("coor/x", -100);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n揚州知府\n程藥發\n";
}