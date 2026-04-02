// midao1.c

inherit ROOM;

void create()
{
	set("short", "密道");
	set("long", @LONG
你的眼前是一條用漢白玉鋪成的臺階，一直向下延伸，兩邊的牆壁
都是花崗巖，牆上隔十來步就有一盞油燈，使你能看清周圍。
LONG );
	set("exits", ([
		"up" : __DIR__"huayuan",
		"northdown": __DIR__"midao2",
	]));
	set("objects",([
		__DIR__"npc/nvlang" : 1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", -51000);
	set("coor/y", 30150);
	set("coor/z", 50);
	setup();
}

int valid_leave(object me, string dir)
{
	if ( (dir == "northdown") &&
		((string)me->query("family/family_name") != "逍遙派") &&
		((string)me->query("family/family_name") != "靈鷲宮") &&
		objectp(present("nv lang", environment(me))) )
		return notify_fail("蒙面女郎伸手攔住你，說道：“對不起，本門重地，請回！”\n");
	return ::valid_leave(me, dir);
}