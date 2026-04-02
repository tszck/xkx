// Room: /d/chengdu/chunxilu2.c
// Last Modifyed by Winder on Jan. 4 2002

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short",HIY "春熙路" NOR);
	set("long", @LONG
你走在一條熱鬧的大道上，街上人羣熙熙攘攘，可得當心小偷哦。
東面是個打鐵鋪子，西面有個錢莊，西南方有條青石巷。
LONG );
	set("outdoors", "chengdu");
	set("exits", ([
		"south" : __DIR__"chunxilu3",
		"north" : __DIR__"chunxilu1",
		"east"  : __DIR__"datiepu",
		"west"  : __DIR__"qianzhuang",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8060);
	set("coor/y", -2980);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);       
}

