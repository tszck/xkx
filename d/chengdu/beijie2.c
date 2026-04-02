// Room: /d/chengdu/beijie2.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "北大街");
	set("long", @LONG
你走在一條寬闊的青石大道上，街上行人很多，個個衣着鮮明，神
氣的很，就是不時傳來幾句四川特有的髒話，“龜兒子的”，“先人板
板”，不過他們並不一定是在罵人哦，只是口頭禪不雅而已！東面是一
家賭場，陣陣喧鬧聲不斷地傳進你的耳朵裏。西面是一家珠寶店。
LONG	);
	set("outdoors","chengdu");
	set("exits", ([
		"east"  : __DIR__"duchang",
		"west"  : __DIR__"zhubaodian",		
		"north" : __DIR__"beijie1",
		"south" : __DIR__"guangchang",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8050);
	set("coor/y", -2990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

 
