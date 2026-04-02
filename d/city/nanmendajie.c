// Room: /yangzhou/nanmendajie.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short", "南門大街");
	set("long", @LONG
南門大街寬二十餘丈，青磚鋪地，東側有一兩丈寬、一丈深的排水
溝，街的中心種着槐樹隔開道路，行人分左右而行。西邊是官河，也叫
草河，岸邊依次種着楊柳和碧桃、街西是太平橋，街東是城守署。由於
城守署在此的緣故，行人大多匆匆而過。
LONG );
	set("outdoors", "yangzhouw");

	set("exits", ([
		"west"  : __DIR__"taipingqiao",
		"east"  : __DIR__"hejiajie",
		"south" : __DIR__"nanmen",
		"north" : __DIR__"shilijie7",
	]));
	set("objects", ([
		"/d/village/npc/girl" : random(5),
	]));
	set("coor/x", 10);
	set("coor/y", -50);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}