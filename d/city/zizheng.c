// Room: /d/city/zizheng.c
// Last Modified by winder on Apr. 10 2000

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "資政書院");
	set("long", @LONG
資政書院是揚州官辦的書院，揚州人大多把小孩送此處讀書識字。
進入書院，院內一大院子，中間湖石堆了一個假山，幾個學童在假山爬
來穿去，邊上搭一鞦韆，幾個女學童在耍鞦韆玩，兩邊各有一小竹棚，
下襬幾張木桌，一個學童躺在桌上，枕着書似乎在睡覺。北向石階上有
間堂屋。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"east"  : __DIR__"caohebeijie",
		"north" : __DIR__"tangwu2",
		"south" : __DIR__"zhonglieci",
	]));
	set("objects", ([ /* sizeof() == 3 */
		__DIR__"npc/lixiaoqi" : 1,
		__DIR__"npc/kongxiaotian" : 1,
		__DIR__"npc/guyueer" : 1,
	]));
	set("coor/x", -30);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
