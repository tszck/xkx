// Room: /d/jueqinggu/dufengling.c
// Last Modified by winder on Feb. 17 2001

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "獨峯嶺");
	set("long", @LONG
這裏兩邊山峯壁立，抬頭望天，只餘一線。山青水碧，景色極盡清
幽，只是四下寂無聲息，隱隱透著兇險，溪心有九塊大石迎面聳立，猶
如屏風一般，擋住了去路。
LONG
	);

	set("exits", ([
		"northeast" : __DIR__"guanlanting",
		"southdown" : "/d/xiangyang/caodi1",
	]));
	set("outdoors","jueqinggu");
	set("no_clean_up", 0);
	set("coor/x", -490);
	set("coor/y", -390);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

