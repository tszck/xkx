// Room: /d/henshan/wangyuetai.c
// Modified By Java Feb.14.1998

#include <room.h>
inherit ROOM;
void create()
{
        set("short", "望月臺");
        set("long", @LONG
望月臺是祝融殿後一高聳巨石。每當夜籟，皓月當空，猶如玉盤冰
輪，漫灑萬裏清輝，清冷月色，輝映低昂的羣峯。此時 "浩然萬裏，舉
七十二峯，峯峯貯冰壺中，始信下方無此月也。" 前人因此有詩: 人間
朗魄已皆盡，此地清光猶未低。
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "southup"    : __DIR__"zhurongdian",
        ]));
        set("outdoors", "henshan");
        set("no_clean_up", 0);
	set("coor/x", -310);
	set("coor/y", -980);
	set("coor/z", 40);
	setup();
        replace_program(ROOM);
}
