// Room: /d/tiezhang/juebi1.c
// Last Modified by winder on Nov. 17 2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "絕壁");
	set("long", @LONG
你走到這裏，發現前面已經沒有路了。你面前是一座立陡的山峯，
高聳入雲，看不到盡頭。石壁上生長着很多松樹，疾風吹來，沙沙作響。
看來想上峯頂，只能爬上去了。
LONG	);
	set("exits", ([ /* sizeof() == 1 */
		"southwest" : __DIR__"shangu2",
	]));
	set("no_clean_up", 0);
	set("outdoors", "tiezhang");
	set("coor/x", -2010);
	set("coor/y", -1880);
	set("coor/z", 50);
	setup();
}

void init()
{
	add_action("do_zhua","zhua");
	add_action("do_climb","climb");
}

int do_zhua(string arg)
{
	object me;
	me=this_player();
    
	if (arg =="松樹")
	{
		write("你牢牢的抓住石壁上的松樹。\n");
		this_player()->set_temp("marks/抓1", 1);
		return 1;
	}
	return notify_fail("你要抓什麼？\n");
}

int do_climb(string arg)
{
	mapping fam;
	object me;
	me=this_player();

	if ( (int)me->query_skill("dodge", 1) < 30)
		return notify_fail("你的輕功不夠，無法爬上去。\n");

	if (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "鐵掌幫")
		return notify_fail("你非本幫弟子，不能上峯！\n");

	if (!me->query_temp("marks/抓1") )
		return notify_fail("無處攀緣，好象爬不上去。\n");
	if (arg =="up")
	{
		write("你吸了口氣，小心的向上爬去。\n");
		message("vision",me->name() + "向上一縱突然不見了。\n", environment(me), ({me}) );
		me->move(__DIR__"juebi2");
		message("vision", me->name() + "爬了上來。\n", environment(me), ({me}) );
		me->delete_temp("marks/抓1");
		if ((int)me->query_skill("dodge",1)>100)
			write("你覺得很難從中領悟到輕功身法。\n");
		else
		{
			me->receive_damage("qi", 40);
			me->improve_skill("dodge",me->query("int"));
		}
		return 1;
	}
	return notify_fail("你要往哪兒爬？\n");
}
