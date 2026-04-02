// Room: /d/baituo/xiaolu4.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
這裏是一條上山的小路。小路兩邊雜草叢生，看來少有行人。不過
路泥卻甚是平滑，倒象常有人來往一般。你不禁有點猶豫。從這裏，上
山的小路向西分出一條岔道。北邊是山賊的老窩。
LONG	);
	set("outdoors", "baituo");
	set("exits", ([
		"north"     : __DIR__"dongkou",
		"southwest" : __DIR__"xiaolu3",
		"westdown"  : "/d/npc/m_weapon/lianzhangshi",
	]));
	set("objects",([
		__DIR__"npc/shanzei2" : 1,
	]));
	set("coor/x", -49960);
	set("coor/y", 20020);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
