// Room: /d/baituo/shijie.c
// Last Modified by winder on May. 15 2001
inherit ROOM;

void create()
{
	set("short","石階");
	set("long",@TEXT
你走在青石板鋪成的石階上。這裏就是傳說中神祕的白駝山。遠遠
望去，兩座白沙堆積形成的山峯好像一隻駱駝的脊背。一座山門立在你
的眼前。
TEXT );
	set("exits",([
		"east"      : __DIR__"caoping",
		"northup"   : __DIR__"damen",
		"southdown" : __DIR__"guangchang" ,
	]));
	set("outdoors", "baituo");
	set("no_clean_up", 0);
	set("coor/x", -50010);
	set("coor/y", 20000);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
