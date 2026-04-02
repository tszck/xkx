// Room: /city/tianjing.c
// Last Modified by Winder on Jul. 15 2000

inherit ROOM;

void create()
{
	set("short", "天井");
	set("long", @LONG
天井甚小，縱深十餘步，寬僅五六步，前有洞室，左有門與官衙的
院子相通。在門的北側，有懸蹬十數級，可由此登山。在洞口的西側，
有石階數級，可以臨水。如此小的天井內有如此景緻，遊人到此多凝思
玩賞一會，對治此園的工匠不禁生出幾分敬意。
LONG );
	set("exits", ([
		"northup" : __DIR__"shixingting",
		"north"   : __DIR__"hushishandong",
		"east"    : __DIR__"yamenyuan",
	]));
	set("outdoors", "yangzhouw");
	set("no_clean_up", 0);
	set("coor/x", -22);
	set("coor/y", 1);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}