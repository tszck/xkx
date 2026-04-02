// sheshenya.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;

void create()
{
	set("short", "捨身崖");
	set("long", @LONG
這是一段極窄極險的山崖，四周雲霧飛繞，下面淵深無底。如不小
心，一失足掉下去，只怕連骨頭都找不到。邊上有個小山洞(dong)。
LONG );
	set("exits", ([ /* sizeof() == 1 */
		"eastdown" : __DIR__"canglong",
	]));
	set("item_desc", ([
		"dong" : "緊靠飛崖下石壁的小洞，黑呼呼的不知有多深。\n",
	]));
	set("objects",([
		__DIR__"npc/referee" : 1,
	]));
	set("outdoors", "huashan" );

	set("coor/x", -890);
	set("coor/y", 210);
	set("coor/z", 110);
	setup();
}

void init()
{
	object me = this_player();
	add_action("do_enter", "enter");
	add_action("do_enter", "zuan");
	if (me->query_temp("xunshan")) me->set_temp("xunshan/sheshen", 1);
	return;
}

int do_enter(string arg)
{
	object me = this_player();
	mapping fam;

	if( !arg || arg=="" ) return 0;
	if( arg=="dong" )
	{
		if( (fam = me->query("family")) && fam["family_name"] == "丐幫")
		{
			message("vision", me->name() + "運起丐幫縮骨功，一彎腰往洞裏鑽了進去。", environment(me), ({me}) );
			me->move("/d/gaibang/underhs");
			message("vision", me->name() + "從洞裏走了進來。\n", environment(me), ({me}) );
			return 1;
		}
		else  return notify_fail("這麼小的洞，你鑽得進去嗎？\n");
	}
}
