// Room: /yangzhou/dashixijie.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","達士西街");
	set("long",@LONG
揚州的手工藝天下聞名，玉器的雕琢，銅鏡的磨製，雕板印刷術，
以及漆器、竹器的製作，無不是名冠天下。達士街上集中揚州大部分的
手工作坊和一些手工藝品的店鋪。
LONG );
	set("outdoors", "yangzhoue");

	set("exits", ([
		"west"  : __DIR__"matou",
		"east"  : __DIR__"dashidongjie",
		"north" : __DIR__"qiqifang",
		"south" : __DIR__"baiyipu",
	]));
	set("no_clean_up", 0);
	set("coor/x", 55);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}