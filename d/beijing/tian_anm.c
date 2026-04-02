// Room: /beijing/tiananmen.c

#include <room.h>

inherit ROOM;


void create()
{
	set("short", "天安門廣場");
	set("long", @LONG
這裏就是天安門廣場，灰色的城牆給人以莊嚴肅穆之感，再往北就
是皇宮了。皇宮正門前有座小橋，一條護城河繞城而過。越過小橋向北
望去，紫禁城的輪廓益發顯得雄偉高大。一條筆直的大道橫貫東西，東
邊是東長安街，西邊是西長安街。南邊是一條繁華的大道，從那往下有
一座天橋，據説遊人很多。
LONG );
	set("exits", ([
		"south" : __DIR__"nandaj1",
		"north" : __DIR__"bridge",
		"west"  : __DIR__"xichang1",
		"east"  : __DIR__"dongcha1",
	]));
	set("objects", ([
		"/d/city/npc/bing" : 2,
	]));
	set("outdoors", "beijing");
	set("coor/x", -200);
	set("coor/y", 4040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
