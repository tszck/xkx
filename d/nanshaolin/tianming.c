// Room: /d/nanshaolin/tianming.c
// Last Modified by winder on May. 29 2001

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{ 
	set("short",CYN"天鳴禪臺"NOR);
	set("long", @LONG
一間寬敞空曠的石室，室中只有一張石牀，四壁如素。抬頭望去，
樑上雕着一隻石鷹，振翅欲飛。鷹爪間垂下幾條粗如兒臂的大繩。大師
是無色無相等的師叔。前輩高僧當年執掌少林佛法淵深，名震天下。天
鳴大師晚年修為更為精進，為重新修訂少林爪法(claw)絕技。於此石室
內閉關經年，坐化於此。其絕世武功湮沒於空室之中。
LONG );
	set("exits", ([
		"out" : __DIR__"fota2",	 
	]));
	set("no_clean_up", 0);
	setup();
}
void init()
{
	add_action("do_claw","claw");
}
int do_claw(string arg)
{
	object me = this_player();
	int lvl = me->query_skill("claw", 1), exp = me->query("combat_exp");
	if (arg!="sheng") return 0;
	if (!living(me)) return 0;
	message("vision", me->name()+"身形飄起，一式振翅迎風，向大繩上抓去。\n", environment(me), ({me}) );
	if (lvl<30)
	{
		write(HIR"你手上乏力，雖然抓住大繩，但隨既痠軟，連忙放開。\n"NOR);
		return 1;
	}
	if (lvl * lvl * lvl / 10 < exp)
	{
		write(HIR"你經驗太淺，沒法夠着大繩。\n"NOR);
		return 1;
	}
	if (lvl>100)
	{
		write(HIR"你用力過猛，大繩從中斷絕。\n"NOR);
		return 1;
	}
	if (lvl >= 30 && lvl <= 100 && arg=="sheng" )
	{
		if ((int)me->query("jing")<30)
		{
			me->unconcious();     
			return 0;
		}
		me->receive_damage("jing", 30);
		me->improve_skill("claw", (me->query("int"))*3/2);
		write(HIR"你攀住大繩，手爪上使力向上，直到鷹下，你仰望神鷹體態，只覺對爪法頗有領悟。\n"NOR);
		return 1;
	}
}

