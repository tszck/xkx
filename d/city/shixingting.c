// Room: /city/shixingting.c
// Last Modified by Winder on Jul. 15 2000

inherit ROOM;

void create()
{
	set("short", "詩興亭");
	set("long", @LONG
亭立之處，是全園的最高點。亭子圍以白石欄檻，可以供四人坐。
近觀山勢起伏，怪石嶙峋，又有松柏穿插其間，玉蘭花樹，蔭蓋於前。
遠眺則宅第鱗次，俯視則水平如鏡，仰視則雲行天際。真真是詩興亭。
LONG );
	set("exits", ([
		"northdown"  : __DIR__"luqiao",
		"southdown"  : __DIR__"tianjing",
	]));
	set("outdoors", "yangzhouw");
	set("no_clean_up", 0);
	set("coor/x", -22);
	set("coor/y", 2);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}