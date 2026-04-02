// Room: /yangzhou/hejiajie.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short", "禾嘉街");
	set("long", @LONG
禾嘉街南面是城守署，幾個士兵在站崗，不時有士兵校尉進出。行
人到此，多不敢停留，怕惹是非。街道寬敞整潔，也少有潑皮在此打鬧。
北面多爲民宅，屋檐比次密接。中間有一小巷通向揚州治園名家「仇好
石」的住所。
LONG );
	set("outdoors", "yangzhouw");

	set("exits", ([
		"west"  : __DIR__"nanmendajie",
		"east"  : __DIR__"dongmenqiao",
		"south" : __DIR__"bingyindamen",
		"north" : __DIR__"rongxiyuan",
	]));
	set("objects", ([
		__DIR__"npc/xiaowei" : 2,
	]));
	set("no_clean_up", 0);
	set("coor/x", 20);
	set("coor/y", -50);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}