// Room: /d/baituo/ximen.c
// Last Modified by winder on May. 15 2001

inherit ROOM;
void create()
{
	set("short","西門");
	set("long", @LONG
這是個白駝山莊的西門。拱月形的竹門分外雅緻，門上掛着一塊竹
牌 (pai)。西門外面雜草叢生。
LONG	);
	set("exits",([
		"west" : __DIR__"cao1",
		"east" : __DIR__"changlang",
	]));
	set("item_desc",([
		"pai" : "西門外面有毒蛇出沒，慎行。\n" ,
	]));
	set("objects",([
		__DIR__"npc/menwei" : 1,
	]));
	set("outdoors", "baituo");
	set("coor/x", -50030);
	set("coor/y", 20040);
	set("coor/z", 30);
	setup();
}

int valid_leave(object me, string dir)
{
	if( (dir == "east") && ((int)me->query("shen")>300) &&
		objectp(present("men wei", environment(me))) )
		return notify_fail("門衞把手一攔：你不能進去！\n");
	if( (dir == "west") &&((int)me->query("combat_exp") < 300) &&
		objectp(present("men wei", environment(me))) )
		return notify_fail("門衞把手一攔：你的經驗太低，會被毒蛇咬死的！還是不要亂闖的好。\n");
	return ::valid_leave(me, dir);
}

