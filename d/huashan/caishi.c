// caishi.c
// Last Modified by winder on Aug. 1 2002

#include <ansi.h>
inherit ROOM;

int do_cai(string arg);

void create()
{
	set("short", "採石場");
	set("long", @LONG
這裏是位於華山腳下的採石場，一羣羣人不停地來回穿梭忙碌着，
累得滿頭大汗，遠處有個大櫃檯，一個老闆模樣的人坐在臺前，仔細的
打着算盤給人結帳，身邊圍了一些人。
LONG);
	set("exits", ([
		"north" : __DIR__"path1",
	]));
	set("objects",([
		__DIR__"npc/zhanggui":1,
	]));
	set("coor/x", -920);
	set("coor/y", 260);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_cai","cai");
}

int do_cai(string arg)
{
	int i;
	object weapon,me = this_player();
	if (!arg || (arg != "stone" && arg != "石頭"))
		return notify_fail("你要採什麼？\n");
	if (!objectp(weapon = me->query_temp("weapon")) ||
		weapon->query("name") != "鐵錘")
		return notify_fail(RED"你手都磨破了，卻什麼也沒做成。\n"NOR);
	if (me->query_temp("caishi/count")<1)
		return notify_fail("這裏不關你的事，還是走遠點吧！\n");
	if (me->query_temp("caishi/count")>4) 
	{
		me->set_temp("caishi/finish",1);
		return notify_fail("你已經採得差不多了，該向老闆交工了！\n");
	}
	if (me->query("qi")<30)
		return notify_fail("你快支持不住了，先歇會兒吧！\n");
	if (me->is_busy()) return notify_fail ("（你上個動作還沒完成，不能進行下一個動作！）\n");
	me->add("qi",-15);
	me->add_temp("caishi/count",1);
	i=random(4);
	message_vision(YEL"$N舉起鐵錘，對準石頭狠狠地砸了下去。\n"NOR,me);
	if (i<1)
		tell_object(me,"你用力過猛，震得虎口發麻，險些摔了一交。\n");
	else if (i==2) tell_object(me, "你狠狠一錘，騰騰騰倒退了幾步，差點沒站穩。\n");
	else tell_object(me, "你用力一錘砸下，“喀”地應聲落下一塊石頭來。\n");
	me->start_busy(1);
	return 1;
}
