//lhqhoumen.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "烈火旗後門");
	set("long", @LONG
這裏就是烈火旗的後門，後面就是明教總舵所在，門宇軒大，教衆
出入紛紛。由於地處緊要，這裏的關防也很嚴密。
LONG );
	set("exits", ([
		"northup"   : __DIR__"zhandao1",
		"southdown" : __DIR__"lhqyuan",
	]));
	set("objects", ([
		__DIR__"npc/tuoba" : 1,
	]));
	set("outdoors", "mingjiao");
	set("no_clean_up", 0);
	set("coor/x", -52030);
	set("coor/y", 1010);
	set("coor/z", 70);
	setup();
}
int valid_leave(object me, string dir)
{
	me = this_player();
	if ((me->query("party/party_name")!=HIG "明教" NOR) &&
		(dir=="northup") &&
		(objectp(present("tuoba", environment(me)))))
		return notify_fail("拓跋攔住你說：此處乃明教重地，請止步。\n");
	return ::valid_leave(me, dir);
}