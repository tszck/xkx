// Room: /d/tiezhang/wuchang.c
// Last Modified by winder on Nov. 17 2000

#include <ansi.h>

inherit ROOM;
//void init();
//int do_chazhi();

void create()
{
        set("short",HIC"武場"NOR);
	set("long", @LONG
這是一片平地，樹着些練功器具。鐵掌幫衆正在熱火朝天地練功。
LONG
	);
        set("exits", ([ 
		"west" : __DIR__"zoulang4",
	]));
	set("objects",([
		"/d/shaolin/npc/mu-ren" : 5,
	]));
	set("coor/x", -2010);
	set("coor/y", -1960);
	set("coor/z", 30);
	setup();
}

void init()
{
	add_action("do_chazhi", "chazhi");
}


int do_chazhi(string arg)
{       
        mapping fam;
	object me;
        me = this_player();

	if (!living(me)) return 0;
	if ( !living(this_player()) || arg != "huo" )
	{
		write("你想往哪兒插呀！\n");
		return 1;
	}
	if (!(fam = me->query("family")) || fam["family_name"] != "鐵掌幫")
		return notify_fail("你非本幫弟子，不能在此練功！\n");

	if ( (int)me->query_skill("strike", 1) > 100)
		return notify_fail("你將雙手插入鑊中，發現鐵沙的溫度對你來說太低，已毫無意義了。\n");
 
	if((int)me->query("qi")<30)
	{
		me->receive_damage("qi",10);
		write("你覺得一股熱氣直逼上來，焦燥難當！\n");
		me->unconcious();
		return 1;
	}
	me->receive_damage("qi", random(40));
	me->improve_skill("strike", me->query("int"));
	message_vision("$N將雙手插進鑊中的鐵沙裏。\n", me);
	write("灼熱的鐵沙將你的雙手燙得通紅，你覺得雙手變得強壯有力。\n");
	return 1;
}
