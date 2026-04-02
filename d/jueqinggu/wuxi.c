// Room: /d/jueqinggu/wuxi.c
// Last Modified by winder on Feb. 17 2001

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "浯溪");
	set("long", @LONG
突然一陣清香湧至，眼前無邊無際的全是水仙花。原來地下是淺淺
的一片水塘，深不逾尺，種滿了水仙。前面好象是一片遍野的花叢，很
難變清道路。一種迥異的香味在空氣中瀰漫着。
LONG
	);

	set("exits", ([
                "east"  : __DIR__"feiyunyan",
                "enter" : __DIR__"huacong1",
	]));
	set("no_clean_up", 0);
	set("outdoors","jueqinggu");
	set("coor/x", -500);
	set("coor/y", -370);
	set("coor/z", 10);
	setup();
	replace_program(ROOM); 
}

