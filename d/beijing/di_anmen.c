// Room: /beijing/di_anmen.c

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "地安門");
	set("long", @LONG
這裏就是地安門廣場，灰色的城牆給人以莊嚴肅穆之感，再往南就
是皇宮後門。門前有座小橋，一條護城河繞城而過。越過小橋向南望去，
紫禁城的輪廓益發顯得雄偉高大。一條筆直的大道橫貫東西，東邊是地
安門東街，西邊是地安門西街。北邊通往安定門。
LONG );
	set("outdoors", "beijing");
	set("exits", ([
		"west"  : __DIR__"di_an3",
		"east"  : __DIR__"di_an2",
		"south" : __DIR__"hbridge",
		"north" : __DIR__"anding",
	]));
	set("objects", ([
		"/d/city/npc/bing" : 2,
	]));
	set("coor/x", -190);
	set("coor/y", 4080);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
