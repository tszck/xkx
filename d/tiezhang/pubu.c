// Room: /d/tiezhang/pubu.c
// Last Modified by winder on Nov. 17 2000

#include <ansi.h>
inherit ROOM;
void init()
{
	add_action("lingwu","lingwu");
}
void create()
{
	set("short", HIC"瀑布"NOR);
	set("long", @LONG
山路行到這裏，忽聽遠處傳來隱隱水聲，轉過一道山樑，只見一道
白龍似的大瀑布從對面雙峯之間奔騰而下，空山寂寂，那水聲在山谷中
激盪迴響，聲勢甚是驚人。
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"northup"  : __DIR__"xzfeng",
		"eastdown" : __DIR__"sblu1",
	]));
	set("no_clean_up", 0);
	set("outdoors", "tiezhang");
	set("coor/x", -2070);
	set("coor/y", -1910);
	set("coor/z", 80);
	setup();
}

int lingwu(string arg)
{
	object me=this_player();
	string special;
	int bl,sl;

	if (!living(me)) return 0;
	if (me->is_busy() || me->is_fighting())
		 return notify_fail("你正忙着呢。\n");
//	if(!me->query("luohan_winner")) return notify_fail("你級別不夠，不能在此領悟。\n");
	if (!arg) return notify_fail("你要領悟什麼？\n");
	if (me->query_skill(arg,1) < 100)
		return notify_fail("你的根基不夠領悟這種技能。\n");
	if (me->query_skill(arg,1) > 150)
		return notify_fail("你已經不能在這裏領悟這項技能了。\n");
	if (!(special=me->query_skill_mapped(arg)))
		return notify_fail("你只能從特殊技能中領悟基本技能。\n");
	bl=me->query_skill(arg,1);
	if (bl > me->query("jing") ||
		me->query("jing")*100/me->query("max_jing") < 20)
	{
		me->receive_damage("jing",bl/2);
		return notify_fail("你沒辦法集中精神。\n");
	}
	sl=me->query_skill(special,1);
	if (bl > sl)
		return notify_fail("你的"+ to_chinese(special)+"造詣不夠，無法領悟更深一層的"+CHINESE_D->chinese(arg)+"。\n");
	write("你瞑思苦想，對"+to_chinese(arg)+"的體會又深了一層。\n");
	me->receive_damage("jing",bl/3);
	me->improve_skill(arg,sl/5+1);
	return 1;
}
