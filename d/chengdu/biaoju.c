// Room: /d/chengdu/biaoju.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "威武鏢局");
	set("long", @LONG
門前兩個威武的石獅子，四間開的大紅門，邊上是大紅燈籠高高掛。
不時有幾個鏢師進進出出，門口是幾個看守門戶的鏢師，個個看上去體
格魁梧，手底下很有些功夫的樣子，大門正中是塊金匾，上書『威武鏢
局』四個金字。這裏就是遠近聞名的威武鏢局成都分號了。
LONG	);
	set("exits", ([
		"east" : __DIR__"beijie",
	]));
	set("objects", ([
		__DIR__"npc/biaotou" : 2,
	]));
	set("coor/x", -8060);
	set("coor/y", -2970);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

