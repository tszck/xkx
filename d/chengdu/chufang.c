// Room: /d/chengdu/chufang.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "廚房");
	set("long", @LONG
一張長長的竈臺上放了五六口鐵鍋，每口鍋面前都有一位大師傅，
他們正在汗流浹背地炒着菜。
LONG	);
	set("exits", ([
		"west" : __DIR__"chenmapo",		
	]));
	set("objects", ([
		__DIR__"npc/dashifu" : 3,
	]));
	set("coor/x", -8030);
	set("coor/y", -2980);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

