// /kaifeng/jiaolou1.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "西角樓");
	set("long", @LONG
角樓是建於城牆之上，用於兵衛守望的處所，只在樓的頂端掛上一
盞燈籠，從此遠眺，遠處山水亭臺，一一在目，西面下去就是西大街。
路上來往的行人不斷。
LONG);
	set("no_clean_up", 0);
	set("exits", ([
		"eastdown" : __DIR__"zhuque",
		"westdown" : __DIR__"wroad2",
	]));
	set("outdoors", "kaifeng");

	setup();
	replace_program(ROOM);
}
