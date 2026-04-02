#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "小房間");
	set("long", @LONG
這是一個小房間，桌上點着蠟燭。房中只有一桌一牀，陳設簡單，
卻十分乾淨，牀上鋪着被褥。
LONG );
	set("exits", ([
		"south" : __DIR__"zhuang8",
	]));
	set("objects", ([
		__DIR__"npc/furen": 1,
		__DIR__"npc/shuanger": 1,
	]));
	set("coor/x", 100);
	set("coor/y", 4740);
	set("coor/z", 0);
	setup();
	replace_program(ROOM); 
}
