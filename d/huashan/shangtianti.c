// shangtianti.c
// Last Modified by winder on Aug. 1 2002

#include <room.h>
inherit ROOM;
void create()
{
	set("short", "上天梯");
	set("long", @LONG
此處絕險，必須面壁挽索，貼身探足前進，步不登高，故名“上天
梯”。北面是下山的路，往南面是金鎖關。西面上去可以通達北峯雲臺
峯。
LONG );
	set("exits", ([ /* sizeof() == 4 */
		"westup"    : __DIR__"canglong",
		"southup"   : __DIR__"jinsuo",
		"northdown" : __DIR__"husun",
	]));
	set("no_clean_up", 0);
	set("outdoors", "huashan");
	set("coor/x", -870);
	set("coor/y", 210);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}
