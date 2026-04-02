#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "戲臺");
	set("long", @LONG
這裏是戲臺，雖然有些小，但是很乾淨。一個戲子正在表演。你一
踏上戲臺，情不自禁地就唱起歌來。
LONG );
	set("exits", ([
		"down"      : __DIR__"xiyuan",
	        "southdown" :__DIR__"houtai",
	]));
	set("objects", ([
		__DIR__"npc/xizi": 1,
	]));
	set("coor/x", -200);
	set("coor/y", 4060);
	set("coor/z", 10);
	setup();
}

int valid_leave(object me, string dir)
{
	int i;
	if(dir=="down")
	{
		message_vision("\n$N一曲唱罷，一揖作禮，身子平飛，從臺上躍出，雙手兀自\n抱拳向觀眾行禮，姿態美妙，眾人齊聲喝采。\n", me);
		i= me->query("meili");
		if(i<20) 
		{
			i=i+10;
			me->set("meili",i);
			message_vision(HIC "\n$N的魅力值提高了。\n" NOR, me);
		}
	}
	this_player()->delete_temp("hastryup");
	return ::valid_leave(me, dir);
}
