// /d/beijing/andao9.c
// Last Modified by winder on Jan. 18 2002

inherit ROOM;

void create()
{
	set("short", "天地會暗道");
	set("long", @LONG
地道里一片漆黑，呼呼的風聲從四面八方傳來。你什麼也看不見，
只能在地道里瞎摸亂撞。北面似乎隱隱約約有人説話，但只一會兒又沒
聲了。你使勁地搖了搖頭，很懷疑這到底是不是幻覺。好象你已經迷路
了。
LONG );
	set("exits", ([
		"east"  : __DIR__"andao10",
		"west"  : __DIR__"andao10",
		"north" : __DIR__"andao10",
		"south" : __DIR__"andao8",
	]));
	set("no_clean_up", 0);
	set("coor/x", -212);
	set("coor/y", 4010);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}
