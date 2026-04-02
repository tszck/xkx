// Room: /d/chengdu/huanhuaxi2.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "浣花溪");
	set("long",@LONG
季節雖然已經是深秋，但日正當中的陽光，仍舊是十分炎熱的。四
周是一片芙蓉樹，遠山隱在雲霧之中，恍若迷離的美人，不遠處有着，
一叢叢的樹林，有一條溪流，沿着林旁蜿蜒流去。這裏已是浣花溪，往
東就是北大街了。
LONG	);
	set("outdoors", "chengdu");
	set("exits", ([
		"southwest" : __DIR__"huanhuaxi1",
		"northeast" : __DIR__"beijie1",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8040);
	set("coor/y", -2950);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);       
}


