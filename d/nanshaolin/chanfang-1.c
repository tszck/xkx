// Room: /d/nanshaolin/chanfang-1.c
// Last Modified by Winder on May. 29 2001

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "禪房");
	set("long", @LONG
這裏是誦經的禪房。房中有一座小香爐，淡淡的清煙從中散出，彌
漫在整間房內。陽光透過窗格照在青石地上，在青煙中形成根根耀眼的
光柱。屋中的地上散放着幾個蒲團，幾個年青的僧人正閉目打坐於其上。
LONG
	);
	set("exits", ([
		"north" : __DIR__"chanfang-2",
		"south" : __DIR__"chanfang-3",
		"east"  : __DIR__"zdyuan",
	]));
	set("objects", ([
		CLASS_D("nanshaolin") + "/dafeng" : 1,
	]));
	set("no_fight", 1);
	set("coor/x", 1790);
	set("coor/y", -6270);
	set("coor/z", 10);
	setup();
//	replace_program(ROOM);
}
void init()
{
	  add_action("do_ask", "chanwu");
}
int do_ask()
{
	object me;
	me = this_player();
	if ((int)me->query("jing")<35)
	{
		write(RED"你太累了精力無法集中。\n"NOR);
		return 1;
	} 
	if ((int)me->query_skill("buddhism",1)<50 &&
		present("moheseng dilu", me) )
	{
		write("你的禪宗修為不到，無法在此領悟禪理。\n");
		return 1;
	}
	if ((int)me->query_skill("buddhism",1)>101
		&& present("moheseng dilu", me) )    
	{
		write("大瘋大師低聲説道："+ RANK_D->query_respect(this_player()) +"的佛法已頗為淵深，已不需老衲指點。\n");
		return 1;
	}
	if ((int)me->query_skill("buddhism", 1) >= 50 &&
		(int)me->query_skill("buddhism", 1) <= 101 &&
		present("moheseng dilu", me) )
	{
		me->receive_damage("jing", 35);
		me->improve_skill("buddhism", me->query("int"));
		if ( random(5) == 0 )
			tell_object(me, RED"你聽了大瘋大師對於禪悟的講解，頓時覺得禪宗心法有所提高。\n"NOR);
	}
	return 1;
} 
