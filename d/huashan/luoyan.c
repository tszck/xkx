// Room: /d/huashan/luoyan.c
// Last Modified by winder on Aug. 1 2002

#include <room.h>
inherit ROOM;
void create()
{
	set("short", "落雁峯");
	set("long", @LONG
南峯又名落雁峯，是華山最高峯。峯頭題刻極多，如“太華峯頭”、
“竣極於天”、“袖拂天星”等，極言華嶽之高。環顧四周，皆在足下。
寇準詩讚曰：只有天在上，更無山與齊；舉頭紅日近，回首白雲低。傳
說五代時候的隱士陳摶就隱居在這裏。宋太祖曾經下詔徵他出山作官，
他便在這裏寫下謝詔表說：“一片野心都被白雲鎖住，九重寵詔休教丹
鳳銜來”，表示不願出山做官。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
		"enter"     : __DIR__"xiaofang",
		"northdown" : __DIR__"zhandao",
	]));
	set("no_clean_up", 0);
	set("outdoors", "huashan");
	set("coor/x", -860);
	set("coor/y", 120);
	set("coor/z", 150);
	setup();
	replace_program(ROOM);
}
