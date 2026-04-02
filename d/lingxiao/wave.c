// Room: /d/lingxiao/wave.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short","冰洞");
	set("long",@LONG
蛇！一條足有水桶粗的白蛇，正橫臥在冰洞正中，望見有人進來，
呼地一聲直立起來，吐出血紅的信子，徑直撲了過來。帶過來一股腥臭
的味道。旁邊一面冰壁很薄，隱約可見裏面有什麼東西。
LONG);
	set("exits",([ /* sizeof() == 1 */
		"out" : __DIR__"wave2", 
	])); 
	set("objects", ([
		__DIR__"npc/snake" : 1, 
	]));
	set("coor/x", -31030);
	set("coor/y", -8950);
	set("coor/z", 100);
	setup();
}

void init()
{
	add_action("do_break", "break");
}
int do_break(string arg)
{
	object me = this_player();

	message_vision(HIC"$N走到冰壁前，運勁向冰壁轟去！\n"NOR,me);
	if (me->query("neili") < 500)
	{
		message_vision( HIC"結果只聽一聲悶哼，$N被冰壁的寒氣回侵經脈，眼前一黑....\n"NOR,me);
		me->set("neili",0);
		me->unconcious();
		return 1;
	}
	message_vision(CYN"$N只聽一聲轟響，冰壁被轟穿了，露出一個小洞來！\n"NOR,me);
	set("exits/enter",__DIR__"yudong");
	me->add("neili",-100);
	remove_call_out("close");
	call_out("close", 5, this_object());
	return 1;
}
void close_out()
{
	if (query("exits/enter")) delete("exits/enter");
}

void close(object room)
{
	message("vision",HIC"一股寒氣自洞中冒出，將洞口又凍了個嚴嚴實實。\n"NOR, room);
	room->delete("exits/enter");
}

