// /d/xingxiu/nanjiang.c
// Last Modified by winder on Feb. 28 2001

inherit ROOM;

void create()
{
	set("short", "南疆沙漠");
	set("long", @LONG
這就是浩瀚的塔克拉馬幹大沙漠，一走進來，你彷彿迷失了方向。
你感到口內十分焦渴，還是快些離開吧。
LONG );
	set("outdoors", "xiyu");
	set("exits", ([
		"northeast" : __DIR__"luzhou",
		"southeast" : __FILE__,
		"southwest" : __FILE__,
		"northwest" : __FILE__,
		"north"     : __FILE__,
		"south"     : __FILE__,
		"west"      : __FILE__,
		"east"      : __FILE__,
	]));
	set("no_clean_up", 0);
	set("coor/x", -41010);
	set("coor/y", 8990);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	int current_water;

	current_water = me->query("water");
	if (current_water==0)
	{
	}

	if (current_water>0 && current_water<20&& userp(me))
	{
		me->set("water",0);
	}

	if (current_water>20&& userp(me))
	{
		me->set("water",current_water-20);
	}
	if (dir=="east" || dir=="south" || dir=="west" || dir=="north") 
		return notify_fail("你向那邊走去，結果發現那是沙漠中的海市蜃樓。\n");
	return ::valid_leave(me, dir);
}
