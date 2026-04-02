// Room: /d/nanshaolin/dzdian.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "地藏殿");
	set("long", @LONG
這是地藏殿。供奉地藏王菩薩。地藏王主宰陰間，手下自然有不少
鬼兵鬼卒，羅列帳前。菩薩眉橫煞氣，手斷陰陽。令人一見之下，頓覺
心驚膽戰，惶恐不已。
LONG );
	set("exits", ([
		"east" : __DIR__"kchang",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1810);
	set("coor/y", -6100);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}

