// Room: /d/huashan/pingdi.c
// Last Modified by winder on Aug. 1 2002

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "山間平地");
	set("long", @LONG
你走在中條山山間平地上。靠東山壁上有一小屋。傳聞當年華山玉
女峯劍氣兩宗大對決，中計敗北的劍宗弟子大多隱匿中條山。難道就是
這裏？林中冷風輕吹門響。很失意的感覺。
LONG );
	set("exits", ([ /* sizeof() == 4 */
		"east"  : __DIR__"xiaowu",
		"north" : __DIR__"shangu",
	]));
	set("outdoors", "zhongtiao");
	set("no_clean_up", 0);

	set("coor/x", -930);
	set("coor/y", 170);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}
