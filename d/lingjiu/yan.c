//room: yan.c
inherit ROOM;

void create()
{
	set("short","失足巖");
	set("long",@LONG
這是通向『靈鷲宮』的必經之路，山道被一塊如鷹喙突出的巨巖截
斷，巨巖光可鑑人，只有中間鑿出了一條窄窄的石階通向山道的那一頭。
你小心翼翼地試着踏了上去，心想：我能過去吧。
LONG );
	set("outdoors", "lingjiu");
	set("exits",([
		"northup"  : __DIR__"jian",
		"eastdown" : __DIR__"ya",
	]));
	set("no_clean_up", 0);
	set("coor/x", -51010);
	set("coor/y", 30000);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}