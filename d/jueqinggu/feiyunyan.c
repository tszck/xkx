// Room: /d/jueqinggu/feiyunyan.c
// Last Modified by winder on Feb. 17 2001

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "飛雲巖");
	set("long", @LONG
這裏似洞非洞，頂上崖檐覆出，石乳倒垂。浮者若飛霞，亙者若虹
霓，豁然樓殿門闕，懸若銅鼓編磬，並有獅象蛟龍、蓮荷阡陌、蜂房水
渦之屬。其下澄潭邃谷，幽深無底，四面茂盛古樹參天，流水瀠洄。
LONG
	);

	set("exits", ([
		"eastup" : __DIR__"xiangqinxie",
		"west"   : __DIR__"wuxi",
	]));
	set("outdoors","jueqinggu");
	set("no_clean_up", 0);
	set("coor/x", -490);
	set("coor/y", -370);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

