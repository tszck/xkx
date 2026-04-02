// Room: /d/nanshaolin/gulou5.c
// Last Modified by Winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "鼓樓五層");
	set("long", @LONG
一眼望去，只見藍天白雲，青山列列，令人將塵俗之氣，頓爲一一
掃。南至前三殿，北到戒臺，整個少林寺盡在眼底。北面槐樹林隨風起
伏，猶如一片林海。東西面圍繞全寺的是密密匝匝的松林，一眼往不到
邊。
LONG );
	set("exits", ([
		"up"   : __DIR__"gulou6",
		"down" : __DIR__"gulou4",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1800);
	set("coor/y", -6280);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}

