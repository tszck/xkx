// Room: /d/henshan/lingxingmen.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
	set("short", "欞星門");
	set("long", @LONG
這裏是南嶽大廟的第一道門，由漢白玉，花崗石打就的石牌坊。南
嶽衡山是祝融遊息之地，道教奉爲第三小洞天。在此遠望衡山，山勢如
飛，如雲霧中凌空的大鳥。
LONG);
	set("exits", ([ /* sizeof() == 4 */
		"north"  : __DIR__"kuixingge",
		"south"  : __DIR__"hengyang",
	]));
	set("objects", ([
		"/clone/misc/dache" : 1,
	]));
	set("outdoors", "henshan");
	set("no_clean_up", 0);
	set("coor/x", -300);
	set("coor/y", -1190);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
