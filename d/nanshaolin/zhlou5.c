// Room: /d/nanshaolin/zhlou5.c
// Last Modified by Winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "鐘樓五層");
	set("long", @LONG
一眼望去，只見藍天白雲，青山列列，令人將塵俗之氣，頓為一一
掃。南至前三殿，北到方丈樓，整個南少林寺盡在眼底。北面松樹林隨
風起伏，林濤陣陣。西面可以看到一大片槐樹林。
LONG );
	set("exits", ([
		"up"   : __DIR__"zhlou6",
		"down" : __DIR__"zhlou4",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1840);
	set("coor/y", -6280);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}



