// Room: /d/nanshaolin/xiaoxi1.c
// Last Modified by winder on May. 29 2001

inherit ROOM;
#include <ansi.h>
int do_jump(string arg);

void create()
{
	set("short", "溪旁空地");
	set("long", @LONG
這是溪旁的一塊空地，地上綠草茵茵，間或點綴着一些叫不出名子
的野山花。遠處樹林中隱隱露出一片紅牆，看來這裏已經是寺中邊緣地
帶了。前面較爲寬敞的地方，有一棟歇山重檐，高二層，建築古樸的樓
閣，樓中懸一方橫匾，上書『藏經閣』三個字。
    西邊是一條小溪。
LONG );
	set("exits", ([
		"enter" : __DIR__"cjlou",
	]));
	set("outdoors", "nanshaolin");
	set("no_clean_up", 0);
	set("coor/x", 1880);
	set("coor/y", -6150);
	set("coor/z", 20);
	setup();
}

void init()
{
	add_action("do_jump", "jump");
	add_action("do_jump", "yue");
}

int do_jump(string arg)
{
	object me = this_player();

	if (arg == "river" || arg == "xiaoxi")
	{
		if (me->query_skill("dodge", 1) >= 60)
		{
			message("vision", me->name() + "吸了口氣，縱身向對面躍去。\n", environment(me), ({me}) );
			write("你吸了口氣，縱身向對面躍去。\n");
			me->move(__DIR__"xiaoxi");
			message("vision", "只見人影一閃，"+me->name() +"縱身躍了過來。\n", environment(me), ({me}) );
			return 1;
		}
		else
		{
			message("vision", me->name()+"縱身向對面躍去，只聽“撲通”一聲，"+me->name()+"摔入溪中，狼狽的爬了回來。\n",environment(me),({me}));
			write( "你縱身向對面躍去，只聽“撲通”一聲，你摔入溪中，狼狽的爬了回來。\n");
			me->receive_damage("qi",30);
			return 1;
		}
	}
	return 0;
}


