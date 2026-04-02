// Room: /city/nanmen.c
// Last Modified by winder on Apr. 10 2000

#include <room.h>

inherit ROOM;
string look_gaoshi();

void create()
{
	set("short", "安定門");
	set("long", @LONG
一座高大的城門聳峙在渡江橋頭，城門嵌有「安定門」三字石額。
城牆上建有一個城樓，幾個巡邏的官兵們被近處的歡聲笑語所吸引，似
乎不是很認真在執勤。左右各有一個水門，便於官河和小秦淮河流通，
及城內外的水運的便利。城牆被當成了廣告牌，貼滿了花花綠綠各行各
業的廣告，城門口貼着幾張榜文告示(gaoshi)因此不太顯目。大量的行
人車輛進出安定門，熙熙攘攘的人羣立即使人感受到揚州的繁華。
LONG );
	set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	]));
	set("exits", ([
		"south" : __DIR__"dujiangqiao",
		"north" : __DIR__"nanmendajie",
	]));
	set("objects", ([
		__DIR__"npc/wujiang" : 1,
		__DIR__"npc/bing" : 2,
	]));
	set("outdoors", "yangzhouw");
	set("coor/x", 10);
	set("coor/y", -100);
	set("coor/z", 0);
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n揚州知府\n程藥發\n";
}