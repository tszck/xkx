// Room: huanhuaxi1.c
// Date: Feb.14 1998 by Java

inherit ROOM;

void create()
{
	set("short", "浣花溪邊");
	set("long",@LONG
你走在浣花溪邊，流水清澈，河邊不少女子在此洗衣，淘菜。這條
蜿蜒的小溪，順着那府南河流出，水面上尚有幾株橫裏伸展的枝椏，輕
拂流水，有一股淡淡的詩意。秋風蕭瑟，枝搖影斜，在靜寂中，帶着一
絲悽清與孤獨。 
LONG	);

	set("outdoors", "chengdu");
	set("exits", ([
		"north"     : __DIR__"huanhuaxi",
		"southwest" : __DIR__"path2",
		"northeast" : __DIR__"huanhuaxi2",
	]));
	set("coor/x", -8050);
	set("coor/y", -2960);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);       
}


