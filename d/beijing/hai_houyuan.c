// /beijing/hai_houyuan.c
// Last modified by winder 2003.10.10

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short","海澄公府後院");
	set("long", @LONG
這裏是海澄公府大廳後側的一個小花園，雜亂地種着各種花草，看
來無人打理，雜草已經長得很高了。一些鮮花夾雜在草叢中，陣陣花香
不斷地飄過。
LONG );
	set("exits", ([
		"north" : __DIR__"hai_dating",
	]));

	set("no_clean_up", 0);
	set("outdoors", "beijing");
	set("coor/x", -230);
	set("coor/y", 4030);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
