// Room: /d/chengdu/southchengmen.c
// Last Modifyed by Winder on Jan. 4 2002

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "南城門");
	set("long", @LONG
成都南門，這年頭天下不太平，再加上成都是蜀中重鎮，是兵家守
衞之要衝，自然是盤查嚴密。厚厚青磚疊起的城牆上爬滿了青藤，也不
知究竟有多少個年頭了。守城的兵勇不懷好意的瞪着你，在此徘徊顯也
易見不是什麼好事，你不由得加快了步伐。
    道路南北延伸。
LONG	);
	set("outdoors", "chengdu");
	set("exits", ([
		"north" : __DIR__"nanjie",
		"south" : __DIR__"nanheqiaos",
	]));
	set("objects", ([
		__DIR__"npc/wujiang" : 1,
		__DIR__"npc/bing" : 2,
	]));
	set("coor/x", -8050);
	set("coor/y", -3040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

