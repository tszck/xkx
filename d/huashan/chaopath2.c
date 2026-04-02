// Room: chaopath2.c 朝陽峯小路
//Date: Oct. 2 1997 by Venus

inherit ROOM;

void create()
{
	set("short","朝陽峯小路");
	set("long",@LONG
這裏是朝陽峯小路，山勢陡峭，兩邊下臨深谷，一不小心都會掉了
下去。西面有一條小路，長草沒徑。
LONG);
	set("outdoors", "huashan");
	set("exits",([ /* sizeof() == 1 */
		"eastup"   : __DIR__"chaoyang",
		"westup"   : __DIR__"ziqitai",
		"southwest": __DIR__"chaopath1",
	]));
	set("objects", ([
		__DIR__"npc/shi-daizi" : 1,
	]));
	set("coor/x", -860);
	set("coor/y", 220);
	set("coor/z", 120);
	setup();
}
 
void init()
{
	object me = this_player();
	if (me->query_temp("xunshan")) me->set_temp("xunshan/chaoyang", 1);
	return;
}

int valid_leave(object me, string dir)
{
	if (dir=="eastup" &&
		objectp(present("shi daizi", environment(me))) &&
		(me->query("family/master_id")!="gao laozhe") &&
		(me->query("family/master_id")!="ai laozhe"))
		return notify_fail("施戴子喝道：上面是兩位長老清修之處，這位" + RANK_D->query_respect(me) + "請止步！\n");
	return ::valid_leave(me, dir);
}
