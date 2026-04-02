// Room: /d/nanshaolin/stoneroad1.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "石板路");
	set("long",@LONG
一條整齊四通八達的石板路。這裏是全寺的正中央，亦是寺中交通
最繁忙的地方，由此向南可達大雄寶殿。向北是大悲殿。向東向西輾轉
可達龍樹院、戒律院等寺中要地。
LONG );
	set("outdoors","nanshaolin");
	set("exits", ([
		"west"  : __DIR__ "huaishu4",
		"east"  : __DIR__ "songshu2",
		"north" : __DIR__"dabeidian",
		"south" : __DIR__"daxiong",
	]));
	set("objects",([
		__DIR__"npc/seng-bing3" : 2,
	]));
	set("coor/x", 1810);
	set("coor/y", -6210);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

