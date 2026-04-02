// Room: /d/nanshaolin/sblu-1.c
// Last Modified by Winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "石板路");
	set("long", @LONG
你走在一條寬闊的石板路上。這是用一米見方的巨大石板鋪設而成
的，可以並行十來個人也絕無問題。兩側是參天古柏，直聳入天，上端
樹冠相疊，遮天蔽日。幾個僧人與香客來往於其間。路的盡頭，矗立着
金壁輝煌的大雄寶殿。
LONG );
	set("exits", ([
		"southeast" : __DIR__"celang-4",
		"southwest" : __DIR__"celang-2",
                "south"     : __DIR__"twdian",
                "north"     : __DIR__"xianglu",
	]));
	set("objects",([
		__DIR__"npc/zjseng1" : 1,
		__DIR__"npc/slseng1" : 1
	]));
	set("outdoors", "nanshaolin");
	set("coor/x", 1820);
	set("coor/y", -6260);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

