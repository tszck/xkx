// Room: /d/nanshaolin/wusetai.c
// Last Modified by winder on May. 29 2001

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{ 
	set("short",HIG"無色臺"NOR);
	set("long", @LONG
這裏是無色禪師的靈臺內部，靈室顯得十分空曠。正中有一張靈案
(lingan)，上書“洛鐘東應”四個大字，乃是無色大師生前親手所書。
筆勢遒勁，大舒大展如同一套極高明的拳法。雖然置身暗室，你卻覺的
靈臺一片空明，似有光芒自心底發出。
LONG );
	set("exits", ([
		"out" : __DIR__"fota2",				
	]));
	set("no_clean_up", 0);
	setup();
}
void init()
{
	add_action("do_study","study");
}
int do_study(string arg)
{
	object me = this_player();
	int lvl = me->query_skill("cuff", 1), exp = me->query("combat_exp");
	if (arg!="lingan") return 0;
	if (!living(me)) return 0;
        message("vision", me->name()+"正在專心的學習靈案上的書法。\n", environment(me), ({me}) );
	if (lvl < 30)
	{
		write(HIR"你看着案上的書法，心中似有所悟，但畢竟拳法修為尚淺，什麼也沒領悟到。\n"NOR);
		return 1;
	}
	if (lvl * lvl * lvl / 10 < exp)
	{
		write(HIR"你看着案上的書法，心中似有所悟，但畢竟經驗尚淺，什麼也沒領悟到。\n"NOR);
		return 1;
	}
	if (lvl > 100)
	{
		write("你已盡數領悟透了案上書法的含義。\n");
		return 1;
	}
        if (lvl >= 30 && lvl <= 100 && arg=="lingan" )
	{
		if ((int)me->query("jing")<30)
		{
			me->unconcious();     
			return 0;
		}
		me->receive_damage("jing", 30);
		me->improve_skill("cuff", (me->query("int"))*3/2);
		write("你看着案上那筆走龍蛇般的大字，對基本拳法有所領悟。\n");
		return 1;
	}
}

