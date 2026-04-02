// Room: /d/nanshaolin/kchang.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "空場");
	set("long", @LONG
這是法堂後面的一片空場，亦是少林寺的最後部分。因爲這裏地處
偏僻，亦是寺中重地，所以平常很少有僧人來這裏。北面是千佛殿，東
面是白衣殿，西面是地藏殿。
LONG );
	set("exits", ([
		"west"  : __DIR__"dzdian",
		"east"  : __DIR__"bydian",
		"north" : __DIR__"qfdian",
		"south" : __DIR__"fatang",
	]));
	set("outdoors", "nanshaolin");
	set("no_clean_up", 0);
	set("coor/x", 1820);
	set("coor/y", -6100);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}

