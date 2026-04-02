// Room: /d/nanshaolin/xumidian.c
// Last Modified by winder on May. 29 2001

#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
	set("short", CYN"須彌殿"NOR);
	set("long", @LONG
一間寬敞的佛殿四壁空蕩蕩的，正中是一張青石屏風，繪有一座
高聳入雲的險峯，白雲繚繞，峯腳下則是一枚芥子。想是取佛家須彌
芥子之典故，佛法修為可將須彌之巨容入芥子之中。屏風前擺着幾個
蒲團，幾位僧人正自對着屏風反睛內視，勤修內功。
LONG );
	set("exits", ([
		"east" : __DIR__"dabeidian",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1800);
	set("coor/y", -6200);
	set("coor/z", 10);
	setup();
}

void init()
{
	this_player()->set_temp("ns_times", 10);
	add_action("do_neishi", "neishi");
}

int do_neishi()
{
 object  me = this_player();
 int lvl = me->query_skill("force", 1);

	me->add_temp("mx_times", -1);	
	message_vision("$N盤膝坐下閉目垂簾意守丹田修煉內功。\n", me);
	if ((int)me->query("jing")<20)
	{
		write(RED"你太累了精力無法集中。\n"NOR);
		return 1;
	} 
	if (lvl >= 30 && lvl <= 100 && present("xisui", me) )
	{
		me->receive_damage("jing", 20);
		me->improve_skill("force", me->query("int"));
		tell_object(me, RED"你內視靜想一股內息自曲骨，中極，關元，石門直通而上。\n經過一個小周天運行貯於氣海膻中。\n"NOR);
	}
	else tell_object(me,RED"你越想越糊塗，內息亂竄，只好站起身來。\n"NOR);
	return 1;
} 

int valid_leave(object me, string dir)
{
	if(me->query_temp("mx_times") >= 0 ) me->delete_temp("mx_times");
	return ::valid_leave(me, dir);
}