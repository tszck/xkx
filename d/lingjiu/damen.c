//ROOM damen.c

inherit ROOM;

void create()
{
	set("short", "獨尊廳大門");
	set("long",@LONG
這就是通向『靈鷲宮』獨尊廳的大門。大門左右各有一頭石雕的猛
鷲，高達三丈有餘，尖喙巨爪，神駿非凡，栩栩如生，似乎隨時要騰空
而去。
LONG );
	set("outdoors", "lingjiu");
	set("exits", ([
		"north" : __DIR__"dating",
		"south" : __DIR__"dadao2",
	]));
	set("objects",([
		CLASS_D("lingjiu") + "/meijian" : 1,
		__DIR__"npc/lanjian" : 1,
	]));
	set("coor/x", -51000);
	set("coor/y", 30120);
	set("coor/z", 70);
	setup();
}
int valid_leave(object me, string dir)
{
	if ( (dir == "north") &&
		((string)me->query("family/family_name") != "逍遙派") &&
		((string)me->query("family/family_name") != "靈鷲宮") &&
		( objectp(present("mei jian", environment(me))) ||
		objectp(present("lan jian", environment(me))) ) )
		return notify_fail("梅蘭雙姝伸手攔住你，説道：“非逍遙弟子請回！”\n");
	return ::valid_leave(me, dir);
}