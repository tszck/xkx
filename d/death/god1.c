// Room: god1

#include <ansi.h>
inherit ROOM;
inherit SKILL;

void create()
{
	set("short", HIY"天庭"NOR);
	set("long", HIC @LONG
這裏就是天庭。祥雲朵朵，色澤潔白無瑕，慢慢從你眼前飄過，那
翠綠色一片的草地上開滿了色彩各異的鮮花，香氣繚繞不散，聞着看着，
你都快要醉了。遠處一棟潔白的宮殿，巍然聳入雲霄，從那兒傳來陣陣
仙樂，音律和祥悅耳，聽着聽着，你覺得自己的心靈都已得了到淨化，
從此脫離了凡塵俗世……。這兒的一切都令你覺得安然、陶醉、寧靜、
和祥……
LONG
NOR   );
	set("no_clean_up", 0);
	setup();
}

void reset()
{
	::reset();
	set("exits", ([ /* sizeof() == 2 */
		"up"   : __DIR__"god2",
		"down" : "/d/city/wumiao",
	]));
}

int valid_leave(object me, string dir)
{
	switch(dir)
	{
		case "up":
			write(HIC"你心如明鏡，慢慢走向聖殿。\n"NOR);
			return 1;
		case "down":
			write(HIW"你要返回凡塵俗世了嗎？……\n\n"NOR);
			break;
		default:
			write(HIG"唉……你既然心意已決，那就去吧……\n\n"NOR);
	}
	write(HIB"去吧……去吧……一個聲音輕輕地說道。\n\n\n\n"NOR);
	write(HIY"你腳下忽然升起一朵祥雲，你一踏上去，就慢慢向下飄去了，……\n\n\n\n"NOR);
	me->reincarnate();
/*
	me->add("combat_exp", (int)me->query("combat_exp") / 49);
	me->add("potential", 50);
	me->add("max_neili", 2);
	me->set("eff_jing",(int)me->query("max_jing"));
	me->set("eff_qi",(int)me->query("max_qi"));
	me->set("jing",(int)me->query("eff_jing"));
	me->set("qi",(int)me->query("eff_qi"));
	me->skillreincarnate();
*/
	return 1;
}
