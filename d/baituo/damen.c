// Room: /d/baituo/damen.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short", "大門");
	set("long", @LONG
這就是聞名天下的『白駝山莊』的大門。大門樑上雕龍刻鳳，美奐
美崙，不知凝聚着多少能工巧匠的心血。更顯出莊主的富有與顯貴。門
前左右各蹲着一隻威武莊嚴的石獅子。
LONG	);
	set("outdoors", "baituo");
	set("exits", ([
		"north" : __DIR__"kongdi",
		"southdown" : __DIR__"shijie",
	]));
	set("objects",([
		__DIR__"npc/menwei" : 2,
		CLASS_D("baituo")+"/first" :1,
	]));
	set("coor/x", -50010);
	set("coor/y", 20010);
	set("coor/z", 20);
	setup();
}

int valid_leave(object me, string dir)
{
	if (  (dir == "north") && ((int)me->query("shen") > 300) &&
		objectp(present("men wei", environment(me))) &&
		living(present("men wei", environment(me))))
		return notify_fail("門衞把手一攔：你這種正派人物，老子一看就噁心，快滾！\n");
	return ::valid_leave(me, dir);
}
