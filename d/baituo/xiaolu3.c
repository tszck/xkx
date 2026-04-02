// Room: /d/baituo/xiaolu3.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
這裏是一條上山的小路。小路兩邊雜草叢生，看來少有行人。不過
路泥卻甚是平滑，倒象常有人來往一般。聽説東北方有山賊出沒，要格
外小心。
LONG	);
	set("outdoors", "baituo");
	set("exits", ([
		"northeast" : __DIR__"xiaolu4",
		"southdown" : __DIR__"xiaolu2",
	]));
	set("objects",([
		__DIR__"npc/shanzei1" : 1,
	]));
	set("coor/x", -49970);
	set("coor/y", 20010);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
