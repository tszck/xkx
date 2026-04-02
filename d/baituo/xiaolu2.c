// Room: /d/baituo/xiaolu2.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
這裏是一條上山的小路。小路兩邊雜草叢生，看來少有行人。不過
路泥卻甚是平滑，倒象常有人來往一般。你不禁有點猶豫。
LONG	);
	set("outdoors", "baituo");
	set("exits", ([
		"northup"   : __DIR__"xiaolu3",
		"southdown" : __DIR__"xiaolu1",
	]));
	set("objects",([
		__DIR__"npc/man" : 1,
	]));
	set("coor/x", -49970);
	set("coor/y", 20000);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
